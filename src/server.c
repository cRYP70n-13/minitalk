#include "minitalk.h"

void	ft_putnbr(int num)
{
	char			c;
	unsigned int	x;

	x = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		x = -((unsigned int)num);
	}
	else
		x = num;
	if (x < 10)
		c = x + 48;
	else
	{
		ft_putnbr(x / 10);
		c = (x % 10) + 48;
	}
	write(1, &c, 1);
}

void	catch_signal(int sig)
{
	static char				c;
	static unsigned char	bit;

	c += (sig == SIGUSR1) << bit;
	bit++;
	if (bit > 7)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int		main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, catch_signal);
	signal(SIGUSR2, catch_signal);
	while (1)
		pause();
	return (0);
}
