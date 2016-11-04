#include "../includes/wolf3d.h"

int			check_file_error(char *file)
{
	if (file == NULL)
		return (1);
	else if (open(file, O_RDONLY) == -1)
		return (1);
	else if (ft_strstr(file, ".txt") == NULL)
		return (1);
	else if (ft_strstr(file, "wolf3d"))
		return (1);
	return (0);
}

void		ft_msg_error(char *msg)
{
	if (msg != NULL)
		ft_putendl(msg);
	else
		ft_putendl("Error");
	exit(1);
}