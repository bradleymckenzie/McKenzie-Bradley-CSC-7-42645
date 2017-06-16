/* 
 * File:   main.cpp
 * Author: Bradley McKenzie
 * Created on May 25, 2017
 * Purpose: Merkle Tree
 */

//System Library
#include <iostream>//Standard library
#include <cmath>//Power
#include <string>//String library
#include <fstream>//File stream library
#include <sstream>//Combining Strings
#include <cstdlib>//C Standard Library
using namespace std;

//User Library

//Global Constants

//Function Prototypes
typedef unsigned int (*HashFunction)(const string&);

unsigned int RSHash  (const string& str);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare a variable array
    string L1 = "Then out spake brave Horatius, The Captain of the Gate:";
    string L2 = "\"To every man upon this earth Death cometh soon or late.";
    string L3 = "And how can man die better Than facing fearful odds,";
    string L4 = "For the ashes of his fathers, And the temples of his Gods.\"";
    stringstream L12, L34, L1234;
    
    //Input
    cout<<"--------------------------Merkle Tree--------------------------"<<endl;
    cout<<"L1: "<<L1<<endl;
    cout<<"L2: "<<L2<<endl;
    cout<<"L3: "<<L3<<endl;
    cout<<"L4: "<<L4<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    //Print the result
    cout<<"Hash 0-0, 0-1, 1-0, & 1-1 (L1, L2, L3, & L4):"<<endl;
    cout<<"   RSHash L1: "<<RSHash(L1)<<endl;
    cout<<"   RSHash L2: "<<RSHash(L2)<<endl;
    cout<<"   RSHash L3: "<<RSHash(L3)<<endl;
    cout<<"   RSHash L4: "<<RSHash(L4)<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Hash 0 (O-0 + 0-1):"<<endl;
    L12<<RSHash(L1)<<RSHash(L2);
    string L12string = L12.str();
    cout<<"   RSHash L1 + L2: "<<RSHash(L12string)<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Hash 1 (1-0 + 1-1):"<<endl;
    L34<<RSHash(L3)<<RSHash(L4);
    string L34string = L34.str();
    cout<<"   RSHash L3 + L4: "<<RSHash(L34string)<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Hash Top (0 + 1):"<<endl;
    L1234<<RSHash(L12string)<<RSHash(L34string);
    string L1234string = L1234.str();
    cout<<"   RSHash L1 & L2 + L3 & L4: "<<RSHash(L1234string)<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    //Exit
    return 0;
}

unsigned int RSHash(const string& str)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }
   return hash;
}
/* End Of RS Hash Function */