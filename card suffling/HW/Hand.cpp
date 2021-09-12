#include <iostream>
#include "Hand.h"
using namespace std;

Hand::Hand( DeckOfCards &deck ){
   for(int i=0; i<5; i++){
      hand.push_back(deck.dealCard());
   }

   for(int i=1; i<=13; i++){
      int number=0;
      for(int j=0; j<5; j++){
          if(hand[j].getFace()==i){
            number++;
          }         
      }
      faceCount.push_back(number);
   }
}
void Hand::print() const{
   for(int i=0; i<5; i++){
      cout<<hand[i].toString()<<endl;
   }
}
bool Hand::pair() const{
   for(int i=0; i<13; i++){
      if(faceCount[i]==2)
         return true;
   }
   return false;
}
bool Hand::twoPair() const{
   int number=0;
   for(int i=0; i<13; i++){
      if(faceCount[i]==2)
         number++;
   }
   if(number==2)
      return true;
   else
      return false;
}
bool Hand::threeOfAKind() const{
   for(int i=0; i<13; i++){
      if(faceCount[i]==3)
         return true;
   }
   return false;
}
bool Hand::fourOfAKind() const{
   for(int i=0; i<13; i++){
      if(faceCount[i]==4)
         return true;
   }
   return false;
}
bool Hand::flush() const{
   int Clubs=0;
   int Diamonds=0;
   int Hearts=0;
   int Spades=0;
   for(int i=0; i<5; i++){
      if(hand[i].getSuit()==0)
         Clubs++;
      else if(hand[i].getSuit()==1)
         Diamonds++;
      else if(hand[i].getSuit()==2)
         Hearts++;
      else if(hand[i].getSuit()==3)
         Spades++;
   }
   if(Clubs==5||Diamonds==5||Hearts==5||Spades==5)
      return true;
   else
      return false;
}
bool Hand::straight() const{
   for(int i=0; i<13; i++){
      if(faceCount[i]>1)
         return false;
   }
   for(int i=0; i<9; i++){
      if(faceCount[i]==1&&faceCount[i+1]==1&&faceCount[i+2]==1&&faceCount[i+3]==1&&faceCount[i+4]==1)
      	return true;
   }
   return false;
}
