#include <cstdio>
#include <cstdlib>
#include <cstdarg>

#include "wally.h"
#include "usbd_cdc_if.h"


static TWally Wally;


void TWally::HAL_GPIO_EXTI_Callback()
{
  bool const PinSCL = HAL_GPIO_ReadPin( I2C1_SCL_GPIO_Port, I2C1_SCL_Pin );
  bool const PinSDA = HAL_GPIO_ReadPin( I2C1_SDA_GPIO_Port, I2C1_SDA_Pin );

  if(( PinSCL != OldSCL ) || ( PinSDA != OldSDA ))
  {
    FlagI2C = true;
  }

  if( PinSCL != OldSCL )
  {
    CntSCL++;
    OldSCL = PinSCL;
  }

  if( PinSDA != OldSDA )
  {
    CntSDA++;
    OldSDA = PinSDA;
  }
}

void TWally::Loop()
{
  auto const Tick = HAL_GetTick();

  auto Time = Tick;
  auto const Msec = Time % 1000;
  Time /= 1000;
  auto const Sec = Time % 60;
  Time /= 60;
  auto const Min = Time % 60;
  auto const Hour = Time / 60;

  if((( Tick % 1000 ) == 0 ) && FlagI2C )
  {
    UsbPrintf( "%02lu:%02lu:%02lu:%03lu SCL:%lu SDA:%lu\n", Hour, Min, Sec, Msec, CntSCL, CntSDA );

    CntSCL = 0;
    CntSDA = 0;
    FlagI2C = false;
    HAL_Delay( 5 );
  }

  bool const New5v = HAL_GPIO_ReadPin( HDMI_5V_IN_GPIO_Port, HDMI_5V_IN_Pin );
  if( New5v != Flag5v )
  {
    Flag5v = New5v;

    UsbPrintf( "%02lu:%02lu:%02lu:%03lu HDMI 5v=%s\n", Hour, Min, Sec, Msec, Flag5v ? "ON" : "OFF" );
  }

  bool const NewHPD = HAL_GPIO_ReadPin( HDMI_HPD_IN_GPIO_Port, HDMI_HPD_IN_Pin );
  if( NewHPD != FlagHPD )
  {
    FlagHPD = NewHPD;
    UsbPrintf( "%02lu:%02lu:%02lu:%03lu HDMI HPD=%s\n", Hour, Min, Sec, Msec, FlagHPD ? "ON" : "OFF" );
  }

  if(( Tick % 2000 ) == 0 )
  {
//    HAL_GPIO_TogglePin(HDMI_5V_EN_GPIO_Port, HDMI_5V_EN_Pin);
//    HAL_GPIO_TogglePin(HDMI_HPD_EN_GPIO_Port, HDMI_HPD_EN_Pin);

    HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET );
    HAL_Delay( 5 );
    HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET );

//    static uint8_t TxBuffer[] = {0xa0, 0x8a, 0xc7, 0x2e, 0x35, 0x12};
//    HAL_CEC_Transmit_IT( &hcec, 0, 5, TxBuffer, sizeof( TxBuffer ));
  }

  if( CecRxFlag )
  {
    CecRxFlag = false;
//    HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET );
//    HAL_Delay( 5 );
//    HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET );

    PrintCecMessage( hcec.Init.RxBuffer, this->RxFrameSize );
  }

  if( CecTxFlag )
  {
    CecTxFlag = false;
    UsbPrintf( "CEC Transmit\n" );

    HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET );
    HAL_Delay( 5 );
    HAL_GPIO_WritePin( LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET );
  }

  if( CecErrorFlag )
  {
    CecErrorFlag = false;

    Len = snprintf( Buffer, sizeof(Buffer), "%02lu:%02lu:%02lu:%03lu CEC Error - %lu\n",
      Hour, Min, Sec, Msec, CecErrorCode );

    HAL_GPIO_WritePin( LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET );
    HAL_Delay( 5 );
    HAL_GPIO_WritePin( LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET );
  }
}

