#include<stdio.h>

#define LOWER 0  // LOWER 取代 0  大写 
/*
	符号常量 取代“幻数”是一个好习惯 
	通常 大写	
*/

//output EOF value.
main(){
	int c;  
	while(c = getchar() != EOF){
		printf("%d\n", c);
	printf("%d - at EOF\n", c);
	}

}
