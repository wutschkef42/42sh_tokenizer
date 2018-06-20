
#include "hashmap.h"
#include "libft.h"
#include "eval.h"


int launch_executable(char **args, t_hashmap *env)
{
    pid_t   pid;
    char    **env_serial;
    char    **paths;
    char    *link_executable;

    pid = fork();
    if (pid == 0)
    {
        env_serial = hm_serialize(env);
        if (!(paths = split_path(env)))
            ft_printf("path is empty\n");
        else if (!(link_executable = seek_executable(paths, args[0])))
            ft_printf("command not found\n");
        else if (execve(link_executable, args, env_serial) == -1)
            ft_printf("error loading executable\n");
        exit(0);
    }
    else if (pid < 0)
        perror("42sh");
    wait(&pid);
    return (1);
}