#include<stdio.h>

/* �ȼ�ת��Ϊ��ʹ��&& ��||����� */
  
/*
main()
{
	int i, lim, c;
	
	for(i = 0,i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i]  = c;	
}

*/

main()
{
	enum loop{NO, YES};
	enum loop okloop = YES;
	
	int = 0;
	while(okloop == YES) {
		if(i >= lim - 1)////��������Ϊ����ѭ���ж� 
			okloop = NO;////
		else if ((c = getchar()) == '\n')////
			okloop = NO;////
		else if (c = EOF)////
			okloop = NO;////
		else {
			s[i] =c;
			++i;
		}
	}
}
