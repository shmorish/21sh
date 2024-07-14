/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:19:03 by kura              #+#    #+#             */
/*   Updated: 2024/07/15 00:35:21 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	exit_status_helper(int status, bool set)
{
	static int	exit_status = 0;

	if (set)
		exit_status = status;
	return (exit_status);
}

void	set_exit_status(int status)
{
	const int	new_status = status % 256;

	exit_status_helper(new_status, true);
}

int	get_exit_status(void)
{
	return (exit_status_helper(0, false));
}
