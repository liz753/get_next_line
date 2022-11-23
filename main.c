#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("testlines.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
