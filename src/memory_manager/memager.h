

// GOAL: store all 42sh allocations in categories and free the categories on every REPL loop
// current issue is that eat_command makes a copy of some tokens, the tokens contain 


/*
** MEMAGER (MEMory menAGER)
**
** memager is a memory management utility designed to
** keep track of a program's heap allocated memory.
** it stores the memory addresses of malloc'd memory
** in user defined categories.
** the idea is to choose categories such that all members can be 
** freed simultaneously.
**
*/


#ifndef MEMAGER_H
# define MEMAGER_H
# define CATEGORY_LABEL_MAXLEN 40
# include <stdlib.h>


/*
** memory category node
** stores list of heap allocated pointers (inside s_mem_ref objects)
** that belong together when its time to free them
** 
*/

typedef struct			s_mem_cat
{
	char				label[CATEGORY_LABEL_MAXLEN];	// category label
	int					ptr_count;						// number of pointers in category
	struct s_mem_ref	*start;							// pointer to first element in category
	struct s_mem_ref	*end;							// pointer to last element in category
	struct s_mem_cat	*next;							// link to next category
}						t_mem_cat;


/*
** memory reference node
** represents a heap allocated pointer
*/

typedef struct			s_mem_ref
{
	struct s_mem_cat	*parent;
	void				*ptr;
	size_t				size;
	struct s_mem_ref	*next;
}						t_mem_ref;


/*
** memory category functions
*/

t_mem_cat	**mgr_get_all(void); // returns head of list of categories
t_mem_cat	*mgr_get_category(const char *label);
int			mgr_del_category(t_mem_cat *category);
int			mgr_del_all(void); // uses mgr_get_all_categories to get head of category list, then frees it all
int			mgr_check_category(const char *label); // check if category exists


/*
** memory reference functions
*/

t_mem_ref	*mgr_add_ref(t_mem_cat *category, void *ptr, size_t size);
void		mgr_del_ref(t_mem_ref *ref);




#endif