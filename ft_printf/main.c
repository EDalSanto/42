#include "libft/includes/libft.h"
#include "includes/libft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	//basic test no convsp
//	printf("ft_____________________\n"); 
//	ft_printf("Hello world! 42  \n");
//	printf("libc___________________\n");
//	printf("Hello world! 42 \n");
//	printf("-------------------------------------------------------\n");
//	//d and i convsp 
//	printf("ft______________________\n"); 
//	ft_printf("int tests (d and i) tests: d: %d i: %i, min_int: %d \n", 42, 0, -2147483648);
//	printf("libc____________________\n");
//	printf("int tests (d and i) tests: d: %d i: %i, min_int: %ld \n", 42, 0, -2147483648);
//	printf("-------------------------------------------------------\n");
//	//o convsp -> unsigned octal
//	printf("ft_______________________\n"); 
//	ft_printf("octal (o) tests: 42: %o, 0: %o, -12345: %o\n", 42, 0, -12345);
//	printf("libc_____________________\n");
//	printf("octal (o) tests: 42: %o, 0: %o, -12345: %o\n", 42, 0, -12345);
//	printf("-------------------------------------------------------\n");
//	//u convsp -> unsigned decimal 
//	printf("ft_______________________\n"); 
//	ft_printf("unsigned (u) tests: 42: %u, 0: %u, U_INT_MAX: %u\n", 42, 0, UINT_MAX);
//	printf("libc_____________________\n");
//	printf("unsigned (u) tests: 42: %u, 0: %u, U_INT_MAX: %u\n", 42, 0, UINT_MAX);
//	printf("-------------------------------------------------------\n");
//	//s convsp -> string 
//	printf("ft_______________________\n"); 
//	ft_printf("string null: %s\n", NULL);
//	printf("libc_____________________\n");
//	printf("string null: %s\n", NULL);
//	printf("-------------------------------------------------------\n");
//	//p convsp -> mem 
//	int	arr[3] = {1, 2, 3};
//	char *hello = "hello";
//	char goodbye[10] = {"goodbye"};
//	char *ciao = malloc(5);
//	strcpy(ciao, "ciao");
//	printf("ft_______________________\n"); 
//	ft_printf("arr address: %p, string literal address: %p, stack address: %p, heap address:%p\n", (void*)arr, &hello, goodbye, ciao);
//	printf("libc_____________________\n");
//	printf("arr address: %p, string literal address: %p, stack address: %p, heap address:%p\n", (void*)arr, &hello, goodbye, ciao);
//	printf("-------------------------------------------------------\n");
//	printf("%% convsp -> string\n"); 
//	printf("ft_______________________\n"); 
//	ft_printf("{%   %}\n");
//	printf("libc_____________________\n");
//	printf("{% %}\n");
//	printf("-------------------------------------------------------\n");
//	printf("%%S\n");
//	printf("ft_______________________\n"); 
//	int ret = ft_printf("{% C}\n", 0);	
//	printf("libc_____________________\n");
//	int lib = printf("{% C}\n", 0);	
//	printf("ret: %d, lib: %d\n", ret, lib);
	//printf("ft_______________________\n"); 
	int ret = ft_printf("%lo\n", LONG_MIN);	
	printf("libc_____________________\n");
	int lib = printf("%lo\n", LONG_MIN);	
	printf("ret: %d, lib: %d\n", ret, lib);
	return (0);	
}
