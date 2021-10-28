/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:03:58 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/28 18:25:58 by mameneze         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_pile	stack_a;
	t_pile	stack_b;

	if (argc < 2)
	{
		write(STDERR_FILENO, ERR, 7);
		exit(0);
	}
	init_stack(&stack_a, &stack_b, argc);
	fill_stack(&stack_a, &stack_b, argv, argc);
	if (stack_a.size < 1)
		write(STDERR_FILENO, ERR, 7);
	if (stack_a.size == 3)
		small_sort(&stack_a);
	if (stack_a.size == 2)
		if (stack_a.number[0] > stack_a.number[1])
			sa(&stack_a);
	free(stack_a.number);
	free(stack_b.number);
	return (0);
}
