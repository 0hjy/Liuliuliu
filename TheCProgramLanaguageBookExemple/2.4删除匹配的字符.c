#include<stdio.h>

/*
	------Ŀ�ģ�����һ���µ�s1[]����-------- 
	1.---for-i++ ����s1[]һλ���ж��Ƿ���Դ��� 
			2.---for-j++��s2[]��s1[i]��ͬ���ַ� ���Ҳ���������	
					-----�ҵ���----����  
					---δ�ҵ���s1[i]������s1[k], k+1 �ж���һλ 
	--------2.----for
			4.���� �ַ����ս��\0 
	1.---for 
*/

/*squeeze: delete each char in s1 which is in s2 */
main(){
}
void squeeze(char s1[], char s2[] )
{
	int i, j, k;//ɾ����������±��䣬�����������±�k 
	
	for(i = k = 0;s1[i] != '\0'; i++) {
		
		for (j = 0;s2[j] != '\0' &&s2[j] != s1[i]; j++)
			;
			
		if (s2[j] == '\0')    /*end of string -on match */
			s1[k++] = s1[i];
	
	}
	s1[k] = '\0'; 	          /* input the end of characters */
} 

