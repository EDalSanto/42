#include <stdio.h>
#include <assert.h>
#include "hashtable.h"

int		main(void)
{
	Dict	d;
	char	buf[512];

	d = DictCreate();
	DictInsert(d, "Eddie", "Dal Santo");
	strcpy(buf, DictSearch(d, "Eddie"));
	printf("My last name is: %s\n", buf);
	printf("It's stored at hashindex: %lu\n", hash_function("Eddie") % d->size);
	return (0);
}
