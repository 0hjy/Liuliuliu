#include<stdio.h>
/*output a words histgram*/
/*��ӡ���뵥�ʳ��ȵ�ֱ��ͼ*/
/*
	��һ��������ʾ �±��ʾ���ʳ��ȣ� ���ݱ�ʾ���ʸ���	
	ֱ��ͼ
		���� Ϊ ���ʳ���1--MAXWORD
	 	���� Ϊ  ��Ӧ���ȵ��ʵĸ��� 1--MAHIST 
*/ 

#define MAXHIST 15 /* max length of histgram ֱ��ͼ���� */
#define MAXWORD 11 /* max length of word    ����max����0--10 11�� */ 
#define IN       1 /* inside of a word */
#define OUT      0 /* outside of a word */

/* print horizontal histgram. */
/*windows����ʽEnter��ֹ�������Ҫ����Ctrl+z��������־���ٴ�Enter��*/  
//������� aa aaaa aaaa aaa aaa aaa 
//aaaaa aaaaaaaaaaaaaaaaaaaa vbbbbbbbbbbbbbbbbbbbbb
main(){
	printf("please input ! \n");
	int c, i, nc, state; //c��ʾ��ǰ���ʣ� nc  ��ǰ���ʳ��� 
	int len;          /* length of each ber ******���� */
	int maxvalue;     /* maxmum value for wl[] */
	int ovflow;       /* number of overflow words */
	int wl[MAXWORD];  /* word length counters */
	
	state = OUT;
	nc = 0;
	ovflow = 0;
	
	//��ʼ���� wl[0] = 0 ������ 
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
		
	//����	
	while ((c= getchar() )!= EOF) { 
	    
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD)
					++wl[nc];//�������� 
			} else
					++ovflow; //���ʳ��� 
		nc = 0;//������� 
		}  else if (state == OUT) {
			state = IN;
			nc = 1;        /* begining of a new word ��һ�ζ��볤��=1*/ 
		} else {
			++nc;		   /* inside of a word */
		}
			 
	} 
	
	//�ҳ��������ֵ ���������� 
	maxvalue = 0; 
	for(i = 1; i < MAXWORD; ++i)// wl[0] = 0 ������  ����i��1��ʼ
		if(wl[i] > maxvalue )
			maxvalue = wl[i];
	printf("*******ˮƽֱ��ͼ*******\n");
	printf("���ʳ���--ֵ : \n");//һ�����ֵ�����������λ		
	for(i = 1; i < MAXWORD; ++i) {
		printf("%7d-%4d : ", i, wl[i]);//output head. ����i������wl[i] 
		if(wl[i] > 0) {
			if((len = wl[i] * MAXHIST / maxvalue) <= 0) //����**���ȣ� �ٷֱ�*��󳤶�maxhist 
				len = 1;//����һ��*��һ���� 
		} else
			len = 0;
		while (len > 0) {
			putchar ('*');//output *
			--len;
		}
		putchar('\n');
	}
	if(ovflow > 0)
			printf("T"); 
		printf("There are %d words length >= %d\n", ovflow, MAXWORD);

} 
