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
# include "utils.h"

typedef struct s_env	t_env;

typedef struct s_env
{
	char	*name;
	char	*value;
	bool	hidden;
	int		num;
}	t_env;

t_dlist	*env_init(char **envp);

t_dlist	*get_envlist_with_key(t_dlist *head, char *key);
char	*get_env_value(t_dlist *head, char *key);

void	add_env_value(t_dlist **head, char *name, char *value, bool hidden);
void	delete_env_value(t_dlist **head, char *key);

void	print_env(t_dlist *head);
void	print_env_export(t_dlist *head);

t_env	*create_env(char *name, char *value, bool hidden);
void	free_all_env(t_dlist *head);

#endif
