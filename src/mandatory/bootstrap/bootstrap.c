/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bootstrap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:44:10 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:53:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_shell	*bootstrap_sh(int argc, char **argv, char **envp)
{
	t_shell	*sh;

	sh = ft_salloc(sizeof(t_shell));
	sh->enviroment.argc = argc;
	sh->enviroment.argv = argv;
	sh->enviroment.envp = envp;
	sh->history = NULL;
	return (sh);
}
