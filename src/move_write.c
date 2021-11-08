/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:04 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/07 21:37:14 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_arg(t_pile *stack, char c)
{
	swap(stack);
	write(STDOUT_FILENO, "s", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	push_arg(t_pile *stack_a, t_pile *stack_b, char c)
{
	if (push(stack_a, stack_b) != 0)
	{
		write(STDOUT_FILENO, "p", 1);
		write(STDOUT_FILENO, &c, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	rotate_arg(t_pile *stack, char c)
{
	rotate(stack);
	write(STDOUT_FILENO, "r", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	rev_rotate_arg(t_pile *stack, char c)
{
	reverse_rotate(stack);
	write(STDOUT_FILENO, "rr", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}
