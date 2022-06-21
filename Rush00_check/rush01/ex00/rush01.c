/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzito <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:51:19 by lzito             #+#    #+#             */
/*   Updated: 2022/06/11 16:58:12 by lzito            ###   ########.fr       */
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
				ft_new_line(x, '/', '*', '\\');
			else if (i == y)
				ft_new_line(x, '\\', '*', '/');
			else
				ft_new_line(x, '*', ' ', '*');
			i++;
		}
	}
}
