/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/20 04:23:20 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_isdigit(av[1]) == 1)
			bit_sender(ft_atoi(av[1]), av[2]);
		exit (0);
	}
	else
	{
		ft_printf("\033[0;31mtry: ./client <server_pid> <text to send>\033[0m\n");
		exit(EXIT_FAILURE);
	}
}

void	bit_sender(int pid, char *s)
{
	int	i;
	int	bit;

	i = 0;
	while (1 && s)
	{
		bit = 0;
		while (bit < 8)
		{
			if (s[i] & (128 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			usleep(500);
			bit++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
}
