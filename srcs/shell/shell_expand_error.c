/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_error.c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	shell_error_helper(int status, bool set)
{
	static int	shell_error = 0;

	if (set)
		shell_error = status;
	return (shell_error);
}

void	set_shell_error(int status)
{
	const int	new_status = status;

	shell_error_helper(new_status, true);
}

int	get_shell_error(void)
{
	return (shell_error_helper(0, false));
}
