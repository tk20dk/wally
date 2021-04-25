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

  void HAL_CEC_ErrorCallback();
  void HAL_CEC_TxCpltCallback();
  void HAL_CEC_RxCpltCallback( uint32_t const RxFrameSize );

private:
  void UsbPrintf( char const *const Format, ... );
  void PrintCecMessage( uint8_t const* const Msg, uint32_t const Length );

private:
  bool CecRxFlag;
  bool CecTxFlag;
  bool CecErrorFlag;
  uint32_t RxFrameSize;
};

#endif // INC_WALLY_H_
