#include<stdio.h>
 
/* 循环右移n位,方法二                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        #include<stdio.h>
 
/* 循环右移n位 */ 
/* 一次右移完成，再 位与操作 */ 
/*
	1.while x 不是n的倍数  n取x%n余数 
		2.rbit= 留最右面n位 
		3.rbit=右移 length-n 位    移到左侧 
		4.x 位与 rbit
	1.while
	
	5. 返回 x  
		 
*/
main() { 
}
unsigned  rightrott(signed x, int n)
{
	int wordlength(void);
	int rbit;
	while((n = n % wordlength() ) >0) {//比较符 优先级大于 赋值 
		rbit = ~(~0 << n) & x ;
		rbit = rbit <<(wordlength() - n);
		
		x = x >> n; 
		x = x | rbit; 
	} 
	return x; 
}
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;
	
	for(i =1; (v = v>>1) >0; i++)
	 ;
	
	return i;
 } 
 
 

 
