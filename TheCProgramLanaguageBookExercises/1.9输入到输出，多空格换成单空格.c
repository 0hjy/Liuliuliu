#include<stdio.h>

#define NONBLANK 'a'

/*replace string of blanks with a single blank.*/
/*
判断当前c是否空
	非空输出
	空：判断前一个是不是空
		非空：就输出
就循环下一次执行--------> 
*/
main(){
	
	int c, lastc;
	
	lastc = NONBLANK;
	while(c = getchar() != EOF){
		if(c != ' ')
			putchar(c);
		if(c == ' ')
			if(lastc != ' ')
				putchar(c);
		lastc = c;
	}
	//不满足条件时可以作为下一判断的其中之一时可以用|| OR 节省判断 
	// 因为第一条件满足就不判断第二条件了
	
	//aother  
	while(c = getchar() != EOF){
		if(c != ' ' || lastc != ' ') // if(c != ' ' || c == ' ' lastc != ' ')
			putchar(c);
		lastc = c;
	}
} 
