#include<stdio.h>


/*使用条件表达式，将大写字母转换为小写字母 */
/*expr1 ? expr2  : expr3 */
/*判断      真2    假3   */ 
main(){
	char c ;
	c = getchar();
	
	printf("输入：%c输出：%c\n", c, lower(c));
}
int lower(int c) 
{
	
	return   c >= 'A' && c <= 'Z'    ?       c + 'a' -'A'    :      c ;
}
