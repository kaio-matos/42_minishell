/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:08:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/21 20:01:52 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linked_list.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = ft_salloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}
