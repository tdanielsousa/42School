/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 09:11:20 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// set i to 1 because of argv0 in case of not split
bool	parsing(t_elem **a, int argc, char *argv[])
{
	char	**usable_argv;
	bool	sucess_status;
	int		i;

	usable_argv = argv;
	i = 1;
	if (argc == 2 && (is_there_space(argv[1]) == 0))
	{
		usable_argv = ft_split(argv[1], ' ');
		i = 0;
	}
	sucess_status = create_stack(a, usable_argv, i);
	free_usable_after_use(usable_argv, argv);
	return (sucess_status);
}

// put all nubrs into stack and check dupes
bool	create_stack(t_elem **a, char **usable_argv, int i)
{
	int	nr;

	nr = 0;
	while (usable_argv[i] != NULL)
	{
		if (is_number(usable_argv[i]) == false)
		{
			free_list(a);
			return (false);
		}
		nr = ft_atol(usable_argv[i]);
		add_value_to_list_end(a, nr);
		if (check_for_duplicate(a) == true)
		{
			free_list(a);
			return (false);
		}
		i++;
	}
	return (true);
}

// add the values to linked
//*a head of linked list, go to end then append new node
void	add_value_to_list_end(t_elem **a, int num)
{
	t_elem	*new_node;
	t_elem	*temp;

	new_node = malloc(sizeof(t_elem));
	if (new_node == NULL)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	temp = *a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

// use current to transverse the list and temp to compare with the rest of list
// check from 1 to last, 2 to last... to avoid redundancy
bool	check_for_duplicate(t_elem **a)
{
	t_elem	*current;
	t_elem	*temp;

	if ((*a) == NULL || (*a)->next == NULL)
		return (false);
	current = *a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->num == temp->num)
				return (true);
			temp = temp->next;
		}
		current = current->next;
	}
	return (false);
}

// count how many nodes have smaller values add it as the index
//*a is start of list
void	stack_indexing(t_elem **a)
{
	t_elem	*current;
	t_elem	*temp;
	int		i;

	current = *a;
	i = 0;
	while (current != NULL)
	{
		temp = *a;
		while (temp != NULL)
		{
			if (current->num > temp->num)
				i++;
			temp = temp->next;
		}
		current->index = i;
		i = 0;
		current = current->next;
	}
}
