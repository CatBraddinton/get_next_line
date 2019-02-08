#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"

int main(void)
{
	int 	fd;
	char 	*filename;
	char 	*line;
	int 	ret;
	int 	lines = 0;

	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		lines++;
		printf("%s\n", line);
	}
	if (ret == 0)
		printf("\nret = %d\nwhole file was read!!!\n", ret);
	close(fd);
	free(line);
	printf("%d\n", lines);
	return (0);
}