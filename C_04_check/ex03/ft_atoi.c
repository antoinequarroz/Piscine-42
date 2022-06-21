/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:10:27 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/15 10:10:29 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	whitespace(char *str, int *ptr_i)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while ((str[1] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			counter *= -1;
		i++;
	}
	*ptr_i = i;
	return (counter);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = whitespace(str, &i);
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

//int	main(void)
//{
//	char	a[] = "---+--+1234ab567";
//	printf("%d", ft_atoi(a));
//}