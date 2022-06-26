/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:12:01 by fpetras           #+#    #+#             */
/*   Updated: 2017/05/13 10:13:16 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//int		main(int ac, char **av)
//{
//	int i;
//
//	i = -1;
//	if (ac > 1)
//		while (av[1][++i])
//			write(1, &av[1][i], 1);
//	write(1, "\n", 1);
//	return (0);
//}
//
//void ft_putstr(char *str)
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
//
//int ft_strlen(char *str)
//{
//	int i;
//
//	i = 0;
//	while(str[i] != '\0')
//		i++;
//	return (i);
//}
//
//int main(int argc, char **argv)
//{
//	int i;
//	int len;
//	char tmp;
//
//	i = 0;
//	if (argc == 2)
//	{
//		len = ft_strlen(argv[1]);
//		len--;
//		while (1 < len)
//		{
//			tmp = argv[1][i];
//			argv[1][i] = argv[1][len];
//			argv[1][len] = tmp;
//			i++;
//			len--;
//		}
//		ft_putstr(argv[1]);
//	}
//	write(1, "\n", 1);
//	return (0);
//}

//int main(int argc, char **argv)
//{
//	int i;
//
//	i = 0;
//	if(argc == 2)
//	{
//		while (argv[1][i])
//		{
//			if (argv[1][i] == 'a')
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

//
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
//
//int ft_strlen(char *str)
//{
//	int i;
//
//	i = 0;
//	while(str[i] != '\0')
//		i++;
//		return (i);
//}
//
//int main(int argc, char **argv)
//{
//	int i;
//	int len;
//	char	tmp;
//
//	i = 0;
//	if (argc == 2)
//	{
//		len = ft_strlen(argv[1]);
//		len--;
//		while (i < len)
//		{
//			tmp = argv[1][i];
//			argv[1][i] = argv[1][len];
//			argv[1][len] = tmp;
//			i++;
//			len--;
//		}
//		ft_putstr(argv[1]);
//	}
//	write(1, "\n", 1);
//	return (0);
//}

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] != '\0';
	return (s1);
}