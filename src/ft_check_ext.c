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

void	ft_quit_1(char *s)
{
	ft_printf("{+} Please provide a valid map!\n");
	free(s);
	exit(1);
}

void	ft_finish_check(const char *s, char *p, char *t, char *tmp)
{
	int	s_len;

	if (*p != '\0' || *t != '\0')
		ft_quit_1(tmp);
	s_len = ft_strlen(s);
	if (s_len == 4)
		ft_quit_1(tmp);
	p = ft_strchr(s, '.');
	if (s_len > 4)
	{
		p--;
		if (*p == '/')
			ft_quit_1(tmp);
	}
	free(tmp);
}

void	ft_check_ext(const char *s)
{
	char	*p;
	char	*t;
	char	*tmp;

	t = ft_strdup(".ber");
	tmp = t;
	p = ft_strchr(s, '.');
	if (!p)
		ft_quit_1(tmp);
	while (*p && *t)
	{
		if (*p != *t)
			ft_quit_1(tmp);
		t++;
		p++;
	}
	while (ft_isspace(*p))
		p++;
	ft_finish_check(s, p, t, tmp);
}
