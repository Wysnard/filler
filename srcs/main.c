#include "filler.h"
#include <stdio.h>

void	ft_get_info_map(t_info *info, int fd)
{
	char	*line;

	if (get_next_line(0, &line) && line && ft_strnequ("Plateau", line, 7))
	{
		info->hauteur = ft_atoi(ft_strchr(line, ' ') + 1);
		info->largeur = ft_atoi(ft_strrchr(line, ' ') + 1);
		dprintf(fd, "player = %c | hauteur = %d | largeur = %d\n", info->player, info->hauteur, info->largeur);
	}
}

void	ft_init(t_info *info, int fd)
{
	char	*line;

	get_next_line(0, &line);
	info->player = (ft_atoi(&line[10]) == 1) ? 'O' : 'X';
	info->opponent = (info->player == 'O') ? 'X' : 'O';
	dprintf(fd, "moi = %c VS %c\n", info->player, info->opponent);
	// free(line);
}

void	ft_print(char **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
		dprintf(2, "piece = %s\n", map[i++]);
}

int	main(void)
{
	t_info	info;
	int	fd;
	int	solved;

	fd = open("log", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	ft_init(&info, fd);
	solved = 1;
	while (1)
	{
		if (!solved)
		{
			ft_printf("0 0\n");
			break ;
		}
		ft_get_info_map(&info, fd);
		solved = ft_solve_it(&info, fd);
	}
	close(fd);
	return (0);
}
