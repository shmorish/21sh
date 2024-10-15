/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:15:51 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/22 13:54:28 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "ft_dlist.h"
# include <stdbool.h>

typedef enum e_token_type
{
	TK_WORD,
	TK_RSVD,
	TK_EOF,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	int				len;
	const char		*str;
}					t_token;

// lexer
t_dlist				*tokenize(const char *input);
void				lx_debug(t_dlist *lst);

// token
t_token				*lx_token_new(t_token_type type, const char *str,
						size_t len);
void				lx_token_free(void *token);
void				lx_token_print(void *token);

// token_list
void				set_token_list(t_dlist *token_list);
t_dlist				*get_token_list(void);
void				lx_token_list_free(void);

// utils
bool				lx_isspace(char c);
bool				lx_ismetachar(char c);
bool				lx_startswith(const char *s, char *prefix);

#endif
