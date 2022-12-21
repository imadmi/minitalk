/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:51:05 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:54 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_size;

	i = 0;
	if (dstsize == 0 && !dst)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	if (dstsize <= dst_size)
		return (dstsize + ft_strlen(src));
	while (src[i] && dst_size + i + 1 < dstsize)
	{
		dst[i + dst_size] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (ft_strlen(src) + dst_size);
}

// int main()
// {
// 	char s1[10] = "imad";
// 	char s2[10]= "zero";
// 	char s3[10] = "imad";
// 	char s4[10] = "zero";
// 	printf("%zu \n", strlcat(s1, NULL, 0));
// // 	printf("s2 =%s\n",s1);
// // 	printf("%zu \n", ft_strlcat(s3, s4, 1));
// // 	printf("%s",s3);
// // 	return 0;
// }