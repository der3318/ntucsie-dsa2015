#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <iostream>

#define MAX 1100000
#define toChar_MAX 200
#define toInt_MAX 256
#define BNT 10
#define NOT 11
#define MIN 12
#define PLU 13
#define MUL 20
#define DIV 21
#define MOD 22
#define ADD 30
#define SUB 31
#define SHL 40
#define SHR 41
#define	BAN 50
#define XOR 60
#define BOR 70
#define AND 80
#define OR 90
#define PAR 100

/*
Sign-Value Table
Sign		~	!	-	+	*	/	%	+	-	<<	>>	&	^	|	&&	||	(
Value		-10	-11	-12	-13	-20	-21	-22	-30	-31	-40	-41	-50	-60	-70	-80	-90	-100
*/

char infix[MAX],tmp[MAX], toChar[toChar_MAX][3];
int postfix[MAX], toInt[toInt_MAX];

void toPostfix()
{
	std::stack<int> op_stack;
	int i = 0, p = 0;
	while(infix[i] != '\n')
	{
		if(infix[i] <= '9' && infix[i] >= '0')
		{
			postfix[p] = (int)(infix[i++] - '0');
			while(infix[i] <= '9' && infix[i] >= '0')	postfix[p] = postfix[p] * 10 + (int)(infix[i++] - '0');
			p++;	i--;
		}
		else if(infix[i] == '(' || infix[i] == '~' || infix[i] == '!' || infix[i] == 'm' || infix[i] == 'u')
		{
			op_stack.push( toInt[ (int)infix[i] ] );
			//printf("Encounter \"%s\":\n\tPush \"%s\" Into The Stack\n", toChar[ -op_stack.top() ], toChar[ -op_stack.top() ]);
		}
		else if(infix[i] == ')')
		{
			//printf("Encounter \")\":\n");
			while(op_stack.top() != toInt[ (int)'(' ])
			{
				postfix[p++] = op_stack.top();
				//printf("\tPop \"%s\" From The Stack\n", toChar[ -op_stack.top() ] );
				op_stack.pop();
			}
			//printf("\tPop \"%s\" From The Stack\n", toChar[ -op_stack.top() ] );
			op_stack.pop();
		}
		else
		{
			int pos = toInt[ (int)infix[i] ] ;
			if(infix[i] == infix[i + 1])
			{
				i++;
				if(infix[i] == '&')	pos = -AND;
				else if(infix[i] == '|')	pos = -OR;
			}
			//printf("Encounter \"%s\":\n", toChar[ -pos ]);
			while((!op_stack.empty()) && ((-op_stack.top()) / 10) <= ((-pos) / 10))
			{
				postfix[p++] = op_stack.top();
				//printf("\tPop \"%s\" From The Stack\n", toChar[ -op_stack.top() ] );
				op_stack.pop();
			}
			op_stack.push(pos);
			//printf("\tPush \"%s\" Into The Stack\n", toChar[ -op_stack.top() ]);
		}
		i++;
	}
	//printf("Encounter nothing:\n");
	while(!op_stack.empty())
	{
		postfix[p++] = op_stack.top();
		//printf("\tPop \"%s\" From The Stack\n", toChar[ -op_stack.top() ] );
		op_stack.pop();
	}
	postfix[p] = -1;
	return;
}

