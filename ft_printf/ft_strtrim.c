/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:57:12 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:58 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*res;

	if (s1 && set)
	{
		while (*s1 && check_set(*s1, (char *)set))
			s1++;
		i = ft_strlen(s1);
		while (*s1 && check_set(*(s1 + i - 1), (char *)set))
			i--;
		res = (char *) malloc(sizeof(char) * (i + 1));
		if (res)
		{
			res[i] = '\0';
			while (--i >= 0)
				res[i] = s1[i];
			return (res);
		}
	}
	return (NULL);
}

// int main ()
// {
// 	char s[20] = "1323admin122133";
// 	char *ss;
// 	ss = ft_strtrim(s, "123");
// 	puts(ss);
// }
