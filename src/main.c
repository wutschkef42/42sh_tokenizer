

#include "lex.h"
#include "ast.h"
#include "eval.h"
#include "misc.h"
#include "hashmap.h"

int	main(int ac, char **av, char **env)
{
	t_hashmap	*hm_env;

	(void)ac;
	(void)av;
	load_env(&hm_env, env);
	event_loop(hm_env);

	return (1);
}