void TWally::Setup()
{
  UsbPrintf("Wally v1.02\n");

  HAL_GPIO_WritePin(HDMI_5V_EN_GPIO_Port, HDMI_5V_EN_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(HDMI_HPD_EN_GPIO_Port, HDMI_HPD_EN_Pin, GPIO_PIN_RESET);

  OldSCL = HAL_GPIO_ReadPin( I2C1_SCL_GPIO_Port, I2C1_SCL_Pin );
  OldSDA = HAL_GPIO_ReadPin( I2C1_SDA_GPIO_Port, I2C1_SDA_Pin );
}

TWally::TWally() :
  OldSCL(false),
  OldSDA(false),
  Flag5v(false),
  FlagHPD(false),
  FlagI2C(false),
  CecRxFlag( false ),
  CecTxFlag( false ),
  CecErrorFlag( false ),
  Len( 0 ),
  Buffer(),
  CntSCL( 0 ),
  CntSDA( 0 ),
  RxFrameSize( 0 ),
  CecErrorCode( 0 )
{
}

const struct CecOpcodeData
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

const struct CecSubopcodeData
{
	char const *Text;
	int Opcode;
}
CecSubopcodeText[] =
{
  "FeatureAbort",          0x00,
  "AnnouncePresence",      0x10,
  "InitSession",           0x11,
  "AcceptSession",         0x12,
  "StromData",             0x13,
  "UnsupportedVersion",    0x14,
  "ResetSession",          0x15,
  "InvalidOpcode",         0xFE,
  "SetFeatureState",       0x30,
  "ReportFeatureState",    0x31,
  "SetLatency",            0x32,
  "Reset",                 0x33,
  "ReportFirmwareVersion", 0x34,
  "KVSet",                 0x35,
  "KVReport",              0x36,
  "KVReset",               0x37,
  "KVNack",                0x38,
  "IR_KeyPress",           0xE0,
  "Abort",                 0xFF
};

void TWally::PrintHex( uint8_t const* const Msg, uint32_t const Start, uint32_t const Length, char const* const Term )
{
  const char *Sep = "";
  for( auto Index = Start; Index < Length; Index++ )
  {
    Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%s%02x", Sep, Msg[ Index ] );
    Sep = " ";
  }
  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%s", Term );
}

void TWally::PrintAscii( uint8_t const* const Msg, uint32_t const Start, uint32_t const Length, char const* const Term )
{
  for( auto Index = Start; Index < Length; Index++ )
  {
    Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%c", Msg[ Index ] );
  }
  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%s", Term );
}

void TWally::PrintKvEntries( uint8_t const* const Msg, uint32_t const Start, uint32_t const Length, char const* const Term )
{
  for( auto Index = Start; Index < Length; Index +=2)
  {
    Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "{K:%u S:%u V:%u}",
      Msg[Index] >> 3, Msg[Index] & 0x07, Msg[Index + 1] & 0x7F );
  }
  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "}");
}

void TWally::PrintCecMessage( uint8_t const* const Msg, uint32_t const Length )
{
  auto Time = HAL_GetTick();
  auto const Msec = Time % 1000;
  Time /= 1000;
  auto const Sec = Time % 60;
  Time /= 60;
  auto const Min = Time % 60;
  auto const Hour = Time / 60;

  Len = snprintf( Buffer, sizeof(Buffer), "%02lu:%02lu:%02lu:%03lu [%u:%u] ",
    Hour, Min, Sec, Msec, ( Msg[ 0 ] >> 4 ) & 0x0f, Msg[ 0 ] & 0x0f );

  if( Length >= 1 )
  {
    switch( Msg[1] )
    {
      case 0x36:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Standby" );
      }
      break;

      case 0x45:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "User Control Released" );
      }
      break;

      case 0x46:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Give OSD Name" );
      }
      break;

      case 0x47:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Set OSD Name {" );
        PrintAscii( Msg, 2, Length, "}" );
      }
      break;

      case 0x64:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Set OSD String {" );
        PrintAscii( Msg, 2, Length, "}" );
      }
      break;

      case 0x70:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "System Audio Mode Request" );
      }
      break;

      case 0x71:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Give Audio Status" );
      }
      break;

      case 0x7d:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Give System Audio Mode Status" );
      }
      break;

      case 0x83:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Give Physical Address" );
      }
      break;

      case 0x8c:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Give Device Vendor ID" );
      }
      break;

      case 0xA0:
      {
        PrintCecVendorMessage( Msg, Length );
      }
      break;

      case 0xc0:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Initiate ARC" );
      }
      break;

      case 0xc1:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Report ARC Initiated" );
      }
      break;

      case 0xc2:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Report ARC Terminated" );
      }
      break;

      case 0xc3:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Request ARC Initiation" );
      }
      break;

      case 0xc4:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Request ARC Termination" );
      }
      break;

      case 0xc5:
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Terminate ARC" );
      }
      break;

      default:
      {
        for( const auto &Entry: CecOpcodeText )
        {
          if( Entry.Opcode == Msg[1] )
          {
   	        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%s ", Entry.Text );
            break;
          }
        }
        PrintHex( Msg, 1, Length );
      }
    }
  }

  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "\n" );

  auto Status = CDC_Transmit_FS( reinterpret_cast<uint8_t*>( Buffer ), static_cast<uint16_t>( Len ));
  if( Status != USBD_BUSY )
  {
  }
}

// 22852	    492	   4104	  27448	   6b38	stm32.elf
// 22788	    492	   4104	  27384	   6af8	stm32.elf
// 22520	    492	   4104	  27116	   69ec	stm32.elf
// 22512	    492	   4104	  27108	   69e4	stm32.elf
// 22492	    492	   4104	  27088	   69d0	stm32.elf

