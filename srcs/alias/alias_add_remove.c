#include "alias.h"

t_alias *alias_new(char *name, char *val)
{
    t_alias *alias;

    alias = ft_calloc(sizeof(t_alias), 1);
    if (!alias)
        alias_malloc_exit();
    alias->name = ft_strdup(name);
    if (!alias->name)
    {
        free(alias);
        alias_malloc_exit();
    }
    alias->value = ft_strdup(val);
    if (!alias->value)
    {
        free(alias->name);
        free(alias);
        alias_malloc_exit();
    }
    alias->next = NULL;
    alias->prev = NULL;
    return (alias);
}

void alias_create(char *name, char *value)
{
    t_alias *alias;

    alias = alias_new(name, value);
    alias_add(alias);
}

void alias_add(t_alias *alias)
{
    t_alias *list;

    list = get_alias_list();
    if (!list)
    {
        set_alias_list(alias);
        return ;
    }
    while (list->next)
        list = list->next;
    list->next = alias;
    alias->prev = list;
}

// unalias - remove alias
bool alias_remove(char *key)
{
    t_alias *list;

    list = get_alias_list();
    while (list)
    {
        if (ft_memcmp(list->name, key, ft_strlen(key)) == 0)
        {
            if (list->prev)
                list->prev->next = list->next;
            if (list->next)
                list->next->prev = list->prev;
            if (list == get_alias_list())
                set_alias_list(list->next);
            alias_free(list);
            set_exit_status(0);
            return (true);
        }
        list = list->next;
    }
    ft_dprintf(2, "minishell: unalias: %s: not found\n", key);
    set_exit_status(1);
    return (false);
}

void alias_change_word(char *key, char *value)
{
    t_alias *list;

    list = get_alias_list();
    while (list)
    {
        if (ft_memcmp(list->name, key, ft_strlen(key)) == 0)
        {
            free(list->value);
            list->value = ft_strdup(value);
            if (!list->value)
                alias_malloc_exit();
            return ;
        }
        list = list->next;
    }
}