

#include "fsm.h"

int	main(int ac, char **av)
{
	if (ac !=2)
	{
		printf("usage: ./alex [string to tokenize]\n");
		return (1);
	}
	
	run_state_machine(av[1]);
	return (1);
}