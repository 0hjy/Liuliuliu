#include<stdio.h>
#define YES    1
#define NO     0

/* 十六进制的字符串转换为 整数值。 */ 
/*
	1.参数为16进制字符串，去掉0x 或者0X 
	2.for循环，从高位到低位计算每一位对应--十进制值
		3.按位计算十进制总值 
		|-----n =       16 * n + hexdigit;------) 
		|十进制总值=  总值进1位 +  本次数值------
		例如；n=1，
			存在下一位，则n值进位 n= 1*16 
			再＋下一位的值 
	2.for	
*/
/* hoti: convert hexadecimal string to integer */
main(){
	
} 
int htoi(char s[])
{	
	int hexdigit;//当前位整数值，
	int i;		//循环用 
	int inhex;	//判断是否符合 16进制数 
	int n;		//记录 
	 
	i = 0;
	if(s[i] == '0') {/* skip optional 0x or  0X */
		++i;
		if(s[i] == 'x' || s[i] == 'X')
			++i;
	}
	
	n = 0;					/* integer value to be returned */
	inhex = YES;			/*assume valid hexadecimal digit */
	for(;inhex == YES; ++i) {
		if(s[i] >= '0'&& s[i] <= '9')
			hexdigit = s[i] - '0';
		else if(s[i] >= 'a'&& s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if(s[i] >= 'A'&& s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;      /* not a valid hexadecimal digit */ 
		
		if(inhex == YES) 
			n = 16 * n + hexdigit;	/*-----get 10 jingzhi-value--*/ 	
	}
	return n;		 
}
