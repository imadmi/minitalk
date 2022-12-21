/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:50:03 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:53 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	if (s && (*f))
	{
		while (s[++i])
			f(i, &s[i]);
	}
}

// void	ff(unsigned int index, char *s)
// {
// 	index = 32;
// 	s[0] = s[0] - index;
// }

// int main ()
// {
// 	char s[10]= "imad";
// 	ft_striteri(s,ff);
// 	printf("%s\n",s);
// }