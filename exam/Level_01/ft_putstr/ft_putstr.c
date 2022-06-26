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


//int main(int argc, char **argv)
//{
//	int i;
//
//	i = 0;
//	if (argc == 2)
//	{
//		while(argv[1][i] == 'a')
//		{
//			if (argv[1][i] != '\0')
//			{
//				write(1, "a\n", 2);
//				return (0);
//			}
//			i++;
//		}
//		write(1, "\n", 1);
//		return (0);
//	}
//	write(1, "a\n", 2);
//	return (0);
//}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	write(1, "z\n", 2);
//	return (0);
//}

//void	ft_putstr(char *str)
//{
//	int i;
//
//	i = 0;
//	while(str[i] != '\0')
//	{
//		write(1, &str[i], 1);
//		i++;
//	}
//}