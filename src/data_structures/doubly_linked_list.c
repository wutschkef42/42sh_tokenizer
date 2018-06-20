/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:35:47 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:29:19 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "doubly_linked_list.h"
#include <stdio.h>

void		dll_insert_head(t_dll_node **head, t_dll_node *new)
{
	if (!head)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	(*head)->prev = new;
	new->next = *head;
	(*head) = new;
}

void		dll_insert_tail(t_dll_node **head, t_dll_node *new)
{
	t_dll_node	*last;

	if (!head)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

t_dll_node	*dll_new_node(void *data, size_t data_size)
{
	t_dll_node	*new;

	if (!(new = malloc(sizeof(t_dll_node))))
		return (NULL);
	if (!(new->data = malloc(sizeof(char) * data_size + 1)))
		return (NULL);
	ft_memcpy(new->data, data, data_size + 1);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		dll_delete_node(t_dll_node **head, void *key, size_t keysize,
				int (*cmp)(const void*, const void*, size_t))
{
	t_dll_node	*node;

	if (!head)
		return ;
	if (!*head)
		return ;
	node = *head;
	if (cmp(key, node->data, keysize) == 0)
		return (dll_delete_head(head));
	while (node)
	{
		if (cmp(key, node->data, keysize) == 0)
		{
			if (node->prev)
				node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			free(node->data);
			node->data = NULL;
			free(node);
			node->prev = NULL;
		}
		node = node->next;
	}
}

size_t		dll_size(t_dll_node *head)
{
	size_t	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
