
#include "libft.h"
#include "ast.h"
#include "fsm.h"
#include "btree.h"

/* parses one ';' - delimited command per call
**
** inserts semicolons into ast
** loops until token stream is empty 
** exits with parse error if token stream is not empty
** or sub-routine returns parse error
*/

int	parse_list(t_list **tokens, t_ast_node **ast)
{
	printf("enter parse_list()\n");
	if (!parse_logic_op(tokens, ast))
		return (0);
	if (!(*tokens))
		return (1);
	while (match((t_tok*)(*tokens)->data, TYPE_semic))
	{	
		next_token(tokens); // accept semicolon
		add_right_child(ast, make_node(NULL, AST_list));
		if (!parse_list(tokens, &((*ast)->op.right)))
			return (0);
	}
	if (!((*tokens)->data))
		return (1);
	return (0);
}



/* parses one - || or && - delimited pipeline per call
**
** inserts logic operators
** loops until current token is not || or &&
** exits with parse error if sub-routine returns error
*/

int	parse_logic_op(t_list **tokens, t_ast_node **ast)
{
	printf("enter parse_logic_op()\n");
	add_left_child(ast, make_node(NULL, AST_logic_op));
	if (!parse_pipeline(tokens, &(*ast)->op.left))
		return (0);
	if (!(*tokens))
		return (1);
	while (match((t_tok*)(*tokens)->data, TYPE_and_if) || match((t_tok*)(*tokens)->data, TYPE_and_or)) // match and skip && or || token
	{
		(*ast)->type = match((t_tok*)(*tokens)->data, TYPE_and_if) ? AST_and_if : AST_and_or;
		next_token(tokens); // accept logical operator
		add_right_child(ast, make_node(NULL, AST_logic_op));
		
		if (!parse_logic_op(tokens, &(*ast)->op.right))
			return (0);
	}
	return (1);
}



/* parses one command consiting of consecutive
**
** WORD - (command name, arguments, flags, filenames)
** LESS - , DLESS - , GREAT - tokens per call
** inserts pipes into ast
** loops until current token is not |
*/

int	parse_pipeline(t_list **tokens, t_ast_node **ast)
{
	printf("enter parse_pipeline()\n");
	add_left_child(ast, make_node(NULL, AST_pipeline));
	if (!parse_command(tokens, &(*ast)->op.left))
		return (0);
	if (!(*tokens))
		return (1);
	while (match((t_tok*)(*tokens)->data, TYPE_pipe))
	{
		next_token(tokens); // skip pipe
		add_right_child(ast, make_node(NULL, AST_pipeline));
		if (!parse_pipeline(tokens, &(*ast)->op.right))
			return (0);
	}
	return (1);
}


int		is_command(t_list *token)
{
	if (token->data)
	{
		if (((t_tok*)token->data)->type == TYPE_word)
		{
			printf("SUCCESS\n");
			return (1);
		}
	}
	return (0);
}

t_list	*eat_command(t_list **tokens)
{
	t_list	*command;

	if (!(command = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(*tokens))
		return (NULL);
	while (*tokens)
	{
		printf("eat\n");
		if (is_command(*tokens))
		{
			ft_lstadd(&command, ft_lstnew((*tokens)->data, (*tokens)->data_size));
		}
		else
		{
			break ;
		}
		next_token(tokens);
	}
	return (command);
}

/* grabs a consecutive set of tokens of type
**
** WORD, LESS, DLESS and GREAT
** inserts the set of tokens into leave node of ast
** doesnt recognise faulty redirects like $ ls >
*/

int	parse_command(t_list **tokens, t_ast_node **ast)
{
	printf("enter parse_command()\n");
	t_list	*cmd_tokens;

	if (!(cmd_tokens = (t_list*)malloc(sizeof(t_list))))
		return (0);

	cmd_tokens = eat_command(tokens);

	
	add_left_child(ast, make_node(cmd_tokens, AST_command));
	// exit code, return of execve
	return (1);
}

