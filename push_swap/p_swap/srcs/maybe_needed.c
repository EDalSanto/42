t_stack		copy_stack(t_stack *stack_to_copy)
{
	t_stack	new_stack;
	int		i;

	i = 0;
	new_stack.cur_size = stack_to_copy->cur_size;
	new_stack.max_size = stack_to_copy->max_size;
	new_stack.min_idx = stack_to_copy->min_num;
	new_stack.nums = (int*)malloc(sizeof(int) * new_stack.max_size);
	while (i < new_stack.cur_size)
	{
		new_stack.nums[i] = stack_to_copy->nums[i]; 
		i++;
	}
	return (new_stack);
}

void		sim_move_B(int indexA, t_stack *stackAcpy, t_stack *stackBcpy, t_flags *flags)
{
	int		num_to_move;
	int		midA;

	num_to_move = stackAcpy->nums[indexA];
	midA = stackAcpy->cur_size / 2;
	if (indexA != 0)
	{
		if (indexA > midA)
		{
			while (stackAcpy->nums[0] != num_to_move)
				perform_op("rra", stackAcpy, stackBcpy, flags);
		}
		else
		{
			while (stackAcpy->nums[0] != num_to_move)
				perform_op("ra", stackAcpy, stackBcpy, flags);
		}
	}
	perform_op("pb", stackAcpy, stackBcpy, flags);
}


