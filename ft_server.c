/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:30 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/20 04:58:51 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int ac, char **av)
{
	struct sigaction	act;

	(void)**av;
	if (ac == 1)
	{
		act.sa_sigaction = action;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		ft_printf("PID: %d\n", getpid());
		while (1)
			pause();
	}
	else
	{
		ft_printf("server: unexpected error.\n");
		exit(EXIT_FAILURE);
	}	
	return (0);
}

void	action(int siguser, siginfo_t *info, void *context)
{
	static int	sender_pid;
	static char	c;
	static int	bit;

	(void) context;
	if (sender_pid != info->si_pid)
	{
		c = (char)255;
		bit = 0;
		sender_pid = info->si_pid;
	}
	if (siguser == SIGUSR1)
		c = c | 128 >> bit;
	else if (siguser == SIGUSR2)
		c = c ^ 128 >> bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = (char)255;
	}
}
