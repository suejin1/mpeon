#pragma once

#include "header.h"

#define IPC_DATA_MAX_SIZE 10

typedef struct {
  long			mtype;          //64bit = 8Byte
  uint32_t      opcode; //unsigned long 32비트 4바이트
  uint32_t      LN;
  uint32_t      P;
  uint32_t      S;
  uint32_t      E;

  uint32_t      data_size; //unsigned long 32비트 4바이트
  uint8_t	    data[IPC_DATA_MAX_SIZE];  //unsigned char 8바이트 1비트
} stIpcMsg ;

typedef enum OP{  OPCODE_LED = 1, OPCODE_TEMP, OPCODE_GPS } op;
typedef enum LN{ LN_1 =1, LN_2, LN_3, LN_4, LN_5 } ln;
typedef enum P{  P_1=1, P_2, P_3 } p;
typedef enum Time{  S, E } t;

typedef struct {
  public:
  
  int a, b, c, t1, t2;
  int run=1;
  int i=0, q=0;
  int target = 0;

  key_t key;
  int msgid;
  int id2;

  time_t timer;
  struct tm* t;
} c_data;