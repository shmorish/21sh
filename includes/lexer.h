/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:15:51 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/14 21:29:49 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "ft_dlist.h"
# include <stdbool.h>

typedef enum e_type
{
	EMPTY,
	STRING,
	PIPE,
	SEMICOLON,
	DOUBLE_SEMICOLON,
	PIPE_AND,
	AND,
	OR,
	TILDE,
	DOLLAR,
	EXPAND_STRING,
	LEFT_PAREN,
	RIGHT_PAREN,
	LEFT_PAREN_PAREN,
	RIGHT_PAREN_PAREN,
	PLUS,
	MINUS,
	MULTIPLY,
	SLASH,
	PERCENT,
	DOUBLE_STAR,
	LEFT_BRACE,
	RIGHT_BRACE,
	SHARP,
	DOUBLE_DOT,
	ASTERISK,
	QUESTION,
	DOUBLE_QUESTION,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	INPUT_REDIR,
	OUTPUT_REDIR,
	APPEND_REDIR,
	HEREDOC,
	NUMBER_REDIR_BEFORE,
	NUMBER_REDIR_AFTER,
	AMPERSAND,
	INPUT_AND,
	OUTPUT_AND,
	INPUT_OUTPUT,
	FILENAME,
	HEREDOC_WORD,
	HEREDOC_WORD_QUOTE,
	HISTORY,
	HISTORY_NUM,
}					t_type;

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
void				lx_token_print(void *token);

// utils
bool				lx_isspace(char c);
bool				lx_ismetachar(char c);
bool				lx_startswith(const char *s, char *prefix);

#endif
