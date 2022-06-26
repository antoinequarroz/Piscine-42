/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Find_First.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhache <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:31:30 by dhache            #+#    #+#             */
/*   Updated: 2022/06/19 16:40:01 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_check_result(int **sol, int *partition, int index, int new_value);

int	**ft_copy_sol(int **sol, int size)
{
	int	**new_sol;
	int	index1;
	int	index2;

	new_sol = malloc (sizeof (int *) * size);
	index1 = -1;
	while (++index1 < size)
	{
		new_sol[index1] = malloc(sizeof(int) * size);
	}
	index1 = -1;
	while (++index1 < size)
	{
		index2 = -1;
		while (++index2 < size)
			new_sol[index1][index2] = sol[index1][index2];
	}
	return (new_sol);
}

//Brute force the remaining
int	**ft_find_first(int ***table, int *partition, int **sol, int index)
{
	int	index_v;
	int	**new_sol;
	int	size;

	size = partition[0] * partition[0];
	if (index == size)
		return (sol);
	index_v = -1;
	while (++index_v < partition[0])
	{
		if (table[index / partition[0]][index % partition[0]][index_v] != 0)
		{
			new_sol = ft_copy_sol(sol, partition[0]);
			new_sol[index / partition[0]][index % partition[0]] = index_v + 1;
			if (ft_check_result(new_sol, partition, index, index_v + 1))
			{
				new_sol = ft_find_first(table, partition, new_sol, index + 1);
				if (new_sol)
					return (new_sol);
			}
		}
	}
	return (0);
}

int	**ft_create_empty_sol(int size)
{
	int	**sol;
	int	index1;
	int	index2;

	sol = malloc (sizeof (int *) * size);
	index1 = -1;
	while (++index1 < size)
	{
		sol[index1] = malloc(sizeof(int) * size);
	}
	index1 = -1;
	while (++index1 < size)
	{
		index2 = -1;
		while (++index2 < size)
			sol[index1][index2] = 0;
	}
	return (sol);
}

void	ft_print_result(int **tbl, int size)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			c = tbl[i][j] + '0';
			write (1, &c, 1);
		}
		write(1, "\n", 1);
	}	
}
