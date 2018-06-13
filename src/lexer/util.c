

#include <stdio.h>
#include "fsm.h"
#include "libft.h"

void	print_tokenstream(t_list *lst)
{
	int	i;
	char *	types[11] = { "LESS", "DLESS", "GREAT", "AND_IF", "AND_OR", "SEMIC", "OP", "WORD", "SQUOT", "DQUOT" };

	if (!lst)
		return ;
	i = 0;
	printf("#\tTYPE\tID\n");
	printf("------------------------\n");
	while (lst)
	{
		printf("%d\t%s\t%s\n", i, types[((t_tok*)lst->data)->type], ((t_tok*)lst->data)->id);
		lst = lst->next;
		i++;
	}
}