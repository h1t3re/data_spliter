#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mem_remem_array(void *array, char *type, int size)
{
	if(strcmp(type, "char *") == 0)
	{
		if(size == 0)
		{
			array = (char *)malloc(sizeof(char));
		}else
		{
			char *tmp;
			tmp = (char *)realloc(array, size*sizeof(char));
			if(tmp == NULL)
				free(array);
			else
				array = tmp;
		}
	}else if(strcmp(type, "char **") == 0)
	{
		if(size == 0)
		{
			array = (char **)malloc(sizeof(char *));
		}else
		{
			char **tmp;
			tmp = (char **)realloc(array, size*sizeof(char *));
			if(tmp == NULL)
				free(array);
			else
				array = tmp;
		}
	}
	return array;
}

char **split(char *buffer, char *separator)
{
	char **array;
	int array_len = 0;
	int j = 0;
	array = (char **)mem_remem_array(array, "char **", j);
	array[array_len] = (char *)mem_remem_array(array[array_len], "char *", j);
	for(int i = 0; i <= strlen(buffer); i++)
	{
		while(buffer[i] != *separator)
		{
			array[array_len][j] = buffer[i];
			j = j + 1;
			array[array_len] = (char *)mem_remem_array(array[array_len], "char *", j+1);
			i = i + 1;
		}
		if(buffer[i] == *separator){
			array[array_len][j] = '\0';
			array_len = array_len + 1;
			array = (char **)mem_remem_array(array, "char **", array_len+1);
			j = 0;
			array[array_len] = (char *)mem_remem_array(array[array_len], "char *", j);
		}
	}
	return array;
}



int main()
{
	char *buffer = "user_id process_id0 0.0 0.0 7656 766 ? Ss 19:44\0";
	char **array0 = split(buffer, " ");
	for(int i = 0; i < 9; i++)
		printf("%s\n", array0[i]);
	return 0;
}
