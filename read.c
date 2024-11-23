#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/cipher.h"
#include"headers/args.h"

void *getmem(size_t len);

int main(int argc,char *argv[]){
	struct t_thing args = sendargs(argc,argv);	

	int to_decipher = pyboolconverter(args.sliced_args[2]);
	int to_cipher = pyboolconverter(args.sliced_args[1]);
	FILE *file;
	const char *file_name = args.sliced_args[0];	
	char *str = (char *)getmem(1024);
	
//	printf("%s\t%d\t%d\n",file_name,to_decipher,to_cipher);

	file = fopen(file_name,"r");
	if(file == NULL){
		printf("No file found with the name %s\n",file_name);		
		return -1;
	}

	char *mem_loc = (char*)getmem(1024);

	while(fgets(mem_loc,1024,file) != NULL);
	*(mem_loc + strlen(mem_loc)) = '\0';
	
	if(to_cipher == 1)
		str = caser(mem_loc);
	else if(to_decipher == 1)
		str = decaser(mem_loc);  
	else if(to_cipher == 0 && to_decipher == 0)
		str = caser(mem_loc);
	else{
		printf("-c and -d cannot be used together\n");
		return -1;
	}

	char new_line = '\n';
	strncat(str,&new_line,1);

//	printf("%s",str);	
	fclose(file);

	remove(file_name);//deletes the file
	

	file = fopen(file_name,"a");
	fprintf(file, str);
	fclose(file);
}

void *getmem(size_t len){// make this into dynamic thing 
	char *data = malloc(sizeof(char) * (len +1));
	return data;
}
