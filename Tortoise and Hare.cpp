#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int arrS=70;

void moveTortoise( int *position ){
	int behave=(rand()%10+1);
	if(behave>=5){
		*position+=3;
	}else if(behave>=3){
		*position-=6;
	}else
		*position+=1;
	if (*position>70)
		*position=70;
	if (*position<1)
		*position=1;
	return;
}

void moveHare( int *position ){
	int behave=(rand()%10)+1;
	if(behave>=8){
		//sleep
	}else if(behave>=6){
		*position+=9;
	}else if(behave>=5){
		*position-=12;
	}else if(behave>=2){
		*position+=1;
	}else
		*position-=2;
	if (*position>70)
		*position=70;
	if (*position<1)
		*position=1;
	return;
}
void printCurrentPositions( const int *Tpo, const int *Hpo ){
	char position[arrS]={};
	for(int i=0;i<70;i++){
		position[i]='-';
	}
	if(*Tpo==*Hpo)
		cout<<"OUCH!!!";
	else{
		position[*Tpo]='T';
		position[*Hpo]='H';
		for(int i=0;i<70;i++){	
			cout<<position[i];
		}
	}
	cout<<endl;
	return;	
}

int main(){
	srand(time(0));
	int Tpo=1;
	int Hpo=1;
	cout<<"Bang !!!!!\nAND THEY'RE OFF !!!!!"<<endl;
	int i=1;
	while(i==1){
		moveTortoise(&Tpo);
		moveHare(&Hpo);
		printCurrentPositions(&Tpo,&Hpo);
		if(Tpo==70&&Hpo<70)
			i=2;
		else if(Tpo<70&&Hpo==70)
			i=3;
		else if(Tpo==70&&Hpo==70)
			i=4;
	}
	if(i==2)
		cout<<"TORTOISE WINS!!! YAY!!!";
	else if (i==3)
		cout<<"HARE WINS!!! YAY!!!";
	else
		cout<<"It's a tie";
	return 0;
}
