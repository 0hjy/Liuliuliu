#include<stdio.h>

void rcomment(int c);
void in_rcomment(void);
void in_rcommentt(void);
void echo_quote(int c);
/*只输入/+* 不输入*+/，程序一直在rcomment()等待。*/ 
/* remove all comments from a valid C program */
/* C 语言中 不允许 注释嵌套，遇到* 和/ 就是注释结束  */ 

/*	逐字符读入**不为空时继续*****************************************************
		1. rcomment()
			2.if读到/反斜杠，
				3.if下一字符读到*，注释开始，转入in_rcomment（） 
					4.else if下一字符还是/反斜杠，转入in_rcommentt（） 
						5.else 照常输出俩字符-------------> 
			6.else if 读到单引号 或者双引号	  
				7.执行echo_quote()  
			8.else 其他字符正常输出 ------------>
		1.rcomment()--end
	逐字符读入 ******************************************************
in_rcomment(): run-->找到注释终结符*+/， 输出后面内容 
in_rcommentt():run-->找到注释终结符\n， 输出后面内容 
 echo_quote(): 原样输出单双引号内的东西，出现注释符也不判断为注释，照常输出。
	  				引号内出现\" 判断为转义字符 正确输出，不判断为“内容终止 
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
	while((d = getchar()) != c) {  /*search for end 1.引号内未结束，输出内容*/
		putchar(d);
		if (d  =='\\')             /* 遇到\, 接着输出\下一位，避免把\"构成的转义字符\"输出按结束引号"--"处理 */ 
			putchar(getchar());   /*ignore escape seq */
	} 
	putchar(d);
}

