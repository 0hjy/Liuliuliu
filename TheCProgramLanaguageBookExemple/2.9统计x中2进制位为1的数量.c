#include<stdio.h>

/* bitcount: count 1 bits in x - faster version */
/* 统计x中二进制位为1的数量 */
/* bitcount()利用x&(x-1)可以将x最右端的1置0. */
/*
	1.for  x！=0时，x&(x-1)循环去1
		2.i统计次数
	1.for

	3.返回i 

*/
main()
{
}
int bitcount( unsigned c)
{
	int i;
	for( i = 0; c !=0; c &= (c-1)) {
		i++;
	}
	return i;
}


/* bitcountt()利用x&01可以将x最右端的1置0. */
/*
	1.for  x！=0时，
		2.if x&01 判断最右位是否为1
			为1时：b统计次数+1
	1.for 循环结束后，x右移1位。
	3.返回b

*/
int bitcountt( unsigned c)
{
	int n;

	for(n=0;c != 0;c >>= 1) {
		if(c&01)
			n++;
	}
	return n;
 }
