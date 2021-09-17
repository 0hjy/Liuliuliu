#include<stdio.h>
#include<stdlib.h>

#define MAXOP    100
#define NUMBER    '0' // 如果是数字类型的 返回值 NUMBER
/*逆波兰式计算器(后缀表达式计算器) */
/*main
	读取输入字符getop()
		判断数据类型switch()
		入栈push()
		出栈pop()
		计算
		入栈push()
		\n输出结果
	return 0
*/

int getop(char []);//判断数组中下个字符的类型
void push(double);//入栈
double pop(void);//出栈并返回栈顶的值
int main()
{
	int type;//字符的类型
	double op2;//栈顶的值
	char s[MAXOP];//计算式

	while( (type = getop(s)) != EOF ) {
		switch(type) {
			case NUMBER://数值类
				//atof(c) 字符串转换为double型
				push(atof(s));//?????????
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
			//两个pop()执行顺序未知，所以/-需要变量op2暂存。
			case '-':
				op2 = pop();
				push(pop() - op2);
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push( pop() / op2 );
				else
					printf("error:zero divisor，输入错误，0不能做除数\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)//fmod？？？？？？？？？？？
					//fmod(x,y)求x/y的浮点余数符号与x相同如y=0 看具体实现。
					push( fmod( pop(), op2 );

				else
					printf("error:zero divisor\n");
					printf("错误：0不能做除数\n");
				break;
			case '\n':
				//\t制表， \n换行
				printf("\t%.8g\n", pop() );//制表换行
				break;
			default:
				printf("error: unknown command %s\n", s );
				break;
		}
	}
	return 0;
}

/* push()函数把f压入栈中 */
void push(doube f)
{
	if(sp < MAXVAL)
		VAL[sp++] = f;
	else
		printf("error: stack full, can not push%g\n", f);///
}

double pop(void)
{
	if (sp >0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER    '0'

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int c, i;
	while( (s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if(isdigit(c) && c != '.' && c != '-')
		return c;
	if(c == '-')
		if(isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else{
			if(c != EOF)
				ungetch(c);
			return '-';
		}
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch() ) )
			;
	if (c == '.')
	{
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}
