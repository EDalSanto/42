#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "swap.h"

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

int			main(void)
{
	t_stack	stackA;
	t_stack	cpyA;

	stackA.nums = (int*)malloc(sizeof(int) * 4);
	stackA.nums[0] = 1;
	stackA.nums[1] = 2;
	stackA.nums[2] = 3;
	stackA.nums[3] = 4;
	cpyA = copy_stack(&stackA);	
	ft_printf("cpyA num 2 shoudl be 3: %d\n", stackA.nums[2]);
}
