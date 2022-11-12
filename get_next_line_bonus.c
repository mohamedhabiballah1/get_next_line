/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:08:53 by mhabib-a          #+#    #+#             */
/*   Updated: 2022/11/12 00:45:52 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"
#define BUFFER_SIZE 1
char	*ft_read1(int fd, char *s)
{
	ssize_t	sz;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	sz = 1;
	while (!ft_strchr(s, '\n') && sz != 0)
	{
		sz = read(fd, buff, BUFFER_SIZE);
		if (sz == -1)
		{
			free(s);
			return (NULL);
		}
		if (sz == 0)
			return (s);
		buff[sz] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		free(tmp);
	}
	return (s);
}

char	*ft_ol(char *ltr)
{
	size_t	i;

	i = 0;
	if (!ft_strchr(ltr, '\n'))
		return (ltr);
	while (ltr[i] != '\n')
		i++;
	i++;
	return (ft_substr(ltr, 0, i));
}

char	*ft_left(char *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!ft_strchr(s, '\n'))
		return (NULL);
	while (s[i] != '\n')
		i++;
	if (s[i + 1] == '\0')
	{
		free(s);
		return (NULL);
	}
	i++;
	tmp = ft_substr(s, i, ft_strlen(s) - i);
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*ltr[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(ltr[fd]);
		ltr[fd] = NULL;
		return (NULL);
	}
	ltr[fd] = ft_read1(fd, ltr[fd]);
	if (!ltr[fd])
		return (NULL);
	line = ft_ol(ltr[fd]);
	ltr[fd] = ft_left(ltr[fd]);
	return (line);
}

/*int main()
{
    int fd;
    char *str;
    int i = 1;
    fd = open("mohamed", O_RDONLY);
    while((str = get_next_line(fd)))
    {
        printf("%s", str);
        free(str);
    }
    system("leaks a.out");
}*/
