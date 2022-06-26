/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:35:02 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/20 12:35:04 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb > 0)
	{
		result *= nb * ft_recursive_factorial(nb -1);
		nb -= 1;
	}
	if (nb < 0)
	{
		return (0);
	}
	return (result);
}

//int	main(void)
//{
//	printf("%i", ft_recursive_factorial(-3));
//}