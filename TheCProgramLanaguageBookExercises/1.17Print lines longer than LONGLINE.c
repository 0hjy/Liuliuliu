#include<stdio.h>

#define MAXLINE  1000   /*maxinum input line size */
#define LONGLINE   10

int getline(char line[], int maxline);
 
/* print lines longer than LONGLINE. */
/* ��ӡ���ⳤ�������г���+������. */
// �����г��Ȱ������з� 
/* ��ӡ�������. */
main()
{
	printf("please input !�س�ȷ�ϣ�Ctrl + z ����getchar����\n�����г��Ȱ������з�\\n\n");
	printf("��ӡ������:��\\n,���Ի���ֿ���\n");
	printf("ע��:-------------------------\n");
	printf("-----���з�--�����ʾΪ--����>\n");
	printf("ע��:-------------------------\n");
	printf("-----------�����г���LONGLINE,print lines--------------\n");
	printf("-----------LONGLINE=%d--------------\n", LONGLINE);
	int len; 
	char line[MAXLINE];
	
	while ((len = getline(line,MAXLINE)) > 0) {//getline(����ȡ�У����� line[]
		
		if(len > LONGLINE) {			
			printf("��ǰ�г���:%d  \n��ǰ������:%s\n", len,line); 
			printf("please input next lines"); 				
		}				

	}				
	return 0;
} 

int getline(char s[], int lim) 
{
 
	int c, i, j;
	 
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



