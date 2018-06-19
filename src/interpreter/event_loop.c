
#include "lex.h"
#include "ast.h"

void	event_loop(void)
{
	char		*line;
	t_list		*tokens;
	t_ast_node	*ast;
	int			status;

	status = 1;
	while (status)
	{
		ast = make_node(NULL, AST_list);
		ft_printf("$> ");
		line = read_line();
		tokens = run_state_machine(line);
		process_tokens(&tokens);
		parse_list(&tokens, &ast);
		print_level_order(ast);
		free(line);
	}
}