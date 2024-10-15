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
# define PARSER_H

# include "lexer.h"

typedef enum {
    NODE_DIGIT,
    NODE_NUMBER,
    NODE_WORD,
    NODE_REDIRECTION,
    NODE_SIMPLE_COMMAND_ELEMENT,
    NODE_REDIRECTION_LIST,
    NODE_SIMPLE_COMMAND,
    NODE_SUBSHELL,
    NODE_GROUP_COMMAND,
    NODE_SHELL_COMMAND,
    NODE_COMMAND,
    NODE_COMPOUND_LIST,
    NODE_LIST,
    NODE_PIPELINE,
    NODE_SIMPLE_LIST
} NodeType;

typedef struct ASTNode {
    NodeType type;
} ASTNode;

typedef struct {
    ASTNode base;
	char *word;
} Word;

typedef struct {
    ASTNode base;
    char* direction;
    int number;
    Word* file;
} Redirection;

typedef struct {
    ASTNode base;
    union {
        Word* word;
        Redirection* redirection;
    } element;
} SimpleCommandElement;

typedef struct {
    ASTNode base;
    Redirection** redirections;
    int redirection_count;
} RedirectionList;

typedef struct {
    ASTNode base;
    SimpleCommandElement** elements;
    int element_count;
} SimpleCommand;

struct CompoundList;

typedef struct {
    ASTNode base;
    struct CompoundList* compound_list;
} SubShell;

struct List;

typedef struct {
    ASTNode base;
    struct List* list_node;
} GroupCommand;

typedef struct {
    ASTNode base;
    union {
        SubShell* subshell;
        GroupCommand* group_command;
    } command;
} ShellCommand;

typedef struct {
    ASTNode base;
    union {
		// char** にして execve にそのまま渡せるようにしたい
		// redirection は redirection_listとして別途管理する
        SimpleCommand* simple_command;
        ShellCommand* shell_command;
    } command;
    RedirectionList* redirection_list;
} Command;

typedef struct CompoundList {
    ASTNode base;
    struct List* list_node;
} CompoundList;

typedef struct List {
    ASTNode base;
    union {
        struct List* list;
        struct Pipeline* pipeline;
    } element;
    char* operator;
    struct List* next;
} List;

typedef struct Pipeline {
    ASTNode base;
    Command** commands;
    int command_count;
} Pipeline;

// 一番上位
typedef struct SimpleList {
    ASTNode base;
    union {
        struct SimpleList* simple_list;
        Pipeline* pipeline;
    } element;
    char* operator;
    struct SimpleList* next;
    int terminated;
} SimpleList;

bool				consume_reserved(char *r);
bool				consume_type(t_token_type t);

bool				expect_reserved(char *r);
bool				expect_type(t_token_type t);

#endif
