/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:36:07 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/10 10:36:08 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int ends_with(char *s, char *target)
{
	int target_len;
	int s_len;

	s_len = ft_strlen(s) - 1;
	target_len = ft_strlen(target) - 1;
	if (target_len <= 0 || s_len <= 0)
		return 0;
	while (target_len >= 0 && s_len >= 0 )
	{
		if (s[s_len] != target[target_len])
			return 0;
		s_len--;
		target_len--;
	}
	return 1;
}

void	ft_check_ext(const char *s, t_map *map)
{
	(void)map;
	if (!ends_with((char *)s, ".ber"))
	{
		ft_printf("{-} Invalid map file!\n");
		exit(1);
	}
}