void TWally::PrintCecVendorMessage( uint8_t const* const Msg, uint32_t const Length )
{
  auto const GetVLT = [Msg](uint32_t &Index)
  {
    uint8_t Data;
    uint32_t Value = 0;
    do
    {
      Data = Msg[Index++];
      Value *= 128;
      Value += (Data & 0x7f);
    }
    while( Data & 0x80 );

    return Value;
  };

   switch( Msg[5] )
  {
    case 0x10:
    {
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuAnnouncePresence {Version:%d.%d}", Msg[6] >> 3, Msg[6] & 0x07);
    }
    break;

    case 0x11:
    {
      uint32_t Index = 7;
      uint32_t Id = GetVLT(Index);
   	  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuInitSession {Version:%d.%d Id:%lu DeviceId{",
        Msg[6] >> 3, Msg[6] & 0x07, Id);

   	  PrintHex( Msg, Index, Length, "}}" );
    }
    break;

    case 0x12:
    {
   	  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuAcceptSession {Version:%u.%u DeviceId{",
        Msg[6] >> 3, Msg[6] & 0x07);

   	  PrintHex( Msg, 7, Length, "}}" );
    }
    break;

    case 0x13:
    {
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuStromData {");
   	  PrintHex( Msg, 6, Length, "}" );
    }
    break;

    case 0x14:
    {
      uint32_t Index = 7;
      uint32_t Id = GetVLT(Index);
   	  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuUnsupportedVersion {Version:%d.%d Id:%lu DeviceId{",
        Msg[6] >> 3, Msg[6] & 0x07, Id);

   	  PrintHex( Msg, Index, Length, "}}" );
    }
    break;

    case 0x15:
    {
      uint32_t Index = 7;
      uint32_t Id = GetVLT(Index);
   	  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuResetSession {Version:%d.%d Id:%lu DeviceId{",
        Msg[6] >> 3, Msg[6] & 0x07, Id);

   	  PrintHex( Msg, Index, Length, "}}" );
    }
    break;

    case 0x30:
    {
      if( Length == 7 )
   	  {
   	    Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuSetState {}");
   	  }
      else
   	  {
        uint32_t Index = 7;
        uint32_t Id = GetVLT(Index);
   	  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuSetState {FeatureSetID:%lu StateVector{", Id );

   	  PrintHex( Msg, Index, Length, "}}" );
    }
    }
    break;

    case 0x31:
    {
      uint32_t Index = 7;
      uint32_t Id = GetVLT(Index);
   	  Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuReportState {FeatureSetID:%lu StateVector{",
        Id);

   	  PrintHex( Msg, Index, Length, "}}" );
    }
    break;

    case 0x33:
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuReset");
    break;

    case 0x34:
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuFirmwareVersion {");
      for( auto Index = 6u; Index < Length; Index++ )
      {
        Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "%c", Msg[ Index ] );
      }
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "}" );
    break;

    case 0x35:
    case 0x36:
    case 0x37:
      PrintCecKvFrame(Msg, Length);
    break;

    default:
      for( const auto &Entry: CecSubopcodeText )
      {
        if (Entry.Opcode == Msg[5] )
        {
          Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "Roku%s ", Entry.Text );
          break;
        }
      }
   	  PrintHex( Msg, 1, Length );
    break;
  }
}

void TWally::PrintCecKvFrame( uint8_t const* const Msg, uint32_t const Length )
{
  switch( Msg[5] )
  {
    case 0x35:
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuKVSet    More:%u Orig:%s Seq:%u Req:%u {",
        (Msg[6] & 0x80) == 0x80, Msg[6] & 0x40 ? "Dev" : "TV ", Msg[6] & 0x07, (Msg[6] >> 3) & 0x07);
      PrintKvEntries( Msg, 7, Length, "}" );
    break;

    case 0x36:
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuKVReport More:%u Orig:%s Seq:%u Req:%u {",
        (Msg[6] & 0x80) == 0x80, Msg[6] & 0x40 ? "Dev" : "TV ", Msg[6] & 0x07, (Msg[6] >> 3) & 0x07);
      PrintKvEntries( Msg, 7, Length, "}" );
    break;

    case 0x37:
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "RokuKVReset  More:%u Orig:%s Seq:%u Req:%u ",
        (Msg[6] & 0x80) == 0x80, Msg[6] & 0x40 ? "Dev" : "TV ", Msg[6] & 0x07, (Msg[6] >> 3) & 0x07);
      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, "{Id:%u}", Msg[7] );
    break;

    default:
      for( const auto &Entry: CecSubopcodeText )
      {
        if (Entry.Opcode == Msg[5] )
        {
   	      Len += snprintf( &Buffer[Len], sizeof(Buffer) - Len, " Vendor%s", Entry.Text );
          break;
        }
      }
    break;
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

void TWally::HAL_CEC_ErrorCallback(uint32_t const ErrorCode)
{
  CecErrorFlag = true;
  CecErrorCode = ErrorCode;
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
  Wally.HAL_CEC_ErrorCallback(hcec->ErrorCode);
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

extern "C" void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  (void)GPIO_Pin;
  Wally.HAL_GPIO_EXTI_Callback();
}
