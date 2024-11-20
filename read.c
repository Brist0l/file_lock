#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/cipher.h"

void *getmem(size_t len);
int sendargs(int argc,char *args[]);

int main(int argc,char *argv[]){

	int to_decipher = 1;
	FILE *file;
	const char *file_name = "test.txt";	
	char *str;
	
	if(sendargs(argc,argv) != 0)
		return 0;
	
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
	fprintf(file, str);
	fclose(file);
}

void *getmem(size_t len){// make this into dynamic thing 
	char *data = malloc(sizeof(char) * (len +1));
	return data;
}

int sendargs(int argc,char *args[]){
	FILE *fp;
  	char *path = (char *)getmem(1024);
	
	char ok[1024] = "python parser.py";
	char sliced_args[1024][1024];

	int word = 0;
	size_t j;

	for(int i = 1; i < argc;i++){
		strcat(ok," ");
		strcat(ok,args[i]);
	}
	
  	fp = popen(ok,"r");

  	if (fp == NULL) {
    		printf("Failed to run command\n" );
    		exit(1);
  	}

	while (fgets(path,1024, fp) != NULL){
		for(size_t i = 0;i <= strlen(path);i++){
			if(word == 0)
				j = i;

	//		printf("Word num->%d\tAscii->%d\tLetter->%c\ti->%ld\tj->%ld\n",word,*(path+i),*(path+i),i,j);
				
			if(*(path+i) == ' '){
				word++;
				j = 0;
			}

			sliced_args[word][j++] = *(path+i);	
			if(*(path+i) == 10)
				break;
		}
	}
	
	printf("sliced -> %s\n",sliced_args[0]);
	printf("sliced -> %s\n",sliced_args[1]);
	printf("sliced -> %s\n",sliced_args[2]);

  	pclose(fp);

  	return 0;	
}
