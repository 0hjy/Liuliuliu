#include<stdio.h>

#define MAXLINE 1000   /*����������е���󳤶� */
 

int getline(char line[], int maxline);
void copy(char to[], char form[]);
 
/* print longest input line. */
/* ��ӡ���ⳤ�������г���+������. */
// �����г��Ȱ������з� 
/* ��ӡ�������. */
main()
{
	printf("please input !�س��жϣ�Ctrl + z ����getchar����\n�����г��Ȱ������з�\\n\n");
	printf("��ӡ������:��\\n,���Ի���ֿ���\n");
	printf("������س�,ֻ�л��з�\\n,����=1 ������;\n");
	printf("���ַ�+\\n����س�,,����=2ʱ��ʼ����\n\n"); 
	printf("ע��:-------------------------\n");
	printf("-----���з�--�����ʾΪ--����>\n");
	printf("ע��:-------------------------\n");
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;//��ʼ��
	while ((len = getline(line,MAXLINE)) > 0) {//getline(����ȡ�У����� line[]
		printf("��ǰ�г���:%d  \n��ǰ������:%s", len, line);
		if(len > max) {
			max = len;
			copy(longest, line);  //copy()//����longest[]				
		}
		printf("\n��ǰ��󳤶������г���:");
		printf("%d\n\n\n", max) ;
}
	
	if(max > 0) 
		printf("�����������:%s  \n����:%d \n����:���з�\\n", longest, max); //��� 
		
	return 0;
} 
int getline(char s[], int lim) 
{//����ǰ��ÿ���ַ�   and limit length,,��\n�ﵽlimit-1 ����\n \0 ����
 
	int c, i, j;
	//j��������  �ַ�\n \0  
	//i��������   �ַ�\n 
	//i=���鳤�� ��\N��\0 ;   j=�ַ���=��ռ�ֽ���  
	j = 0; 
	for(i = 0; (c=getchar()) != EOF && c != '\n'; ++i) //��ֵ�س� i=0 
		if(i < lim-2) {
			s[j] = c;
			++j;
		}
		if(c == '\n') {
			s[j] = c;
			++j;
			++i;
		}
		
	s[j] = '\0';
	return i;
	
} 
void copy(char to[], char form[]) 
{//���ζ����ַ�����\0�⡣ 
	int i;
	i = 0;
	while((to[i] = form[i]) != '0')
		++i; 
}


