/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:15:52 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:10:00 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	words_lenght(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_free(int i, char **str)
{
	i--;
	while (--i >= 0)
		free(str[i--]);
	free (str);
	return (NULL);
}

static char	**ft_fill(char const *s, int countwords, char c, char **spl_words)
{
	int		i;
	int		j;
	int		lenght;

	i = 0;
	while (i < countwords)
	{
		while (*s == c)
			s++;
		lenght = words_lenght(s, c);
		spl_words[i] = (char *)malloc(sizeof(char) * (lenght + 1));
		if (spl_words == NULL)
			return (ft_free(i, spl_words));
		j = 0;
		while (j < lenght)
			spl_words[i][j++] = *s++;
		spl_words[i][j] = '\0';
		i++;
	}
	spl_words[i] = NULL;
	return (spl_words);
}

char	**ft_split(char	const *s, char c)
{
	char	**spl_words;
	int		countwords;

	if (!s)
		return (NULL);
	countwords = count_words(s, c);
	spl_words = (char **)malloc(sizeof(char *) * (countwords + 1));
	if (!spl_words)
		return (NULL);
	spl_words = ft_fill(s, countwords, c, spl_words);
	return (spl_words);
}

// int		main()
// {
// 	int i = -1;
// 	char **tab;	
// 	tab = ft_split("My mane is Imad",' ');
// 	while (++i < 4)
// 		printf("%d : %s\n", i, tab[i]);
// 	return (0);
// }