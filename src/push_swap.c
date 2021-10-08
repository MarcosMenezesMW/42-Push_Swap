/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:49:42 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/07 21:35:54 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	*init_stack(int argc, char *argv[])
{
	int		i;
	t_pile	*stack;
	t_pile	*node;

	i = 1;
	stack = malloc(sizeof(t_pile));
	stack->number = ft_atoi(argv[1]);
	stack->next = NULL;
	while (++i < argc)
	{
		node = create_node(ft_atoi(argv[i]));
		add_node_back(&stack, &node);
	}
	return (stack);
}

void	print_stack(t_pile *stack, char c)
{
	printf("\nStack_%c:\n", c);
	while (stack != NULL)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	t_pile	*stack_a;
	t_pile	*stack_b;

	stack_b = NULL;
	stack_a = init_stack(argc, argv);
	print_stack(stack_a, 'A');
	printf("\nSwap A\n");
	swap_a(&stack_a, &stack_a->next);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\nPush b 1:");
	push_b(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\nPush b 2:");
	push_b(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\nPush b 3:");
	push_b(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\nPush a 1:");
	push_b(&stack_b, &stack_a);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\nPush a 2:");
	push_b(&stack_b, &stack_a);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\nPush a 3:");
	push_b(&stack_b, &stack_a);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
}
