#include<stdio.h>
#include<limits.h>

/* determine ranges of types */

main()
{
	/*	signed types */
	printf("signed char min  = %4d\n", SCHAR_MIN);
	printf("signed char max  = %4d\n\n", SCHAR_MAX);
	
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signed short max = %d\n\n", SHRT_MAX);
	
	printf("signed int min = %d\n", INT_MIN);
	printf("signed int max = %d\n\n", INT_MAX);
	
	printf("signed long min = %ld\n", LONG_MIN);
	printf("signed long max = %ld\n\n", LONG_MAX);
	
		printf("无符号只能定义char和整型:0-->max\n");
	printf("unsigned char max = %u\n", UCHAR_MAX);	
	printf("unsigned short max = %u\n", USHRT_MAX);	
	printf("unsigned int max = %u\n", UINT_MAX);
	printf("unsigned long max = %u\n", ULONG_MAX);
	
} 
