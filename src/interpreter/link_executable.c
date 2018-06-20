

#include "hashmap.h"
#include "libft.h"
#include <dirent.h>

static
char    *get_path(t_hashmap *env)
{
    return (hm_lookup(env, "PATH"));
}


char    **split_path(t_hashmap *env)
{
    return (ft_strsplit(get_path(env), ':'));
}


static
int its_here(char *path, char *name)
{
    DIR             *dirp;
    struct dirent   *entry;

    if (!(dirp = opendir(path)))
        return (0);
    while ((entry = readdir(dirp)))
    {
        if (ft_strcmp(entry->d_name, name) == 0)
            return (1);
    }
    (void)closedir(dirp);
    return (0);
}

char    *is_path(char *name)
{
    return (ft_strchr(name, '/'));
}

char    *seek_executable(char **paths, char *name)
{
    int i;

    if (is_path(name))
        return (name);
    if (!name || !*paths)
        return (NULL);
    if (*name == '.')
        return (name);
    i = 0;
    while (paths[i])
    {
        if (its_here(paths[i], name))
            return (ft_strjoin(ft_strjoin(paths[i], "/"), name));
        i++;
    }
    return (NULL);

}