#include<stdio.h>

/* datermine rangse of types */
/*
	max�����ƿ���ͨ��min0 ��λȡ���õ�����ֵ��������
	�޷�������������λ������ �з�����
/*
	|--(char)((unsigned char) ~0 >> 1)
	|1.-----------------------~0-----------0�ĸ�������λ��1
	|2.-------(unsigned char) ~0-----------תΪunsigned char����
	|3.------((unsigned char) ~0 >> 1)-----����һλ����������λ
	|4.(char)((unsigned char) ~0 >> 1)-----ת��Ϊchar ����
	|--���Ĳ����� �õ��� signed���� �ַ�������ֵ
*/

main()
{
	/*signed types */
	printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1)   );
	printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1)    );

	printf("signed short min = %d\n", -(short)((unsigned short) ~0 >> 1)    );
	printf("signed short max = ");
	printf(" %d\n",  (short)((unsigned short) ~0 >> 1)    );

	printf("signed int min = ");
	printf(" %d\n", -(int)((unsigned int) ~0 >> 1)    );
	printf("signed int max = ");
	printf(" %d\n",  (int)((unsigned int) ~0 >> 1)    );

	printf("signed long min = ");
	printf(" %ld\n", -(long)((unsigned long) ~0 >> 1)    );
	printf("signed long max = ");
	printf(" %ld\n",  (long)((unsigned long) ~0 >> 1)    );


	/* unsigned types */
	printf("unsigned char max = %u\n", (unsigned char) ~0 >> 1   );
	printf("unsigned short max = %u\n", (unsigned short) ~0 >> 1   );
	printf("unsigned int max = %u\n", (unsigned int) ~0 >> 1   );
	printf("unsigned long max = %lu\n", (unsigned int) ~0 >> 1   );

}
