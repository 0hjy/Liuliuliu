#include<stdio.h>

#define LOWER 0  // LOWER ȡ�� 0  ��д 
/*
	���ų��� ȡ������������һ����ϰ�� 
	ͨ�� ��д	
*/

//output EOF value.
main(){
	int c;  
	while(c = getchar() != EOF){
		printf("%d\n", c);
	printf("%d - at EOF\n", c);
	}

}
