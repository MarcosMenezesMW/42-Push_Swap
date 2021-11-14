/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:03:58 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/14 23:44:58 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_sort(t_pile *stack_a, t_pile *stack_b)
{
	if (stack_a->size < 1)
		write(STDERR_FILENO, ERR, 7);
	if (stack_a->size == 2)
		smallest_sort(stack_a, 'a');
	if (stack_a->size == 3)
		small_sort(stack_a, 'a');
	if (stack_a->size == 5 || stack_a->size == 4)
		medium_sort(stack_a, stack_b);
	if (stack_a->size > 5)
		big_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_pile	stack_a;
	t_pile	stack_b;

	if (argc == 1)
		exit(0);
	init_stack(&stack_a, &stack_b, argc, argv);
	fill_stack(&stack_a, &stack_b, argv, argc);
	if (stack_a.size == 0 || stack_a.size == 1)
		return (free(stack_a.number), free(stack_b.number), exit(0), 0);
	if (!is_sorted(&stack_a))
		check_sort(&stack_a, &stack_b);
	free(stack_a.number);
	free(stack_b.number);
	return (0);
}
