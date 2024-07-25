/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:10:48 by shmorish          #+#    #+#             */
/*   Updated: 2024/04/30 03:15:30 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

static pid_t	proccess_id_helper(pid_t pid, bool set)
{
	static pid_t	proccess_id = 0;

	if (set)
		proccess_id = pid;
	return (proccess_id);
}

void	set_proccess_id(pid_t pid)
{
	proccess_id_helper(pid, true);
}

pid_t	get_proccess_id(void)
{
	return (proccess_id_helper(0, false));
}
