#include<stdio.h>

int brace, brack, paren; 

	 
void in_quote(int c);
void in_rcomment(void);
void search(int c);
/*��������
*/ 
 /* ȫ�ֱ���(��static)��ʼֵΪ0. */
 
main()
{

	int c;
	extern int brace, brack, paren; /* ȫ�ֱ���(��static)��ʼֵΪ0. */
	if (brace == 0) 
		printf("{---}�ɶ�\n");
	if (brack == 0) 
		printf("[---]�ɶ�\n");
	if (paren == 0) 
		printf("(---)�ɶ�\n"); 
	printf("%d%d%d", brace, brack, paren); 
	while((c = getchar()) != EOF) {
		if (c == '/') {
			if((c = getchar()) == '*')
				in_rcomment();/*��ע�ڲ���*/ 
			else 
				search(c);
		} else if (c == '\''|| c == '"') 
			in_quote(c);/*�����ڲ���*/
		else
			search(c);
		
		if (brace < 0) {
			printf("Unbalanced bracesȱ��---{\n");
			brace = 0;
		} else if (brack < 0) {
			printf("Unbalanced bracketsȱ��---[\n");
			brack = 0;
		} else if (paren < 0) {
			printf("Unbalanced parenthesesȱ��---(\n");
			paren = 0;
		}
	}
		
	if (brace > 0) 
		printf("Unbalanced bracesȱ��---}\n");
	if (brack > 0) 
		printf("Unbalanced bracketsȱ��---]\n");
	if (paren > 0) 
		printf("Unbalanced parenthesesȱ��---)\n");
	
	if (brace == 0) 
		printf("{---}�ɶ�\n");
	if (brack == 0) 
		printf("[---]�ɶ�\n");
	if (paren == 0) 
		printf("(---)�ɶ�\n");

}


void search(int c)
{
	extern int brace, brack, paren;
	
	if(c == '{')
		++brace;
	else if (c == '}')
		--brace;
	else if (c == '[')
		++brack;
	else if (c == ']')
		--brack;
	else if (c == '(')
		++paren;
	else if(c == ')')
		--paren;
 } 


/* rcomment: read each character,remove the comments */

/* in_rcomment: inside of a valid comment  */
void in_rcomment(void)   
{
	int c, d;
	c = getchar();        /* prev character */
	d = getchar();		/*curr character */

	while(c != '*' || d != '/') { /* search for end */
		c = d;
		d = getchar();
	}
	
}


void in_quote(int c)
{
	int d;
	
	while((d = getchar()) != c) /*search for end 1.����" " '  '����δ�������������*/
		if (d == '\\')  /*����б��\, �������\��һλ��*/
			getchar();  /* �����⹹�ɵ�ת���ַ�\"�������������"--"���� */ 
	

} 

