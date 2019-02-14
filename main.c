#include "get_next_line.h"
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
	printf("main statred\n");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		lines++;
	}
	printf("%d\n", lines);
	if (ret == 0)
		printf("\nret = %d\nwhole file was read!!!\n", ret);
	else
		printf("errror\n");
	close(fd);
	return (0);
}