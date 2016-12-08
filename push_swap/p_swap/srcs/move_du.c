int			move_down_counter(int indexA, t_stack *stackA,
							t_stack *stackB, t_flags *flags)
{
	t_stack	stackAcpy;
	t_stack	stackBcpy;
	int		ops;
	int		rrbs;
	int		swaps;	

	ops = 0; 
	swaps = 0;
	stackAcpy = copy_stack(stackA);
	stackBcpy = copy_stack(stackB);
	sim_move_B(indexA, &stackAcpy, &stackBcpy, flags);
	rrbs = find_right_location_desc(&stackBcpy, stackBcpy.nums[0]);
	//ft_printf("rrbs: %d, indexA: %d, num: %d\n", rrbs, indexA, stackBcpy.nums[0]);
	if (rrbs)
		swaps = rrbs - 1;	
	//stackAcpy = copy_stack(stackA);
	//stackBcpy = copy_stack(stackB);
	//sim_move_B(indexA, &stackAcpy, &stackBcpy, flags);
	while (swaps--)
	{	
		perform_op("sb", &stackAcpy, &stackBcpy, flags);	
		perform_op("rb", &stackAcpy, &stackBcpy, flags);	
		ops += 2;
	}
	while (!is_revsorted(stackBcpy.nums, stackBcpy.cur_size))
	{
		perform_op("rrb", &stackAcpy, &stackBcpy, flags);	
		ops++;
	}
	free(stackAcpy.nums);
	free(stackBcpy.nums);
	//ft_printf("ops leaving movedown coutner: %d\n", ops);
	return (ops);
}

int			move_up_counter(int indexA, t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	t_stack	stackAcpy;
	t_stack	stackBcpy;
	int		ops;
	int		rbs;
	int		swaps;	

	ops = 0;
	swaps = 0;
	rbs = (stackB->cur_size - (find_right_location_desc(stackB, stackA->nums[indexA]))) + 1;
	if (rbs)
		swaps = (rbs - 1);	
	stackAcpy = copy_stack(stackA);
	stackBcpy = copy_stack(stackB);
	sim_move_B(indexA, &stackAcpy, &stackBcpy, flags);
	while (swaps--)
	{
		perform_op("rrb", &stackAcpy, &stackBcpy, flags);	
		perform_op("sb", &stackAcpy, &stackBcpy, flags);	
		ops += 2;
	}
	while (rbs--)
	{
		perform_op("rb", &stackAcpy, &stackBcpy, flags);	
		ops++;
	}
	free(stackAcpy.nums);
	free(stackBcpy.nums);
	return (ops);
}

char		*move_down(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	int		top;
	int		rrbs;
	int		swaps;	

	top = stackB->nums[0];
	rrbs = find_right_location_desc(stackB, top);
	swaps = 0;
	if (rrbs)
		swaps = rrbs - 1;	
	while (swaps--)
	{	
		solution = update_solution(solution, "sb");
		perform_op("sb", stackA, stackB, flags);	
		solution = update_solution(solution, "rb");
		perform_op("rb", stackA, stackB, flags);	
	}
	while (!is_revsorted(stackB->nums, stackB->cur_size))
	//while (rrbs--)
	{
		solution = update_solution(solution, "rrb");
		perform_op("rrb", stackA, stackB, flags);	
	}
	return (solution);
}

char		*move_up(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	int		top;
	int		rbs;
	int		swaps;	

	top = stackB->nums[0];
	rbs = (stackB->cur_size - (find_right_location_desc(stackB, top))) + 1;
	swaps = (rbs - 1);	
	while (swaps--)
	{
		solution = update_solution(solution, "rrb");
		perform_op("rrb", stackA, stackB, flags);	
		solution = update_solution(solution, "sb");
		perform_op("sb", stackA, stackB, flags);	
	}
	while (rbs--)
	{
		solution = update_solution(solution, "rb");
		perform_op("rb", stackA, stackB, flags);	
	}
	return (solution);
}


