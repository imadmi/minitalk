/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:00:54 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/19 05:29:16 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*str;
// 	int		size;
// 	int		i;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	size = ft_strlen(s1) + ft_strlen(s2);
// 	str = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!str)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i])
// 		str[i] = s1[i];
// 	i = -1;
// 	while (s2[++i])
// 		str[ft_strlen(s1) + i] = s2[i];
// 	str[size] = '\0';
// 	return (str);
// }
