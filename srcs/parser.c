#include "../includes/wolf3d.h"

int				check_map_width(char *file)
{
	int			fd;
	char		*line;
	int			size;

	size = 0;
	if (!(fd = open(file, O_RDONLY)))
		ft_msg_error("CHECK SIZE MAP X BUT OPEN FILE FAIL");
	while (get_next_line(fd, &line) > 0)
	{
		size = ft_strlen(line);
		if (size != 47)
			ft_msg_error("map is not valid");
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd) == -1)
		ft_msg_error("CLOSE FILE FAIL");
	if (size > 0)
		return (size);
	return (0);
}

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

int				**generate_map(t_env *e, char *file)
{
	int			i;
	int 		**ret;
	char		***tab;

	if ((e->mapWidth = check_map_width(file)) != 47)
		ft_msg_error("map is not valid");
	if ((e->mapHeight = check_map_height(file)) != 24)
		ft_msg_error("map is not valid");
	i = 0;
	tab = cut_map(e, file);
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