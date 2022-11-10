/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:42:41 by mhabib-a          #+#    #+#             */
/*   Updated: 2022/11/10 02:19:17 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#define BUFFER_SIZE 1
char    *ft_read1(int fd, char *s)
{
    ssize_t sz;
    char    *buff;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
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
        if(sz == 0)
            break;
    }
    free(buff);
    return (s);
}

char    *ft_ol(char *ltr)
{
    char    *line;
    size_t  i = 0;
    
    if(!ltr)
        return (NULL);
    while(ltr[i] != '\n' && ltr[i])
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
    if (ltr[i] && ltr[i] == '\n')
		line[i++] = '\n';
    free(ltr);
    return(line);
}

char    *ft_left(char *s)
{
    char    *str;
    size_t  i = 0;
    size_t  j = 0;
    if(!s)
        return (NULL);
    while (s[i] != '\n' && s[i])
        i++;
        str = malloc(sizeof(char) * (ft_strlen(s) - i) + 1);
    if (!str)
        return (NULL);
    i++;
    while (s[i])
        str[j++] = s[i++];
    str[j] = '\0';
    return (str);
}

char    *get_next_line(int fd)
{
    static char *ltr;
    char        *line;
    
    if (BUFFER_SIZE <= 0)
        return (NULL);
    ltr = ft_read1(fd,ltr);
    line = ft_ol(ltr);
    ltr = ft_left(ltr);
    return(line);
}

int main()
{
    int fd;
    char *str;
    int i = 1;
    fd = open("mohamed", O_RDWR);
    while(i < 2)
    {
        str = get_next_line(fd);
        printf("line [%d] : %s\n", i, str);
        i++;
    }
    return(0);
}