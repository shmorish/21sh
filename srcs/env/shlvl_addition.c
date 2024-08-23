/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_addition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mori <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by mori              #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by mori             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "shell.h"
#include <errno.h>

static void	print_high_shlvl_warning(int new_shlvl)
{
	shell_error();
	ft_dprintf(STDERR_FILENO, "warning: ");
	ft_dprintf(STDERR_FILENO, "shell level ");
	ft_dprintf(STDERR_FILENO, "(%d) too high, ", new_shlvl);
	ft_dprintf(STDERR_FILENO, "resetting to 1\n");
}


static int	get_new_shlvl(char *shlvl)
{
	int		shlvl_num;
	int		new_shlvl;
	char	*endptr;

	shlvl_num = ft_strtol(shlvl, &endptr, 10);
	if (shlvl_num < 0 || errno == ERANGE)
		return (1);
	while (*endptr != '\0')
	{
		if (!ft_isspace(*endptr))
			return (1);
		endptr++;
	}
	new_shlvl = shlvl_num + 1;
	if (shlvl_num > 999)
	{
		print_high_shlvl_warning(new_shlvl);
		return (1);
	}
	return (new_shlvl);
}

void	shlvl_addition(void)
{
	t_env	*shlvl;
	int		new_shlvl;

	shlvl = get_env_by_key("SHLVL");
	if (shlvl == NULL)
		return ;
	new_shlvl = get_new_shlvl(shlvl->value);
	free(shlvl->value);
	shlvl->value = ft_itoa(new_shlvl);
}
