/* 
 File: main.cpp
 Author: Bradley McKenzie
 Created on: April 3, 2017
 Purpose: Hashing Function
 */

//System Libraries
#include <iostream>
#include "GeneralHashFunctions.h"
using namespace std;

//User Libraries

//Global Constants
    //Such as PI, Vc, -> Math/Science Values
    //as well as conversions from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    string keyd = "Then out spake brave Horatius,"
            "\n     The Captain of the Gate:"
            "\n     To every man upon this earth"
            "\n     Death cometh soon or late."
            "\n     And how can man die better"
            "\n     Than facing fearful odds,"
            "\n     For the ashes of his fathers,"
            "\n     And the temples of his gods.";
 string key[8] = {"Then out spake brave Horatius,","The Captain of the Gate:","To every man upon this earth","Death cometh soon or late.","And how can man die better","Than facing fearful odds,","For the ashes of his fathers,","And the temples of his gods."};
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output Values
    cout<<setw(50)<<"********************************************"<<endl;
    cout<<setw(50)<<"Horatius from the Lays of Ancient Rome XXVII"<<endl;
    cout<<setw(50)<<"********************************************"<<endl;
	cout<<setw(11)<<"Key: "<<endl;
        cout<<setw(40)<<"Then out spake brave Horatius,"<<endl;
        cout<<setw(34)<<"The Captain of the Gate:"<<endl;
        cout<<setw(38)<<"To every man upon this earth"<<endl;
        cout<<setw(36)<<"Death cometh soon or late."<<endl;
        cout<<setw(36)<<"And how can man die better"<<endl;
        cout<<setw(35)<<"Than facing fearful odds,"<<endl;
        cout<<setw(39)<<"For the ashes of his fathers,"<<endl;
        cout<<setw(38)<<"And the temples of his gods."<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"RSHash: "<<RSHash(key[8])<<", "<<RSHash(key[7])<<", "<<RSHash(key[6])
                <<", "<<RSHash(key[5])<<endl;
        cout<<setw(18)<<RSHash(key[4])<<", "<<RSHash(key[3])<<", "<<RSHash(key[2])
                <<", "<<RSHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"JSHash: "<<JSHash<<JSHash(key[8])<<", "<<JSHash(key[7])<<", "<<JSHash(key[6])
                <<", "<<JSHash(key[5])<<endl;
        cout<<setw(18)<<JSHash(key[4])<<", "<<JSHash(key[3])<<", "<<JSHash(key[2])
                <<", "<<JSHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"PJWHash: "<<PJWHash(key[8])<<", "<<PJWHash(key[7])<<", "<<PJWHash(key[6])
                <<", "<<PJWHash(key[5])<<endl;
        cout<<setw(16)<<PJWHash(key[4])<<", "<<PJWHash(key[3])<<", "<<PJWHash(key[2])
                <<", "<<PJWHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"ELFHash: "<<ELFHash(key[8])<<", "<<ELFHash(key[7])<<", "<<ELFHash(key[6])
                <<", "<<ELFHash(key[5])<<endl;
        cout<<setw(16)<<ELFHash(key[4])<<", "<<ELFHash(key[3])<<", "<<ELFHash(key[2])
                <<", "<<ELFHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"BKDRHash: "<<BKDRHash(key[8])<<", "<<BKDRHash(key[7])<<", "<<BKDRHash(key[6])
                <<", "<<BKDRHash(key[5])<<endl;
        cout<<setw(20)<<BKDRHash(key[4])<<", "<<BKDRHash(key[3])<<", "<<BKDRHash(key[2])
                <<", "<<BKDRHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"SDBMHash: "<<SDBMHash(key[8])<<", "<<SDBMHash(key[7])<<", "<<SDBMHash(key[6])
                <<", "<<SDBMHash(key[5])<<endl;
        cout<<setw(20)<<SDBMHash(key[4])<<", "<<SDBMHash(key[3])<<", "<<SDBMHash(key[2])
                <<", "<<SDBMHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"DJBHash: "<<DJBHash(key[8])<<", "<<DJBHash(key[7])<<", "<<DJBHash(key[6])
                <<", "<<DJBHash(key[5])<<endl;
        cout<<setw(19)<<DJBHash(key[4])<<", "<<DJBHash(key[3])<<", "<<DJBHash(key[2])
                <<", "<<DJBHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"DEKHash: "<<DEKHash(key[8])<<", "<<DEKHash(key[7])<<", "<<DEKHash(key[6])
                <<", "<<DEKHash(key[5])<<endl;
        cout<<setw(19)<<DEKHash(key[4])<<", "<<DEKHash(key[3])<<", "<<DEKHash(key[2])
                <<", "<<DEKHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"BPHash: "<<BPHash(key[8])<<", "<<BPHash(key[7])<<", "<<BPHash(key[6])
                <<", "<<BPHash(key[5])<<endl;
        cout<<setw(18)<<BPHash(key[4])<<", "<<BPHash(key[3])<<", "<<BPHash(key[2])
                <<", "<<BPHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"FNVHash: "<<FNVHash(key[8])<<", "<<FNVHash(key[7])<<", "<<FNVHash(key[6])
                <<", "<<FNVHash(key[5])<<endl;
        cout<<setw(19)<<FNVHash(key[4])<<", "<<FNVHash(key[3])<<", "<<FNVHash(key[2])
                <<", "<<FNVHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
	cout<<"APHash: "<<APHash(key[8])<<", "<<APHash(key[7])<<", "<<APHash(key[6])
                <<", "<<APHash(key[5])<<endl;
        cout<<setw(18)<<APHash(key[4])<<", "<<APHash(key[3])<<", "<<APHash(key[2])
                <<", "<<APHash(key[1])<<endl;
        cout<<"--------------------------------------------------------"<<endl;
    cout<<setw(50)<<"********************************************"<<endl;
    cout<<setw(33)<<"McKenzie"<<endl;
    cout<<setw(50)<<"********************************************"<<endl;
    //Exit stage right!
    return 0;
}

unsigned int RSHash(const std::string& str)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }
   return hash;
}
/* End Of RS Hash Function */


unsigned int JSHash(const std::string& str)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}
/* End Of JS Hash Function */


unsigned int PJWHash(const std::string& str)
{
   unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << OneEighth) + str[i];

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}
/* End Of  P. J. Weinberger Hash Function */


unsigned int ELFHash(const std::string& str)
{
   unsigned int hash = 0;
   unsigned int x    = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << 4) + str[i];
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
   }

   return hash;
}
/* End Of ELF Hash Function */


unsigned int BKDRHash(const std::string& str)
{
   unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash * seed) + str[i];
   }

   return hash;
}
/* End Of BKDR Hash Function */


unsigned int SDBMHash(const std::string& str)
{
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}
/* End Of SDBM Hash Function */


unsigned int DJBHash(const std::string& str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
/* End Of DJB Hash Function */


unsigned int DEKHash(const std::string& str)
{
   unsigned int hash = static_cast<unsigned int>(str.length());

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
   }

   return hash;
}
/* End Of DEK Hash Function */


unsigned int BPHash(const std::string& str)
{
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash << 7 ^ str[i];
   }

   return hash;
}
/* End Of BP Hash Function */


unsigned int FNVHash(const std::string& str)
{
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }

   return hash;
}
/* End Of FNV Hash Function */

unsigned int APHash(const std::string& str)
{
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
                               (~((hash << 11) + (str[i] ^ (hash >> 5))));
   }

   return hash;
}
/* End Of AP Hash Function */