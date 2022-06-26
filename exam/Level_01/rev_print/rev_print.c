#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int	i;
	int	len;
	char	tmp;

	i = 0;
	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		len--;
		while (i < len)
		{
			tmp = argv[1][i];
			argv[1][i] = argv[1][len];
			argv[1][len] = tmp;
			i++;
			len--;
		}
		ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
