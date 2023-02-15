#pragma once

#include <iostream>
#include <cstdlib>
#include <unistd.h>	// usleep
#include <fcntl.h>	// threads
#include <pthread.h>
// #include <string>	// messages
#include <queue>	// the message queue
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include "R_data.h"
#include "R.h"
#include "input.h"
#include "message.h"

#define _CRT_SECURE_NO_WARNINGS // 혹은 localtime_s를 사용


#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include "stdio.h"
