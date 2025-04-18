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

void	ft_quit_1(char *s, t_map *map)
{
	ft_printf("{+} Please provide a valid map!\n");
	(void)s;
	free(map);
	exit(1);
}

void	ft_finish_check(t_norm *here)
{
	int	s_len;

	if (*here->p != '\0' || *here->t != '\0')
		ft_quit_1(here->tmp, here->map);
	s_len = ft_strlen(here->s);
	if (s_len == 4)
		ft_quit_1(here->tmp, here->map);
	here->p = ft_strchr(here->s, '.');
	if (s_len > 4)
	{
		(*(here->p))--;
		if (*here->p == '/')
			ft_quit_1(here->tmp, here->map);
	}
	free(here->tmp);
}

void	ft_check_ext(const char *s, t_map *map)
{
	char	*p;
	char	*t;
	char	*tmp;
	t_norm	here;

	t = ft_strdup(".ber");
	tmp = t;
	p = ft_strchr(s, '.');
	if (!p)
		ft_quit_1(tmp, map);
	while (*p && *t)
	{
		if (*p != *t)
			ft_quit_1(tmp, map);
		t++;
		p++;
	}
	while (ft_isspace(*p))
		p++;
	here.p = p;
	here.t = t;
	here.tmp = tmp;
	here.s = (char *)s;
	here.map = map;
	ft_finish_check(&here);
}
