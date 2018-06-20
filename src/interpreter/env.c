/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:00:52 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:20:28 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "hashmap.h"
#include "libft.h"
#include "misc.h"

static int	string2hashmap(t_hashmap *hashmap, const char *envi)
{
	char	*key;
	char	*value;

	key = ft_strndup(envi, ft_strchr(envi, '=') - envi);
	value = ft_strdup(ft_strchr(envi, '=') + 1);
	hm_insert(hashmap, key, value);
	free(key);
	free(value);
	return (0);
}

int			load_env(t_hashmap **hm_env, char **env)
{
	int			i;

	*hm_env = hm_new_map(HM_SIZE);
	i = 0;
	while (env[i])
	{
		string2hashmap(*hm_env, env[i]);
		i++;
	}
	return (0);
}
