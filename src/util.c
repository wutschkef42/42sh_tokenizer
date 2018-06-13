

#include <stdio.h>
#include "fsm.h"
#include "libft.h"

void	print_list(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("token_type: %d, token_id: %s\n", ((t_tok*)lst->data)->type, ((t_tok*)lst->data)->id);
		lst = lst->next;
	}
}