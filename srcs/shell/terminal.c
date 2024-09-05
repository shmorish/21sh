/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c　 　                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/01/01 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

void	save_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_iflag |= ICRNL;
	term.c_oflag |= ONLCR;
	term.c_cflag |= B19200;
	term.c_lflag |= (PENDIN | ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// term.c_iflag: 27394
// term.c_oflag: 3
// term.c_cflag: 19200
// term.c_lflag: 536872399
// term.c_ispeed: 38400
// term.c_ospeed: 38400
