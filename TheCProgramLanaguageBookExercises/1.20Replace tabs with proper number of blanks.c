#include<stdio.h>

#define TABINC 8   /*Tab increment size  */ 

/* replace tabs with the proper number of blanks */
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
	
	int c, nb, pos;/*c��ǰ�ַ��� nb����number�� pos�ַ�λ�ã�*/
	 
	
	nb = 0;/* number of blanks necessary */ //��ʼ�� 
	pos = 1;/* position of character*///��ʼ�� 
	while (getchar() != EOF ) {
		if(c =='\t') {/* tabs character*/
			nb = TABINC - (pos - 1 ) % TABINC;
			while( nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
			} else if(c == '\n') { /*nweline character*/
			putchar(c);
			pos = 1;
		} else {/*all other characters*/
			putchar(c);
			++pos;
		}
	}		 		
} 

