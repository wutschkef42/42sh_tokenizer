

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# include "doubly_linked_list.h"

typedef struct			s_hm_entry
{
	t_dll_node			*key;

	char				*value;
	struct s_hm_entry	*next;

}						t_hm_entry;

typedef struct			s_hashmap
{
	int					size_table;
	t_hm_entry			**table;
	t_dll_node			**keychain;
}						t_hashmap;

t_hashmap				*hm_new_map(int size);
int						hm_hash(t_hashmap *hashmap, const char *key);
t_hm_entry				*hm_new_entry(const char *key, const char *value);
void					hm_insert(t_hashmap *hashmap, const char *key,
						const char *value);
char					*hm_lookup(t_hashmap *hashmap, const char *key);
void					hm_delete(t_hashmap *hashmap, const char *key);
char					**hm_serialize(t_hashmap *hashmap);
void					hm_free_entry(t_hm_entry *entry);

#endif