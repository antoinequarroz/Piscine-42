/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert_String.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhache <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:35:36 by dhache            #+#    #+#             */
/*   Updated: 2022/06/19 02:21:57 by dhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_valid_str(char *str)
{
	int	index;
	int	nbr_values;
	int	was_space;

	was_space = 1;
	nbr_values = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == ' ' && !was_space)
			was_space = 1;
		else if (str[index] <= '9' && str[index] >= '0')
		{
			if (was_space)
				++nbr_values;
			was_space = 0;
		}
		else
			return (0);
	}
	if (was_space)
		return (0);
	else
		return (nbr_values);
}

int	ft_check_overflow(int *table, int nbr_values)
{
	int	index;

	index = 0;
	while (++index <= nbr_values)
	{
		if (table[index] > table[0] || table[index] == 0)
			return (0);
	}
	return (1);
}

int	*ft_init_to_zero(int *table, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		table[index] = 0;
	return (table);
}

//First index is for the table size

int	*ft_convert(char *str)
{
	int	nbr_values;
	int	index_str;
	int	index_result;
	int	*result;

	nbr_values = ft_check_valid_str(str);
	if (nbr_values <= 0 || nbr_values % 4 != 0)
		return (0);
	result = ft_init_to_zero(malloc(sizeof(*result)
				* (nbr_values + 1)), nbr_values + 1);
	result[0] = (nbr_values) / 4;
	index_str = -1;
	index_result = 1;
	while (str[++index_str])
	{
		if (str[index_str] <= '9' && str[index_str] >= '0')
			result[index_result] = (result[index_result]
					* 10) + str[index_str] - '0';
		else
			++index_result;
	}
	if (!ft_check_overflow(result, nbr_values))
		return (0);
	return (result);
}
//Create a 3D table with n^3 values

int	***ft_create_table(int n)
{
	int	i;
	int	j;
	int	k;
	int	***tbl;

	tbl = malloc(n * sizeof (int **));
	i = 0;
	while (i < n)
	{
		tbl[i] = malloc(n * sizeof (int *));
		j = 0;
		while (j < n)
		{
			k = 0;
			tbl[i][j] = malloc(n * sizeof(int));
			while (k < n)
			{
				tbl[i][j][k] = k + 1;
				k ++;
			}
			j ++;
		}
		i++;
	}
	return (tbl);
}
