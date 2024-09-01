/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:07 by mori              #+#    #+#             */
/*   Updated: 2024/07/13 03:00:19 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <unistd.h>
# include <stdbool.h>
// # include "libft.h"
# include "utils.h"

# define DEFAULT_PATH "/usr/local/bin:/bin:/usr/bin:."

typedef struct s_env	t_env;

typedef struct s_env
{
	char	*name;
	char	*value;
	bool	hidden;
	int		num;
	t_env	*next;
	t_env	*prev;
}	t_env;

// add_env_value.c
void	add_env_value(char *key, char *value, bool hidden);
void	add_init_shell_variable(void);

// delete_env_value.c
void	delete_env_value(char *key);

// env_init.c
void	node_add_back(t_env *new);
t_env	*node_init(bool hidden);
void	env_init(char **envp);

// env_utils.c
char	*split_env_to_key(char *envp);
char	*split_env_to_value(char *envp);
void	free_all_env(void);

// ft_getpid.c
pid_t	ft_getpid(void);

// get_env.c
char	*get_env_value(char *key);
t_env	*get_env_by_key(char *key);

// store_env_head.c
void	store_env_head(t_env *head);
t_env	*get_env_head(void);

// print_env.c
void	print_env(void);
void	print_env_export(void);

// shlvl_addition.c
void	shlvl_addition(void);

#endif
