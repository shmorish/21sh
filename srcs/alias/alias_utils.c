#include "alias.h"

static t_alias *alias_list_helper(t_alias *alias, bool set)
{
    static t_alias *list = NULL;

    if (set)
        list = alias;
    return (list);
}

void set_alias_list(t_alias *alias)
{
    alias_list_helper(alias, true);
}

t_alias *get_alias_list(void)
{
    return (alias_list_helper(NULL, false));
}

int alias_malloc_exit(void)
{
    perror("minishell: malloc");
    exit(1);
}