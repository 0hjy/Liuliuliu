#include<stdio.h>

#define IN  1 /*inside a word*/
#define OUT 0 /*outside a word*/
/*print input one word per line*/
main(){
	
	int c, state;
	
	state = OUT;//初始化，OUT 0 
	/*
	state表示是否处于单词外，避免多次输出空格\n。 
		*/
	while((c = getchar()) != EOF) {
		if(c = ' ' || c = '\n' || c = '\t'){
			if (state == IN) {
				putchar('\n');/* finish the word */
				state = OUT;
			}
		} else if(state == OUT) {
			state = IN;
			putchar(c);
	    } else
	    	putchar(c);
		
	}
} 
