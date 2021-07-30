#ifndef INC_WALLY_H_
#define INC_WALLY_H_

#include "main.h"
#include <array>


class TWally
{
public:
  TWally();

  void Loop();
  void Setup();

  void SysTick_Handler();
  void HAL_CEC_ErrorCallback();
  void HAL_CEC_RxCpltCallback( uint32_t RxFrameSize );
  void HAL_CEC_TxCpltCallback();

private:
  void PrintCecError( uint32_t Error );
  void PrintCecMessage( uint8_t const *Data, uint32_t Length );
  char const* GetLogPrefix();

  void tprintf( char const* Format, ...  );

public:
  bool Hdmi5V;
  bool HdmiHPD;
  bool FlagCecRx;
  bool FlagCecTx;
  bool FlagSysTick;
  bool FlagCecError;
  char LogPrefix[ 32 ];
  uint32_t LogTick;
  uint32_t LedCount;
  uint32_t CecRxFrameSize;
};

#endif // INC_WALLY_H_
