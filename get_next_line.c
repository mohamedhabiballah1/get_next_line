/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:42:41 by mhabib-a          #+#    #+#             */
/*   Updated: 2022/11/09 01:39:12 by mhabib-a         ###   ########.fr       */
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
    free(buff);
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

char    *ft_left(char *s)
{
    char    *str;
    size_t  i;
    
    while (s[i] != '\n' && s[i])
        i++;
    str = malloc(sizeof(char) * (ft_strlen(s) - i) + 1);
    if (!str)
        return (NULL);
   /* while(s[i] != '\0')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';*/
    str = ft_strchr(s,'\n');
    return (str);
}

char    *get_next_line(int fd)
{
    static char *ltr;
    char        *line;

    ltr = ft_read1(fd,ltr);
    line = ft_ol(ltr);
    ltr = ft_left(ltr);
    //printf("%s",ltr);
    return(line);
}

int main()
{
    int fd;
    char *str;
    int i = 1;
    fd = open("mohamed", O_RDONLY);
    while(i < 5)
    {
        str = get_next_line(fd);
        printf("line [%d] : %s",i, str);
        i++;
    }
    return(0);
}