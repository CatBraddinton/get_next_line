#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>

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
		printf("%s\n", line);
		lines++;
	}
	if (ret == 0)
		printf("\nret = %d\nwhole file was read!!!\n", ret);
	close(fd);
	return (0);
}