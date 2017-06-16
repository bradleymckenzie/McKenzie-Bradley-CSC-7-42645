/* 
 * File:   main.cpp
 * Author: Bradley McKenzie
 * Created on March 22, 2017
 * Purpose: Luhn Algorithm Part 3
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);
bool valLuhn(char [],int );
void genCC(char,char []);
void flipDig(char []);
bool validCC(char[]);

int main(int argc, char** argv) {
    //Title
    cout<<"--------------------------------------------------"<<endl;
    cout<<"\t\tLuhn Algorithm"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    Luhn(crdCard,SIZE-1);
    cout<<crdCard;
    if (valLuhn(crdCard,SIZE-1)) cout<<" is valid!"<<endl;
    else cout<<" is not valid!"<<endl;
    //Exit Stage Right
    return 0;
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}

void Luhn(char cc[], int n){
    char doubled[n];
	for( int i = 0;i < n;i++){
		doubled[i] = cc[i];
	}
	
	//double every other and minus 9 if needed
	for(int i= n-1;i >= 0;i -= 2){
		doubled[i] = (doubled[i] - 48) * 2 + 48;
		if(doubled[i] - 48  > 9) { 
			doubled[i] = (doubled[i] - 48) - 9 + 48;
		}
	}
	int total = 0;
	for( int i = 0;i < n;i++){
            total += (doubled[i] - 48);
	}

	cc[n] =((total * 9)% 10) + 48;
	cout<<"total % 10 = "<<(total * -9) % 10<<endl;
}
bool valLuhn(char cc[],int n){
    short total=0;
    bool result=false;
    //Sum the numbers adjusting for char
    for (int i=0;i<n;i++){
        total+=(cc[i]-48);
    }
    //validation testing
    if (total%10==0) result=true;//valid
    else result=false;//not valid 
    return result; //return result
}

enum CrdCard{
    Visa,
    AmericanExpress,
    MasterCard,
    Discover,
    ALL
};

void genCC(CrdCard,char cc[]){
    
}

void flipDig(char cc[]){
    int length;
    int i = rand() % (length - 1);
    char flip;
    char newDigit = rndDgit();
    cc[i] = newDigit;
    if (flip) cout<<cc<<endl;
        return;
}

bool validCC(char cc[]){
	int length;
	char equals = cc[length-1];
	cc[length-1] = 0;
	Luhn(cc, length+1);
	cc[length-1] = true;
	return (true);
}