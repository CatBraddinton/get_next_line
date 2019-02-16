#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int 	fd;
	char 	*filename;
	char 	*line;
	int 	ret;

	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	if (ret == 0)
		ft_putstr("whole file was read!!!\n");
	else
		ft_putstr("errror\n");
	close(fd);
	return (0);
}