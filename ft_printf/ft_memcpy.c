/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:54:37 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:49 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*destt;
	unsigned char		*str;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	destt = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (i < n)
	{
		destt[i] = str[i];
		i++;
	}
	return (dest);
}
