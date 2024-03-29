/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:34:49 by jthor             #+#    #+#             */
/*   Updated: 2023/03/21 14:34:50 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
A slightly modified version of the original get_next_line function, that
allows for multiple files to be read at once, with multiple static
variables in use.

The magic number 4896 is taken from the soft limit of the number of file
descriptors that can be open at one time, obtained by running ulimit -n on
an open shell terminal.
*/

char	*get_next_line(int fd)
{
	static char	*stat_str[4896];
	char		*buff;
	ssize_t		read_ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (!(stat_str[fd]))
		ft_handleptr(&(stat_str[fd]), 0);
	while (read_buff(fd, &buff, &read_ret) > 0)
	{
		handle_buff(&(stat_str[fd]), &buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	ft_handleptr(&buff, 1);
	if (read_ret <= 0 && !(stat_str[fd]))
		return (NULL);
	return (final_line(&(stat_str[fd])));
}

ssize_t	read_buff(int fd, char **buff, ssize_t *read_ret)
{
	ssize_t	ret;

	ret = read(fd, *buff, BUFFER_SIZE);
	if (ret > 0)
		(*buff)[ret] = '\0';
	*read_ret = ret;
	return (ret);
}

void	handle_buff(char **stat_str, char **buff)
{
	char	*temp;

	temp = ft_strjoin(*stat_str, *buff);
	ft_handleptr(stat_str, 1);
	*stat_str = temp;
}

char	*final_line(char **stat_str)
{
	char	*ret;
	char	*leftov;
	int		i;

	i = 0;
	while ((*stat_str)[i] && (*stat_str)[i] != '\n')
		i++;
	if ((*stat_str)[i])
	{
		i += 1;
		ret = ft_strldup(*stat_str, i);
		leftov = ft_strldup(*stat_str + i, ft_strlen(*stat_str) - i);
		ft_handleptr(stat_str, 1);
		if (!leftov || !(leftov[0]))
			ft_handleptr(&leftov, 1);
		else
			*stat_str = leftov;
	}
	else
	{
		ret = ft_strldup(*stat_str, ft_strlen(*stat_str));
		ft_handleptr(stat_str, 1);
	}
	return (ret);
}
