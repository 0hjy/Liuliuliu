#include<stdio.h>

int brace, brack, paren; 

	 
void in_quote(int c);
void in_rcomment(void);
void search(int c);
/*测试用例
*/ 
 /* 全局变量(无static)初始值为0. */
 
main()
{

	int c;
	extern int brace, brack, paren; /* 全局变量(无static)初始值为0. */
	if (brace == 0) 
		printf("{---}成对\n");
	if (brack == 0) 
		printf("[---]成对\n");
	if (paren == 0) 
		printf("(---)成对\n"); 
	printf("%d%d%d", brace, brack, paren); 
	while((c = getchar()) != EOF) {
		if (c == '/') {
			if((c = getchar()) == '*')
				in_rcomment();/*备注内不计*/ 
			else 
				search(c);
		} else if (c == '\''|| c == '"') 
			in_quote(c);/*引号内不计*/
		else
			search(c);
		
		if (brace < 0) {
			printf("Unbalanced braces缺少---{\n");
			brace = 0;
		} else if (brack < 0) {
			printf("Unbalanced brackets缺少---[\n");
			brack = 0;
		} else if (paren < 0) {
			printf("Unbalanced parentheses缺少---(\n");
			paren = 0;
		}
	}
		
	if (brace > 0) 
		printf("Unbalanced braces缺少---}\n");
	if (brack > 0) 
		printf("Unbalanced brackets缺少---]\n");
	if (paren > 0) 
		printf("Unbalanced parentheses缺少---)\n");
	
	if (brace == 0) 
		printf("{---}成对\n");
	if (brack == 0) 
		printf("[---]成对\n");
	if (paren == 0) 
		printf("(---)成对\n");

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
	
	while((d = getchar()) != c) /*search for end 1.不是" " '  '内容未结束，输出内容*/
		if (d == '\\')  /*到反斜杠\, 接着输出\下一位，*/
			getchar();  /* 遇避免构成的转义字符\"按输出结束引号"--"处理 */ 
	

} 

