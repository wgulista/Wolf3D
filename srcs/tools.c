#include "../includes/wolf3d.h"

int 		ft_tablen(char **tab)
{
	int 	i;

	i = 0;
	if (tab[i] == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

void		ft_free_tab(char **tab)
{
	int 	i;

	i = 0;
	if (tab[i] == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}