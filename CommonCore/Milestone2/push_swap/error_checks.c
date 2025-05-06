/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 09:11:50 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check for null and only 1 arg, pdf specifies should print nothing
bool	start_arg_check(int argc, char *argv[])
{
	if (argc == 1)
	{
		return (false);
	}
	if ((argv[1][0] == '\0' && argc == 2))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	return (true);
}

// a is the stack where the parsing writes to
void	parsing_error_free(t_elem **a)
{
	if (a)
		free_list(a);
	write(2, "Error\n", 6);
	exit(1);
}

// fixed cleanup!! store next node, free current node, move to next node
// fixed for next the precedence of * and ()
// added check for empty list and empty pointer to list
void	free_list(t_elem **list)
{
	t_elem	*store_next_node;

	if (*list == NULL || list == NULL)
		return ;
	while (*list)
	{
		store_next_node = (*list)->next;
		free(*list);
		*list = store_next_node;
	}
}

// if split need to free because pointer stops being argv
void	free_usable_after_use(char **usable_argv, char **argv)
{
	int	i;

	if (usable_argv != argv)
	{
		i = 0;
		while (usable_argv[i])
			free(usable_argv[i++]);
		free(usable_argv);
	}
}
