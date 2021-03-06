#ifndef __AT_H
#define __AT_H

#include "c_types.h"

#define at_recvTaskPrio        1
#define at_recvTaskQueueLen    4

#define at_procTaskPrio        0
#define at_procTaskQueueLen    1

#define at_backOk      uart0_sendStr("\r\nOK\r\n")
#define at_backError   uart0_sendStr("\r\nERROR\r\n")

typedef enum{
  at_statIdle,
  at_statRecving,
  at_statProcess,
  at_statIpSending,
  at_statIpSended,
  at_statIpTraning
}at_stateType;

typedef enum{
  m_init,
  m_wact,
  m_gotip,
  m_linked,
  m_unlink,
  m_wdact
}at_mdStateType;

typedef struct
{
	char *at_cmdName;
	int8_t at_cmdLen;
  void (*at_testCmd)(uint8_t id);
  void (*at_queryCmd)(uint8_t id);
  void (*at_setupCmd)(uint8_t id, char *pPara);
  void (*at_exeCmd)(uint8_t id);
}at_funcationType;

void at_init(void);
void at_cmdProcess(uint8_t *pAtRcvData);

#endif
