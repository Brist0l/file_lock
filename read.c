#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/cipher.h"
#include"headers/args.h"

void *getmem(size_t len);
void prepend(char *s,const char* t);
char *slice(char *s,const char t,int part);

int main(int argc,char *argv[]){
	struct t_thing args = sendargs(argc,argv);	

	//sliced_args:
	//0 -> file name
	//1 -> cipher flag
	//2 -> decipher flag
	//3 -> delete flag
	//4 -> hide flag
	//5 -> name flag
	//6 -> extension flag
	int to_decipher = pyboolconverter(args.sliced_args[2]);
	int to_cipher = pyboolconverter(args.sliced_args[1]);
	int to_delete = pyboolconverter(args.sliced_args[3]);
	int to_hide = pyboolconverter(args.sliced_args[4]);
	char *name = args.sliced_args[5];
	char *ext = args.sliced_args[6];
	FILE *file;
	char *file_name_org = args.sliced_args[0];	
	char *file_name;
	char *str = (char *)getmem(1024);
	int name_fl = 0,ext_fl = 0;

//	printf("%s\t%d\t%d\n",file_name,to_decipher,to_cipher);
	printf("%s\n",ext);

	file = fopen(file_name_org,"r");
	if(file == NULL){
		printf("No file found with the name %s\n",file_name_org);		
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

	char *first = slice(file_name_org,'.',0);
	char *second = slice(file_name_org,'.',1);
	
	if(strcmp(name,"None") != 0){
		name_fl = 1;	
		strcpy(first,name);
	}

	if(strcmp(ext,"None") != 0){
		ext_fl = 1;
		strcpy(second,ext);
	}

	file_name = strcat(first,second);
	printf("%s\n",file_name);

//	printf("%s",str);
	fclose(file);
	
	if(to_delete == 1)
		remove(file_name_org);//deletes the file
	else
//		printf("%c\n",file_name[strlen(file_name)-1]);
		if (name_fl == 0 && ext_fl == 0)
			if(file_name[strlen(file_name)-1] != '_')
				strcat(file_name,"_");
	
	if(to_hide == 1)
		prepend(file_name,".");

//	printf("Filename:%s\n",file_name);
	file = fopen(file_name,"w+");
	fprintf(file, str);
	fclose(file);
}

void *getmem(size_t len){
	void *data = malloc(len +1);
	//printf("Data used is:%ld\n",sizeof(data));
	return data;
}

void prepend(char *s,const char* t){
	size_t len = strlen(t);
	memmove(s+len,s,strlen(s) +1);
	memcpy(s,t,len);
}

char *slice(char *s,const char t,int part){
	size_t len = strlen(s);	
	char *first = getmem(1024),*second= getmem(1024);
	size_t i,j;
	for(i = 0;i <= len;i++)
		if(*(s+i) == t){
			for(j = 0;j < i;j++)
				*(first+j) = *(s+j);
			break;	
		}
	for(j = 0;j <= len-i;j++)
		*(second+j)= *(s+i+j);
	
	if(part == 0)
		return first;
	else
		return second;
}
