#include<stdio.h>
main(){
	int fahr, celsius;//定义变量必须  , 分隔 
	int lower, upper, step;
	//printf("please imput !\n");
	//scanf("%d",&fahr);
	step=20;
	lower=0;
	upper=300;
	
	fahr=lower;
	printf("this is a from.");
	while(fahr <= upper){
		celsius = 5*(fahr-32)/9;
		printf("%d\t%d\n",fahr, celsius);
		fahr = fahr + step;
	}
	
	
}
