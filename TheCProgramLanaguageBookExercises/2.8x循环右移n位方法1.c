#include<stdio.h>
 
/* ѭ������nλ */ 
/* һλһλ���� */ 
/*
	1.while һλһλ����
		2.rbit=��x���� ����-1λ��  ����������λ������λ�� 
		3.x����һλ
		4.x λ�� rbit
	1.while
	
	5. ���� x  
		 
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
 
 

