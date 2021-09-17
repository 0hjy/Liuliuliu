#include<stdio.h>

#define TABINC 8   /*Tab increment size  */ 

/* replace strings of blanks with tabs and blanks */
/*
	用\t替换空格，原样输出 
	eg:12345678        1234567        123456  12345   1234 
	读入字符串，判断是否空格
		空格
			1.不满足制表位，记录blanks number 
			2. 满足制表位，转换\t，记录 tabs number，blanks number 归0   
		不空格
			1.输出\t  
			2.输出blanks
				 1.是\t,blanks number归0，不输出了
				 2.不\t，输出blanks
			3.输出  其他字符
			4.遇到\t,计算制表补位，继续读取
			5.遇到\n，pos=0，结束程序 
*/
/*
	if (c == '\n')
		pos = 0;
	else if (c == '\t')
		pos = pos - 1 + (TABINC-(pos - 1)%TABINC)); 	
等价：
if (c == '\t')
	pos = pos - 1 + (TABINC-(pos - 1)%TABINC)); 
if (c == '\n')
	pos = 0;
*/ 
/*
	nb = TABINC - (pos - 1 ) % TABINC;
	需要补充的空格位= 一个表格单位  -（去除制表符后的长度）除以制表单位所得的余数    即：
	需要补充的空格位= 一个表格单位  -  已占的长度 
*/
	 
main()
{
	printf("please input !回车中断，Ctrl + z 结束getchar（）\n输入行长度包含换行符\\n\n");
	printf("打印输入行:带\\n,所以会出现空行\n");
	printf("无输入回车,只有换行符\\n,长度=1 不计入;\n");
	printf("单字符+\\n输入回车,,长度=2时开始计入\n\n"); 
	printf("注释:-------------------------\n");
	printf("-----换行符--输出显示为--空行>\n");
	printf("注释:-------------------------\n");
	printf("aaaaaaaa--------========--------========--------========-----------------\n");
	int c, nb, nt, pos;/*c当前字符； nb空格数量； nt制表符数量；pos字符位置；*/
	 
	
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

