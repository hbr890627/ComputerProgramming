/* Fig. 12.19: fig12_19.c
   Create a binary tree and traverse it 
   preorder, inorder, and postorder */
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

#include <time.h>

struct treeNode { 
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *, int );
void inOrder( TreeNodePtr );
void preOrder( TreeNodePtr );
void postOrder( TreeNodePtr );
TreeNodePtr getNewNode(int value );

int main()
{ 
   int i, item;
   TreeNodePtr rootPtr = NULL;

   srand( time( NULL ) );

   /* insert random values between 1 and 15 in the tree */
   cout << "The numbers being placed in the tree are:\n" ;

   for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 100;
      cout <<  " " << item ;
      insertNode( &rootPtr, item );
   }

   /* traverse the tree preOrder */
   cout << "\n\nThe preOrder traversal is:\n" ;
   preOrder( rootPtr );

   /* traverse the tree inOrder */
   cout << "\n\nThe inOrder traversal is:\n" ;
   inOrder( rootPtr );

   /* traverse the tree postOrder */
   cout << "\n\nThe postOrder traversal is:\n" ;
   postOrder( rootPtr );

   return 0;
}

void insertNode( TreeNodePtr *treePtr, int value )
{ 
   if ( *treePtr == NULL )    /* Sucessfuly get a new node*/
         *treePtr= getNewNode( value);
	  else if ( value < ( *treePtr )->data )
         insertNode( &( ( *treePtr )->leftPtr ), value );
      else if ( value > ( *treePtr )->data )
         insertNode( &( ( *treePtr )->rightPtr ), value );
      else 
         cout << "\nDuplicated Value " << value <<" not inserted\n";
}


void inOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) { 
      inOrder( treePtr->leftPtr );
      cout << " " << treePtr->data ;
      inOrder( treePtr->rightPtr );
   }
}

void preOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) { 
      cout << " " << treePtr->data ;
      preOrder( treePtr->leftPtr );
      preOrder( treePtr->rightPtr );
   }
}

void postOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) { 
      postOrder( treePtr->leftPtr );
      postOrder( treePtr->rightPtr );
      cout << " " << treePtr->data ;
   }
}

TreeNodePtr getNewNode(int value )
{
      TreeNodePtr newPtr = (TreeNodePtr) new (TreeNode);
      if ( newPtr != NULL ) {     /* is space available */
      newPtr->data = value;
      newPtr->leftPtr = NULL;
      newPtr->rightPtr = NULL;
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
