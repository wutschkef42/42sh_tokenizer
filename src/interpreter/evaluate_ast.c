
#include "lex.h"
#include "ast.h"
#include "libft.h"
#include "eval.h"

/*


COMMANDS

command is stored in list of tokens

example: ls ~/Documents/work > output.txt

[ WORD: ls ]  -->  [ WORD: ~/Documents/work ]  -->  [ LESS: > ]  -->  [ WORD: output.txt ]

the leftmost word is the command name
it must be searched for in path

all other words are arguments
redirects must be matched with the word that follows them (a filename)

the interpreter must construct an array of arguments from the word tokens
it must setup the redirect
it must fork a new process
then execve the command (passing path/to/command, argument array, environment array)


AST

Commands are stored in AST leave nodes. So interpreter must traverse tree
to get to the commands


*/



/*
** extract token type from list node container
*/

static
TokType	get_token_type(t_list *node)
{
	return (((t_tok*)(node->data))->type);
}


/*
** extract token value from list container
*/

static
char	*get_command_value(t_list *node)
{
	return (((t_tok*)(node->data))->id);
}

/*
** count number of TYPE_word tokens in command list
** all TYPE_word tokens are passed to execve 
** in argument tab
*/

static
int		count_args(t_list *command)
{
	int	n;

	if (!command)
		return (0);
	n = 0;
	while (command)
	{
		if (get_token_type(command) == TYPE_word)
			n++;
		command = command->next;
	}
	return (n);
}




void	print_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		printf("arg_%d : %s\n", i, args[i]);
		i++;
	}
}



AstType	get_ast_node_type(t_ast_node *node)
{
	return (node->type);
}


/*
** traverse AST and evaluate it
** for now, stupidly go left until it hits a command node
** then convert the command to argument tab
** then pass to execve() for execution
*/

char	**get_leftmost_command(t_ast_node **root)
{
	if (!root)
		return (NULL);
	while (get_ast_node_type(*root) != AST_command)
		*root = (*root)->op.left;
	return(get_args((*root)->cmd));
}





/*
** find the worst TYPE_word token in command list
** and return its value
** example: input = list_node([TYPE_word: cd]), output = "cd"
*/

char	*get_cname(t_list *command)
{
	if (!command)
		return (NULL);
	while (command)
	{
		if (get_token_type(command) == TYPE_word)
			return (get_command_value(command));
		command = command->next;
	}
	return (NULL);
}





/*
** count number of tokens in list


static
int		count_tokens(t_list *command)
{
	int	n;

	if (!command)
		return (0);
	n = 0;
	while (command)
	{
		n++;
		command = command->next;
	}
	return (n);
}

*/




/*
** consume token list making up a command 
** return argument array to be passed to execve
*/

char	**get_args(t_list *command)
{
	char	**args;
	int		i;
	int		command_count;
	t_list	*cp;

	cp = command;
	command_count = 0;
	if (!command)
		return (NULL);
	if (!(args = (char**)malloc(sizeof(*args) * count_args(command) + 1)))
		return (NULL);
	i = 0;
	while (i < count_args(command))
	{
		command_count = count_args(command);
		if (!(args[i] = ft_strnew(ft_strlen(get_command_value(command)))))
			return (NULL);
		i++;
	}
	i = 0;
	command = cp;
	while (command)
	{
		if (get_token_type(command) == TYPE_word)
			ft_strcpy(args[i], get_command_value(command));
		command = command->next;
		i++;
	}
	args[i] = 0;
	return (args);
}








