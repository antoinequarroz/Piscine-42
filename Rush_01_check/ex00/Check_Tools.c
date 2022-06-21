/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:48:46 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/19 18:49:23 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_up(int *max_length, int **sol, int index1, int index2)
{
	*max_length = sol[index1][index2];
	return (1);
}

void	ft_init_tables_index(int *nbr_view, int *max_length, int *index)
{
	nbr_view[0] = 0;
	nbr_view[1] = 0;
	nbr_view[2] = 0;
	nbr_view[3] = 0;
	max_length[0] = 0;
	max_length[1] = 0;
	max_length[2] = 0;
	max_length[3] = 0;
	*index = -1;
}

int	ft_check_duplicate(int **sol, int *partition, int new_value, int index)
{
	int	index_duplicate;
	int	col;
	int	row;

	row = index / partition[0];
	col = index % partition[0];
	index_duplicate = -1;
	while (++index_duplicate < partition[0])
	{
		if (sol[index_duplicate][col] == new_value &&
				index_duplicate * partition[0] + col != index)
			return (0);
	}
	index_duplicate = -1;
	while (++index_duplicate < partition[0])
	{
		if (sol[row][index_duplicate] == new_value &&
				index_duplicate + row * partition[0] != index)
			return (0);
	}
	return (1);
}

void	ft_free_tables(int *nbr_view, int *max_length)
{
	free(max_length);
	free(nbr_view);
}

void	ft_compute_row_col(int *partition, int *row_col, int index)
{
	row_col[0] = index / partition[0];
	row_col[1] = index % partition[0];
}
