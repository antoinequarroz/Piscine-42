/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:31:25 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/23 14:31:27 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*t;
	int	i;

	if (min >= max)
		return (NULL);
	max -= min;
	t = malloc(max * sizeof(int));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < max)
		t[i] = min + i;
	return (t);
}

//#include <stdio.h>
//int		main(void)
//{
//	int	min;
//	int	max;
//	int	*tab;
//	int	i = 0;
//	int	size;
//
//	min = 5;
//	max = 10;
//	size = max - min;
//	tab = ft_range(min, max);
//	while(i < size)
//	{
//		printf("%d, ", tab[i]);
//		i++;
//	}
//
//}