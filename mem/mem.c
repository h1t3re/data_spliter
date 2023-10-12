#include <stdlib.h>
#include <string.h>

int cmp(int length, char *str1, char *str2)
{
	int i = 0;
	while(i < length)
	{
		if(str1[i] != str2[i])
			return 1;
		i = i +1;
	}
	return 0;
}




void *mem_remem_array(void *array, char *type, int size)
{
	if(cmp(6, type, "char *") == 0)
	{
		if((array == NULL) | (size == 0))
		{
			array = (char *)array;
			array = (char *)malloc(size*sizeof(char));
			for(int i = 0; i < size; i++)
				(*(char *)&array[i]) = ' ';
		}else
		{
			char *tmp;
			tmp = (char *)realloc((char *)array, size*sizeof(char));
			if((tmp != array) | (tmp == NULL))
			{
				if(array != NULL)
					free(array);
				array = tmp;
			}
		}
	}else if(cmp(6, type, "char **") == 0)
	{
		if((array == NULL) | (size == 0))
		{
			array = (char **)array;
			array = (char **)malloc(size*sizeof(char *));
		}else
		{
			char **tmp;
			tmp = (char **)realloc((char **)array, size*sizeof(char *));
			if((tmp != array) | (tmp == NULL))
			{
				if(array != NULL)
					free(array);
				array = tmp;
			}
		}
	}
	return array;
}

void free_array(void *array, char *type, int size)
{
	if((cmp(6, type, "char **") == 0) | (strcmp(type, "int **") == 0))
	{
		for(int i = 0; i < size; i++)
			free(*(char *)&array[i]);
	}
	free(array);
}
