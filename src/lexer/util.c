

#include <stdio.h>
#include "lex.h"
#include "libft.h"

void	print_tokenstream(t_list *lst)
{
	int	i;
	char *	types[11] = { "LESS", "DLESS", "GREAT", "AND_IF", "AND_OR", "SEMIC", "OP", "WORD", "SQUOT", "DQUOT", "PIPE" };

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

void	print_tokenstream_short(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		if (lst->next)
			printf("%s, ", ((t_tok*)lst->data)->id);
		else
			printf("%s", ((t_tok*)lst->data)->id);
		lst = lst->next;
	}
	printf("\n");
}