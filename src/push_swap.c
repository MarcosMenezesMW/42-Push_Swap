/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:03:58 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/16 18:58:53 by mameneze         ###   ########.fr       */
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
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	t_pile	stack_a;
	t_pile	stack_b;

	if (argc < 2)
		write(STDERR_FILENO, ERRPARAM, 21);
	init_stack(&stack_a, &stack_b, argc);
	fill_stack(&stack_a, &stack_b, argv, argc);
	free(stack_a.number);
	free(stack_b.number);
	return (0);
}
