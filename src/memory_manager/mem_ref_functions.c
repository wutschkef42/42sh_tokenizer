

#include "memager.h"


t_mem_ref	*mgr_add_ref(t_mem_cat *category, void *ptr, size_t size)
{
	t_mem_ref	*ref;

	if (!(ref = (t_mem_ref*)malloc(sizeof(t_mem_ref))))
		return (NULL);
	ref->category = category;
	ref->ptr = ptr;
	ref->size = size;
	ref->next = category->start;
	category->start = ref;
	if (!category->end)
		category->end = ref;
	return (ref);
}


void		mgr_del_ref(t_mem_ref *ref)
{
	free(ref->ptr);
	free(ref);
}


void		mgr_print_category(t_mem_cat *category)
{
	t_mem_ref	*s;

	if (!category)
		return ;
	s = category->start;
	while (s)
	{
		printf("ref content: %s\n", (char*)(s->ptr));
		s = s->next;
	}
}