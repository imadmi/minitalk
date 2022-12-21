/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:24 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:48 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_stock(char *nbr, int n, int len)
{
	unsigned int	i;

	if (n < 0)
		i = n * (-1);
	else
		i = n;
	nbr[len] = '\0';
	while (i != 0 || len == 1)
	{
		len--;
		nbr[len] = (char)(i % 10 + 48);
		i = i / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nbr;

	if (n == 0)
		len = 1;
	if (n > 0)
		len = ft_nbrlen(n);
	if (n < 0)
		len = ft_nbrlen(n) + 1;
	nbr = (char *) malloc(sizeof(char) * len + 1);
	if (nbr)
	{
		ft_stock(nbr, n, len);
		if (n < 0)
			nbr[0] = '-';
		return (nbr);
	}
	return (NULL);
}

// int main()
// {
// 	puts(ft_itoa(0));
// }