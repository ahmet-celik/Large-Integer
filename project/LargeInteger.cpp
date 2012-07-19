/*
 * LargeInteger.cpp
 *
 *  Created on: 23 Oct 2011
 *      Author: Ahmet Celik
 */

#include <cstring> //to use memcpy in multiplication
#include <vector>  //to hold LargeIntUnits in LargeInt
#include <iomanip> //to print decimal numbers nicely
#include <iostream>//to print
#include "LargeInteger.h" //my LargeInteger class
#include "LargeIntUnit.h"//my structure for new digit of numbers

using namespace std;

typedef unsigned  int ZN;

 LargeInteger::LargeInteger():number(1)
 {
   number[0]= LargeIntUnit(0);
 }

 LargeInteger::LargeInteger(const LargeIntUnit& x):number(1)
 {
   number[0]= x;
 }

 LargeInteger::LargeInteger(const LargeInteger& x,const ZN size):number(size+x.size())
 {
   //number.resize();
   memcpy(&number[size],&(x.getUnit(0)),x.size()*sizeof(LargeIntUnit));
   /*for(ZN i=x.size();i>0;i--) this->number[i+size-1]=x.number[i-1];*/ //old for version
 }

 LargeInteger::LargeInteger(const ZN size):number(size){}

 LargeInteger::LargeInteger(const LargeInteger & newone)
 {
        this->number=newone.number;
 }

 LargeInteger& LargeInteger::operator=(const LargeInteger & newone)
 {
        this->number=newone.number;
        return *this;
 }

 LargeInteger LargeInteger::operator+(const LargeInteger &lhs) const
 {
     const LargeInteger *max =this;
     const LargeInteger *min=&lhs;
     if(lhs.size()>this->size())
     { //finding which one has bigger and smaller size of numbers.
		 max=&lhs;
		 min=this;
     }
     ZN maxs=max->size();
     ZN mins=min->size();
     LargeInteger result(maxs+1); //in case there might be a carry in last digit.
     result.number[0]=LargeIntUnit(min->getUnit(0).data+max->getUnit(0).data);
     //perform this addition,because in first digit there is not a carry.

     ZN i=1;//since sizes are ZN type, I do not want compare unsigned int with signed int.
     while(i<(maxs))//there is digit to sum
     {
         if(i<(mins))//there is a digit to sum in smaller number
         {
			 result.number[i] = LargeIntUnit(min->getUnit(i).data+result.getUnit(i-1).remain+max->getUnit(i).data);
         }else{//there is only bigger number and carries from result
             result.number[i]=LargeIntUnit(result.getUnit(i-1).remain+max->getUnit(i).data);
         }
         i++;
     }
     result.number[i]=LargeIntUnit(result.getUnit(i-1).remain);
     if(result.getUnit(i).data==0) result.number.resize(i); //make sure there is not any 0 LargeIntUnit
     	 	 	 	 	 	 	   // in most significant digit.
     return result;
  }

 LargeInteger LargeInteger::operator*(const LargeIntUnit &lhs)const
 {
      ZN size=this->size();
      LargeInteger result(size+1);
      result.number[0]=LargeIntUnit(this->number[0].data*lhs.data);//again there is not any
      ZN i=1;							//any remain for 1st digit
      for( ;i<size;i++)//multiply by one by LargeInt with LargeIntUnit
      {
         result.number[i]=LargeIntUnit((this->number[i].data*lhs.data)+result.getUnit(i-1).remain);
      }
      result.number[i]=LargeIntUnit(result.getUnit(i-1).remain);
      if(result.getUnit(i).data==0) result.number.resize(i); //make sure there is not any 0 LargeIntUnit
      return result;					    // in most significant digit.
  }

 LargeInteger LargeInteger::operator*(const LargeInteger &lhs)const
 {
      ZN maxs=this->size()+lhs.size();//multiplication result can have at most
      LargeInteger result(maxs);          //total digits of operands digits.
      ZN i=0;
      for(;i<lhs.size();i++)
      {
         result=result+LargeInteger((*this)*lhs.number[i],i);//here "i" makes LargeInt to move left eg: <-xxxxx
      }							 //after each digit multiplication      eg: xxxxx
      if(result.getUnit(maxs-1).data==0) result.number.resize(maxs-1);//make sure there is not any 0 LargeIntUnit
      return result;						      // in most significant digit.
  }

 ostream &operator<<( ostream &out, const LargeInteger&lhs)
 {
     lhs.print(out);
     return out;
  }

 void LargeInteger::print(ostream &out)const
 {    ZN tmp = this->size();
  	   out<<this->getUnit(tmp-1).data;
       for(int i=tmp-2;i>=0;i--)
          out<<setw(4) << setfill('0')<<this->getUnit(i).data;
  }
