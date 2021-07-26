#include "wally.h"
#include <array>
#include <cstdio>


extern "C" CEC_HandleTypeDef hcec;
extern "C" UART_HandleTypeDef huart2;
extern "C" uint8_t cec_receive_buffer[ 16 ];

static TWally Wally;
static uint8_t UartBuffer[ 256 ];
static uint32_t UartHead;
static uint32_t UartTail;
static uint32_t UartCount;

void TWally::Loop()
{
  if( FlagCecRx )
  {
    FlagCecRx = false;
    PrintCecMessage( cec_receive_buffer, CecRxFrameSize );
  }

  if( FlagCecTx )
  {
    FlagCecTx = false;
  }

  if( FlagCecError )
  {
    FlagCecError = false;
    PrintCecError( HAL_CEC_GetError( &hcec ));
  }

  if( bool const New5V = HAL_GPIO_ReadPin( HDMI_5V_IN_GPIO_Port, HDMI_5V_IN_Pin ); New5V != Hdmi5V )
  {
    Hdmi5V = New5V;
    printf( "%sHDMI 5v: %s\n", GetLogPrefix(), Hdmi5V ? "ON" : "OFF" );
  }

  if( bool const NewHPD = HAL_GPIO_ReadPin( HDMI_HPD_IN_GPIO_Port, HDMI_HPD_IN_Pin ); NewHPD != HdmiHPD )
  {
    HdmiHPD = NewHPD;
    printf( "%sHDMI HPD: %s\n", GetLogPrefix(), HdmiHPD ? "ON" : "OFF" );
  }

  if( FlagSysTick )
  {
    FlagSysTick = false;

    if( LedCount && ( --LedCount == 0 ))
    {
      HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET );
    }
    else if(( HAL_GetTick() % 1000 ) == 0 )
    {
      LedCount = 100;
      HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET );
    }
  }
}

void TWally::Setup()
{
  puts( "Wally v1.02" );
}

TWally::TWally() :
  Hdmi5V( false ),
  HdmiHPD( false ),
  FlagCecRx( false ),
  FlagCecTx( false ),
  FlagSysTick( false ),
  FlagCecError( false ),
  LogPrefix{ 0 },
  LogTick( 0 ),
  LedCount( 0 ),
  CecRxFrameSize( 0 )
{
}

char const* TWally::GetLogPrefix()
{
  uint32_t Tick = HAL_GetTick();
  uint32_t const Diff = Tick > LogTick ? Tick - LogTick : ( 0xffffffffu - LogTick ) + Tick + 1;
  LogTick = Tick;

  uint32_t const Milliseconds = Tick % 1000;
  Tick /= 1000;
  uint32_t const Seconds = Tick % 60;
  Tick /= 60;
  uint32_t const Minutes = Tick % 60;
  Tick /= 60;
  uint32_t const Hours = Tick % 24;

  if( Diff < 1000 )
    snprintf( LogPrefix, std::size( LogPrefix ), "%02lu:%02lu:%02lu:%03lu %03lu ", Hours, Minutes, Seconds, Milliseconds, Diff );
  else
    snprintf( LogPrefix, std::size( LogPrefix ), "%02lu:%02lu:%02lu:%03lu     ", Hours, Minutes, Seconds, Milliseconds );

  return LogPrefix;
}

void TWally::SysTick_Handler()
{
  FlagSysTick = true;
}

void TWally::HAL_CEC_ErrorCallback()
{
  FlagCecError = true;
}

void TWally::HAL_CEC_RxCpltCallback( uint32_t const RxFrameSize )
{
  FlagCecRx = true;
  CecRxFrameSize = RxFrameSize;
}

void TWally::HAL_CEC_TxCpltCallback()
{
  FlagCecTx = true;
}

extern "C" void WallyLoop()
{
  Wally.Loop();
}

extern "C" void WallySetup()
{
  Wally.Setup();
}

extern "C" void SysTick_Handler()
{
  HAL_IncTick();
  Wally.SysTick_Handler();
}

extern "C" void HAL_CEC_ErrorCallback( CEC_HandleTypeDef *const hcec )
{
  (void)hcec;
  Wally.HAL_CEC_ErrorCallback();
}

extern "C" void HAL_CEC_RxCpltCallback( CEC_HandleTypeDef *const hcec, uint32_t const RxFrameSize )
{
  (void)hcec;
  Wally.HAL_CEC_RxCpltCallback( RxFrameSize );
}

extern "C" void HAL_CEC_TxCpltCallback( CEC_HandleTypeDef *const hcec )
{
  (void)hcec;
  Wally.HAL_CEC_TxCpltCallback();
}

extern "C" int __io_putchar(int const ch)
{
  if( UartCount < std::size( UartBuffer ))
  {
    __disable_irq();
    UartCount++;
    __enable_irq();

    UartBuffer[ UartHead ] = ch;
    if( ++UartHead == std::size( UartBuffer ))
    {
      UartHead = 0;
    }
  }

  if( UartCount == 1 )
  {
    auto const Status = HAL_UART_Transmit_IT( &huart2, &UartBuffer[ UartTail ], 1 );
    if( Status != HAL_OK )
    {
      HAL_GPIO_WritePin( LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET );
    }
  }

  return 1;
}

extern "C" void HAL_UART_TxCpltCallback( UART_HandleTypeDef *huart )
{
  UartCount--;
  if( ++UartTail == std::size( UartBuffer ))
  {
    UartTail = 0;
  }

  if( UartCount )
  {
    auto const Status = HAL_UART_Transmit_IT( huart, &UartBuffer[ UartTail ], 1 );
    if( Status != HAL_OK )
    {
      HAL_GPIO_WritePin( LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET );
    }
  }
}
