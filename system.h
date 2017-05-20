#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <mcs51/8051.h>
#include <at89c51ed2.h>

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#include "stepper_xy.h"
#include "delays.h"
#include "lcd.h"

void system_init(void);

#endif // SYSTEM_H_INCLUDED
