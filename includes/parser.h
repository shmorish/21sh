/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:54:33 by kura              #+#    #+#             */
/*   Updated: 2024/10/15 21:00:27 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct simple_cmd_element {
  char *word;
  int number;
  struct redirection *redirection;
} t_simple_cmd_element;

typedef struct redirection {
  char *operator;  // ">", "<", ">>", "<<", etc.
  char *filename;
  int fd;
  struct redirection *next;
} t_redirection;

typedef struct simple_cmd {
  t_simple_cmd_element *elements;
  int element_count;
} t_simple_cmd;

typedef struct pipeline {
  t_simple_cmd *cmds;
  int cmd_count;
} t_pipeline;

typedef struct list {
  t_pipeline *pipelines;
  int pipeline_count;
  char *separator;  // "&&", "||", ";"
} t_list;

typedef struct subshell {
  t_list *compound_list;
} t_subshell;

typedef struct group_cmd {
  t_list *list;
} t_group_cmd;

typedef struct cmd {
  t_simple_cmd *simple_cmd;
  t_subshell *subshell;
  t_group_cmd *group_cmd;
  t_redirection *redirections;
} t_cmd;

typedef struct shell_cmd {
  t_cmd *cmd;
} t_shell_cmd;

t_cmd *parse_cmd(t_token *cmd);
t_simple_cmd *parse_simple_cmd(t_token *cmd);
t_redirection *parse_redirection(t_token *cmd);
t_pipeline *parse_pipeline(t_token *cmd);
t_list *parse_list(t_token *cmd);
t_subshell *parse_subshell(t_token *cmd);
t_group_cmd *parse_group_cmd(t_token *cmd);

bool consume_reserved(char *r);
bool consume_type(t_token_type t);
bool expect_reserved(char *r);
bool expect_type(t_token_type t);

#endif
