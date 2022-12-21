/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:11 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:56 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*result;

	if (!s || !f)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (s[++i])
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}

// char ft_f(unsigned int i, char str)
// {
// 	return (str - 32);
// }

// int main()
// {
// 	char str[10] = "imad";
// 	printf("%s\n", str);
// 	char *ss;
// 	ss = ft_strmapi(str, ft_f);
// 	printf("%s\n", ss);
// 	return 0;
// }