#include <stdlib.h>
#include "../include/strlen.h"
#include "../include/strncmp.h"
#include <stdio.h>

char **split(char *buffer, char *separator)
{
	int i = 0;
	int j = 0;
	int v = 0;
	int backup_i = 0;
	int array_len = 0;
	char *data = (char *)malloc(strlen(buffer)*sizeof(char));
	char **array = (char **)malloc(sizeof(char *));
	char *str1 = (char *)malloc(2*sizeof(char));
	char *str2 = (char *)malloc(2*sizeof(char));
	while(i < strlen(buffer))
	{
		*(data+(i*sizeof(char))) = *(buffer+(i*sizeof(char)));
		i = i +1;
	}
	i = 0;
	while(i < strlen(data))
	{
		backup_i = i;
		*str1 = *(data+(i*sizeof(char)));
		*(str1+1) = '\0';
		*str2 = *separator;
		*(str2+1) = '\0';
		j = 0;
		while(strncmp(str1, str2) != 0)
		{
			i = i +1;
			*str1 = *(data+(i*sizeof(char)));
			*(str1+1) = '\0';
			j = j +1;
		}
		array[array_len] = (char *)malloc((j+1)*sizeof(char));
		v = 0;
		while(v < j)
		{
			*(array[array_len]+(v*sizeof(char))) = *(data+((backup_i+v)*sizeof(char)));
			v = v +1;
		}
		*(array[array_len]+(v*sizeof(char))) = '\0';
		if(strncmp(str1, str2) == 0){
			while(strncmp(str1, str2) == 0)
			{
				i = i +1;
				*str1 = *(data+(i*sizeof(char)));
				*(str1+1) = '\0';
			}
			array_len = array_len +1;
			array = (char **)realloc(array, (array_len+1)*sizeof(char *));
		}
	}
	array[array_len] = "\0";
	return array;
}
