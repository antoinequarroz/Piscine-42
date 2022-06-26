/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:20:40 by fpetras           #+#    #+#             */
/*   Updated: 2017/05/13 10:21:31 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//#include <unistd.h>
//
//int main(int argc, char **argv)
//{
//	int i;
//
//	i = 0;
//	if (argc == 2)
//	{
//		while (argv[1][i])
//		{
//			if(argv[1][i] == 'a')
//			{
//				write(1, "a\n", 2);
//				return (0);
//			}
//			i++;
//		}
//		write(1, "\n",1);
//		return (0);
//	}
//	write(1, "a\n", 2);
//	return (0);
//}