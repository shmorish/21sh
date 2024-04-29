#include <stdio.h>
#include <stdlib.h>
#include <readline.h>
#include <history.h>
#include <sys/syscall.h>
#include <unistd.h>

int main() {
	char *line;

	rl_instream = stdin;
	rl_outstream = stderr;
	pid_t pid = fork();
	if (pid == 0)
		exit(0);
	waitpid(pid, NULL, 0);
	printf("pid: %d\n", pid);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		add_history(line);
		free(line);
	}
	return 0;
}
