/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:08 by imimouni          #+#    #+#             */
/*   Updated: 2022/11/22 16:11:42 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	ft_putchar(nbr % 10 + '0', count);
}

void	ft_putbase(unsigned long nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_putbase(nbr / 16, base, count);
	ft_putchar(base[nbr % 16], count);
}

void	ft_putaddress(unsigned long address, int *count)
{
	ft_putstr("0x", count);
	ft_putbase(address, "0123456789abcdef", count);
}

static void	ft_converter(char CHAR, va_list ap, int *count)
{
	if (CHAR == 'c')
		ft_putchar((char)va_arg(ap, int), count);
	else if (CHAR == 'd' || CHAR == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (CHAR == 'u')
		ft_putnbr((unsigned int)va_arg(ap, int), count);
	else if (CHAR == 'p')
		ft_putaddress(va_arg(ap, long), count);
	else if (CHAR == 'x')
		ft_putbase((unsigned int)va_arg(ap, int), "0123456789abcdef", count);
	else if (CHAR == 'X')
		ft_putbase((unsigned int)va_arg(ap, int), "0123456789ABCDEF", count);
	else if (CHAR == 's')
		ft_putstr((char *)va_arg(ap, long), count);
	else
		ft_putchar(CHAR, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			if (*++format == '\0')
				break ;
			ft_converter(*format, ap, &count);
		}
		format++;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	char s[]=" Mimouni";
// 	void *ss = &s;
// 	int d = ft_printf("Imad%s\n%d\n%p\n%x\n",s,123,ss,0x123a);
// 	printf("Somme des characters est : %d\n",d);
// 	ft_printf("%%%");
// }