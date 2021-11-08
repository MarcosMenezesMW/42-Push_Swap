/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:03:58 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/08 00:42:08 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	print_stack(t_pile stack, char c)
{
	int	i;

	i = 0;
	write (STDOUT_FILENO, "Stack ", 7);
	write (STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
	while (i < stack.size)
	{
		ft_putnbr_fd(stack.number[i], STDOUT_FILENO);
		write(STDOUT_FILENO, " ", 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

static void	check_sort(t_pile *stack_a, t_pile *stack_b)
{
	if (stack_a->size < 1)
		write(STDERR_FILENO, ERR, 7);
	if (stack_a->size == 2)
		smallest_sort(stack_a, 'a');
	if (stack_a->size == 3)
		small_sort(stack_a, 'a');
	if (stack_a->size >= 5)
	{
		quick_sort(stack_a, stack_b);
		if (is_sorted(stack_b))
			swap_arg(stack_b, 'b');
		small_sort(stack_a, 'a');
		while (stack_b->size > 0)
			push_arg(stack_a, stack_b, 'b');
	}
}

int	main(int argc, char *argv[])
{
	t_pile	stack_a;
	t_pile	stack_b;

	init_stack(&stack_a, &stack_b, argc);
	fill_stack(&stack_a, &stack_b, argv, argc);
	if (stack_a.size == 0 || stack_a.size == 1)
		return (free(stack_a.number), free(stack_b.number), exit(0), 0);
	if (!is_sorted(&stack_a))
		check_sort(&stack_a, &stack_b);
	// print_stack(stack_a, 'A');
	// print_stack(stack_b, 'B');
	free(stack_a.number);
	free(stack_b.number);
	return (0);
}
