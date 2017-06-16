/* 
 * File:   main.cpp
 * Author: Bradley McKenzie
 * Created on May 01, 2017
 * Purpose:  Check and Set a bit
 */

//System Library
#include <iostream>//Standard library
#include <cmath>//Power
#include <string>//String library
#include <fstream>//File stream library
using namespace std;

//User Library

//Global Constants

//Function Prototypes
typedef unsigned int (*HashFunction)(const string&);

unsigned int RSHash  (const string& str);
unsigned int JSHash  (const string& str);
unsigned int PJWHash (const string& str);
unsigned int ELFHash (const string& str);
unsigned int BKDRHash(const string& str);
unsigned int SDBMHash(const string& str);
unsigned int DJBHash (const string& str);
unsigned int DEKHash (const string& str);
unsigned int BPHash  (const string& str);
unsigned int FNVHash (const string& str);
unsigned int APHash  (const string& str);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare a variable array
    int nBits=750;
    const int SIZE=nBits/8+1;
    char bitVec[SIZE];
    
    //What bit to set?
    int bitSet=100;
    
    //What element is that in the array?
    int byte=bitSet/8;
    int bit=bitSet%8;
    
    //Now set that bit
    bitVec[byte]|=1<<bit;
    
    //Check and see if the bit got set
    bool set=(bitVec[byte]>>bit)&1;
    
    //Instantiate and Open files
    ifstream file;
    file.open("StringInput.dat");//Inputs
    //Input
    cout<<"       ----Bloom Filter----"<<endl;
    
    //Print the result
    cout<<"The number of bits in the array = "<<nBits<<endl;
    cout<<"The size of the byte array = "<<SIZE<<endl;
    cout<<"The bit to set = "<<bitSet<<endl;
    cout<<"The byte = "<<byte<<endl;
    cout<<"The bit  = "<<bit<<endl;
    cout<<"The value of 2^"<<bit<<" = "<<pow(2,bit)<<endl;
    cout<<"The value of the bitVec = "
            <<static_cast<int>(bitVec[byte])<<endl;
    if(set)cout<<"The bit was set"<<endl;
    
    cout<<"RSHash: "<<RSHash(file)<<endl;
    cout<<"JSHash: "<<JSHash(file)<<endl;
    cout<<"PJWHash: "<<PJWHash(file)<<endl;
    cout<<"ELFHash: "<<ELFHash(file)<<endl;
    cout<<"BKDRHash: "<<BKDRHash(file)<<endl;
    cout<<"SDBMHash: "<<SDBMHash(file)<<endl;
    cout<<"DJBHash: "<<DJBHash(file)<<endl;
    cout<<"DEKHash: "<<DEKHash(file)<<endl;
    cout<<"BPHash: "<<BPHash(file)<<endl;
    cout<<"FNVHash: "<<FNVHash(file)<<endl;
    cout<<"APHash: "<<APHash(file)<<endl;
    //Exit
    return 0;
    file.close();
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

unsigned int JSHash(const string& str)
{
   unsigned int hash = 1315423911;

   for(size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}
/* End Of JS Hash Function */

unsigned int PJWHash(const string& str)
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


unsigned int ELFHash(const string& str)
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


unsigned int BKDRHash(const string& str)
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


unsigned int SDBMHash(const string& str)
{
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}
/* End Of SDBM Hash Function */


unsigned int DJBHash(const string& str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
/* End Of DJB Hash Function */


unsigned int DEKHash(const string& str)
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


unsigned int FNVHash(const string& str)
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

unsigned int APHash(const string& str)
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