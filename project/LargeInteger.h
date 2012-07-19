/*
 * LargeInt.h
 *
 *  Created on: 23 Oct 2011
 *      Author: Ahmet Celik
 */

#ifndef LARGEINTEGER_H
#define LARGEINTEGER_H

#include "LargeIntUnit.h"
using namespace std;

typedef unsigned int ZN;

/**
 * Holds my numbers, using a vector of LargeIntUnits.
 * Subscript 0 is least significant digit.
 */
class LargeInteger{

 vector<LargeIntUnit> number; //holds actual number.
 	 	 //There will not a zero LargeIntUnit in most significant digit.
public:
    
 /**
  * Default constructor.
  */
 LargeInteger();

 /**
  * Takes a LargeIntUnit and makes conversion to LargeInteger
  */
 explicit LargeInteger(const LargeIntUnit& x);

 /**
  * Constructs a copy of a LargeInteger to a bigger array then size of number.
  * new size= old size + size
  */
 LargeInteger(const LargeInteger& x,const ZN size);

 /**
  * Constructs a new LargeInteger at given size.
  */
 explicit LargeInteger(const ZN size);

 /**
   * Copy constructor of LargeInteger.
   */
 LargeInteger(const LargeInteger & newone);

 /**
  * Overloaded Assignment operator
  */
 LargeInteger& operator=(const LargeInteger & newone);

 /**
  * Returns number of digits in number.
  */
 const ZN size() const
 {
   return number.size();
 }

 /**
  * Returns a reference to LargeIntUnit vector
  */
 const LargeIntUnit& getUnit(const ZN i) const
 {
	 return number[i];
 }

 /**
  * Adds two LargeInteger.
  */
 LargeInteger operator+(const LargeInteger &lhs) const;

 /**
   * Multiplies a LargeInteger with LargeIntUnit
   */
 LargeInteger operator*(const LargeIntUnit &lhs)const;

 /**
   * Multiplies a LargeInteger with a LargeInteger
   */
 LargeInteger operator*(const LargeInteger &lhs)const;

 /**
   * Stream output of LargeInteger
   */
 friend ostream &operator<<( ostream &out, const LargeInteger&lhs  );

 /**
   * Helper method of operator<<.
   */
 void print(ostream &out)const;
};

#endif /* LARGEINTEGER_H */

