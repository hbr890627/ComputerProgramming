/* Fig. 12.8: fig12_08.c
   dynamic stack program */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>
#include <stdlib.h>

struct stackNode {   /* self-referential structure */
   int data;
   struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode * StackNodePtr;

void push( StackNodePtr *, int );
int pop( StackNodePtr *,  int *);
int isEmpty( StackNodePtr );
void printStack( StackNodePtr );
void instructions( void );
bool insertAtFront( StackNodePtr *sPtr, int );
bool removeFromFront( StackNodePtr *sPtr, int * );
StackNodePtr getNewNode(int value );

int main()
{ 
   StackNodePtr stackPtr = NULL;  /* points to stack top */
   int choice, value;
 
   instructions();
   cout << "? ";
   cin >> choice ;

   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:      /* push value onto stack */
            cout << "Enter an integer: " ;
            cin >> value ;
            push( &stackPtr, value );
            printStack( stackPtr );
            break;
         case 2:      /* pop value off stack */
            if ( !isEmpty( stackPtr ) )
               cout << "The popped value is :" 
                    <<  pop( &stackPtr, & value) 
					<< "\n";

            printStack( stackPtr );
            break;
         default:
            cout << "Invalid choice.\n\n";
            instructions();
            break;
       }

      cout << "? ";
      cin >> choice ;
   }

 return 0;
}

/* Print the instructions */
void instructions( void )
{ 
   printf( "Enter choice:\n"
          "1 to push a value on the stack\n"
          "2 to pop a value off the stack\n"
          "3 to end program\n" );
}

/* Insert a node at the stack top */
void push( StackNodePtr *topPtr, int info )
{ 
   StackNodePtr newPtr;

//   newPtr = getNewNode(info);
   if ( insertAtFront( topPtr, info )) 
	  cout << "Value: " << info << "pushed into stack\n";
   else
      cout << info << "not inserted. No memory available.\n";
}

/* Remove a node from the stack top */
int pop( StackNodePtr *topPtr, int * )
{ 
   StackNodePtr tempPtr;
   int popValue;

   removeFromFront( topPtr, &popValue );

   return popValue;
}

/* Print the stack */
void printStack( StackNodePtr currentPtr )
{ 
   if ( currentPtr == NULL )
      printf( "The stack is empty.\n\n" );
   else { 
      printf( "The stack is:\n" );

      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      }

      printf( "NULL\n\n" );
   }
}

/* Is the stack empty? */
int isEmpty( StackNodePtr topPtr )
{ 
   return topPtr == NULL;
}

bool insertAtFront( StackNodePtr *sPtr, int value )
   {
      StackNodePtr newPtr = getNewNode( value ); // new node

      if (newPtr == NULL)
          return false;
	  if ( isEmpty(*sPtr) ) // List is empty
         *sPtr = newPtr; // new list has only one node
      else // List is not empty
      {
         newPtr->nextPtr = *sPtr; // point new node to old 1st node
         *sPtr = newPtr; // aim firstPtr at new node
      } // end else
    return true;
   } // end function insertAtFront

   // insert node at back of list

bool removeFromFront( StackNodePtr *sPtr, int *value )
   {
      if ( isEmpty(*sPtr) ) // List is empty
         return false; // delete unsuccessful
      else 
      {
         StackNodePtr tempPtr = *sPtr; // hold item to delete
         *value = ( *sPtr )->data;
	     *sPtr = ( *sPtr )->nextPtr;  /* de-thread the node */
         delete tempPtr;             /* free the de-threaded node */
         
         return true; // delete successful
      } // end else
   } // end function removeFromFront

StackNodePtr getNewNode(int value )
{
      StackNodePtr newPtr = (StackNodePtr) new ( StackNode);
      if ( newPtr != NULL ) {     /* is space available */
      newPtr->data = value;
      newPtr->nextPtr = NULL;
      } 
	  return newPtr;
}
/**************************************************************************
 * (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
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
 *************************************************************************/
