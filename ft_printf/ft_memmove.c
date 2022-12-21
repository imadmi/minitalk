/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:35:50 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:49 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	str_dest = (char *)dest;
	str_src = (char *)src;
	if (str_dest > str_src)
	{
		while (n--)
			str_dest[n] = str_src[n];
	}
	else if (str_dest < str_src)
		ft_memcpy(dest, src, n);
	return (dest);
}

// int main(void)
// {
// 	char str1[50];
// 	char str2[50] = "imad mim";
// 	ft_memmove(str1, str2, 11);
// 	printf("%s", str1);
// 	return (0);
// }