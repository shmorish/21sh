#include "alias.h"

t_alias *alias_new(char *name, char *value)
{
    t_alias *alias;

    alias = ft_calloc(sizeof(t_alias), 1);
    if (!alias)
        return (NULL);
    alias->name = ft_strdup(name);
    if (!alias->name)
    {
        free(alias);
        return (NULL);
    }
    alias->value = ft_strdup(value);
    if (!alias->value)
    {
        free(alias->name);
        free(alias);
        return (NULL);
    }
    alias->next = NULL;
    alias->prev = NULL;
    return (alias);
}

void alias_free(t_alias *alias)
{
    if (!alias)
        return ;
    free(alias->name);
    free(alias->value);
    free(alias);
}
