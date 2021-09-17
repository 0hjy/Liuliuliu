#include<stdio.h>
 
/* 循环右移n位 */ 
/* 一位一位处理 */ 
/*
	1.while 一位一位处理
		2.rbit=（x左移 长度-1位）  即：留最右位到最左位。 
		3.x右移一位
		4.x 位与 rbit
	1.while
	
	5. 返回 x  
		 
*/
main() { 
}
unsigned rightrot(signed x, int n)
{
	int wordlength(void);
	int rbit;
	while(n-->0) {
		rbit = (x & 1) << (wordlength() - 1) ;
		x = x >> 1;
		x = x | rbit;
		 
	} 
	return x ;
}
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;
	
	for(i = 1;(v = v>>1) >0;i++)
	 ;
	
	return i;
 } 
 
 

