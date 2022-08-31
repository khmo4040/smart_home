#ifndef CONFIG_H
#define	CONFIG_H

#define F_CPU 16000000UL

#define _PA   0
#define _PB   1
#define _PC   2
#define _PD   3

#define IN    0
#define OUT   1

#define ON    1
#define OFF   0






#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <string.h>
#include "IO.h"
#include "Timer.h"
#include "UART.h"
#include "applayer_Slave.h"


#endif	/* CONFIG_H */

