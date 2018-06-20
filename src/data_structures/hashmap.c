/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:15:06 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:37:45 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_hashmap		*hm_new_map(int size_table)
{
	t_hashmap	*hashmap;
	int			i;

	if (size_table < 1 || !(hashmap = malloc(sizeof(t_hashmap))))
		return (NULL);
	if (!(hashmap->table = malloc(sizeof(t_hm_entry*) * size_table)))
		return (NULL);
	i = 0;
	while (i < size_table)
	{
		hashmap->table[i] = NULL;
		i++;
	}
	hashmap->size_table = size_table;
	*(hashmap->keychain) = NULL;
	return (hashmap);
}

int				hm_hash(t_hashmap *hashmap, const char *key)
{
	unsigned long int	hashval;
	size_t				i;

	i = 0;
	hashval = 0;
	while (hashval < ULONG_MAX && i < ft_strlen(key))
	{
		hashval = hashval << 8;
		hashval += key[i];
		i++;
	}
	return (hashval % hashmap->size_table);
}

t_hm_entry		*hm_new_entry(const char *key, const char *value)
{
	t_hm_entry		*new;

	if (!(new = malloc(sizeof(t_hm_entry))))
		return (NULL);
	new->key = dll_new_node((void*)key, ft_strlen(key));
	if (!(new->value = ft_strdup(value)))
		return (NULL);
	new->next = NULL;
	return (new);
}
