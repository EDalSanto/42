#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int			empty_stack(int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (arr[i++])
			return (0);
	}
	return (1);
}

void		push_on_A(int *stackA, int *stackB, int size)
{
	int		temp;

	if (!empty_stack(stackB, size))
	{
		temp = stackB[0];
		memmove(&stackB[0], &stackB[1], sizeof(int) * (size - 1));
		memmove(&stackA[1], &stackA[0], sizeof(int) * (size - 1));
		stackA[0] = temp;
	}
}

void		rotate(int *stack, int size)
{
	int		temp;

	temp = stack[0];
	memmove(&stack[0], &stack[1], sizeof(int) * (size - 1));
	stack[size - 1] = temp;
}

void		reverse_rotate(int *stack, int size)
{
	int		temp;

	temp = stack[size - 1];
	memmove(&stack[1], &stack[0], sizeof(int) * (size - 1));
	stack[0] = temp;
}

void		display_stacks(int *stackA, int *stackB, int size)
{
	int		i;
	
	i = 0;
	while (i < size && !(empty_stack((stackA + i), (size - i))
				&& empty_stack((stackB + i), (size - i))))

	{
		if (!empty_stack((stackA + i), (size - i)))
			printf("%d ", stackA[i]);
		else
			printf("  ");
		if (!empty_stack((stackB + i), (size - i)))
			printf("%d\n", stackB[i]);	
		else
			printf("\n");
		i++;
	}
	printf("\n- -\na b\n---------\n");
}

int			main(void)
{
	int	*stackA;
	int	*stackB;

	stackA = (int*)malloc(sizeof(int) * 3);
	bzero(stackA, sizeof(int) * 3);
	stackA[0] = 3;
	stackA[1] = 2;
	if (stackA[2])
		printf("A[2]: %d\n", stackA[2]); 
	stackB = (int*)malloc(sizeof(int) * 3);
	bzero(stackB, sizeof(int) * 3);
	display_stacks(stackA, stackB, 3);
	rotate(stackB, 3);
	rotate(stackA, 3);
	display_stacks(stackA, stackB, 3);
//	reverse_rotate(stackB, 3);
//	reverse_rotate(stackA, 3);
//	display_stacks(stackA, stackB, 3);
//	stackB[0] = 42;
//	push_on_A(stackA, stackB, 3);
//	display_stacks(stackA, stackB, 3);
//
//	int i = 1;
//	while (i < ac)
//	{
//		printf("arg[%d]: %d\n", i, atoi(av[i])); 
//		i++;
//	}
}
