#include<stdio.h>

#define SHIFT 3

char output[100];

int getindex(int ascii_val,int *letters){
	int i;
	if(ascii_val == ' ')
		return 69;
	for(i = 0;i<26;i++)
		if(*(letters + i) == ascii_val)
			return i;
	return -1;
}

char* caser(char *input){
	int letters[26];
	int i,j=97; //
	int index;
	
	for(i = 0; i < 26;i++)//stores letters in the array
		letters[i] = j++;
	for(i = 0;*(input+i) != '\0';i++){
		index = getindex(*(input+i),letters);
		if(index>= 0){
			if(index == 69){
				*(output+i) = ' ';
				continue;
			}
			
			else if(index >=23)
				index = (index + SHIFT) - 26;
			else 
				index = index + SHIFT;
			
			*(output + i) = letters[index];
		}
	}
	*(output+i) = '\0';
		
	return output;

}

