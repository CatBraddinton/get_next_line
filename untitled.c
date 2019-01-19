int    check_and_copy(unsigned char *buff, unsigned char *line)
{
    size_t  i;

    i = 0;
    while ((buff[i] != 13 || !buff[i]) && i <= BUFF_SIZE)
    {
        line[i] = buff[i];
        i++;
    }
    if (i < BUFF_SIZE)
    {
        line[i] = '\0';
        return (1);
    }
    return (0);
}


void    *ft_realloc(char **line, size_t len)
{
    char   *arr;

    if ((arr = ft_memalloc(len)) == NULL) 
        return (NULL);
    arr = ft_memcpy(arr, line, len);
    free(line);
    if ((line = ft_memalloc(sizeof(arr) + BUFF_SIZE)) == NULL)
        return (NULL);
    line = ft_memcpy(line, arr, sizeof(arr));
    free(arr);
    return (line);
}