#include "../include/minishell.h"

int	check_and_init(int argc, char **envp, t_env **env_lst)
{
	if (argc > 1)
	{
		ft_putstr_fd("Argument error\n", 2);
		return (EXIT_FAILURE);
	}
	env_list(envp, env_lst);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
	t_env		*env_lst;
	t_token		*tokens;
	char		*line;
	int			status;

	(void)argv;
	if (check_and_init(argc, envp, &env_lst) == 1)
		return (0);
	while (true)
	{
		line = readline("GXX: ");
		if (!line)
		{
			ft_putstr_fd("exit", 1);
			return (EXIT_SUCCESS);
		}
		printf("%s\n", line);
		if (ft_strncmp(line, "", ft_strlen(line)) != 0)
			add_history(line);
	}
	
	return (0);
}
