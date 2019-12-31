#include <iostream>
#include <stack>
using namespace std;

//问题：输入运算处数为两位及以上时怎么处理？ 

#define OperandType int

char priority[7][7]=
{
	'>','>','<','<','<','>','>',
	'>','>','<','<','<','>','>',
	'>','>','>','>','<','>','>',
	'>','>','>','>','<','>','>',
	'<','<','<','<','<','=',' ',
	'>','>','>','>',' ','>','>',
	'<','<','<','<','<',' ','='
};

char Precede(char op1, char op2)
{
	int row,col;
	switch(op1)
	{
		case '+':row=0;break;
		case '-':row=1;break;
		case '*':row=2;break;
		case '/':row=3;break;
		case '(':row=4;break;
		case ')':row=5;break;
		case '#':row=6;break;
	}
	switch(op2)
	{
		case '+':col=0;break;
		case '-':col=1;break;
		case '*':col=2;break;
		case '/':col=3;break;
		case '(':col=4;break;
		case ')':col=5;break;
		case '#':col=6;break;
	}
	return priority[row][col];
}

int Operate(int a, char theta, int b)
{
	int result;
	a-='0';
	b-='0';
	switch(theta)
	{
		case '+':
			result = a+b;
			break;
		case '-':
			result = a-b;
			break;
		case '*':
			result = a*b;
			break;
		case '/':
			result = a/b;
			break;
	}
	return result;
}

OperandType EvaluateExpression()
{
	stack<char> optr;
	stack<int>  opnd;
	char x, theta, c;
	int a, b, inc;
	
	optr.push('#');
	cin>>(char)inc;
	c = inc+'0';
	while(c!='#' || optr.top()!='#')
	{
		if(c>'0' && c<'9')	//is operand
		{
			opnd.push(c);
			cin>>inc;
			c = inc+'0';
		}
		else
			switch(Precede(optr.top(),c))
			{
				case '<':	//stack top has lower priority
					optr.push(c);
					cin>>inc;
					c = inc+'0';
					break;
				case '=':	//get rid of braket
					x = optr.top();
					optr.pop();
					cin>>inc;
					c = inc+'0';
					break;
				case '>':	//pop and push the result
					theta = optr.top();	optr.pop();
					b = opnd.top();		opnd.pop();
					a = opnd.top();		opnd.pop();
					opnd.push(Operate(a,theta,b));
					break;
			}
	}
	return opnd.top();
}

int main()
{
	cout<<EvaluateExpression()<<endl;
	return 0;
}
