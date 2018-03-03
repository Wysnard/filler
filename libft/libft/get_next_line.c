/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:32:50 by vlay              #+#    #+#             */
/*   Updated: 2018/03/03 20:31:12 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy(char *dest, char *str, int *offset)
{
	int		i;
	int		j;
	char	*res;

	i = *offset;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(dest) + i + 1))))
		return (NULL);
	ft_strcpy(res, dest);
	i = *offset;
	j = ft_strlen(res);
	while (str[i] && str[i] != '\n')
		res[j++] = str[i++];
	res[j] = '\0';
	*offset = (str[i] == '\n') ? i + 1 : 0;
	free(dest);
	return (res);
}

static t_clist	*getcontent(t_clist **alst, int fd)
{
	t_clist *tmp;

	if (!alst || fd < 0)
		return (NULL);
	tmp = *alst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_clist *)malloc(sizeof(t_clist));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->next = *alst;
	tmp->offset = 0;
	*alst = tmp;
	return (*alst);
}

static int		delclist(t_clist **lst, t_clist *buff)
{
	if (!lst || !buff)
		return (0);
	while ((*lst) != buff && (*lst))
		lst = &(*lst)->next;
	*lst = buff->next;
	free(buff);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_clist	*lst = NULL;
	t_clist			*b;
	int				nb;

	if (fd < 0 || read(fd, "", 0) < 0 || !line || !(b = getcontent(&lst, fd))
		|| !(*line = ft_strnew(1)))
		return (-1);
	if (b->offset)
	{
		if (!(*line = copy(*line, b->buff, &b->offset)))
			return (-1);
		if (b->offset)
			return (1);
	}
	while ((nb = read(fd, b->buff, BUFF_SIZE)))
	{
		b->buff[nb] = '\0';
		if (!(*line = copy(*line, b->buff, &b->offset)))
			return (-1);
		if (b->offset)
			return (1);
	}
	if (**line != '\0')
		return (1);
	return (delclist(&lst, b));
}
