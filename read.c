#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/cipher.h"
#include"headers/args.h"

void *getmem(size_t len);
void prepend(char *s,const char* t);
struct t_thing slice(char *s,const char t);

int main(int argc,char *argv[]){
	struct t_thing args = sendargs(argc,argv);	

	//sliced_args:
	//0 -> file name
	//1 -> cipher flag
	//2 -> decipher flag
	//3 -> delete flag
	//4 -> hide flag
	int to_decipher = pyboolconverter(args.sliced_args[2]);
	int to_cipher = pyboolconverter(args.sliced_args[1]);
	int to_delete = pyboolconverter(args.sliced_args[3]);
	int to_hide = pyboolconverter(args.sliced_args[4]);
	FILE *file;
	char *file_name = args.sliced_args[0];	
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
	
	if(to_delete == 1)
		remove(file_name);//deletes the file
	else{
//		printf("%c\n",file_name[strlen(file_name)-1]);
		if(file_name[strlen(file_name)-1] != '_')
			strcat(file_name,"_");
	}
	
//	printf("Filename:%s\n",file_name);
	
	if(to_hide == 1)
		prepend(file_name,".");

//	printf("Filename:%s\n",file_name);
	file = fopen(file_name,"w+");
	fprintf(file, str);
	fclose(file);
}

void *getmem(size_t len){// make this into dynamic thing 
	char *data = malloc(sizeof(char) * (len +1));
	return data;
}

void prepend(char *s,const char* t){
	size_t len = strlen(t);
	memmove(s+len,s,strlen(s) +1);
	memcpy(s,t,len);
}

struct t_thing slice(char *s,const char t){
	struct t_thing strings;
	size_t len = strlen(s);	
	size_t i,j;
	for(i = 0;i <= len;i++)
		if(*(s+i) == t){
			for(j = 0;j < i;j++)
				strings.sliced_args[0][j]=*(s+j);
			break;	
		}
	for(j = 0;j <= len-i;j++)
		strings.sliced_args[1][j] = *(s+i+j);

	return strings;
}

