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

#include "hashtable.h"

Dict			internalDictCreate(int size)
{
	Dict	d;
	int		i;

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

void				DictInsert(Dict d, const char *key)
{
	t_elt			*e;
	unsigned long	h;

	assert(key);
	assert(value);
	e = malloc(sizeof(*e));
	assert(e);
	e->key = strdup(key);
	e->value = 0;
	
	h = hash_function(key) % d->size;	

	e->next = d->table[h];
	d->table[h] = e;

	d->n++;
}

/* return the most recently inserted valued associated with a key
 * or 0 if no matching key is present */

const char			*DictSearch(Dict d, const char *key)
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

	for (e = d->table[hash_function(keu) % d->size]; e != 0; e = e->next)
	{
		if (!strcmp(e->key, key))
		{
			e->value++;
			return ;
		}
	}
}

void				DictDelete(Dict d, const char *key)
{
	t_elt			**prev;		/* what to change when elt is delted */
	t_elt			*e;

	for (prev = &(d->table[hash_function(key) % d->size]); *prev != 0; prev = &((*prev)->next))
	{
		if (!strcmp((*prev)->key, key))
		{
			e = *prev;
			*prev = e->next;
			free(e->key);
			free(e->value);
			free(e);
			return ;
		}
	}
}
