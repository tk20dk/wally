#include <cstdio>
#include <cstdlib>
#include <cstdarg>

#include "wally.h"
#include "usbd_cdc_if.h"


static TWally Wally;

void TWally::Loop()
{
  if(( HAL_GetTick() % 1000 ) == 0 )
  {
    HAL_GPIO_WritePin( HMI_LED0_GPIO_Port, HMI_LED0_Pin, GPIO_PIN_SET );
    HAL_Delay( 10 );
    HAL_GPIO_WritePin( HMI_LED0_GPIO_Port, HMI_LED0_Pin, GPIO_PIN_RESET );

//    static uint8_t TxBuffer[ 16 ];
//    HAL_CEC_Transmit_IT( &hcec, 5 ,1, TxBuffer, 0 );
}

   if( CecRxFlag )
  {
    CecRxFlag = false;
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_SET );
    HAL_Delay( 10 );
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_RESET );

    PrintCecMessage( hcec.Init.RxBuffer, this->RxFrameSize );
  }

  if( CecTxFlag )
  {
    CecTxFlag = false;
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_SET );
    HAL_Delay( 100 );
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_RESET );
  }

  if( CecErrorFlag )
  {
    CecErrorFlag = false;
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_SET );
    HAL_Delay( 100 );
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_RESET );
  }
}

void TWally::Setup()
{
}

TWally::TWally() :
  CecRxFlag( false ),
  CecTxFlag( false ),
  CecErrorFlag( false ),
  RxFrameSize( 0 )
{
}

void TWally::PrintCecMessage( uint8_t const* const Msg, uint32_t const Length )
{
  static char Buffer[ 128 ];

  auto Len = snprintf( Buffer, sizeof(Buffer), "%u %u", ( Msg[ 0 ] >> 4 ) & 0x0f, Msg[ 0 ] & 0x0f );

  for( auto Index = 1u; Index < Length; Index++ )
  {
    Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, " %02x", Msg[ Index ] );
  }
  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "\n" );

  auto Status = CDC_Transmit_FS( reinterpret_cast<uint8_t*>( Buffer ), static_cast<uint16_t>( Len ));
  if( Status != USBD_BUSY )
  {
  }
}

void TWally::UsbPrintf( char const *const Format, ... )
{
  static int Length;
  static char Buffer[ 128 ];
  va_list Args;

  va_start( Args, Format );
  Length += vsnprintf( &Buffer[ Length ], sizeof( Buffer ) - Length, Format, Args );
  va_end( Args );

  if( Length > 0 )
  {
    auto Status = CDC_Transmit_FS( reinterpret_cast<uint8_t*>( Buffer ), static_cast<uint16_t>( Length ));
    if( Status != USBD_BUSY )
    {
      Length = 0;
    }
  }
}

void TWally::HAL_CEC_ErrorCallback()
{
  CecErrorFlag = true;
}

void TWally::HAL_CEC_TxCpltCallback()
{
  CecRxFlag = true;
}

void TWally::HAL_CEC_RxCpltCallback( uint32_t const RxFrameSize )
{
  CecRxFlag = true;
  this->RxFrameSize = RxFrameSize;
}

extern "C" void WallyLoop()
{
  Wally.Loop();
}

extern "C" void WallySetup()
{
  Wally.Setup();
}

extern "C" void HAL_CEC_ErrorCallback(CEC_HandleTypeDef *const hcec)
{
  (void)hcec;
  Wally.HAL_CEC_ErrorCallback();
}

extern "C" void HAL_CEC_TxCpltCallback( CEC_HandleTypeDef *const hcec )
{
  (void)hcec;
  Wally.HAL_CEC_TxCpltCallback();
}

extern "C" void HAL_CEC_RxCpltCallback( CEC_HandleTypeDef *const hcec, uint32_t const RxFrameSize )
{
  (void)hcec;
  Wally.HAL_CEC_RxCpltCallback( RxFrameSize );
}
