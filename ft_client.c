/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/17 02:04:34 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int ac, char **argv)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{
		ft_printf("%sclient pid: %d%s\n", RED, client_pid, RESET);
		signal(SIGUSR1, wssel);
		signal(SIGUSR2, wssel);
		server_pid = ft_atoi(argv[1]);
		ft_printf("%smessage currently sending.. %s\n", YELLOW, RESET);
		sent_text(argv[2], server_pid);
	}
	else
		ft_printf("%suse: ./client <server_pid> <text to send>%s\n",
			RED, RESET);
	return (EXIT_FAILURE);
}

void	wssel(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%smessage sent successfully%s\n", GREEN, RESET);
}

void	sent_text(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		msg_to_binary(msg[i], pid);
		i++;
	}
	msg_to_binary('\0', pid);
}

void	msg_to_binary(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				sig_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				sig_error();
		}
		c = c << 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	sig_error(void)
{
	ft_printf("\n%serror in the client.%s\n", RED, RESET);
	exit(EXIT_FAILURE);
}
