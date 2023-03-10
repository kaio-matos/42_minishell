/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:42:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/28 22:10:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_shell	*sh;

int	main(int argc, char **argv, char **envp)
{
	t_command	command;

	sh = bootstrap_sh(argc, argv, envp);
	while (1)
	{
		command = i__request_command();
		printf("%s\n", command.raw);
		printf("%s\n", c__get_str(command.flags->content));
	}
	return (0);
}
