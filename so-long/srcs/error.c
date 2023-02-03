#include "so_long.h"

void	error_get_map(int fd, char *str1, char *str2)
{
	close(fd);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	printf("Error m\n");
	exit(1);
}

void	error_parsing(char *str)
{
	if (str)
		free(str);
	printf("Error p\n");
	exit(1);
}