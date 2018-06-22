

#include "libft.h"
#include "memager.h"
#include <stdio.h>


void		mgr_init(void)
{
	t_mem_cat	**categories;

	categories = mgr_get_all();
	*categories = NULL;
}


t_mem_cat	**mgr_get_all(void)
{
	static	t_mem_cat	*categories;

	return (&categories);
}


/*

t_mchain	*ft_mcget(const char *label)
{
	t_mchain	**mchain;

	mchain = ft_mcgetall();
	while (*mchain && ft_strcmp(label, (*mchain)->label))
		mchain = &(*mchain)->next;
	if (!*mchain)
	{
		if (!(*mchain = (t_mchain *)ft_memalloc(sizeof(t_mchain))))
			return (NULL);
		ft_stpncpy((*mchain)->label, label, MCHAIN_LABEL_MAXLEN);
	}
	return (*mchain);
}

*/

t_mem_cat	*mgr_get_category(const char *label)
{
	t_mem_cat	**categories;

	categories = mgr_get_all();
	while (*categories && ft_strcmp(label, (*categories)->label))
		categories = &(*categories)->next;
	if (!*categories)
	{
		if (!(*categories = (t_mem_cat*)malloc(sizeof(t_mem_cat))))
			return (NULL);
		(*categories)->start = NULL;
		(*categories)->end = NULL;
		(*categories)->ptr_count = 0;
		ft_strncpy((*categories)->label, label, CATEGORY_LABEL_MAXLEN);
	}
	return (*categories);
}


/*


int			ft_mcdel(t_mchain *mchain)
{
	t_mchain	**mchead;
	t_mchain	*next_chain;
	t_mlink		*next_link;
	int			count;

	if (!mchain)
		return (-1);
	count = 0;
	while (mchain->start)
	{
		next_link = mchain->start->next;
		free(mchain->start->ptr);
		free(mchain->start);
		mchain->start = next_link;
		count++;
	}
	mchead = ft_mcgetall();
	while (*mchead && *mchead != mchain)
		mchead = &(*mchead)->next;
	next_chain = mchain->next;
	free(mchain);
	*mchead = next_chain;
	return (count);
}

*/

void		mgr_del_category(t_mem_cat *category)
{
	t_mem_ref	*next_link;

	t_mem_cat	*next_cat;
	t_mem_cat	**head;

	if (!category)
		return ;
	while (category->start)
	{
		next_link = category->start->next;
		free(category->start->ptr);
		free(category->start);
		category->start = next_link;
	}
	head = mgr_get_all();
	while (*head && *head != category)
		head = &(*head)->next;
	next_cat = category->next;
	free(category);
	*head = next_cat;
}



/*
int			ft_mcdelall(void)
{
	t_mchain	**mchain;
	t_mchain	*next_chain;
	t_mlink		*next_link;
	int			count;

	mchain = ft_mcgetall();
	count = 0;
	while (*mchain)
	{
		while ((*mchain)->start)
		{
			next_link = (*mchain)->start->next;
			free((*mchain)->start->ptr);
			free((*mchain)->start);
			(*mchain)->start = next_link;
			count++;
		}
		next_chain = (*mchain)->next;
		free(*mchain);
		*mchain = next_chain;
	}
	return (count);
}
*/


void		mgr_del_all()
{
	t_mem_cat	**category;
	t_mem_cat	*next_cat;
	t_mem_ref	*next_link;

	category = mgr_get_all();
	while (*category)
	{
		while ((*category)->start)
		{
			next_link = (*category)->start->next;
			free((*category)->start->ptr);
			free((*category)->start);
			(*category)->start = next_link;
		}
		next_cat = (*category)->next;
		free(*category);
		*category = next_cat;
	}
}



int			mgr_check_category(const char *label)
{
	t_mem_cat	**categories;
	t_mem_cat	*tmp;

	categories = mgr_get_all();
	tmp = *categories;
	while (tmp)
	{
		if (ft_strcmp(tmp->label, label) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


size_t		mgr_count_categories(t_mem_cat *categories)
{
	size_t	count;

	if (!categories)
		return (0);
	count = 0;
	while (categories)
	{
		count++;
		categories = categories->next;
	}
	return (count);
}


void		mgr_print_categories(t_mem_cat *categories)
{
	if (!categories)
		return ;
	while (categories)
	{
		printf("category label: %s\n", categories->label);
		categories = categories->next;
	}
}


