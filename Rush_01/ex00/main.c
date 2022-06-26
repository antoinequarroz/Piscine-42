/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhache <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:33:27 by dhache            #+#    #+#             */
/*   Updated: 2022/06/19 16:31:03 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		***ft_filter_table(int ***table, int *partition, int size);
int		***ft_create_table(int n);
int		*ft_convert(char *str);
int		**ft_find_first(int ***table, int *partition, int **sol, int index);
int		**ft_create_empty_sol(int size);
void	ft_print_result(int **tbl, int size);

int	ft_print_error(void)
{
	write (1, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	int	**solution;
	int	*partition;
	int	***table;

	if (argc != 2)
		return (ft_print_error());
	partition = ft_convert(argv[1]);
	if (!partition)
		return (ft_print_error());
	table = ft_create_table(partition[0]);
	ft_filter_table(table, partition, partition[0]);
	solution = ft_create_empty_sol(partition[0]);
	solution = ft_find_first(table, partition, solution, 0);
	if (solution)
		ft_print_result(solution, partition[0]);
	else
		return (ft_print_error());
	return (0);
}
