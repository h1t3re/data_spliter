#include <stdlib.h>
#include <string.h>

void *mem_remem_array(void *array, char *type, int size)
{
	if(strcmp(type, "char *") == 0)
	{
		if((array == NULL) | (size == 0))
		{
			array = (char *)malloc(size*sizeof(char));
			for(int i = 0; i < size; i++)
				(*(char *)&array[i]) = '\0';
		}else
		{
			char *tmp;
			tmp = (char *)realloc(array, size*sizeof(char));
			if((tmp != array) | (tmp == NULL))
			{
				free(array);
				array = tmp;
			}
		}
	}else if(strcmp(type, "char **") == 0)
	{
		if((array == NULL) | (size == 0))
		{
			array = (char **)malloc(size*sizeof(char *));
			for(int i = 0; i < size; i++)
				(**(char **)&array[i]) = '\0';
		}else
		{
			char **tmp;
			tmp = (char **)realloc(array, size*sizeof(char *));
			if((tmp != array) | (tmp == NULL))
			{
				free(array);
				array = tmp;
			}
		}
	}
	return array;
}

void free_array(void *array, char *type, int size)
{
	if((strcmp(type, "char **") == 0) | (strcmp(type, "int **") == 0))
	{
		for(int i = 0; i < size; i++)
			free(array[i]);
	}
	free(array);
}
