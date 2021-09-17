#include<stdio.h>
/*print Celsius-Fehrenheit table in reverse order
  for celsius =  300, ...,20, 0; floating-point version*/
//摄氏转化华氏 
float fehr(float celsius) {
	float fehr;
	fehr = (9.0*celsius) / 5.0 + 32.0;
	return fehr;
}
main(){
	float celsius;
	int lower, upper, step;
	
	lower = 0;/* lower limit of temperature table*/
	upper = 300;/*upper limit*/
	step = 20;/*step size*/
	
	//printf("please imput celsius!\n");
	//scanf("%f",&celsius);
	
	printf("celsius\t fahr\n");
	
	//for循环 条件用封号;隔离
	//格式规范字符 数字 完了要空格； 
	for(celsius = 300; celsius >= 0; celsius = celsius - 20){
		printf("%3.0f\t%6.1f\n", celsius, fehr(celsius));
	}

}


