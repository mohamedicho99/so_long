#include "so_long.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

int ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

void	ft_pc(const char *s)
{
	char *p;
	char *t = ".ber";
	int s_len;
	p = ft_strchr(s, '.');
	if (!p)
	{
		ft_printf("{+} Please provide a valid map!\n");
		exit(1);
	}
	while (*p && *t)
	{
		if (*p != *t)
		{
			ft_printf("{+} Please provide a valid map!\n");
			exit(1);
		}
		t++;
		p++;
	}
	while (ft_isspace(*p))
		p++;
	if (*p != '\0' || *t != '\0')
	{
		ft_printf("{+} Please provide a valid map!\n");
		exit(1);
	}
	s_len = ft_strlen(s);
	if (s_len == 4)
	{
		ft_printf("{+} Please provide a valid map!\n");
		exit(1);
	}
	p = ft_strchr(s, '.');
	if (s_len > 4)
	{
		p--;
		if (*p == '/')
		{
			ft_printf("{+} Please provide a valid map!\n");
			exit(1);
		}
	}
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("{+} Please, provide the correct number of arguments!\n");
		exit(1);
	}
	char *s = argv[1];
	ft_pc(s);

	return (0);
}
