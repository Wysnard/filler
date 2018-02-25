#include "filler.h"
#include <limits.h>

void	print_hot(t_info *info, int hotmap[info->hauteur + 1][info->largeur + 1], int fd)
{
	unsigned	x;
	unsigned	j;

	j = 0;
	while (j < info->hauteur)
	{
		x = 0;
		while (x < info->largeur)
			dprintf(fd, "%d", hotmap[j][x++]);
		dprintf(fd, "\n");
		j++;
	}
}

void	print_map(t_info *info, char hotmap[info->hauteur + 1][info->largeur + 1], int fd)
{
	unsigned	x;
	unsigned	j;

	j = 0;
	while (j < info->hauteur)
	{
		x = 0;
		dprintf(fd, "print = ");
		while (x < info->largeur)
			dprintf(fd, "%c", hotmap[j][x++]);
		dprintf(fd, "\n");
		j++;
	}
}

int	*make_it_hot(t_info *info, int *hotmap, char *line)
{
	unsigned	i;

	i = 0;
	while (i < info->largeur)
	{
		hotmap[i] = (line[i] == info->opponent) ? 0 : info->hauteur * info->largeur;
		i++;
	}
	return (hotmap);
}

void	distcalc(t_info *info, int hotmap[info->hauteur + 1][info->largeur + 1])
{
	unsigned	chg;
	unsigned	i;
	unsigned	j;

	chg = 1;
	while (chg)
	{
		j = 0;
		chg = 0;
		while (j < info->hauteur)
		{
			i = 0;
			while (i < info->largeur)
			{
				if (hotmap[j][i] >= 0)
				{
					if (j > 0 && hotmap[j - 1][i] > hotmap[j][i] + 1)
					{
						hotmap[j - 1][i] = hotmap[j][i] + 1;
						chg++;
					}
					if (i > 0 && hotmap[j][i - 1] > hotmap[j][i] + 1)
					{
						hotmap[j][i - 1] = hotmap[j][i] + 1;
						chg++;
					}
					if (j < info->hauteur - 1 && hotmap[j + 1][i] > hotmap[j][i] + 1)
					{
						hotmap[j + 1][i] = hotmap[j][i] + 1;
						chg++;
					}
					if (i < info->largeur - 1 && hotmap[j][i + 1] > hotmap[j][i] + 1)
					{
						hotmap[j][i + 1] = hotmap[j][i] + 1;
						chg++;
					}
					if (j > 0 && i > 0 && hotmap[j - 1][i - 1] > hotmap[j][i] + 1)
					{
						hotmap[j - 1][i - 1] = hotmap[j][i] + 1;
						chg++;
					}
					if (j > 0 && i < info->largeur - 1 && hotmap[j - 1][i + 1] > hotmap[j][i] + 1)
					{
						hotmap[j - 1][i + 1] = hotmap[j][i] + 1;
						chg++;
					}
					if (i > 0 && j < info->hauteur - 1 && hotmap[j + 1][i - 1] > hotmap[j][i] + 1)
					{
						hotmap[j + 1][i - 1] = hotmap[j][i] + 1;
						chg++;
					}
					if (j < info->hauteur - 1 && i < info->largeur - 1 && hotmap[j + 1][i + 1] > hotmap[j][i] + 1)
					{
						hotmap[j + 1][i + 1] = hotmap[j][i] + 1;
						chg++;
					}
				}
				i++;
			}
			j++;
		}
	}
}

int	ft_solve_it(t_info *info, int fd)
{
	char	*line;
	unsigned	i;
	char	map[info->hauteur + 1][info->largeur + 1];
	int	hotmap[info->hauteur + 1][info->largeur + 1];

	i = 0;
	dprintf(fd, "get out\n");
	get_next_line(0, &line);
	// dprintf(fd, "first line = %s\n", line);
	free(line);
	while (i < info->hauteur)
	{
		while (get_next_line(0, &line) <= 0)
			if (line)
				free(line);
		ft_strcpy(map[i], &line[4]);
		map[i][info->largeur] = '\0';
		make_it_hot(info, hotmap[i], &line[4]);
		free(line);
		i++;
	}
	distcalc(info, hotmap);
	print_map(info, map, fd);
	ft_getinfopiece(info, fd);
	standard_it(fd, info);
	// print_hot(info, hotmap, fd);
	return (place(info, hotmap, map, fd));
}
