#include<stdio.h>

int any(char s1[],char s2[]);
int anyy(char s1[],char s2[]);
main()
{
	char s1[10] ={1,2,3,4,5,6,7,8,9,0};
	char s2[4]  ={5,6,7};
	printf("��ʼλ��Ϊ0\n");
	printf("����һ���α�ԭ����any()��� %d\n", any(s1,s2));
	printf("����������һ�������޸ĺ������ %d\n", anyy(s1,s2));

}

int anyy(char s1[],char s2[])/*forѰ�Ҳ����ڣ���������ڣ���� -1����������ڲ����ڣ����i */ 
{
	int i, j;
	
	for(i = 0;s1[i] != '\0'; i++) {
		
		for (j = 0;s2[j] != '\0' &&s2[j] != s1[i]; j++)
			;
			
		if (s2[j] != '\0')    /*end of string -on match */
			return i ;
	
	}
	if (s1[i] == '\0')    /*end of string -on match */
		return -1 ;
}

int any(char s1[],char s2[])/*Ѱ�Ҵ��ڣ�putout--i���Ҳ���putout-1*/ 
{
	int i, j;
	
	for(i = 0;s1[i] != '\0'; i++) {
		
		for (j = 0;s2[j] != '\0' ; j++)			
			if (s2[j] == s1[i])    
				return i ;	
	}
	return -1 ;
}

