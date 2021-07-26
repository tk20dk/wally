#include "wally.h"

#include <array>
#include <cstdio>
#include <cstring>


constexpr auto Feature_Abort                  = 0x00;
constexpr auto Image_View_On                  = 0x04;
constexpr auto Tuner_Step_Increment           = 0x05;
constexpr auto Tuner_Step_Decrement           = 0x06;
constexpr auto Tuner_Device_Status            = 0x07;
constexpr auto Give_Tuner_Device_Status       = 0x08;
constexpr auto Record_On                      = 0x09;
constexpr auto Record_Status                  = 0x0A;
constexpr auto Record_Off                     = 0x0B;
constexpr auto Text_View_ON                   = 0x0D;
constexpr auto Record_TV_Screen               = 0x0F;
constexpr auto Give_Deck_Status               = 0x1A;
constexpr auto Deck_Status                    = 0x1B;
constexpr auto Set_Menu_Language              = 0x32;
constexpr auto Clear_Analogue_Timer           = 0x33;
constexpr auto Set_Analogue_Timer             = 0x34;
constexpr auto Timer_Status                   = 0x35;
constexpr auto Standby                        = 0x36;
constexpr auto Play                           = 0x41;
constexpr auto Deck_Control                   = 0x42;
constexpr auto Timer_Cleared_Status           = 0x43;
constexpr auto User_Control_Pressed           = 0x44;
constexpr auto User_Control_Released          = 0x45;
constexpr auto Give_OSD_Name                  = 0x46;
constexpr auto Set_OSD_Name                   = 0x47;
constexpr auto Set_OSD_String                 = 0x64;
constexpr auto Set_Timer_Program_Title        = 0x67;
constexpr auto System_Audio_Mode_Request      = 0x70;
constexpr auto Give_Audio_Status              = 0x71;
constexpr auto Set_System_Audio_Mode          = 0x72;
constexpr auto Report_Audio_Status            = 0x7A;
constexpr auto Give_System_Audio_Mode_Status  = 0x7D;
constexpr auto System_Audio_Mode_Status       = 0x7E;
constexpr auto Routing_Change                 = 0x80;
constexpr auto Routing_Information            = 0x81;
constexpr auto Active_Source                  = 0x82;
constexpr auto Give_Physical_Address          = 0x83;
constexpr auto Report_Physical_Address        = 0x84;
constexpr auto Request_Active_Source          = 0x85;
constexpr auto Set_Stream_Path                = 0x86;
constexpr auto Device_Vendor_ID               = 0x87;
constexpr auto Vendor_Command                 = 0x89;
constexpr auto Vendor_Remote_Button_Down      = 0x8A;
constexpr auto Vendor_Remote_Button_Up        = 0x8B;
constexpr auto Give_Device_Vendor_ID          = 0x8C;
constexpr auto Menu_Request                   = 0x8D;
constexpr auto Menu_Status                    = 0x8E;
constexpr auto Give_Device_Power_Status       = 0x8F;
constexpr auto Report_Power_Status            = 0x90;
constexpr auto Get_Menu_Language              = 0x91;
constexpr auto Select_Analogue_Service        = 0x92;
constexpr auto Select_Digital_Service         = 0x93;
constexpr auto Set_Digital_Timer              = 0x97;
constexpr auto Clear_Digital_Timer            = 0x99;
constexpr auto Set_Audio_Rate                 = 0x9A;
constexpr auto Inactive_Source                = 0x9D;
constexpr auto CEC_Version                    = 0x9E;
constexpr auto Get_CEC_Version                = 0x9F;
constexpr auto Vendor_Command_With_ID         = 0xA0;
constexpr auto Clear_External_Timer           = 0xA1;
constexpr auto Set_External_Timer             = 0xA2;
constexpr auto Report_Short_Audio_Descriptor  = 0xA3;
constexpr auto Request_Short_Audio_Descriptor = 0xA4;
constexpr auto Request_Current_Latency        = 0xA7;
constexpr auto Report_Current_Latency         = 0xA8;
constexpr auto Initiate_ARC                   = 0xC0;
constexpr auto Report_ARC_Initiated           = 0xC1;
constexpr auto Report_ARC_Terminated          = 0xC2;
constexpr auto Request_ARC_Initiation         = 0xC3;
constexpr auto Request_ARC_Termination        = 0xC4;
constexpr auto Terminate_ARC                  = 0xC5;
constexpr auto CDC_Message                    = 0xF8;
constexpr auto Abort                          = 0xFF;

struct TCecOpcodeData
{
	char const *Text;
	int Opcode;
};

TCecOpcodeData const CecOpcodeText[] =
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

void TWally::PrintCecError( uint32_t const Error )
{
  if( Error & HAL_CEC_ERROR_RXOVR )  printf( "%sRx Overrun\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_BRE )    printf( "%sRx Bit Rising Error\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_SBPE )   printf( "%sRx Short Bit period Error\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_LBPE )   printf( "%sRx Long Bit period Error\n", GetLogPrefix() );
//  if( Error & HAL_CEC_ERROR_RXACKE ) printf( "%sMissing Rx Acknowledge\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_ARBLST ) printf( "%sArbitration Lost\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_TXUDR )  printf( "%sTx Buffer Underrun\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_TXERR )  printf( "%sTx Error\n", GetLogPrefix() );
  if( Error & HAL_CEC_ERROR_TXACKE ) printf( "%sTx Missing Acknowledge\n", GetLogPrefix() );
}

void TWally::PrintCecMessage( uint8_t const* const Data, uint32_t const Length )
{
  printf( "%s[%u:%u]", GetLogPrefix() , Data[ 0 ] >> 4, Data[ 0 ] & 0x0f );

  if( Length == 1 )
  {
    puts( " PING" );
    return;
  }

  for( const auto &Entry: CecOpcodeText )
  {
    if( Entry.Opcode == Data[ 1 ] )
    {
      printf( " %s {", Entry.Text );
      break;
    }
  }

  for( auto Index = 2u; Index < Length; Index++ )
  {
    printf( "%s%02x", Index > 2 ? " " : "", Data[ Index ] );
  }
  printf( "}\n" );
}
