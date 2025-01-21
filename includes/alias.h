#ifndef ALIAS_H
# define ALIAS_H

#include "libft.h"
#include "executor.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct s_alias t_alias;

typedef struct s_alias
{
    char *name;
    char *value;
    t_alias *next;
    t_alias *prev;
} t_alias;

void set_alias_list(t_alias *alias);
t_alias *get_alias_list(void);
int alias_malloc_exit(void);
#endif