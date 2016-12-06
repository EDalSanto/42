#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "swap.h"

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

int			find_right_location(int *nums, int num, int size)
{
	int		i;

	i = 0;
	if (num > nums[0])
		return (i);
	while ((i < (size) && !((num < nums[i]) && num >= nums[i + 1])))
		i++;
	return (i + 1);
}

int			main(void)
{
	int		nums[4] = {5, 2, 1};

	printf("location of 5 should be 4: %d\n", find_right_location(nums, 5, 3));	
}
