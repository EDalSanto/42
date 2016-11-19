/*
** If the cycle exists, the fast pointer will eventually fall behind the slow
** pointer and catch up to it, no matter the size of the list.
*/

int			ft_lst_has_cycle(t_list **head)
{
	t_list	*slow;
	t_list	*fast;
	
	slow = *head;
	fast = slow->next;
	if (!head || !*head)
		return (0);
	while (slow != fast)
	{
		if (!fast->next || !fast)		
			return (0);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (1);	
}
