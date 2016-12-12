#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "swap.h"

#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"

int			main(void)
{
	ft_printf("mine: %sblue text, %smagenta text\n", BLUE, MAGENTA);
	printf("lib: %sblue text, %smagenta text\n", BLUE, MAGENTA);
}
