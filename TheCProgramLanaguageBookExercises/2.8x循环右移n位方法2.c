#include<stdio.h>
 
/* ѭ������nλ,������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        #include<stdio.h>
 
/* ѭ������nλ */ 
/* һ��������ɣ��� λ����� */ 
/*
	1.while x ����n�ı���  nȡx%n���� 
		2.rbit= ��������nλ 
		3.rbit=���� length-n λ    �Ƶ���� 
		4.x λ�� rbit
	1.while
	
	5. ���� x  
		 
*/
main() { 
}
unsigned  rightrott(signed x, int n)
{
	int wordlength(void);
	int rbit;
	while((n = n % wordlength() ) >0) {//�ȽϷ� ���ȼ����� ��ֵ 
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
 
 

 
