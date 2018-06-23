
#include "lex.h"
#include "ast.h"
#include "eval.h"
#include "misc.h"
#include "hashmap.h"
#include "memager.h"

void	event_loop(t_hashmap *env)
{
	char		*line;
	t_list		*tokens;
	t_list		*tokens_cpy;
	t_ast_node	*ast;
	int			status;
	char		**cmd;
	t_list		**cmd_tokens;

	status = 1;
	while (status)
	{
		mgr_init(); // initialize memory manager (set head of categories list to NULL)
		(void)env;
		ast = make_node(NULL, AST_list);
		ft_printf("$> ");
		line = read_line();
		tokens = run_state_machine(line);
		tokens_cpy = tokens;
		process_tokens(tokens);
		parse_list(&tokens, &ast);
		cmd_tokens = get_leftmost_command_tokens(ast);
		//print_tokenstream(*cmd_tokens);
		setup_redirects(cmd_tokens);
		cmd = get_args(*cmd_tokens);
		//cmd = get_leftmost_command(ast);
		//print_args(cmd);
		launch_executable(cmd, env);
		//mgr_print_category(mgr_get_category(AST));
		mgr_del_category(mgr_get_category(AST));
		free(line);
		free_list(tokens_cpy);
		//free_ast(ast);
		free_tab(cmd);
	}
}