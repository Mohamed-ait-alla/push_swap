/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:51:14 by mait-all          #+#    #+#             */
/*   Updated: 2024/11/15 15:52:53 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_line_buffer(int fd, char *readed_lines, char *buffer)
{
	ssize_t		nbytes;
	char		*tmp;

	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(readed_lines);
			return (NULL);
		}
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		if (!readed_lines)
			readed_lines = ft_strdup("");
		tmp = readed_lines;
		readed_lines = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (readed_lines);
}

static char	*ft_separate_lines(char *line_buffer)
{
	char	*remain_lines;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[i + 1] == '\0')
		return (NULL);
	remain_lines = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (!remain_lines)
	{
		free(remain_lines);
		remain_lines = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (remain_lines);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*buffer;
	char		*line;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remains);
		remains = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_fill_line_buffer(fd, remains, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remains = ft_separate_lines(line);
	return (line);
}
