#include<stdio.h>

void rcomment(int c);
void in_rcomment(void);
void in_rcommentt(void);
void echo_quote(int c);
/*ֻ����/+* ������*+/������һֱ��rcomment()�ȴ���*/ 
/* remove all comments from a valid C program */
/* C ������ ������ ע��Ƕ�ף�����* ��/ ����ע�ͽ���  */ 

/*	���ַ�����**��Ϊ��ʱ����*****************************************************
		1. rcomment()
			2.if����/��б�ܣ�
				3.if��һ�ַ�����*��ע�Ϳ�ʼ��ת��in_rcomment���� 
					4.else if��һ�ַ�����/��б�ܣ�ת��in_rcommentt���� 
						5.else �ճ�������ַ�-------------> 
			6.else if ���������� ����˫����	  
				7.ִ��echo_quote()  
			8.else �����ַ�������� ------------>
		1.rcomment()--end
	���ַ����� ******************************************************
in_rcomment(): run-->�ҵ�ע���ս��*+/�� ����������� 
in_rcommentt():run-->�ҵ�ע���ս��\n�� ����������� 
 echo_quote(): ԭ�������˫�����ڵĶ���������ע�ͷ�Ҳ���ж�Ϊע�ͣ��ճ������
	  				�����ڳ���\" �ж�Ϊת���ַ� ��ȷ��������ж�Ϊ��������ֹ 
*/	 
main()
{

	int c, d;
	
	while((c = getchar()) != EOF) {
		rcomment(c);
		
	}
		
	return 0;
}

/* rcomment: read each character,remove the comments */
void rcomment(int c)
{
	int d;

	
	if (c == '/') 
		if ((d = getchar()) == '*') {
		
			in_rcomment();     /* begining  comment */
			
		} else if (d == '/') {
			in_rcommentt();
			    			
		} else {
			putchar(c);        /* not a comment */
			putchar(d);
		}
	else if (c == '\'' || c == '"')		
		echo_quote(c);			/* quote begins */
	else
		putchar(c);	            /* not a comment */
		
}


/* in_rcomment: inside of a valid comment  */
void in_rcomment(void)   
{
	int c, d;
	c = getchar();        /* prev character */
	d = getchar();		/*curr character */
	while(c != '*' || d != '/') { /* search for end */
		c = d ;
		d = getchar();
	}
}

void in_rcommentt(void)   
{
	int c, d;
	c = getchar();        /* prev character */
	d = getchar();		/*curr character */
	while(d != '\n') { /* search for end */
		c = d ;
		d = getchar();
	}
}


/* echo_quote: echo characters within quotes  */
void echo_quote(int c)
{
	int d;
	
	putchar(c);
	while((d = getchar()) != c) {  /*search for end 1.������δ�������������*/
		putchar(d);
		if (d  =='\\')             /* ����\, �������\��һλ�������\"���ɵ�ת���ַ�\"�������������"--"���� */ 
			putchar(getchar());   /*ignore escape seq */
	} 
	putchar(d);
}

