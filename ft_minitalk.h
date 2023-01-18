/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:37 by imimouni          #+#    #+#             */
/*   Updated: 2023/01/18 04:07:03 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

void	wssl(int signum);
void	bit_sender(int pid, char *s);
void	action(int siguser, siginfo_t *info, void *context);

#endif