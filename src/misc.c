
#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	if (!(dup = malloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_strncpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}
