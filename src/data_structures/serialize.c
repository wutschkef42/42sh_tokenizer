/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:08:05 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:08:36 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

char	**hm_serialize(t_hashmap *hashmap)
{
	t_dll_node	*keychain;
	char		**env;
	int			i;
	size_t		size_keychain;

	keychain = *(hashmap->keychain);
	size_keychain = dll_size(keychain);
	if (!(env = malloc(sizeof(char*) * size_keychain + 1)))
		return (NULL);
	i = 0;
	while (keychain)
	{
		env[i] = ft_strdup((char*)keychain->data);
		env[i] = ft_strjoin(env[i], "=");
		env[i] = ft_strjoin(env[i], hm_lookup(hashmap, (char*)keychain->data));
		keychain = keychain->next;
		i++;
	}
	env[(int)size_keychain] = NULL;
	return (env);
}
