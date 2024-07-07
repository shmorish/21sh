/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:10:48 by shmorish          #+#    #+#             */
/*   Updated: 2024/04/30 03:15:30 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "libft.h"

#ifdef __linux__

static pid_t	get_number_from_line(char *line)
{
	int		i;
	pid_t	number;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	number = (pid_t)ft_atoi(&line[i]);
	return (number);
}

pid_t	ft_getpid(void)
{
	const int	fd = open("/proc/self/status", O_RDONLY);
	char		*line;
	pid_t		pid;

	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	while (line && ft_strncmp(line, "Pid:", 4))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (close(fd), -1);
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
