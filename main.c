#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("testlines.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break ;
	// 	printf("%s", line);
	// 	free(line);
	// }
	return (0);
}
