/* Fig. 12.13: fig12_13.c
   Operating and maintaining a queue */

#include <iostream>
//using std::cout;
//using std::cin;
//using std::endl;
//using std::ios;

#include <iomanip>

using std::setiosflags;
using std::setw;
using namespace std;

 
struct queueNode {   /* self-referential structure */
   char data;
   struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

/* function prototypes */
void printQueue( QueueNodePtr );
int isEmpty( QueueNodePtr );
char dequeue( QueueNodePtr * );
void enqueue( QueueNodePtr *, QueueNodePtr *, char );
void instructions( void );

bool insertAtBack( QueueNodePtr *sPtr, char value);
bool removeFromFront( QueueNodePtr *sPtr, char *value );
QueueNodePtr getNewNode(char value );

int main()
{ 
   QueueNodePtr headPtr = NULL, tailPtr = NULL;
   int choice;
   char item;

   instructions();
   printf( "? " );
   scanf( "%d", &choice );

   while ( choice != 3 ) { 

      switch( choice ) { 

         case 1:
            cout << "Enter a character: " ;
            cin >>  item ;
            enqueue( &headPtr, &tailPtr, item );
            printQueue( headPtr );
            break;
         case 2:
            if ( !isEmpty( headPtr ) ) { 
               item = dequeue( &headPtr);
               cout << item << " has been dequeued.\n";
            }

            printQueue( headPtr );
            break;

         default:
            cout << "Invalid choice.\n\n" ;
            instructions();
            break;
      }

      cout << "? " ;
      cin >> choice;
   }

   cout <<  "End of run.\n" ;
   return 0;
}

void instructions( void )
{ 
   cout << "Enter your choice:\n"
        <<  "   1 to add an item to the queue\n"
        <<   "   2 to remove an item from the queue\n"
        <<   "   3 to end\n" ;
}

void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, 
              char value )
{ 
   QueueNodePtr newPtr = getNewNode( value ) ;

   if ( newPtr != NULL ) { 
      if ( isEmpty( *headPtr ) )
         *headPtr = newPtr;
      else
         insertAtBack( headPtr, value);

      *tailPtr = newPtr;
   }
   else
      cout << value << " not inserted. No memory available.\n";
}

char dequeue( QueueNodePtr *headPtr)
{ 
   char value;

   if ( removeFromFront( headPtr,  &value ))
       return value;
}

int isEmpty( QueueNodePtr headPtr )
{ 
   return headPtr == NULL;
}

void printQueue( QueueNodePtr currentPtr )
{ 
   if ( currentPtr == NULL )
      cout << "Queue is empty.\n\n";
   else { 
      cout << "The queue is:\n" ;

      while ( currentPtr != NULL ) { 
         cout << currentPtr->data <<  "--> ";
         currentPtr = currentPtr->nextPtr;
      }

      cout << "NULL\n\n" ;
   }
}

bool insertAtBack( QueueNodePtr *sPtr, char value)
   {
      QueueNodePtr newPtr = getNewNode( value );// new node
      QueueNodePtr previousPtr, currentPtr;  
      
      if (newPtr== NULL)
	   return false;
      if ( isEmpty(*sPtr) ) // List is empty
         *sPtr = newPtr; // new list has only one node
      else // List is not empty
      {
       previousPtr = NULL;
       currentPtr = *sPtr;

       while ( currentPtr != NULL ) { 
          previousPtr = currentPtr;          /* walk to ...   */
          currentPtr = currentPtr->nextPtr;  /* ... next node */
       }    
         previousPtr->nextPtr = newPtr;
 return true;
      } // end function insertAtBack
}
   // delete node from front of list
bool removeFromFront( QueueNodePtr *sPtr, char *value )
   {
      if ( isEmpty(*sPtr) ) // List is empty
         return false; // delete unsuccessful
      else 
      {
         QueueNodePtr tempPtr = *sPtr; // hold item to delete
         *value = ( *sPtr )->data;
	     *sPtr = ( *sPtr )->nextPtr;  /* de-thread the node */
         delete tempPtr;             /* free the de-threaded node */
         
         return true; // delete successful
      } // end else
   } // end function removeFromFront

QueueNodePtr getNewNode(char value )
{
      QueueNodePtr newPtr = (QueueNodePtr) new ( queueNode);
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
