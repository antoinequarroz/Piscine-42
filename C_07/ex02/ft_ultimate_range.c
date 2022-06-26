/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:57:57 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/25 15:57:58 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	max -= min;
	*range = malloc(max * sizeof(int));
	if (!*range)
		return (-1);
	i = -1;
	while (++i < max)
		(*range)[i] = min + i;
	return (max);
}

//#include <stdio.h>
//int		main(void)
//{
//	int	min;
//	int	max;
//	int	*tab;
//	int	size;
//	int	i = 0;
//
//	min = 5;
//	max = 10;
//	size = ft_ultimate_range(&tab, min, max);
//	while(i < size)
//	{
//		printf("%d, ", tab[i]);
//		i++;
//	}
//
//}