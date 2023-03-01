/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i__parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:39:39 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/28 22:12:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_command	i__parse_command(char *command_str)
{
	t_command	command;

	command.executable = command_str;
	command.flags = ft_dlstnew(c__new_str(command_str));
	command.is_builtin = FALSE;
	command.raw = command_str;
	return (command);
}
