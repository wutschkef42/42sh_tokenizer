

#include "lex.h"
#include "ast.h"
#include "eval.h"
#include "misc.h"
#include "hashmap.h"
#include "memager.h"


int	main(int ac, char **av, char **env)
{
	t_hashmap	*hm_env;

	(void)ac;
	(void)av;

	
	load_env(&hm_env, env);
	event_loop(hm_env);

	/*
	(void)ac;
	(void)av;
	(void)env;
	
	
	

	mgr_get_category("yolo");
	mgr_get_category("waifu");
	mgr_get_category("nugs");
	//mgr_get_category("cookies");

	char	*s1;
	char	*s2;

	s1 = malloc(1000);
	s2 = malloc(1000);

	ft_strcpy(s1, "hello world");
	ft_strcpy(s2, "what is up in here");

	mgr_add_ref(mgr_get_category("yolo"), (void*)s1, ft_strlen(s1));
	mgr_add_ref(mgr_get_category("yolo"), (void*)s2, ft_strlen(s2));
	mgr_print_categories(*categories);
	mgr_print_category(mgr_get_category("yolo"));
	printf("before %zu\n", mgr_count_categories(*categories));
	mgr_del_category(mgr_get_category("nugs"));
	
	if (mgr_check_category("nugs") == 0)
		printf("nugs are gone\n");
	if (mgr_check_category("waifu") == 1)
		printf("waifu is here\n");
	



	mgr_del_all();
	printf("after %zu\n", mgr_count_categories(*categories));
	
	*/











/*
	t_list		*tokens;
	t_ast_node	*ast;
	char		**cmd;
	t_hashmap	*hm_env;

	hm_env = malloc(sizeof(t_hashmap));
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
*/



	return (1);
}