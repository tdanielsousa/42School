/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:53 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/06/04 15:14:22 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdbool.h>

static volatile bool	g_current_bit_transmission_confirmed = false;

static void	confirm_bit_transmission(int sig)
{
	(void)sig;
	g_current_bit_transmission_confirmed = true;
}

static void	exit_client(int sig)
{
	(void)sig;
	exit(0);
}

static void	send_char_bits(int server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_current_bit_transmission_confirmed = false;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_current_bit_transmission_confirmed == false)
			pause();
		i--;
	}
}

static void	send_message_bit_by_bit(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char_bits(server_pid, str[i]);
		i++;
	}
	send_char_bits(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	struct sigaction	sigaction_setup;

	if (argc != 3)
	{
		ft_printf("Usage must be: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1)
	{
		ft_printf("Wrong server PID or server is not running.\n");
		return (1);
	}
	sigaction_setup.sa_handler = confirm_bit_transmission;
	sigemptyset(&sigaction_setup.sa_mask);
	sigaction_setup.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigaction_setup, NULL);
	sigaction_setup.sa_handler = exit_client;
	sigaction(SIGUSR2, &sigaction_setup, NULL);
	send_message_bit_by_bit(server_pid, argv[2]);
	return (0);
}
