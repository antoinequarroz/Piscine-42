/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:05:40 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/19 17:05:44 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_keep_only(int ***table, int *index_table, int size)
{
	int	index_v;

	index_v = -1;
	while (++index_v < size)
	{
		if (index_v + 1 != size)
			table[index_table[3]][index_table[4]][index_v] = 0;
	}
}

void	ft_easy_line(int ***table, int *index_table, int *way, int size)
{
	int	index_l;
	int	index_v;

	index_l = -1;
	while (++index_l < size)
	{
		index_v = -1;
		while (++index_v < size)
		{
			if (index_v != index_l)
				table[index_table[3] + way[0] * index_l][index_table[4] + way[1]
					* index_l][index_v] = 0;
		}
	}
}

void	ft_reduce_line(int ***table, int *partition, int *index, int *way)
{
	index[1] = -1;
	while (++index[1] <= partition[index[0]] - 2)
	{
		index[2] = -1;
		while (++index[2] <= index[1])
		{
			table[index[0] + way[0] * (index[1] - index[2])]
			[index[0] + way[1]
				* (index[1] - index[2])][partition[0] - 1 - index[2]] = 0;
		}
	}
}
