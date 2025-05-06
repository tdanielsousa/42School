/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 08:42:30 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_elem	*a;
	t_elem	*b;

	a = NULL;
	b = NULL;
	if (start_arg_check(argc, argv) == false)
		exit(1);
	if (parsing(&a, argc, argv) == false)
	{
		parsing_error_free(&a);
	}
	if (is_sorted(&a) == true)
	{
		free_list(&a);
		return (0);
	}
	stack_indexing(&a);
	choose_sorting(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
