/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:04 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/28 18:46:19 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_pile *stack_a)
{
	swap(stack_a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	pa(t_pile *stack_a, t_pile *stack_b)
{
	push(stack_a, stack_b);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	ra(t_pile *stack_a)
{
	rotate(stack_a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rra(t_pile *stack_a)
{
	reverse_rotate(stack_a);
	write(STDOUT_FILENO, "rra\n", 4);
}