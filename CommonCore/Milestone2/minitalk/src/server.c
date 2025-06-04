/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:53 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/06/04 15:24:44 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>

static void	print_char(char c, int client_pid)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(client_pid, SIGUSR2);
	}
	else
	{
		write(1, &c, 1);
	}
}

/* bits: 1 0 1 0 1 0 0 1
1	00000001	Shift 0 left, add 1
2	00000010	Shift 1 left, add 0
3	00000101	Shift 2 left, add 1
4	00001010	Shift 5 left, add 0
5	00010101	Shift 10 left, add 1
6	00101010	Shift 21 left, add 0
7	01010100	Shift 42 left, add 0
8	10101001	Shift 84 left, add 1
*/
void	signal_to_char_handler(int sig, siginfo_t *info, void *context)
{
	static int	received_bit_count = 0;
	static char	bits_to_reconstruct_char = 0;

	(void)context;
	if (sig == SIGUSR1)
		bits_to_reconstruct_char = (bits_to_reconstruct_char << 1);
	else if (sig == SIGUSR2)
		bits_to_reconstruct_char = (bits_to_reconstruct_char << 1) | 1;
	else
		return ;
	received_bit_count++;
	if (received_bit_count == 8)
	{
		print_char(bits_to_reconstruct_char, info->si_pid);
		bits_to_reconstruct_char = 0;
		received_bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_config;
	pid_t				pid;

	pid = getpid();
	ft_printf("***************** Server PID *****************\n");
	ft_printf("*****************   %d   ******************\n", (int)pid);
	ft_printf("**********************************************\n");
	sa_config.sa_sigaction = signal_to_char_handler;
	sigemptyset(&sa_config.sa_mask);
	sa_config.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigaction(SIGUSR1, &sa_config, NULL);
	sigaction(SIGUSR2, &sa_config, NULL);
	while (1)
		pause();
	return (0);
}
