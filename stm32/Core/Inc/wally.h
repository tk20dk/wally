#ifndef INC_WALLY_H_
#define INC_WALLY_H_

#include "main.h"

extern CEC_HandleTypeDef hcec;


class TWally
{
public:
  TWally();

  void Loop();
  void Setup();

  void HAL_CEC_ErrorCallback( uint32_t CecErrorCode );
  void HAL_CEC_TxCpltCallback();
  void HAL_CEC_RxCpltCallback( uint32_t RxFrameSize );
  void HAL_GPIO_EXTI_Callback();

private:
  void UsbPrintf( char const *const Format, ... );
  void PrintCecKvFrame( uint8_t const* const Msg, uint32_t const Length );
  void PrintCecMessage( uint8_t const* const Msg, uint32_t const Length );
  void PrintCecVendorMessage( uint8_t const* const Msg, uint32_t const Length );
  void PrintHex( uint8_t const* const Msg, uint32_t const Start, uint32_t const Length, char const* const Term = "" );
  void PrintAscii( uint8_t const* const Msg, uint32_t const Start, uint32_t const Length, char const* const Term = "" );
  void PrintKvEntries( uint8_t const* const Msg, uint32_t const Start, uint32_t const Length, char const* const Term = "" );

private:
  bool OldSCL;
  bool OldSDA;
  bool Flag5v;
  bool FlagHPD;
  bool FlagI2C;
  bool CecRxFlag;
  bool CecTxFlag;
  bool CecErrorFlag;
  int Len;
  char Buffer[ 128 ];
  uint32_t CntSCL;
  uint32_t CntSDA;
  uint32_t RxFrameSize;
  uint32_t CecErrorCode;
};

#endif // INC_WALLY_H_
