#include <fcntl.h>
#include <unistd.h>

#ifdef __linux__
static pid_t	get_number_from_line(char *line)
{
	int	    i;
	pid_t	number;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	number = (pid_t)ft_atoi(&line[i]);
	return (number);
}

pid_t	ft_getpid(void)
{
	const int   fd = open("/proc/self/status", O_RDONLY);
	char    	*line;
	pid_t		pid;

	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line && ft_strncmp(line, "Pid:", 4))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		close(fd);
		return (-1);
	}
	pid = get_number_from_line(line);
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (pid);
}
#else

pid_t	ft_getpid(void)
{
	const pid_t	pid = fork();

	if (pid < 0)
		return (-1);
	if (pid == 0)
		exit(0);
	waitpid(pid, NULL, 0);
	return (pid - 1);
}
#endif
