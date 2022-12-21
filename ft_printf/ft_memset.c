/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:43:47 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:49 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (b);
}
