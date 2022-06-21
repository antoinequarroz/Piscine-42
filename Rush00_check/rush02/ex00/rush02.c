/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzito <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:42:37 by lzito             #+#    #+#             */
/*   Updated: 2022/06/11 17:44:11 by lzito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_new_line(int taille, char debut, char milieu, char fin)
{
	int	i;

	i = 1;
	while (i <= taille)
	{
		if (i == 1)
			ft_putchar(debut);
		else if (i == taille)
			ft_putchar(fin);
		else
			ft_putchar(milieu);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x >= 1 && y >= 1)
	{
		while (i <= y)
		{
			if (i == 1)
				ft_new_line(x, 'A', 'B', 'A');
			else if (i == y)
				ft_new_line(x, 'C', 'B', 'C');
			else
				ft_new_line(x, 'B', ' ', 'B');
			i++;
		}
	}
}
