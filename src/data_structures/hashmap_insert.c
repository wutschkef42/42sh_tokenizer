/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:13:00 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 22:13:34 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void			find_position(t_hm_entry **last, t_hm_entry **next,
					const char *key)
{
	while (*next != NULL && (*next)->key != NULL &&
		ft_strcmp(key, (*next)->key->data) > 0)
	{
		*last = *next;
		*next = (*next)->next;
	}
}

int				hm_insert_overwrite(t_hm_entry **next,
					const char *key, const char *value)
{
	if ((*next) != NULL && (*next)->key != NULL &&
			ft_strcmp(key, (*next)->key->data) == 0)
	{
		free((*next)->value);
		(*next)->value = ft_strdup(value);
		return (1);
	}
	return (0);
}

void			hm_insert_new(t_hashmap *hashmap, t_hm_entry **new,
					t_hm_entry **last, t_hm_entry **next)
{
	int		bin;

	bin = hm_hash(hashmap, (char*)(*new)->key->data);
	if (*next == hashmap->table[bin])
	{
		(*new)->next = *next;
		hashmap->table[bin] = *new;
	}
	else if (!(*next))
	{
		(*last)->next = *new;
	}
	else
	{
		(*new)->next = *next;
		(*last)->next = *new;
	}
	(*new)->key->next = *(hashmap->keychain);
	if ((*(hashmap->keychain)))
		(*(hashmap->keychain))->prev = (*new)->key;
	(*(hashmap->keychain)) = (*new)->key;
}

void			hm_insert(t_hashmap *hashmap, const char *key,
					const char *value)
{
	int				bin;
	t_hm_entry		*new;
	t_hm_entry		*next;
	t_hm_entry		*last;

	bin = hm_hash(hashmap, key);
	next = hashmap->table[bin];
	last = NULL;
	new = NULL;
	find_position(&last, &next, key);
	if (hm_insert_overwrite(&next, key, value))
		return ;
	else
	{
		new = hm_new_entry(key, value);
		hm_insert_new(hashmap, &new, &last, &next);
	}
}
