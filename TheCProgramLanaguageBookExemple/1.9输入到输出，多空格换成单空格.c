#include<stdio.h>

#define NONBLANK 'a'

/*replace string of blanks with a single blank.*/
/*
�жϵ�ǰc�Ƿ��
	�ǿ����
	�գ��ж�ǰһ���ǲ��ǿ�
		�ǿգ������
��ѭ����һ��ִ��--------> 
*/
main(){
	
	int c, lastc;
	
	lastc = NONBLANK;
	while(c = getchar() != EOF){
		if(c != ' ')
			putchar(c);
		if(c == ' ')
			if(lastc != ' ')
				putchar(c);
		lastc = c;
	}
	//����������ʱ������Ϊ��һ�жϵ�����֮һʱ������|| OR ��ʡ�ж� 
	// ��Ϊ��һ��������Ͳ��жϵڶ�������
	
	//aother  
	while(c = getchar() != EOF){
		if(c != ' ' || lastc != ' ') // if(c != ' ' || c == ' ' lastc != ' ')
			putchar(c);
		lastc = c;
	}
} 
