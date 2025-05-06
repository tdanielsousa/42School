/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 09:13:11 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_elem
{
	int				num;
	int				index;
	struct s_elem	*next;
}	t_elem;

// choose_sort.c
void	choose_sorting(t_elem **a, t_elem **b);
void	sort_three_comparisons(t_elem **a, int first, int second, int third);
void	sort_three(t_elem **a);
void	sort_four(t_elem **a, t_elem **b);
void	sort_five(t_elem **a, t_elem **b);

//error_checks.c
bool	start_arg_check(int argc, char *argv[]);
void	parsing_error_free(t_elem **a);
void	free_list(t_elem **list);
void	free_usable_after_use(char **usable_argv, char **argv);

//ft_split.c
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		do_malloc(char **word_matrix, int position, int nr_bytes);
int		fill_rows(char **word_matrix, char const *s, char delimiter);
int		count_words(char const *s, char delimeter);
char	**ft_split(char const *s, char c);

//main.c
int		main(int argc, char *argv[]);

//parsing.c
bool	parsing(t_elem **a, int argc, char *argv[]);
bool	create_stack(t_elem **a, char **usable_argv, int i);
void	add_value_to_list_end(t_elem **a, int num);
bool	check_for_duplicate(t_elem **a);
void	stack_indexing(t_elem **a);

//push.c
void	pb(t_elem **b, t_elem **a);
void	pa(t_elem **a, t_elem **b);

//radix_sort.c
int		bits_required_for_max(t_elem *a);
void	radix_sort(t_elem **a, t_elem **b);

//rotate_swap.c
void	ra(t_elem **a);
void	rra(t_elem **a);
void	sa(t_elem **a);

//sort_utils.c
bool	is_sorted(t_elem **a);
int		list_size(t_elem *a);
int		find_min(t_elem *a);
void	move_to_top(t_elem **a, int min);
int		get_min_position(t_elem *a, int min);

//utils.c
long	ft_atol(const char *str);
bool	ft_isdigit(int n);
int		is_there_space(char *str);
bool	is_number(char *str);

#endif