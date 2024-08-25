/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:10:48 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/15 20:59:03 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "executor.h"
#include "lexer.h"
#include "shell.h"
#include <errno.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	cleanup(char *line)
{
	lx_token_list_free();
	free(line);
}

void	test_function(char *line)
{
	if (ft_memcmp(line, "env", 4) == 0)
		print_env();
	if (ft_memcmp(line, "export", 7) == 0)
		print_env_export();
}

__attribute__((constructor)) static void	constructor(void)
{
	const pid_t	pid = ft_getpid();

	set_proccess_id(pid);
	rl_instream = stdin;
	rl_outstream = stderr;
	using_history();
	read_history(HISTORY_FILE);
	errno = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;

	(void)argc, (void)argv;
	env_init(envp);
	while (1)
	{
		line = prompt();
		test_function(line);
		set_token_list(tokenize(line));
		cleanup(line);
		lx_debug(get_token_list());
	}
	free_all_env();
	return (0);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <readline/readline.h>
// #include <readline/history.h>

// int main() {
//     // 履歴にエントリを追加
//     add_history("ls -l");
//     add_history("grep 'foo' bar.txt");

//     // 履歴をファイルに保存
//     if (write_history("history.txt") != 0) {
//         perror("Failed to write history to file");
//         return 1;
//     }

//     // 履歴をクリア
//     clear_history();

//     // ファイルから履歴を読み戻す
//     if (read_history("history.txt") != 0) {
//         perror("Failed to read history from file");
//         return 1;
//     }

//     // 履歴エントリを表示
//     HIST_ENTRY **list = history_list();
//     if (list != NULL) {
//         for (int i = 0; list[i] != NULL; i++) {
//             printf("Entry %d: %s\n", i, list[i]->line);
//         }
//     }

//     // メモリを解放
//     clear_history();

//     return 0;
// }
