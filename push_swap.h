/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:01:16 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/08 00:37:47 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# define ERR "Error\n"
# define MAX_INT 2147483647
# define MIN_INT -2147483647

typedef struct s_pile{
	int	*number;
	int	size;
}				t_pile;

void	init_stack(t_pile *stack_a, t_pile *stack_b, int argc);
void	fill_stack(t_pile *stack_a, t_pile *stack_b, char **argv, int argc);
int		check_lower_pos(t_pile *stack);
int		check_higher_pos(t_pile *stack);
int		check_below(t_pile *stack);
int		check_med(t_pile *stack);
void	swap(t_pile *stack);
int		push(t_pile *stack_a, t_pile *stack_b);
void	rotate(t_pile *stack);
void	reverse_rotate(t_pile *stack);
int		is_sorted(t_pile *stack);
void 	smallest_sort(t_pile *stack, char c);
void	small_sort(t_pile *stack, char c);
void	quick_sort(t_pile *stack_a, t_pile *stack_b);
void	swap_arg(t_pile *stack, char c);
void	push_arg(t_pile *stack_a, t_pile *stack_b, char c);
void	rotate_arg(t_pile *stack, char c);
void	rev_rotate_arg(t_pile *stack, char c);

#endif