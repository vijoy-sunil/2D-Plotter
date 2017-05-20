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
#include "i2c.h"
#include "expander.h"
#include "text.h"
#include "custom_logo.h"
#include "menu.h"

#define INT0_EDGE 0x01
#define INT0_MASK 0x01
#define GLOBAL_INT 0x80

void system_init(void);

#endif // SYSTEM_H_INCLUDED
