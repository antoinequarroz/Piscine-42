/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquarroz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:08:30 by aquarroz          #+#    #+#             */
/*   Updated: 2022/06/21 19:58:16 by aquarroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>
int		main(void)
{
	char	*str;

	str = ft_strdup("");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("hello 42");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("tz0OYvujCiYV9F2S2ID5TXSqcHIs94bF1BEwCtV");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("OD");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("wIVFMmhVyqbhOltpnmt8C4BiCdUhjCVbjrs");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("0iUkfwIPSy1lcC5HD7fWi8xCtulVEL2kxM2j");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("6nz2uiJTcuradRy8");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("3al5jRq0FzR8kaAxX0RKgmq7vHsn7U64rujhJN8OTvO7tQSni");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("KouCRN8e3ippGZ");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("halbC6J2UDWXt0ytUElO95o5ngE4AdNBNanQGffyh37k57B");
	printf("%s\n", str);
	free(str);
}