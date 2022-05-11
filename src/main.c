/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:48:57 by tumolabs          #+#    #+#             */
/*   Updated: 2022/05/11 20:53:20 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envp)
{
	int i = 0;
	//char *line;

	//line = readline("line");
	(void)argc;
	(void)argv;
	//while (true)
	//	printf( "%s\n", readline("GXX: "));
	while(true)
		printf("%s\n", envp[i++]);
	return (0);
}
