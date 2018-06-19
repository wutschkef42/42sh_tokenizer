

#ifndef EVAL_H
# define EVAL_H



AstType	get_ast_node_type(t_ast_node *node);
char	**get_leftmost_command(t_ast_node **root);
char	*get_cname(t_list *command);
char	**get_args(t_list *command);
void	print_args(char **args);

void	event_loop(void);

#endif