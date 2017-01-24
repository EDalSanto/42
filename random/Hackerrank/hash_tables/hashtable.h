#ifndef HASHTABLE_H
# define HASHTABLE_H
# define INITIAL_SIZE (1024)
# define GROWTH_FACTOR (2)
# define MAX_LOAD_FACTOR (1)
# include <stdlib.h>
# include <assert.h>
# include <string.h>

typedef struct			s_elt
{
	char				*key;
	int					value;
	struct s_elt		*next;
}						t_elt;

typedef struct			s_dict
{
	int					size;	/* size of the pointer table */
	int					n;		/*number of elements stored */
	t_elt				**table;
}						t_dict;

typedef t_dict			*Dict;

Dict					DictCreate(void);
void					DictDestroy(Dict);
void					DictInsert(Dict, const char *key);
int						DictSearch(Dict, const char *key);
void					DictDelete(Dict, const char *key);
unsigned long			hash_function(const char *s);

#endif
