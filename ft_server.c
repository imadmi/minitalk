/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:30 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/15 23:37:05 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	// act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (EXIT_FAILURE);
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	received;
	static int	current_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
		received = 0;
	}
	c = c | (sig == SIGUSR2);
	// ft_printf("%d\n",c);
	received++;
	// ft_printf("%d\n",received);
	bit++;
	ft_printf("%d\n",bit);
	if (bit == 8)
		tkmila(&c, &received, &client_pid, &bit);
	c <<= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
}

void	tkmila(char *c, int *received, int *client_pid, int *bit)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\n%s%d signal recieved from client PID: %d%s\n",
			GREEN, *received, *client_pid, RESET);
		*received = 0;
		*c = 0;
		if (kill(*client_pid, SIGUSR1) == -1)
			sig_error();
		return ;
	}
	*bit = 0;
}

void	sig_error(void)
{
	ft_printf("\n%sserver: unexpected error.%s\n", RED, RESET);
	exit(EXIT_FAILURE);
}
