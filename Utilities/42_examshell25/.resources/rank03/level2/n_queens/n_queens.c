#include <unistd.h>
#include <stdlib.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	print_solution(int *pos, int n)
{
	int i = 0;

	while (i < n)
	{
		ft_putnbr(pos[i]);
		if (i < n - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *pos, int col, int row)
{
	int i = 0;

	while (i < col)
	{
		if (pos[i] == row)
			return (0);
		if (ft_abs(pos[i] - row) == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *pos, int n, int col)
{
	int row = 0;

	if (col == n)
	{
		print_solution(pos, n);
		return ;
	}
	while (row < n)
	{
		if (is_safe(pos, col, row))
		{
			pos[col] = row;
			solve(pos, n, col + 1);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int n;
	int *pos;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n <= 0)
		return (0);

	pos = malloc(sizeof(int) * n);
	if (!pos)
		return (1);

	solve(pos, n, 0);
	free(pos);
	return (0);
}
