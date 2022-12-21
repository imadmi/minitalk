/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:54:27 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:51 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	while (len_s >= 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
		len_s--;
	}
	return (NULL);
}
