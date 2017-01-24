/* We could implement a dictionary as an array of structs but that would be
 * exensive: O(n) time to find a key in the worst case*/
/* entry fed into hashcode, a function, that returns a code for the hashindex
 * location */
/* this can lead to Collisions, or multiple keys mapping to same hashindex
 * */
/* Resolving Collisions
 *	Chaining -> each record in array is a pointer to a linked list; every time
 *	we insert a new element in a particualr location, we simply add it to this
 *	list
 *		O(n) to the number of keys in the table that have the same keys
 *			load factor -> cost of a failed search; number of elements in the
 *			table over the number of locations in the table
 *				rehashing -> when the load factor passes some threshold, create
 *				a new hashtable of size 2n and migrate all elements to it
 */

/* 
   Find frequency of letters in both and store in seperate Dictionaries */
/*	Dict_Mag, Dict_Note */
/* iterate thourgh ransom note Dictionary and find corresponding value in
 * Dict_Mag
 * if value greater than Dict_Mag, return false
 * else keep going till end at which point you can return true 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)

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

Dict			internalDictCreate(int size)
{
	Dict		d;
	int			i;

	d = malloc(sizeof(*d));

	assert(d != 0);

	d->size = size;
	d->n = 0;
	d->table = malloc(sizeof(t_elt*) * d->size);

	assert(d->table != 0);

	for(i = 0; i < d->size; i++)
		d->table[i] = 0;

	return (d);
}

Dict	DictCreate(void)
{
	return (internalDictCreate(INITIAL_SIZE));
}

void			DictDestroy(Dict d)
{
	int			i;
	t_elt		*e;
	t_elt		*next;

	for(i = 0; i < d->size; i++)
	{
		for(e = d->table[i]; e != 0; e = next)
		{
			next = e->next;
			free(e->key);
			free(e);
		}
	}
	free(d->table);
	free(d);
}

#define MULTIPLIER (97)

unsigned long hash_function(const char *s)
{
	unsigned const char *us;
	unsigned long		h;

	h = 0;
	for(us = (unsigned const char *) s; *us; us++)
		h = h * MULTIPLIER + *us;	
	return (h);
}

/* insert a new key-value pair into an existing dictionary */
int					DictSearch(Dict d, const char *key)
{
	t_elt			*e;

	for (e = d->table[hash_function(key) % d->size]; e != 0; e = e->next)
	{
		if (!strcmp(e->key, key))
			return (e->value);
	}
	return (0);
}

void				DictIncrValue(Dict d, const char *key)
{
	t_elt			*e;

	for (e = d->table[hash_function(key) % d->size]; e != 0; e = e->next)
	{
		if (!strcmp(e->key, key))
		{
			e->value++;
			return ;
		}
	}
}


void				DictInsert(Dict d, const char *key)
{
	t_elt			*e;
	unsigned long	h;
	
	if (DictSearch(d, key))
	{
		DictIncrValue(d, key);
		return ;
	}

	assert(key);
	e = malloc(sizeof(*e));
	assert(e);
	e->key = strdup(key);
	e->value = 1;	
	h = hash_function(key) % d->size;	

	e->next = d->table[h];
	d->table[h] = e;

	d->n++;
}

/* return the most recently inserted valued associated with a key
 * or 0 if no matching key is present */

int					enough(Dict d_mag, Dict d_note)
{
	for (int i = 0; i < d_note->size; i++)
	{
		for (t_elt *e = d_note->table[i]; e != 0; e = e->next)
		{
			if (e->value > DictSearch(d_mag, e->key))
				return (0);
		}
	}
	return (1);
}

int					main()
{
	int				m; 
	int				n; 
	Dict			d_mag;
	Dict			d_note;

	scanf("%d %d",&m,&n);
	char *temp = malloc(sizeof(char*));
	d_mag = DictCreate();
	for(int magazine_i = 0; magazine_i < m; magazine_i++)
	{
		scanf("%s", temp);
		DictInsert(d_mag, temp);
	}
	d_note = DictCreate();
	for(int ransom_i = 0; ransom_i < n; ransom_i++)
	{
		scanf("%s", temp);
		DictInsert(d_note, temp);
	}
	if (enough(d_mag, d_note))
		printf("Yes");
	else
		printf("No");
	return (0);
}
