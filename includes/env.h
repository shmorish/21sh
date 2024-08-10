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
	t_env	*next;
	t_env	*prev;
}	t_env;

void	env_init(char **envp);
t_env	*get_env_by_key(char *key);
void	free_all_env(void);
char    *get_env_value(char *key);

#endif
