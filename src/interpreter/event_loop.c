
#include "lex.h"
#include "ast.h"
#include "eval.h"
#include "misc.h"
#include "hashmap.h"

void	event_loop(t_hashmap *env)
{
	char		*line;
	t_list		*tokens;
	t_list		*tokens_cpy;
	t_ast_node	*ast;
	int			status;
	//char		**cmd;

	status = 1;
	while (status)
	{
		(void)env;
		ast = make_node(NULL, AST_list);
		ft_printf("$> ");
		line = read_line();
		tokens = run_state_machine(line);
		tokens_cpy = tokens;
	//	process_tokens(tokens);
	//	parse_list(&tokens, &ast);
	//	print_level_order(ast);
		//cmd = get_leftmost_command(ast);
		//print_args(cmd);
		//launch_executable(cmd, env);
		free(line);
		free_list(tokens_cpy);
		printf("UHYA %u\n", ast->type);
		//free_ast(ast);
//		free_tab(cmd);
	}
}