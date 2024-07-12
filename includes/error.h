/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:07 by kura              #+#    #+#             */
/*   Updated: 2024/07/13 03:00:19 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_MALLOC "Memory allocation failed"

void	fatal_error(char *fmt, ...);
void	syntax_error(char *fmt, ...);
void	*or_exit(void *ptr, char *fmt, ...);

#endif
