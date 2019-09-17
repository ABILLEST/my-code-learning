#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100	//操作数或运算符的最大长度
#define NUMBER '0'	//标识找到一个数
#define MAXVAL 100	//栈val的最大深度
#define BUFSIZE 100	//缓冲区大小 
 
int getop(char []);
void push(double);
double pop (void);
int getch(void);
//void ungetch(int);
void ungets(char *);
void clear(void);

int sp = 0;			//下一个空闲栈位置
double val[MAXVAL];	//值栈 
char buf[BUFSIZE];	//用于ungetch函数的缓冲区
int bufp = 0;		//buf中的下一个空闲位置 

//逆波兰运算器(用一个静态变量代替getch函数的作用)
int main()
{
	int type,near,i,var = 0.0;
	double op1,op2,v;
	char s[MAXOP];
	double variable[26];
	const double pi=acos(-1.0);
	
	
	printf("注意：两个操作数之间用空格隔开\n");
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;
	while ((type = getop(s)) != EOF){	//判断下一个位置的类型 
		switch (type){
			case NUMBER:  
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();//被减数 
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)//分母不为零 
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			case 's':		//使用sin()
				push(sin(pop()*pi/180));
				break;
			case 'e':
				push(exp(pop()));
				break; 
			case '?':		//帮助信息 helping
				 printf("\n帮助信息：\np	打印栈顶元素并压入堆栈\nc	清空栈\nd	复制栈顶元素\nx	交换栈顶元素\n");
			case 'p':		//打印栈顶元素并压入堆栈 print top element of the stack
				op2 = pop();
				printf("\t%.8g\n",op2);
				push(op2);
				break;
			case 'c':		//清空栈 clear the stack
				clear();
				break;
			case 'd':		//复制栈顶元素 duplicate top elem. of the stack 
				 op2 = pop();
				 push(op2);
				 push(op2);
				 break;
			case 'x':		//交换栈顶元素 swap the top two elems.
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case '='://给变量赋值 
				pop();
				if (var >= 'A' && var <= 'Z'){
					variable[var - 'A'] = pop();
					//printf("%c <- %ld\n",var,variable[var - 'A']);
				}
					
				else
					printf("error: no variable name\n");
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if (type >= 'a' && type <= 'z')
					if (type == 'v')
						push(v);
					else
						printf("PLEASE USE UPPER LETTER.\n");
				else
					printf("error: unknown command %s.\n",s);
				break;
		};
		var = type;
	}
	return 0;
 } 
 
//push函数：把f压入到值栈中
void push(double f)
{
 	if (sp < MAXVAL)
 		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n",f);
} 
  
//pop函数：弹出并返回栈顶的值
double pop(void)
{
	if (sp > 0)
		return val[--sp];	//倒序弹出的是栈顶值 
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
} 
   
//getop函数：获取下一个运算符或数值操作数
int getop(char s[])
{
	int i, c;
	static int lastc;//保存最后一个被读入的字符
	
	if (lastc == 0)
		c = getch();
	else{
		c = lastc;
		lastc = 0;
	} 
	while ((s[0] = c)== ' ' || c == '\t')//只有处理完当前字符才需要读入新字符 
		c = getch();
	s[1] = '\0';		//???
	i = 0;				//重新写入s 
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	//不是数、小数点、负号 
	if (c == '-')	//最后getch会超前读入来确定'-'的意义
		if (isdigit(c = getch()) || c == '.')	//短路运算
			s[++i] = c;		//符号意义是负号 
		else {				//'-'后不紧跟数字
			if (c != EOF)
				lastc = c;
			return '-';		//减号
		}
	if (isdigit(c))			//收集整数部分 
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//收集小数部分 
	   while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';	
	if (c != EOF)
		lastc = c;
	return NUMBER;	//是数字
}
	
int getch(void)	//取一个字符（可能是压回的字符）
{
	return (bufp > 0) ? buf[--bufp] : getchar();//缓冲区中还有就从中取，否则用getchar()取 
}

/*
void ungetch(int c)	//把字符压回输入中
{
	if (bufp >= BUFSIZE)//缓冲区满 
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
*/

void ungets(char s[])//把整个字符串压回输入中 
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		ungetch(s[i]);
}

int printop(void)
{
	if (sp > 0)
		printf("the stack top is %lld",val[sp]);
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

//clear: clear the stack
void clear(void)
{
	sp = 0;
}
