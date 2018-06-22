

/*
** MEMAGER (MEMory menAGER)
**
** memager is a memory management utility designed to
** keep track of a program's heap allocated memory.
** it stores the memory addresses of malloc'd memory
** in user defined categories.
** the idea is to choose categories such that all members can be 
** freed simultaneously.

** memory categories are chained together in a singly linked list with a pointer
** at the front and one at the end.
** each category itself is a singly linked list and a pointer to the category 
** a point to the head of the categories list is stored as a static variable 
** inside mgr_get_all();
** mgr_get_category() returns the requested category if it exists and creates it if it doesnt.
** mgr_del_category() iterates over list of memory references and frees the reference and the node
** itself.
** mgr_dell_all() deletes all categories
** mgr_check_category() returns true if a given category exists
** mgr_add_ref() adds a reference to a given category
** mgr_del_ref() deletes a reference 
**
*/


#ifndef MEMAGER_H
# define MEMAGER_H
# define CATEGORY_LABEL_MAXLEN 40
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

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
	struct s_mem_cat	*category;
	void				*ptr;
	size_t				size;
	struct s_mem_ref	*next;
}						t_mem_ref;


/*
** memory category functions
*/

t_mem_cat	**mgr_get_all(void); // returns head of list of categories
t_mem_cat	*mgr_get_category(const char *label);
void		mgr_del_category(t_mem_cat *category);
void		mgr_del_all(void); // uses mgr_get_all_categories to get head of category list, then frees it all
int			mgr_check_category(const char *label); // check if category exists
size_t		mgr_count_categories(t_mem_cat *categories);
void		mgr_print_categories(t_mem_cat *categories);


/*
** memory reference functions
*/

t_mem_ref	*mgr_add_ref(t_mem_cat *category, void *ptr, size_t size);
void		mgr_del_ref(t_mem_ref *ref);
void		mgr_print_category(t_mem_cat *category);


#endif