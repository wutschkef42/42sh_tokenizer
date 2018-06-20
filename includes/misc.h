

#ifndef MISC_H
# define MISC_H

#include "ast.h"

#define HM_SIZE 1024

void	free_tab(char **tab);
void	free_ast(t_ast_node *ast);
char	*ft_strndup(const char *s, size_t n);


#endif