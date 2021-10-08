/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:46:19 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/07 21:06:02 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	*create_node(int value)
{
	t_pile	*new_node;

	new_node = malloc(sizeof(t_pile));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->number = value;
	return (new_node);
}

void	add_node_back(t_pile **root, t_pile **node)
{
	t_pile	*curr;

	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *node;
}

void	add_node_front(t_pile **root, t_pile **node)
{
	t_pile	*nxtnode;

	nxtnode = *node;
	nxtnode->next = *root;
	*root = nxtnode;
}
