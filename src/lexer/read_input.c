

#include "get_next_line.h"

char	*read_line(void)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line))
		return (line);
	return (NULL);
}