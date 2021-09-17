#include<stdio.h>
/*print Celsius-Fehrenheit table
  for celsius = 0, 20, ..., 300; floating-point version*/
//ÉãÊÏ×ª»¯»ªÊÏ 
main(){
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;/* lower limit of temperature table*/
	upper = 300;/*upper limit*/
	step = 20;/*step size*/
	
	printf("please imput celsius!\n");
	scanf("%f",&celsius);
	
	//celsius = lower;
	printf("celsius\tfahr\n");
	while(celsius <= upper){
		fahr =(9.0*celsius) / 5.0 + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

