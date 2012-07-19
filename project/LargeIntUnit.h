/*
 * LargeIntUnit.h 
 * Inline implementation of LargeIntUnit my new digit structure
 *  Created on: 23 Oct 2011
 *      Author: Ahmet Celik
 */

#ifndef LARGEINTUNIT_H
#define LARGEINTUNIT_H

typedef unsigned int ZN;

/**
 * My new 8-byte units for LargeInteger numbers. Its range is from 0 to 9999(inclusive).
 * This will make multiplication and addition better than using just 1 digit.
 * remain will hold carries for addition and multiplication in result number.
 * Indeed I could create a carry array for each multiplication and addition, 
 * but I found this easier.
 * Also, I am able to print numbers just printing them in a order, 
 * without using 10^n multiplications.
 */
struct LargeIntUnit
{
   ZN data;  //my new digit
   ZN remain;//holds carry

/**
 * Default Constructor, takes any unsigned int and make conversion to LargeIntUnit.
 */
LargeIntUnit(ZN x=0 ):remain(0)
{
	  if(x<=9999)
		  data=x;
	  else
	  {
		  data= x%10000;
		  remain=x/10000;
	  }
 }

/**
  * Copy constructor
  */
LargeIntUnit(const LargeIntUnit&newone)
{
     this->data= newone.data;
     this->remain= newone.remain;
 }

/**
  * Overloaded Assignment operator
  */
LargeIntUnit & operator=(const LargeIntUnit&newone)
{
     this->data= newone.data;
     this->remain= newone.remain;
     return *this;
 }

};

#endif /* LARGEINTUNIT_H */
