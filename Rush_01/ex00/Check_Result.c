/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhache <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:30:10 by dhache            #+#    #+#             */
/*   Updated: 2022/06/19 19:03:48 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_up(int *max_l, int **sol, int index1, int index2);
void	ft_init_tables_index(int *nbr_v, int *max_l, int *index);
int		ft_check_duplicate(int **sol, int *part, int new_value, int index);
void	ft_free_tables(int *nbr_v, int *max_l);
void	ft_compute_row_col(int *part, int *row_col, int index);
int		ft_final_check(int **sol, int *nbr_v, int *part, int *row_col);
void	ft_row_col_finished(int **sol, int *part,
			int *row_col, int *row_col_finished);
int		ft_check_result(int **sol, int *part, int index, int new_value);

int	ft_check_result(int **sol, int *part, int index, int new_value)
{
	int	row_col[2];
	int	id_p;
	int	*nbr_v;
	int	*max_l;

	if (!ft_check_duplicate(sol, part, new_value, index))
		return (0);
	ft_compute_row_col(part, row_col, index);
	nbr_v = malloc(sizeof(int) * 4);
	max_l = malloc(sizeof(int) * 4);
	ft_init_tables_index(nbr_v, max_l, &id_p);
	while (++id_p < part[0])
	{
		if (max_l[0] < sol[id_p][row_col[1]])
			nbr_v[0] += ft_up(max_l, sol, id_p, row_col[1]);
		if (max_l[1] < sol[part[0] - 1 - id_p][row_col[1]])
			nbr_v[1] += ft_up(max_l + 1, sol, part[0] - 1 - id_p, row_col[1]);
		if (max_l[2] < sol[row_col[0]][id_p])
			nbr_v[2] += ft_up(max_l + 2, sol, row_col[0], id_p);
		if (max_l[3] < sol[row_col[0]][part[0] - 1 - id_p])
			nbr_v[3] += ft_up(max_l + 3, sol,
					row_col[0], part[0] - 1 - id_p);
	}
	ft_free_tables(nbr_v, max_l);
	return (ft_final_check(sol, nbr_v, part, row_col));
}

void	ft_row_col_finished(int **sol, int *part,
				int *row_col, int *row_col_finished)
{
	int	index;

	row_col_finished[0] = 0;
	row_col_finished[1] = 0;
	index = -1;
	while (++index < part[0])
	{
		if (sol[row_col[0]][index] != 0)
			++row_col_finished[0];
		if (sol[index][row_col[1]] != 0)
			++row_col_finished[1];
	}
	if (row_col_finished[1] != part[0])
		row_col_finished[1] = 0;
	if (row_col_finished[0] != part[0])
		row_col_finished[0] = 0;
}

int	ft_final_check(int **sol, int *nbr_v, int *part, int *row_col)
{
	int	row_col_fin[2];

	ft_row_col_finished(sol, part, row_col, row_col_fin);
	if (part[row_col[1] + 1] < nbr_v[0]
		|| (part[row_col[1] + 1 + part[0]] < nbr_v[1]
			&& row_col_fin[1])
		|| part[row_col[0] + 1 + part[0] * 2] < nbr_v[2]
		|| (part[row_col[0] + 1 + part[0] * 3] < nbr_v[3]
			&& row_col_fin[0]))
		return (0);
	if (row_col_fin[1] && (part[row_col[1] + 1] != nbr_v[0]
			|| part[row_col[1] + 1 + part[0]] != nbr_v[1]))
		return (0);
	if (row_col_fin[0] && (part[row_col[0] + 1 + part[0] * 2]
			!= nbr_v[2]
			|| part[row_col[0] + 1 + part[0] * 3] != nbr_v[3]))
		return (0);
	return (1);
}
