/*
 * process_console.c
 *
 *  Created on: Feb 8, 2024
 *      Author: A
 */
#include "process_console.h"
#include "algorithm.h"

uint8_t manual_mode = 0;
int xCmd = 0;
int yCmd = 0;

void process_console(void)
{
	char cmd;
	char ch;
	uint16_t value;

	if(kbhit())
		{
			cmd = uart2_read();
			ch = uart2_read();	// dummy read of '='
			value = 0;
			ch = uart2_read();
			while (ch != 13) {
				value = 10 * value + ch - '0';
				ch = uart2_read();
			}

		    switch(cmd) {
				case 'm':
					manual_mode = value;
					break;
				case 'h':
					heartbeat = value;
					break;
				case 'p':
					KP = value;
					printf("KP: %i\n\r", KP);
					break;
				case 'i':
					KI = value;
					printf("KI: %i\n\r", KI);
					break;
				case 'd':
					KD = value;
					printf("KD: %i\n\r", KD);
					break;
				case 't':
					DT = value;
					break;
		        case 'x':	// command x=123<cr>
#if 0

#else
		        	xCmd = value;
#endif

		            break;
		        case 'y':
#if 0

#else
		        	yCmd = value;
#endif
		        case 'X':
		        	xPos = value;
		        	break;

		    }

	}

}
