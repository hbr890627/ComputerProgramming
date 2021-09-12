// Exercise 20.12 Solution: Ex20_12.cpp
// Infix to postfix conversion
#include <iostream> 
#include <cctype>
#include <cmath>
#include <cstring>
#include "Stack.h" 
#include <cstdlib> //


using namespace std;

// function prototype
void convertToPostfix( char * const, char * const ); //Function name says it.
bool isOperator( char );       //Test if a character is an operator or not.
bool precedence( char, char ); //Decide which operator has hirher precedence.
int evaluatePostfixExpression( char * const ); //Compute the final result.
int calculate( int opnd1, int opnd2, char oper );  
//Called by evaluatePostfixExpression for calculating (opnd1 oper opnd2), e.g 8+6  

int main()
{
   const int MAXSIZE = 100;
   char c;
   char inFix[ MAXSIZE ];
   char postFix[ MAXSIZE ];
   int pos = 0;
   int answer;
 
   cout << "Enter the infix expression.\n";

   // get input
   while ( ( c = static_cast< char >( cin.get() ) ) != '\n' )

      if ( c != ' ' )
         inFix[ pos++ ] = c;

   inFix[ pos ] = '\0';

   cout << "The original infix expression is:\n" << inFix << '\n';

   // change from infix notation into postfix notation
   convertToPostfix( inFix, postFix );
   
   cout << "The expression in postfix notation is:\n" << postFix << endl;

   answer = evaluatePostfixExpression( postFix );
   cout << "The value of the expression is: " << answer << endl;	
   return 0;
} // end main    
// take out the infix and change it into postfix
void convertToPostfix( char * const infix, char * postfix ){
	int i=0;
	int j=0;
	Stack ope;
	ope.push('(');
	ope.printStack();
	while (infix[i]!='\0')
	{
		if(isOperator(infix[i])){
			if(infix[i]==')'){
				do{
					char a=ope.stackTop();	
					ope.pop(a);
					ope.printStack();
					
					postfix[j]=a;
					j++;
				}while(ope.stackTop()!='(');
				char a=ope.stackTop();
				ope.pop(a);
				ope.printStack();
			}else{
				while( precedence(ope.stackTop(),infix[i]) ){
					char a=ope.stackTop();
					ope.pop(a);
					ope.printStack();
					
					postfix[j]=a;	
					j++;
				}
				char a=infix[i];
				ope.push(a);
				ope.printStack();
			}
		}else{
			char a=infix[i];
			
			postfix[j]=a;
			j++;
		}
		i++;
	}
	while (ope.stackTop()!='\0'){
		char a=ope.stackTop();
		ope.pop(a);
		ope.printStack();
		postfix[j++]=a;
	}
	postfix[--j]='\0';
}


// check if c is an operator
bool isOperator( char c ){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' ||c== '%')
		return true;
	else
		return false;
}


// ensure proper order of operations
bool precedence( char operator1, char operator2 ){
	
	if(operator1=='('||operator1==')'&&operator2=='('&&operator2==')')
	return false;
	
	int pre1=1;
	int pre2=2;
	
	if(operator1=='+'||operator1=='-')
		pre1=1;
	if(operator1=='*'||operator1=='/')
		pre1=2;
		
	if(operator2=='+'||operator2=='-')
		pre2=1;
	if(operator2=='*'||operator2=='/')
		pre2=2;
		
		
	if(pre1>=pre2)
		return true;
	else
		return false;
}

//evaluate the final result for the postfix expression
int evaluatePostfixExpression( char * const expr ){
	int i=0;
	int j=0;
	int ans=0;
	Stack value;
	while (expr[i]!='\0'){
		if(isOperator(expr[i])){
			char a=value.stackTop();
			value.pop(a);
			value.printStack();

			char b=value.stackTop();
			value.pop(b);
			value.printStack();

			ans=calculate(a-'0',b-'0',expr[i]);

			char c=ans+'0';
			value.push(c);
			value.printStack();

		}else{
			value.push(expr[i]);
			value.printStack();
		}
		i++; 
	}
	char a=value.stackTop();
	value.pop(a);
	return ans;
}

// do the calculation
int calculate( int op1, int op2, char oper ){
	switch (oper){
	case '+':
		return (op1+op2);
	case '-':
		return (op2-op1);
	case '*':
		return (op1*op2);
	case '/':
		return (op2/op1);
	}
}

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
