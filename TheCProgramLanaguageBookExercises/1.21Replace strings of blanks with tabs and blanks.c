#include<stdio.h>

#define TABINC 8   /*Tab increment size  */ 

/* replace strings of blanks with tabs and blanks */
/*
	��\t�滻�ո�ԭ����� 
	eg:12345678        1234567        123456  12345   1234 
	�����ַ������ж��Ƿ�ո�
		�ո�
			1.�������Ʊ�λ����¼blanks number 
			2. �����Ʊ�λ��ת��\t����¼ tabs number��blanks number ��0   
		���ո�
			1.���\t  
			2.���blanks
				 1.��\t,blanks number��0���������
				 2.��\t�����blanks
			3.���  �����ַ�
			4.����\t,�����Ʊ�λ��������ȡ
			5.����\n��pos=0���������� 
*/
/*
	if (c == '\n')
		pos = 0;
	else if (c == '\t')
		pos = pos - 1 + (TABINC-(pos - 1)%TABINC)); 	
�ȼۣ�
if (c == '\t')
	pos = pos - 1 + (TABINC-(pos - 1)%TABINC)); 
if (c == '\n')
	pos = 0;
*/ 
/*
	nb = TABINC - (pos - 1 ) % TABINC;
	��Ҫ����Ŀո�λ= һ�����λ  -��ȥ���Ʊ����ĳ��ȣ������Ʊ�λ���õ�����    ����
	��Ҫ����Ŀո�λ= һ�����λ  -  ��ռ�ĳ��� 
*/
	 
main()
{
	printf("please input !�س��жϣ�Ctrl + z ����getchar����\n�����г��Ȱ������з�\\n\n");
	printf("��ӡ������:��\\n,���Ի���ֿ���\n");
	printf("������س�,ֻ�л��з�\\n,����=1 ������;\n");
	printf("���ַ�+\\n����س�,,����=2ʱ��ʼ����\n\n"); 
	printf("ע��:-------------------------\n");
	printf("-----���з�--�����ʾΪ--����>\n");
	printf("ע��:-------------------------\n");
	printf("aaaaaaaa--------========--------========--------========-----------------\n");
	int c, nb, nt, pos;/*c��ǰ�ַ��� nb�ո������� nt�Ʊ��������pos�ַ�λ�ã�*/
	 
	
	nb = 0;/* number of blanks necessary */ 
	nt = 0;/* number of tabs  necessary */ 
	for(pos = 1; (c = getchar()) != EOF;++pos)
		if(c == ' ') { 
			if(pos %TABINC != 0)
				++nb;                       /*increment # of blanks */  
			else {
				++ nt;                     /* one more tabs */
				nb = 0;                    /* reset of blanks */ 
			} 
		} else {
			for( ; nt > 0; --nt)
				putchar('\t');                /*output tabs(s) */
			
			if (c == '\t')					/* forget the blanks(s) */
				nb = 0;
			else
				for ( ;nb > 0; --nb)		
					putchar(' ');			/* output blanks */
			
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos - 1 + (TABINC-(pos - 1)%TABINC); 		
		}
	printf("aaaaaaaa--------========--------========--------========-----------------\n");
 
} 

