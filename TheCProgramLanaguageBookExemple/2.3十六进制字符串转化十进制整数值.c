#include<stdio.h>
#define YES    1
#define NO     0

/* ʮ�����Ƶ��ַ���ת��Ϊ ����ֵ�� */ 
/*
	1.����Ϊ16�����ַ�����ȥ��0x ����0X 
	2.forѭ�����Ӹ�λ����λ����ÿһλ��Ӧ--ʮ����ֵ
		3.��λ����ʮ������ֵ 
		|-----n =       16 * n + hexdigit;------) 
		|ʮ������ֵ=  ��ֵ��1λ +  ������ֵ------
		���磻n=1��
			������һλ����nֵ��λ n= 1*16 
			�٣���һλ��ֵ 
	2.for	
*/
/* hoti: convert hexadecimal string to integer */
main(){
	
} 
int htoi(char s[])
{	
	int hexdigit;//��ǰλ����ֵ��
	int i;		//ѭ���� 
	int inhex;	//�ж��Ƿ���� 16������ 
	int n;		//��¼ 
	 
	i = 0;
	if(s[i] == '0') {/* skip optional 0x or  0X */
		++i;
		if(s[i] == 'x' || s[i] == 'X')
			++i;
	}
	
	n = 0;					/* integer value to be returned */
	inhex = YES;			/*assume valid hexadecimal digit */
	for(;inhex == YES; ++i) {
		if(s[i] >= '0'&& s[i] <= '9')
			hexdigit = s[i] - '0';
		else if(s[i] >= 'a'&& s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if(s[i] >= 'A'&& s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;      /* not a valid hexadecimal digit */ 
		
		if(inhex == YES) 
			n = 16 * n + hexdigit;	/*-----get 10 jingzhi-value--*/ 	
	}
	return n;		 
}
