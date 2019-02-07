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
	line = NULL;
	filename = "gnl1_3.txt";
	fd = open(filename, O_RDONLY);
	// printf("main started ... \n");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		lines++;
		// printf("main loop started ...\n");
		// printf("gnl returned %d\n", ret);
			printf("%s\n", line);
		// printf("ret = %d\n", ret);
		// printf("lines read: %d\n", lines);
	}
	if (ret == 0)
		printf("file was read!!!\n");
	close(fd);
	printf("%d\n", lines);
	return (0);
}