#include "minitalk.h"

#define DELAY		250
#define INV_ARGS	"Error\nClient only accepts two ARGs\n"
#define NO_PID		"Error\nPID does not exist\n"
#define INV_PID		"Error\nInvalid PID\n"

static size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	n;

	i = 0;
	while (((str[i] >= 8 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '0')
		i++;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - 48;
	return (n);
}

int	main(int ac, const char **argv)
{
	pid_t	server_pid;
	char	i;
	int		j;

	if (ac < 3)
		return (write(2, INV_ARGS, str_len(INV_ARGS)) || 1);
	if (argv[1][0] == '-')
		return (write(2, INV_PID, str_len(INV_PID)) || 1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 1)
		return (write(2, INV_PID, str_len(INV_PID)) || 1);
	j = -1;
	while (argv[2][++j])
	{
		i = -1;
		while (++i < 8 && (usleep(DELAY) || 0x1))
			if (kill(server_pid, SIGUSR2 - ((argv[2][j] >> i) & 1)) == -1)
				return (write(2, NO_PID, str_len(NO_PID)) || 1);
	}
	return (0);
}
