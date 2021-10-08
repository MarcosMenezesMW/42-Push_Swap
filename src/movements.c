/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:24:48 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/07 21:22:35 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack_b(t_pile **head, t_pile **b)
{
	t_pile	*tmp;
	t_pile	*tmpb;

	tmpb = malloc(sizeof(t_pile));
	tmpb->next = NULL;
	*b = tmpb;
	tmp = *head;
	tmpb = *b;
	*head = tmp->next;
	tmp->next = tmpb->next;
	*b = tmp;
	free(tmpb);
}

void	swap_a(t_pile **n1, t_pile **n2)
{
	t_pile	*tmp;
	t_pile	*current;
	t_pile	*next;

	current = *n1;
	next = *n2;
	*n1 = next;
	*n2 = current;
	tmp = current->next;
	current->next = next->next;
	next->next = tmp;
}

void	push_b(t_pile **head, t_pile **b)
{
	t_pile	*tmp;
	t_pile	*tmpb;

	if (*head != NULL)
	{
		if (*b == NULL)
			create_stack_b(*(&head), *(&b));
		else
		{
			tmpb = *b;
			tmp = *head;
			*head = tmp->next;
			tmp->next = tmpb;
			*b = tmp;
		}
	}
}
