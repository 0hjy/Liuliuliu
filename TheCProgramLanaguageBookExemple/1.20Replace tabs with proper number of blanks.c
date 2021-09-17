#include<stdio.h>

#define TABINC 8   /*Tab increment size  */ 

/* replace tabs with the proper number of blanks */
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
	
	int c, nb, pos;/*c当前字符； nb数量number； pos字符位置；*/
	 
	
	nb = 0;/* number of blanks necessary */ //初始化 
	pos = 1;/* position of character*///初始化 
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

