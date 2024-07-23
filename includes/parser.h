/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:54:33 by kura              #+#    #+#             */
/*   Updated: 2024/07/26 01:49:20 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

typedef enum e_node_type
{
	ND_AND,
	ND_OR,
	ND_CMD,
	ND_PIPE,
	ND_SUBSHELL,
	ND_COMPOUND_CMD,
}					t_node_type;

typedef struct s_node
{
	t_node_type		type;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*next;
	char			*value;
}					t_node;

bool				consume_reserved(char *r);
bool				consume_type(t_token_type t);

bool				expect_reserved(char *r);
bool				expect_type(t_token_type t);

#endif
