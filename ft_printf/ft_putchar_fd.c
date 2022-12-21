/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:00:27 by imimouni          #+#    #+#             */
/*   Updated: 2022/11/13 12:20:06 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include<fcntl.h>
// int main (void)
// {
//     int fd = open("imad.txt", O_CREAT | O_RDWR);             
//     write(fd, "hello world", 12);       
//     close(fd);
//     return 0;
// }