/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i__request_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:32:46 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/28 21:54:30 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_command	i__request_command(void)
{
	char	*command_str;

	command_str = readline("$> ");
	return (i__parse_command(command_str));
}