void toValue()
{
	std::stack<int> val_stack;
	int p = 0, v_1 = 0, v_2 = 0;
	while(postfix[p] != -1)
	{
		if(postfix[p] >= 0)	val_stack.push(postfix[p]);
		else
		{
			v_2 = val_stack.top();
			val_stack.pop();
			if(postfix[p] == -BNT)	val_stack.push(~v_2);
			else if(postfix[p] == -NOT)	val_stack.push(!v_2);
			else if(postfix[p] == -MIN)	val_stack.push(-v_2);
			else if(postfix[p] == -PLU)	val_stack.push(+v_2);
			else
			{
				v_1 = val_stack.top();
				val_stack.pop();
				if(postfix[p] == -ADD)	val_stack.push(v_1 + v_2);
				else if(postfix[p] == -SUB)	val_stack.push(v_1 - v_2);
				else if(postfix[p] == -MUL)	val_stack.push(v_1 * v_2);
				else if(postfix[p] == -DIV)	val_stack.push(v_1 / v_2);
				else if(postfix[p] == -MOD)	val_stack.push(v_1 % v_2);
				else if(postfix[p] == -BAN)	val_stack.push(v_1 & v_2);
				else if(postfix[p] == -XOR)	val_stack.push(v_1 ^ v_2);
				else if(postfix[p] == -BOR)	val_stack.push(v_1 | v_2);
				else if(postfix[p] == -SHL)	val_stack.push(v_1 << v_2);
				else if(postfix[p] == -SHR)	val_stack.push(v_1 >> v_2);
				else if(postfix[p] == -AND)	val_stack.push(v_1 && v_2);
				else if(postfix[p] == -OR)	val_stack.push(v_1 || v_2);
			}
		}
		p++;
	}
	if(val_stack.size() != 1)	printf("Error Form\n");
	else	printf("RESULT: %d\n", val_stack.top());
	return;
}

int main()
{
	toInt[(int)'+'] = -ADD;	strcpy(toChar[ADD], "+");
	toInt[(int)'-'] = -SUB;	strcpy(toChar[SUB], "-");
	toInt[(int)'*'] = -MUL;	strcpy(toChar[MUL], "*");
	toInt[(int)'/'] = -DIV;	strcpy(toChar[DIV], "/");
	toInt[(int)'%'] = -MOD;	strcpy(toChar[MOD], "%");
	toInt[(int)'&'] = -BAN;	strcpy(toChar[BAN], "&");
	toInt[(int)'^'] = -XOR;	strcpy(toChar[XOR], "^");
	toInt[(int)'|'] = -BOR;	strcpy(toChar[BOR], "|");
	toInt[(int)'~'] = -BNT;	strcpy(toChar[BNT], "~");
	toInt[(int)'!'] = -NOT;	strcpy(toChar[NOT], "!");
	toInt[(int)'u'] = -PLU;	strcpy(toChar[PLU], "+");
	toInt[(int)'m'] = -MIN;	strcpy(toChar[MIN], "-");
	toInt[(int)'<'] = -SHL;	strcpy(toChar[SHL], "<<");
	toInt[(int)'>'] = -SHR;	strcpy(toChar[SHR], ">>");
	toInt[(int)'a'] = -AND;	strcpy(toChar[AND], "&&");
	toInt[(int)'o'] = -OR;	strcpy(toChar[OR], "||");
	toInt[(int)'('] = -PAR;	strcpy(toChar[PAR], "(");
	while(fgets(tmp, MAX, stdin) != NULL)
	{
		if(tmp[1] == '\0')	break;
		int j = 0;
		for(int i = 0 ; tmp[i] != '\n' ; i++)
			if(tmp[i] != ' ')
			{
				if(tmp[i] == '+' || tmp[i] == '-')
					if(j == 0 || ((infix[j - 1] > '9' || infix[j - 1] < '0') && infix[j - 1] != ')'))
					{
						if(tmp[i] == '-')	infix[j++] = 'm';
						else	infix[j++] = 'u';
						continue;
					}
				infix[j++] = tmp[i];
			}
		infix[j] = '\n';
		//printf("# transform from indix to postfix\n");
		toPostfix();
		//printf("# postfix expression transforming complete\n");
		printf("Postfix Exp: %d", postfix[0]);
		for(int i = 1 ; postfix[i] != -1 ; i++)
		{
			if(postfix[i] >= 0)	printf(" %d", postfix[i]);
			else printf(" %s", toChar[ (-postfix[i]) ]);
		}
		printf("\n");
		toValue();
	}
	return 0;
}
