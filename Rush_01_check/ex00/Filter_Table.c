/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filter_Table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhache <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:28:59 by dhache            #+#    #+#             */
/*   Updated: 2022/06/19 17:07:12 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_keep_only(int ***table, int *index_table, int size);
void	ft_easy_line(int ***table, int *index_table, int *way, int size);
void	ft_reduce_line(int ***table, int *partition, int *index, int *way);

void	ft_compute_way(int *way, int index, int size)
{
	if (index < size)
	{
		way[0] = 1;
		way[1] = 0;
	}
	else if (index < size * 2)
	{
		way[0] = -1;
		way[1] = 0;
	}
	else if (index < size * 3)
	{
		way[0] = 0;
		way[1] = 1;
	}
	else if (index < size * 4)
	{
		way[0] = 0;
		way[1] = -1;
	}
}

void	ft_compute_index_table(int *index_table, int index, int size)
{
	if (index < size)
	{
		index_table[3] = 0;
		index_table[4] = index;
	}
	else if (index < size * 2)
	{
		index_table[3] = size - 1;
		index_table[4] = index - size;
	}
	else if (index < size * 3)
	{
		index_table[3] = index - size * 2;
		index_table[4] = 0;
	}
	else if (index < size * 4)
	{
		index_table[3] = index - size * 3;
		index_table[4] = size - 1;
	}
}

//Delete all useless possibilities
//Index 0-2 are indexs for loop and 3-4 for index_table
int	***ft_filter_table(int ***table, int *partition, int size)
{
	int	index[5];
	int	way[2];

	index[0] = 0;
	while (++index[0] <= size * 4)
	{
		ft_compute_index_table(index, index[0] - 1, size);
		ft_compute_way(way, index[0] - 1, size);
		if (partition[index[0]] == 1)
		{
			ft_keep_only(table, index, size);
		}
		if (partition[index[0]] == size)
		{
			ft_easy_line(table, index, way, size);
		}
	}
	return (table);
}
