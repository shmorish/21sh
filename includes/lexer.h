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
    // |, ;
	PIPE,
	SEMICOLON,
    // &&, ||
    AND,
    OR,
    // ~
    TILDE,
    // $
    DOLLAR,
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
    // {, }, #, %
    LEFT_BRACE,
    RIGHT_BRACE,
    SHARP,
    PERCENT,
    // *, ?, ??
    ASTERISK,
    QUESTION,
    DOUBLE_QUESTION,
    // [, ]
    LEFT_BRACKET,
    RIGHT_BRACKET,
    // number redirection
    NUMBER_REDIR_BEFORE,
    NUMBER_REDIR_AFTER,
    // redirection <, >, >>, <<
	INPUT_REDIR,
	OUTPUT_REDIR,
	APPEND_REDIR,
	HEREDOC,
    // &, <&, >&, <>
    AMPERSAND,
    INPUT_AND,
    OUTPUT_AND,
    INPUT_OUTPUT,
    // file name
    FILENAME,
    HEREDOC_WORD,
    HEREDOC_WORD_QUOTE,
}	t_token_type;

#endif