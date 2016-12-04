#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "checker.h"

char		*update_str(char *str, char *op)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(str);
	dst = str + len;
	ft_strcpy(dst, op);
	ft_strcat(dst, "\n");
	str = ft_realloc(str, len + 5);
	return (str);
}

int			main(void)
{
	char	*str;
	
	str = (char*)malloc(5);
	ft_bzero(str, 5);
	str = update_str(str, "pa");
	str = update_str(str, "pb");
	printf("%s", str);
}
