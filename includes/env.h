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

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_env	t_env;

typedef struct s_env
{
	char	*name;
	char	*value;
	bool	hidden;
	t_env	*next;
	t_env	*prev;
	int		num;
}	t_env;

t_env	*env_init(char **envp, const pid_t pid);

char	*get_env_value(t_env *head, char *key);
bool	get_env_hidden(t_env *head, char *key);
t_env	*get_env_by_key(t_env *head, char *key);

t_env	*add_env_value(t_env *head, t_env *new_env);
t_env	*delete_env_value(t_env *head, char *key);

void	print_env(t_env *head);
void	print_env_export(t_env *head);

t_env	*create_env(char *name, char *value, bool hidden);
void	free_all_env(t_env *head);

#endif
