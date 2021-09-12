/* Fig. 12.3: fig12_03.c
   Operating and maintaining a list */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>
#include <stdlib.h>

using std::setiosflags;
using std::setw;
using namespace std;



struct listNode {   /* self-referential structure */
   char data;
   struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insertinorder( ListNodePtr *, char );
char deletefound( ListNodePtr *, char );
bool insertAtFront( ListNodePtr *sPtr, char );
bool insertAtBack( ListNodePtr *sPtr, char value);
bool removeFromFront( ListNodePtr *sPtr, char *value );
bool removeFromBack( ListNodePtr *sPtr, char *value );
int isEmpty( ListNodePtr );
void printList( ListNodePtr );
void instructions( void );
ListNodePtr getNewNode(char value );

int main()
{ 
   ListNodePtr startPtr = NULL;
   int choice;
   char item;

   instructions();  /* display the menu */
   cout << "? ";
   cin >> choice ;

   while ( choice != 0 ) { 

      switch ( choice ) { 
         case 1:
            cout << "Enter a character: ";
            cin >> item ;
            insertinorder( &startPtr, item );
            printList( startPtr );
            break;
         case 2:
            if ( !isEmpty( startPtr ) ) { 
               cout << "Enter character to be deleted: ";
               cin>> item;

               if ( deletefound( &startPtr, item ) ) { 
                  cout << item << "deleted.\n" ;
                  printList( startPtr );
               }
               else
                  cout << "not found., item << ""\n\n";
            }
            else
              cout<<  "List is empty.\n\n" ;

            break;
         case 3:
            cout << "Enter a character: ";
            cin >> item ;
        	insertAtFront(&startPtr, item );
            printList( startPtr );
            break;
         case 4:
         	cout << "Enter a character: ";
            cin >> item;
            insertAtBack(&startPtr, item);
            printList( startPtr );
            break;
         case 5:
            if (removeFromFront( &startPtr, &item ) )
               cout << item << " removed from list\n";
            else
               cout<<  "List is empty.\n\n" ;
		    printList( startPtr );
            break;
         case 6: // remove from end
            if ( removeFromBack( &startPtr, &item ) )
               cout << item  << " removed from list\n";
            else
               cout<<  "List is empty.\n\n" ;
		    printList( startPtr );
            break;         	     	
         default:
            cout << "Invalid choice.\n\n" ;
            instructions();
            break;
      }

      cout << "? " ;
      cin >> choice ;
   }

   printf( "End of run.\n" );
   return 0;
}

/* Print the instructions */
void instructions( void )
{ 
   cout << "Enter your choice:\n"
        <<  "   1 to insert an element into the list in order.\n"
        <<  "   2 to delete an specified element from the list.\n"
        <<  "   3 to insert at beginning of list\n" 
        <<  "   4 to insert at end of list\n" 
        <<  "   5 to delete from beginning of list\n" 
        <<  "   6 to delete from end of list\n" 
        <<  "   0 to end.\n" ;
}

/* Insert a new value into the list in sorted order */
void insertinorder( ListNodePtr *sPtr, char value )
{ 
   ListNodePtr newPtr, previousPtr, currentPtr;

   newPtr = (ListNodePtr) new (  ListNode  );

   if ( newPtr != NULL ) {     /* is space available */
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while ( currentPtr != NULL && value > currentPtr->data ) { 
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      }

      if ( previousPtr == NULL ) {  // List is empty
         newPtr->nextPtr = *sPtr;   // new list has only one node
         *sPtr = newPtr;
      }
      else { 
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      }
   }
   else
      cout << value << " not inserted. No memory available.\n";
}

/* Delete a list element */
char deletefound( ListNodePtr *sPtr, char value )
{ 
   ListNodePtr previousPtr, currentPtr, tempPtr;

   if ( value == ( *sPtr )->data ) { 
      tempPtr = *sPtr;
      *sPtr = ( *sPtr )->nextPtr;  /* de-thread the node */
      free( tempPtr );             /* free the de-threaded node */
      return value;
   }
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      while ( currentPtr != NULL && currentPtr->data != value ) { 
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      }

      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value;
      }                                                        
   }

   return '\0';
}

bool insertAtFront( ListNodePtr *sPtr, char value )
   {
      ListNodePtr newPtr = getNewNode( value ); // new node

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
bool insertAtBack( ListNodePtr *sPtr, char value)
   {
      ListNodePtr newPtr = getNewNode( value );// new node
      ListNodePtr previousPtr, currentPtr;  
      
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
bool removeFromFront( ListNodePtr *sPtr, char *value )
   {
      if ( isEmpty(*sPtr) ) // List is empty
         return false; // delete unsuccessful
      else 
      {
         ListNodePtr tempPtr = *sPtr; // hold item to delete
         *value = ( *sPtr )->data;
	     *sPtr = ( *sPtr )->nextPtr;  /* de-thread the node */
         delete tempPtr;             /* free the de-threaded node */
         
         return true; // delete successful
      } // end else
   } // end function removeFromFront

   // delete node from back of list
bool removeFromBack( ListNodePtr *sPtr, char *value )
   {
      ListNodePtr previousPtr, currentPtr;  
      
      if ( isEmpty(*sPtr) ) // List is empty
         return false; // delete unsuccessful
      else // List is not empty
      {
         previousPtr = NULL;
         currentPtr = *sPtr;

       while ( currentPtr->nextPtr != NULL ) { 
          previousPtr = currentPtr;          /* walk to thw end of the list.   */
          currentPtr = currentPtr->nextPtr;  /* ... next node */
       }    
       *value = currentPtr->data;
       previousPtr->nextPtr=NULL;
       delete currentPtr; // reclaim former last node
       return true; // delete successful
      } // end else
   } // end function removeFromBack
   
ListNodePtr getNewNode(char value )
{
      ListNodePtr newPtr = (ListNodePtr) new ( listNode);
      if ( newPtr != NULL ) {     /* is space available */
      newPtr->data = value;
      newPtr->nextPtr = NULL;
      } 
	  return newPtr;
}
/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{ 
   return sPtr == NULL;
}

/* Print the list */
void printList( ListNodePtr currentPtr )
{ 
   if ( currentPtr == NULL )
      cout <<  "List is empty.\n\n" ;
   else { 
      cout << "The list is:\n" ;

      while ( currentPtr != NULL ) { 
         cout << currentPtr->data << "--> ";
         currentPtr = currentPtr->nextPtr;
      }

      cout << "NULL\n\n" ;
   }
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
