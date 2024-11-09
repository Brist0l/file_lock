#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/cipher.h"

void *getmem(size_t len);

int main(){
	FILE *file;
	const char *file_name = "test.txt";	

	file = fopen(file_name,"r");
	char *mem_loc = (char*)getmem(1024);
	while(fgets(mem_loc,1024,file) != NULL);
	
	*(mem_loc + strlen(mem_loc)) = '\0';

	char *str = caser(mem_loc);

	printf("%s\n",str);	

//	remove(file_name);//deletes the file

}

void *getmem(size_t len){// make this into dynamic thing 
	char *data = malloc(sizeof(char) * (len +1));
	return data;
}
