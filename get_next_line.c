/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:42:41 by mhabib-a          #+#    #+#             */
/*   Updated: 2022/11/08 23:54:11 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#define BUFFER_SIZE 1

char    *ft_read1(int fd, char *s)
{
    ssize_t sz;
    char    *buff;
    char    *line;
    
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    if (!buff)
        return (NULL);
    sz = read(fd, buff, BUFFER_SIZE);
    while (sz)
    {
        buff[sz] = 0;
        if(!s)
            s = ft_strdup(buff);
        else 
            s = ft_strjoin(s, buff);
        if(ft_strchr(s, '\n'))
            break;
        sz = read(fd, buff, BUFFER_SIZE);
    }
    return (s);
}

char    *ft_ol(char *ltr)
{
    char    *line;
    size_t  i = 0;

    while(ltr[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (ltr[i]  != '\n')
    {
        line[i] = ltr[i];
        i++;
    }
    line[i] = '\n';
    
    return(line);
}

char    *get_next_line(int fd)
{
    static char *ltr;
    char        *line;

    ltr = ft_read1(fd,ltr);
    line = ft_ol(ltr);
    printf("%s",line);
    return(line);
}

int main()
{
    int fd;
    char *str;
    fd = open("mohamed", O_RDONLY);
    str = get_next_line(fd);
  //  printf("%s",str);    
    return(0);
}