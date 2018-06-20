/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:33:12 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:36:05 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

char	*hm_lookup(t_hashmap *hashmap, const char *key)
{
	int			bin;
	t_hm_entry	*pair;

	bin = hm_hash(hashmap, key);
	pair = hashmap->table[bin];
	while (pair != NULL && pair->key != NULL &&
			ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) > 0)
		pair = pair->next;
	if (pair == NULL || pair->key == NULL ||
			ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) != 0)
		return (NULL);
	return (pair->value);
}

void	relink_keychain(t_hm_entry *pair)
{
	if (pair->key->prev)
		pair->key->prev->next = pair->key->next;
	if (pair->key->next)
		pair->key->next->prev = pair->key->prev;
}

void	find_pair(t_hm_entry **prev, t_hm_entry **pair, const char *key)
{
	while (*pair != NULL && (*pair)->key != NULL &&
			ft_strncmp(key, (char*)((*pair)->key->data), ft_strlen(key)) > 0)
	{
		(*prev) = (*pair);
		(*pair) = (*pair)->next;
	}
}

int		check_head(int bin, t_hm_entry *pair, t_hashmap *hashmap,
			const char *key)
{
	if (pair != NULL && pair->key != NULL &&
			ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) == 0)
	{
		if (ft_strncmp(key, (*(hashmap->keychain))->data, ft_strlen(key)) == 0)
			*(hashmap->keychain) = (*(hashmap->keychain))->next;
		relink_keychain(pair);
		hashmap->table[bin] = pair->next;
		return (1);
	}
	return (0);
}

void	hm_delete(t_hashmap *hashmap, const char *key)
{
	int			bin;
	t_hm_entry	*prev;
	t_hm_entry	*pair;

	bin = hm_hash(hashmap, key);
	prev = NULL;
	pair = hashmap->table[bin];
	if (check_head(bin, pair, hashmap, key))
	{
		hm_free_entry(pair);
		return ;
	}
	find_pair(&prev, &pair, key);
	if (pair == NULL || pair->key == NULL ||
			ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) != 0)
		return ;
	prev->next = pair->next;
	if (ft_strncmp(key, (*(hashmap->keychain))->data, ft_strlen(key)) == 0)
		*(hashmap->keychain) = (*(hashmap->keychain))->next;
	relink_keychain(pair);
	hm_free_entry(pair);
}
