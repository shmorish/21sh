/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:15:51 by tkuramot          #+#    #+#             */
/*   Updated: 2024/04/30 03:17:07 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <stdbool.h>

// 入力文字をトークンに分割する（どんなトークンがあるかな？）
typedef enum e_token_type
{
	EMPTY,
	STRING,
	// |, ;, ;;, |&
	PIPE,
	SEMICOLON,
	DOUBLE_SEMICOLON,
	PIPE_AND,
	// &&, ||
	AND,
	OR,
	// ~
	TILDE,
	// $
	DOLLAR,
	EXPAND_STRING,
	// (, )
	LEFT_PAREN,
	RIGHT_PAREN,
	// ((, )), +, -, *, /, %, **
	LEFT_PAREN_PAREN,
	RIGHT_PAREN_PAREN,
	PLUS,
	MINUS,
	MULTIPLY,
	SLASH,
	PERCENT,
	DOUBLE_STAR,
	// {, }, #, %, ..
	LEFT_BRACE,
	RIGHT_BRACE,
	SHARP,
	PERCENT,
	DOUBLE_DOT,
	// *, ?, ??
	ASTERISK,
	QUESTION,
	DOUBLE_QUESTION,
	// [, ]
	LEFT_BRACKET,
	RIGHT_BRACKET,
	// redirection <, >, >>, <<
	INPUT_REDIR,
	OUTPUT_REDIR,
	APPEND_REDIR,
	HEREDOC,
	// number redirection
	NUMBER_REDIR_BEFORE,
	NUMBER_REDIR_AFTER,
	// &, <&, >&, <>
	AMPERSAND,
	INPUT_AND,
	OUTPUT_AND,
	INPUT_OUTPUT,
	// file name
	FILENAME,
	HEREDOC_WORD,
	HEREDOC_WORD_QUOTE,
	// !, !2
	HISTORY,
	HISTORY_NUM,
}	t_token_type;

#endif
