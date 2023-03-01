/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c__str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:57:19 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/28 22:12:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**c__new_str(char *value)
{
	char	**heaped_value;

	heaped_value = ft_salloc(sizeof(char *));
	*heaped_value = value;
	return (heaped_value);
}

char	*c__get_str(void *content)
{
	if (content == NULL)
		ft_exterr("Trying to extract string from NULL\n");
	return (*(char **)content);
}
