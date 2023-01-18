/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/18 05:34:16 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		signal(SIGUSR1, wssl);
		pid = ft_atoi(av[1]);
		bit_sender(pid, av[2]);
	}
	else
	{
		ft_printf("try: ./client <server_pid> <text to send>\n");
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
		while (bit < 9)
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

void	wssl(int siguser)
{
	if (siguser == SIGUSR1)
		ft_printf("\033[0;32mmessage sent successfully\033[0m\n");
	exit (EXIT_SUCCESS);
}
