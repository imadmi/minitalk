/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:24:24 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/20 00:49:07 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char *c)
{
	int	l;
	int	i;

	i = 0;
	l = ft_strlen(c);
	while (l)
	{
		if (c[i] >= '0' && c[i] <= '9')
			return (1);
		else
			return (0);
		l--;
		i++;
	}
	return (0);
}
