#include<stdio.h>

int a();
int b();

main()
{
	int i;
	printf("main()ִ��------>\n");
	if(a() ==0){
		printf("if(a() ==0)ִ��------>\n"); 
	}
	
	if(b() > 0){
		printf("if(b() > 0)ִ��------>\n"); 
	}
	if(c() > 0){
		printf("if(c() > 0)ִ��------>\n"); 
	}
}
int a() {
	return 0;
} 
int b() {
	return 1;
} 
int c() {
	int i;
	i=1;
	return i;
}
