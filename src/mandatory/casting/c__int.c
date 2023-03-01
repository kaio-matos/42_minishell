/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c__int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:57:19 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/28 22:06:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	*c__new_int(int value)
{
	int	*heaped_value;

	heaped_value = ft_salloc(sizeof(int));
	*heaped_value = value;
	return (heaped_value);
}

int	c__get_int(void *content)
{
	if (content == NULL)
		ft_exterr("Trying to extract integer from NULL\n");
	return (*(int *)content);
}
