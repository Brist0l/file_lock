#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/cipher.h"

void *getmem(size_t len);

int main(){
	int to_decipher = 1;
	FILE *file;
	const char *file_name = "test.txt";	
	char *str;
	
	file = fopen(file_name,"r");
	char *mem_loc = (char*)getmem(1024);

	while(fgets(mem_loc,1024,file) != NULL);
	*(mem_loc + strlen(mem_loc)) = '\0';
	
	if(to_decipher == 0)
		str = caser(mem_loc);
	else
		str = decaser(mem_loc);  

	printf("%s\n",str);	
	fclose(file);

	remove(file_name);//deletes the file
	
	file = fopen(file_name,"a");
	fprintf(file,str);
	fclose(file);
}

void *getmem(size_t len){// make this into dynamic thing 
	char *data = malloc(sizeof(char) * (len +1));
	return data;
}


