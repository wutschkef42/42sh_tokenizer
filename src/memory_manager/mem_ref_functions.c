
#include "ast.h"
#include "memager.h"

void		*mgr_alloc(t_mem_cat *category, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	mgr_add_ref(category, ptr, size);
	return (ptr);
}

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
	t_ast_node	*node;

	if (!category)
		return ;
	if (ft_strcmp(category->label, AST) == 0)
	{
		s = category->start;
		while (s)
		{
			node = (t_ast_node*)(s->ptr);
			printf("ast node: type %u\n", node->type);
			if (node->type == AST_command)
			{
					printf("\tcommand: ");
					print_tokenstream_short(node->cmd);
			}
			
			s = s->next;
		}
	}
	
}