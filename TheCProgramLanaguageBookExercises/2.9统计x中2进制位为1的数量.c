#include<stdio.h>

/* bitcount: count 1 bits in x - faster version */
/* ͳ��x�ж�����λΪ1������ */
/* bitcount()����x&(x-1)���Խ�x���Ҷ˵�1��0. */
/*
	1.for  x��=0ʱ��x&(x-1)ѭ��ȥ1
		2.iͳ�ƴ���
	1.for

	3.����i 

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


/* bitcountt()����x&01���Խ�x���Ҷ˵�1��0. */
/*
	1.for  x��=0ʱ��
		2.if x&01 �ж�����λ�Ƿ�Ϊ1
			Ϊ1ʱ��bͳ�ƴ���+1
	1.for ѭ��������x����1λ��
	3.����b

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
