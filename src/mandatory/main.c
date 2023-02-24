/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:42:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:47:14 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_shell	*sh;

int	main(int argc, char **argv, char **envp)
{
	sh = bootstrap_sh(argc, argv, envp);
	return (0);
}
