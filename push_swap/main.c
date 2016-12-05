#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "swap.h"

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

int			main(void)
{
	ft_printf("\033[22;34mHello, world!\033[0m");	
//	printf(ANSI_COLOR_BLUE     "This text is BLUE!"     ANSI_COLOR_RESET "\n");	
}
