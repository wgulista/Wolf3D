#include "../includes/wolf3d.h"

int				check_map_height(char *file)
{
	int			fd;
	char		*line;
	int			size;

	size = 0;
	if (!(fd = open(file, O_RDONLY)))
		ft_msg_error("CHECK SIZE MAP Y BUT OPEN FILE FAIL");
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		size++;
	}
	free(line);
	if (close(fd) == -1)
		ft_msg_error("CLOSE FILE FAIL");
	if (size > 0)
		return (size);
	return (0);
}

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
		free(line);
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
	while (tab[i])
	{
		ret[i] = ft_strsplit(tab[i], ' ');
		free(tab[i]);
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

int				**generate_map(t_env *e, char *file)
{
	int			i;
	int 		**ret;
	char		***tab;

	if (check_file_error(file))
		ft_msg_error("Usage: ./wolf3d <map_file.txt>");
	e->mapHeight = check_map_height(file);
	tab = cut_map(e, file);
	i = 0;
	ret = (int **)malloc(sizeof(int *) * (e->mapHeight));
	while (i < e->mapHeight)
	{
		ret[i] = add_line(tab[i]);
		ft_free_tab(tab[i]);
		i++;
	}
	free(tab);
	if (ret != 0)
		return (ret);
	return (0);
}