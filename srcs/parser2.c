#include "../includes/wolf3d.h"

char			**cut_map_2(t_env *e, char *file)
{
	int			fd;
	char		**tab;
	char		*line;
	int			i;

	if (!(tab = (char**)malloc(sizeof(char*) * (e->mapHeight + 1))))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_msg_error("Can't open file");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	free(line);
	close(fd);
	tab[i] = NULL;
	return (tab);
}

char			***cut_map(t_env *e, char *file)
{
	char		***ret;
	char		**tab;
	int			i;

	tab = cut_map_2(e, file);
	if (!(ret = (char***)malloc(sizeof(char**) * (e->mapHeight + 1))))
		return (NULL);
	i = 0;
	while (i < e->mapHeight && tab[i] != NULL)
	{
		ret[i] = ft_strsplit(tab[i], ' ');
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	ret[i] = NULL;
	return (ret);
}

int				*add_line(char **tab)
{
	int			i;
	int			*ret;
	int			tab_size;

	tab_size = ft_tablen(tab);
	if (!(ret = (int*)malloc(sizeof(int) * (tab_size))))
		return (0);
	i = 0;
	while (i < tab_size)
	{
		ret[i] = ft_atoi(tab[i]);
		i++;
	}
	return (ret);
}