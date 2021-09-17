#include<stdio.h>
#define MAXCOL 10  /*maxinum column of input */ 
#define TABINC 8   /*Tab increment size  */ 

char line[MAXCOL];
int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */
/*
	���ַ�����*******************************************************
		1.����line[] 
		2.����\t��ִ��exptab(pos)---->תΪblanks���롣
		3.����\n, ִ��printl(pos);--->���һ���ַ�����pos��0. 
		4.����TABINC
			5.findblnk() ���ҿո񷵻���һλposition���Ҳ����ͷ���TABINC	  
			6.printl()  
			7.newpos()  pos��0;������������pos��(����) 
		4.����TABINC 
	���ַ����� ******************************************************
	
	printl(pos);
		���һ�� 
	exptab(pos);
		\t����>blanks;  
		û����return pos��
   		������ִ��printl(),return 0; 
	findblnk(); 
		�ҵ�ǰ��ǰһ���ո� ������һ�����ʷ����У� 
		�Ҳ��������� 
	newpos();***
		����Ԥ���ַ�����pos��¼�ַ��� 
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

	int c, pos;/*c��ǰ�ַ���pos�ַ�λ�ã�*/
	 
	pos = 0;
	while ((c =getchar()) != EOF) {
		line[pos] = c;
		if (c == '\t')
			pos = exptab(pos);
		else if (c == '\n') {
			printl(pos);
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = findblnk(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}
}

/* printl: print line until pos column */
void printl(int pos)//���line[0]-->line[pos-1]  \n�� 
{
	int i;
	for(i = 0; i< pos; ++i)
		putchar(line[i]);
	if(pos > 0)					/*any chars printed?????????????????*/
		putchar('\n');
}

/* exptab: expand tab into blanks */
int exptab(int pos)
{
	line[pos] =' ';              /*tab is at least one blank */
	for (++pos; pos < MAXCOL && pos % TABINC != 0;++pos )
		line[pos] = ' ';		
	if  (pos < MAXCOL)          /* room left in current line */
		return pos;
	else {						/* current line is full */ 
		printl(pos);             
		return 0;               /* reset current position */ 
	}
}

/*findblnk: find blanks's position */
int findblnk(int pos)
{
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if(pos == 0)                           /* no blanks in the line ? */ 
		return MAXCOL; 
	else								   /* at least one blank      */
		return pos+1;					   /* position after the blank */ 
}

/* newpos: rearrange line with new position */ 
int newpos(int pos)
{
	int i, j;
	
	if (pos <= 0 || pos >= MAXCOL) 
		return 0;                           /* nothing to rerrange */
	else {
		i = 0;
		for (j = pos; j < MAXCOL; ++j) {
			line[i] = line[j];
			++i;//++jȴ 
		}
		return i;                           /* new position in line */ 
	}
}

