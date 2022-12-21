/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:17:50 by imimouni          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:50 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		number %= 10;
	}
	ft_putchar_fd(number + '0', fd);
}
