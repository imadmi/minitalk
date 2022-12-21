/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:30:04 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:48 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char  s[20] = "ABFDEF";
//     char c = 'D';
//     int  n = 6;
//     char    *ss;

//     ss = ft_memchr(s, c, n);
//     printf("%s\n", ss);
//     return (0);
// }