/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/21 00:54:30 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		signal(SIGUSR1, wssl);
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
			usleep(700);
			bit++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
}

void	wssl(int siguser)
{
	if (siguser == SIGUSR1)
		ft_printf("\033[0;32mmessage sent successfully\033[0m\n");
	exit (EXIT_SUCCESS);
}
