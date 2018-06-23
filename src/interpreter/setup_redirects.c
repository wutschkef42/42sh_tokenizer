
#include "libft.h"
#include "lex.h"
#include <unistd.h>
#include <fcntl.h>


t_list  *get_redirect(t_list *cmd)
{
    while (cmd)
    {
        if (((t_tok*)(cmd->data))->type == TYPE_less ||
            ((t_tok*)(cmd->data))->type == TYPE_dless ||
            ((t_tok*)(cmd->data))->type == TYPE_great)
            return (cmd);
        cmd = cmd->next;
    }
    return (NULL);
}


// no need to free because pointers are tracked in memory manager
void    delete_token(t_list **cmd, t_list *token)
{
    t_list  *tmp;

    if (!*cmd)
        return ;
    while (*cmd && *cmd != token)
        cmd = &(*cmd)->next;
    tmp = token->next;
    *cmd = tmp;
}

int     setup_redirects(t_list **cmd)
{
    t_list  *filename;
    t_list  *redir;
    int     fd;
    int     stdout_ref;

    if (!cmd || !get_redirect(*cmd))
        return (0);
    while ((redir = get_redirect(*cmd)))
    {
        stdout_ref = dup(1);
        if (!(filename = redir->next))
            return (0);
        if (!(((t_tok*)(filename->data))->type == TYPE_word))
            return (0);
        if ((((t_tok*)redir->data))->type == TYPE_less)
        {
            fd = open(get_token_id(filename), O_RDONLY);
            dup2(fd, 0);
        }    
        else
        {
            fd = open(get_token_id(filename), O_WRONLY | O_CREAT, 777);
            dup2(fd, stdout_ref);
        }
        delete_token(cmd, redir);
        delete_token(cmd, filename);
        print_tokenstream(*cmd);
        close(fd);       
    }
    return (1);
}