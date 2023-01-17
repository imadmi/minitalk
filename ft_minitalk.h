/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:37 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/17 00:56:51 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

void	sig_error(void);
void	tkmila(char *c, int *received, int *client_pid, int *bit);
void	action(int sig, siginfo_t *info, void *context);
void	sig_error(void);
void	msg_to_binary(unsigned char c, int pid);
void	sent_text(char *msg, int pid);
void	wssel(int sig);

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

#endif