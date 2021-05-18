#include <cstdio>
#include <cstdlib>
#include <cstdarg>

#include "wally.h"
#include "usbd_cdc_if.h"


static TWally Wally;


struct CecOpcodeData
{
	char const *Text;
	int Opcode;
}
CecOpcodeText[] =
{
  "Feature_Abort",                     0x00,
  "Image_View_On",                     0x04,
  "Tuner_Step_Increment",              0x05,
  "Tuner_Step_Decrement",              0x06,
  "Tuner_Device_Status",               0x07,
  "Give_Tuner_Device_Status",          0x08,
  "Record_On",                         0x09,
  "Record_Status",                     0x0A,
  "Record_Off",                        0x0B,
  "Text_View_On",                      0x0D,
  "Record_TV_Screen",                  0x0F,
  "Give_Deck_Status",                  0x1A,
  "Deck_Status",                       0x1B,
  "Set_Menu_Language",                 0x32,
  "Clear_Analogue_Timer",              0x33,
  "Set_Analogue_Timer",                0x34,
  "Timer_Status",                      0x35,
  "Standby",                           0x36,
  "Play",                              0x41,
  "Deck_Control",                      0x42,
  "Timer_Cleared_Status",              0x43,
  "User_Control_Pressed",              0x44,
  "User_Control_Released",             0x45,
  "Give_OSD_Name",                     0x46,
  "Set_OSD_Name",                      0x47,
  "Set_OSD_String",                    0x64,
  "Set_Timer_Program_Title",           0x67,
  "System_Audio_Mode_Request",         0x70,
  "Give_Audio_Status",                 0x71,
  "Set_System_Audio_Mode",             0x72,
  "Report_Audio_Status",               0x7A,
  "Give_System_Audio_Mode_Status",     0x7D,
  "System_Audio_Mode_Status",          0x7E,
  "Routing_Change",                    0x80,
  "Routing_Information",               0x81,
  "Active_Source",                     0x82,
  "Give_Physical_Address",             0x83,
  "Report_Physical_Address",           0x84,
  "Request_Active_Source",             0x85,
  "Set_Stream_Path",                   0x86,
  "Device_Vendor_ID",                  0x87,
  "Vendor_Command",                    0x89,
  "Vendor_Remote_Button_Down",         0x8A,
  "Vendor_Remote_Button_Up",           0x8B,
  "Give_Device_Vendor_ID",             0x8C,
  "Menu_Request",                      0x8D,
  "Menu_Status",                       0x8E,
  "Give_Device_Power_Status",          0x8F,
  "Report_Power_Status",               0x90,
  "Get_Menu_Language",                 0x91,
  "Select_Analogue_Service",           0x92,
  "Select_Digital_Service",            0x93,
  "Set_Digital_Timer",                 0x97,
  "Clear_Digital_Timer",               0x99,
  "Set_Audio_Rate",                    0x9A,
  "Inactive_Source",                   0x9D,
  "CEC_Version",                       0x9E,
  "Get_CEC_Version",                   0x9F,
  "Vendor_Command_With_ID",            0xA0,
  "Clear_External_Timer",              0xA1,
  "Set_External_Timer",                0xA2,
  "Report_Short_Audio_Descriptor",     0xA3,
  "Request_Short_Audio_Descriptor",    0xA4,
  "Request_Current_Latency",           0xA7,
  "Report_Current_Latency",            0xA8,
  "Initiate_ARC",                      0xC0,
  "Report_ARC_Initiated",              0xC1,
  "Report_ARC_Terminated",             0xC2,
  "Request_ARC_Initiation",            0xC3,
  "Request_ARC_Termination",           0xC4,
  "Terminate_ARC",                     0xC5,
  "CDC_Message",                       0xF8,
  "Abort",                             0xFF
};

void TWally::Loop()
{
  bool const New5v = HAL_GPIO_ReadPin( HDMI_5V_IN_GPIO_Port, HDMI_5V_IN_Pin );
  if( New5v != Flag5v )
  {
    Flag5v = New5v;
    UsbPrintf( "HDMI 5v=%s\n", Flag5v ? "ON" : "OFF" );
  }

  bool const NewHPD = HAL_GPIO_ReadPin( HDMI_HPD_IN_GPIO_Port, HDMI_HPD_IN_Pin );
  if(NewHPD != FlagHPD)
  {
    FlagHPD = NewHPD;
    UsbPrintf( "HDMI HPD=%s\n", FlagHPD ? "ON" : "OFF");
  }

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
    HAL_Delay( 50 );
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_RESET );
  }

  if( CecErrorFlag )
  {
    CecErrorFlag = false;
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_SET );
    HAL_Delay( 50 );
    HAL_GPIO_WritePin( HMI_LED1_GPIO_Port, HMI_LED1_Pin, GPIO_PIN_RESET );
  }
}

void TWally::Setup()
{
  UsbPrintf("Wally v1.01\n");
}

TWally::TWally() :
  Flag5v(false),
  FlagHPD(false),
  CecRxFlag( false ),
  CecTxFlag( false ),
  CecErrorFlag( false ),
  RxFrameSize( 0 )
{
}

void TWally::PrintCecMessage( uint8_t const* const Msg, uint32_t const Length )
{
  static char Buffer[ 128 ];

  auto Len = snprintf( Buffer, sizeof(Buffer), "[%u:%u] ", ( Msg[ 0 ] >> 4 ) & 0x0f, Msg[ 0 ] & 0x0f );

  if( Length >= 1 )
  {
    for( const auto &Entry: CecOpcodeText )
    {
      if (Entry.Opcode == Msg[1] )
      {
   	    Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%s", Entry.Text );
        break;
      }
    }
  }

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
  CecTxFlag = true;
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
