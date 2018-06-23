

#ifndef EVAL_H
# define EVAL_H

#include "hashmap.h"
#include "ast.h"

AstType	get_ast_node_type(t_ast_node *node);
char	**get_leftmost_command(t_ast_node *root);
t_list	**get_leftmost_command_tokens(t_ast_node *ast);
char	**get_lcommand(t_ast_node *ast);
char	*get_cname(t_list *command);
char	**get_args(t_list *command);
void	print_args(char **args);

void	event_loop(t_hashmap *env);

int     launch_executable(char **args, t_hashmap *env);
char    *seek_executable(char **paths, char *name);
char    **split_path(t_hashmap *env);


int		load_env(t_hashmap **hm_env, char **env);


t_list  *get_redirect(t_list **cmd);
int     setup_redirects(t_list **cmd);

#endif