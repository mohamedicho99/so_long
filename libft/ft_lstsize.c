/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:31 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/24 00:00:17 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int	ct;

	ct = 0;
	if (!lst)
		return (ct);
	while (lst)
	{
		ct++;
		lst = lst->next;
	}
	return (ct);
}
