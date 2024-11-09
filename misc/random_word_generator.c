#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define WORD_LEN 2 //defines how long should a word be
#define LINE_LEN 10 // define how many words should a line have
#define RAND_LEN 10 // define the range of random numbers

// Upper case assci range = [65,90]
// Lower case assci range = [97,122]

int main(){
	int letters[26*2]; // stores capital+small cased letters
	char word[RAND_LEN*LINE_LEN][RAND_LEN*WORD_LEN];
	int i,k;
	int j = 65;
	int rand_val,max_word_len,max_line_len;
	
	srand(time(NULL));

	for(i = 0;i < 52;i++){ // store all the letters in the array
		if(j == 91)
			j = 97;
		letters[i] = j++;
	}

	rand_val = (rand()/((RAND_MAX+1u)/(RAND_LEN-1)))+1; // generates a random value from 1-RAND_LEN
	max_word_len = rand_val * WORD_LEN;	
	max_line_len = rand_val * LINE_LEN;
	
//	printf("Max word limit:%d\tMax line limit:%d\n",max_word_len,max_line_len);
	for(k = 0;k < max_line_len;k++){
		// varies the range of chars from 0-max_word_len
		int rand_word_len = max_word_len - (rand()/((RAND_MAX + 1u)/max_word_len));

		for(i = 0;i <= rand_word_len;i++){
			if(i== rand_word_len){
				word[k][i] = '\0';
				break;
			}
			int word_num = (rand()/((RAND_MAX+1u)/(26*2-1)));
			word[k][i] = letters[word_num];
		}
	printf("%s ",word[k]);
	}

	printf("\n");
	return 0;
}

