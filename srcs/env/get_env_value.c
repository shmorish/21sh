/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "executor.h"

t_env *get_env_head(void);

char    *get_env_value(char *key)
{
    t_env	*env;

    env = get_env_by_key(key);
    if (env)
        return (env->value);
    return (NULL);
}

t_env	*get_env_by_key(char *key)
{
    t_env	*head;
    t_env	*current;

    head = get_env_head();
    if (head == NULL)
        return (NULL);
    current = head;
    while (1)
    {
        // printf("current n, v: %s, %s\n", current->name, current->value);
        // printf("key: %s, len: %ld\n", key, ft_strlen(key));
        if (ft_memcmp(current->name, key, ft_strlen(key) + 1) == 0)
        {
            // printf("key: %s, len: %ld\n", key, ft_strlen(key));
            // printf("current n, v: %s, %s\n", current->name, current->value);
            return (current);
        }
            
        current = current->next;
        if (current == head)
            break ;
    }
    return (NULL);
}
