

#include "fsm.h"

int	main(int ac, char **av)
{
	t_list	*tokens;

	if (ac !=2)
	{
		printf("usage: ./alex [string to tokenize]\n");
		return (1);
	}
	
	tokens = run_state_machine(av[1]);
	printf("\n--- before processing\n\n");
	print_tokenstream(tokens);
	process_tokens(&tokens);
	printf("\n--- after processing\n\n");
	print_tokenstream(tokens);

	return (1);
}