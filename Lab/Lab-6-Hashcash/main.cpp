/* 
 * File:   main.cpp
 * Author: Bradley McKenzie
 * Created on May 17, 2017
 * Purpose: Hashcash
 */

//System Library
#include <iostream>//Standard library
#include <string>//String library
#include <iostream>//Standard library
#include <ctime>
#include <sstream>
#include <cstdlib>
using namespace std;

//User Library

//Global Constants

//Function Prototypes
typedef unsigned int (*HashFunction)(const string&);

unsigned int RSHash  (const std::string& str);
unsigned int JSHash  (const std::string& str);
unsigned int PJWHash (const std::string& str);
unsigned int ELFHash (const std::string& str);
unsigned int BKDRHash(const std::string& str);
unsigned int SDBMHash(const std::string& str);
unsigned int DJBHash (const std::string& str);
unsigned int DEKHash (const std::string& str);
unsigned int BPHash  (const std::string& str);
unsigned int FNVHash (const std::string& str);
unsigned int APHash  (const std::string& str);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    string message = "Make America Great Again!";
    unsigned int RSHashInt,JSHashInt,PJWHashInt,ELFHashInt,BKDRHashInt,
            SDBMHashInt,DJBHashInt,DEKHashInt,FNVHashInt;
    int SIZE = 9;
    long results[] = {0,0,0,0,0,0,0,0,0};
    // function pointers
    unsigned (*hashers[SIZE])(const string &);
    hashers[0] = RSHash;
    hashers[1] = JSHash;
    hashers[2] = PJWHash;
    hashers[3] = BKDRHash;
    hashers[4] = SDBMHash;
    hashers[5] = DJBHash;
    hashers[6] = DEKHash;
    hashers[7] = FNVHash;
    hashers[8] = BPHash;

    int randNum=rand();

    for ( int j = 0; j < SIZE; j++ ){
            for (int i = 0; i < 10000; i++){
                    ostringstream convert;   // stream used for the conversion
                    convert << randNum++;      // insert the textual representation of 'Number' in the characters in the stream
                    string strRnd = convert.str();
                    string newMsg=message+strRnd;
                    unsigned int v = hashers[j](newMsg);
                    if (v < 10e1){
                            results[0]++;
                    }else if (v < 10e2)
                    {
                            results[1]++;
                    } else if (v < 10e3)
                    {
                            results[2]++;
                    }else if (v < 10e4)
                    {
                            results[3]++;
                    }else if (v < 10e5)
                    {
                            results[4]++;
                    } else if (v < 10e6)
                    {
                            results[5]++;
                    } else if (v < 10e7)
                    {
                            results[6]++;
                    } else if (v < 10e8)
                    {
                            results[7]++;
                    } else if (v < 10e9)
                    {
                            results[8]++;
                    }
            }
    }
        
    cout<<"\t      Hashcash"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Message: "<<message<<endl; 
    cout<<"The random number: "<<randNum<<endl; 

    cout<<"-------------------------------------"<<endl;
    cout<<"Final Hashes: "<<endl;
    cout<<"      RSHash Function: "<<RSHash(message)<<endl;
    cout<<"      JSHash Function: "<<JSHash(message)<<endl;
    cout<<"     PJWHash Function: "<<PJWHash(message)<<endl;
    cout<<"     ELFHash Function: "<<ELFHash(message)<<endl;
    cout<<"    BKDRHash Function: "<<BKDRHash(message)<<endl;
    cout<<"    SDBMHash Function: "<<SDBMHash(message)<<endl;
    cout<<"     DJBHash Function: "<<DJBHash(message)<<endl;
    cout<<"     DEKHash Function: "<<DEKHash(message)<<endl;
    cout<<"     FNVHash Function: "<<FNVHash(message)<<endl;

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