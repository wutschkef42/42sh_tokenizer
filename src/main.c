

#include "lex.h"
#include "ast.h"
#include "eval.h"
#include "misc.h"
#include "hashmap.h"

int	main(int ac, char **av, char **env)
{
	t_list		*tokens;
	t_ast_node	*ast;
	char		**cmd;
	t_hashmap	*hm_env;

	load_env(&hm_env, env);
	(void)ac;
	(void)env;
	ast = make_node(NULL, AST_list);
	tokens = run_state_machine(av[1]);
	process_tokens(tokens);
	parse_list(&tokens, &ast);
	//print_level_order(ast);
	cmd = get_leftmost_command(ast);
	//print_args(cmd);
	launch_executable(cmd, hm_env);
	free_ast(ast);
	free_tab(cmd);

/*	t_hashmap	*hm_env;

	(void)ac;
	(void)av;
	load_env(&hm_env, env);
	event_loop(hm_env);
*/


	return (1);
}