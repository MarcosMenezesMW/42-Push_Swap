/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:01:16 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/28 18:22:27 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# define ERR "Error\n"

typedef struct s_pile{
	int	*number;
	int	size;
}				t_pile;

void	init_stack(t_pile *stack_a, t_pile *stack_b, int argc);
void	fill_stack(t_pile *stack_a, t_pile *stack_b, char **argv, int argc);
void	swap(t_pile *stack_a);
void	push(t_pile *stack_a, t_pile *stack_b);
void	rotate(t_pile *stack);
void	reverse_rotate(t_pile *stack);
int		is_sorted(t_pile *stack);
void	simple_sort(t_pile *stack_a, t_pile *stack_b);
void	small_sort(t_pile *stack_a);
void	sa(t_pile *stack_a);
void	pa(t_pile *stack_a, t_pile *stack_b);
void	ra(t_pile *stack_a);
void	rra(t_pile *stack_a);
void	sb(t_pile *stack_b);
void	pb(t_pile *stack_b, t_pile *stack_a);
void	rb(t_pile *stack_b);
void	rra(t_pile *stack_b);

#endif