/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:17:46 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/28 18:46:14 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_pile *stack_b)
{
	swap(stack_b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	pb(t_pile *stack_a, t_pile *stack_b)
{
	push(stack_b, stack_a);
	write(STDOUT_FILENO, "pb\n", 3);
}

void	rb(t_pile *stack_b)
{
	rotate(stack_b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rrb(t_pile *stack_b)
{
	reverse_rotate(stack_b);
	write(STDOUT_FILENO, "rrb\n", 4);
}
