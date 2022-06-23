#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef struct s_env
{
	char			*name;
	char			*value;
	char			meaning;
	int				status;
	struct s_env	*next;
}					t_env;

typedef struct s_token
{
	char			type;
	char			*value;
	char			*quote;
	struct s_token	*next;
}					t_token;

typedef struct s_command
{
	int					id;
	char				**args;
	char				*path;
	int					path_error;
	char				*oper;
	char				*oper_value;
	char				delimitor;
	int					builtin;
	int					std_in;
	int					std_in_dup1;
	int					std_out;
	int					std_out_dup1;
	int					std_err;
	int					pipe;
	int					pipe_out;
	int					pipe_in;
	struct s_command	*next;
}						t_command;

int 	env_list(char **envp, t_env **env_lst);
t_env	*lst_new_elem(char *name, char *value);

#endif
