#include "../include/minishell.h"

static t_env	*env_content(char *before_eq, char *after_eq)
{
	char	*name;
	char	*value;
	t_env	*node;

	name = ft_strdup(before_eq);
	value = ft_strdup(after_eq);
	node = lst_new_elem(name, value);
	node->next = 0;
	return (node);
}

static int	for_exit_status(t_env *node, t_env **env_lst)
{
	char	*blank;

	blank = malloc(sizeof(char) * 2);
	if (blank == 0)
		return (0);
	blank[0] = '0';
	blank[1] = '\0';
	node = lst_new_elem(ft_strdup("?"), blank);
	node->meaning = '?';
	node->status = 0;
	ft_lstadd_front(env_lst, node);
	return (1);
}
int env_list(char **envp, t_env **env_lst)
{
    int		i;
	char	*eq;
	t_env	*node;

	i = 0;
	*env_lst = 0;
	while (envp[i] != 0)
		i++;
	i = 0;
	while (envp[i] != 0)
	{
		eq = ft_strchr(envp[i], '=');
		*eq = '\0';
		node = env_content(envp[i], eq + 1);
		ft_lstadd_back(env_lst, node);
		i++;
	}
	return (for_exit_status(node, env_lst));
}