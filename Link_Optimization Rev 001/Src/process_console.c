/*
 * process_console.c
 *
 *  Created on: Feb 8, 2024
 *      Author: A
 */
#include "process_console.h"
#include "algorithm.h"

//uint8_t mode = 0;
int xCmd = 0;
int yCmd = 0;
uint32_t elapsed_time;
// Update timing measurements and servo positions

void process_console(void)
{
	char cmd;
	char ch;
	float value = 0;
	bool dp = false;
	signed int sign = 1;
	int num_places = 1;


	if(kbhit())
		{

			cmd = uart2_read();
			ch = uart2_read();	// dummy read of '='
			value = 0.;
			ch = uart2_read();
			while (ch != 13) {
				if(ch >= '0' && ch <= '9')
				{
					value = 10 * value + ch - '0';
					if(dp)
					{
						num_places = 10 * num_places;
					}
				}

				else if(ch == '.')
				{
					dp = true;
				}
				else if(ch == '-')
				{
					sign = -1;
				}

				ch = uart2_read();
			}

			value = (sign * value)/(num_places);


		    switch(cmd) {
				case 'm':
					mode = value;
					if(value == 1)
					{
						mode = m;
						printf("Manual Mode ON\n\r");
					}
					if(value == 0)
					{
						mode != m;
						printf("Manual Mode OFF\n\r");
					}
					break;
				case 'v':
					mode = value;
					if(value == 1)
					{
						mode = v;
						printf("Vector Mode ON\n\r");
					}
					if(value == 0)
					{
						mode != v;
						printf("Vector Mode OFF\n\r");
					}
					break;
				case 'p':
					mode = value;
					if(value == 1)
					{
						mode = p;
					printf("PID mode ON\n\r");
					}
					if(value == 0)
					{
						mode != p;
					printf("PID mode OFF\n\r");
					}
					break;
				case 'h':
					heartbeat = value;
					break;
				case 'P':
					KP = value;
					printf("KP: %f\n\r", KP);
					break;
				case 'I':
					KI = value;
					printf("KI: %f\n\r", KI);
					break;
				case 'D':
					KD = value;
					printf("KD: %f\n\r", KD);
					break;
				case 'X':
					deltX = value;
					printf("deltaX: %i\n\r", deltX);
					break;
				case 'Y':
					deltY = value;
					printf("deltaY: %i\n\r", deltY);
					break;
				case 't':
					DT = value;
					printf("DT: %f\n\r", DT);
					break;
				case 's':
					mode = value;
					if(value == 1)
					{
						mode = s;
						mode != p;
						printf("Scanning Mode ON\n\r");
						perform_scanningX();
						delay(20);
						perform_scanningY();
					}
					if(value == 0)
					{
						mode != s;
						mode = p;
						printf("Scanning Mode OFF\n\r");
					}
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

		    }

	}

}




