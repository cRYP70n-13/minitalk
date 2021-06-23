#include "minitalk.h"

const int WAITNG_TIME = 180;

int		ft_atoi(const char *str)
{
	int i;
	int n;

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

int 	main(int argc, char const *argv[])
{
	int i;
	int j;
	int server_process_id;
	int ret;

	if (argc < 3)
		return (write(2, "Error\nClient needs two arguments\n", 34) || 1);
	if (argv[1][0] == '-')
		return (write(2, "Error\nPID does not exist\n", 26) || 1);
	server_process_id = ft_atoi(argv[1]);
	if (server_process_id < 1)
		return (write(2, "Error\nInvalid PID\n", 19) || 1);
	j = -1;
	while (argv[2][++j])
	{
		i = -1;
		while (++i < 8 && (usleep(WAITNG_TIME) || 1))
		{
			if ((argv[2][j] >> i) & 1)
				ret = kill(server_process_id, SIGUSR1);
			else
				ret = kill(server_process_id, SIGUSR2);
		}
		if (ret == -1)
			return (write(2, "There is no process id", 23));
	}
	return 0;
}
