#include<stdio.h>


/*ʹ���������ʽ������д��ĸת��ΪСд��ĸ */
/*expr1 ? expr2  : expr3 */
/*�ж�      ��2    ��3   */ 
main(){
	char c ;
	c = getchar();
	
	printf("���룺%c�����%c\n", c, lower(c));
}
int lower(int c) 
{
	
	return   c >= 'A' && c <= 'Z'    ?       c + 'a' -'A'    :      c ;
}
