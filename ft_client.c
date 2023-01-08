/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/07 13:38:42 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	signal_error(void)
{
	ft_printf("\n%sclient: unexpected error.%s\n", RED, RESET);
	exit(EXIT_FAILURE);
}

void	char_to_binary(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	sent_text(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_binary(str[i++], pid);
	char_to_binary('\0', pid);
}

void	recieved(int sig)
{
	static int	sent;

	if (sig == SIGUSR1)
	{
		ft_printf("%s%d signal sent successfully!%s\n", GREEN, ++sent, RESET);
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGUSR2)
		++sent;
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{
		ft_printf("%sclient pid: %d%s\n", RED, client_pid, RESET);
		signal(SIGUSR1, recieved);
		signal(SIGUSR2, recieved);
		server_pid = ft_atoi(av[1]);
		ft_printf("%sText currently sending.. %s\n", YELLOW, RESET);
		sent_text(av[2], server_pid);
	}
	else
		ft_printf("%susage: ./client <server_pid> <text to send>%s\n",
			RED, RESET);
	return (EXIT_FAILURE);
}
