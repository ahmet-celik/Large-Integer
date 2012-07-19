//============================================================================
// Name        : Assignment I
// Author      : Ahmet Celik
// Version     : 0.91
// Description : Finding and Printing Catalan Numbers from 0 to 200 by implementing a LargeInteger class.
//============================================================================

#include <iostream>
#include <vector>
#include "LargeInteger.h"
#include "LargeIntUnit.h"
using namespace std;

typedef unsigned  int ZN; // typing unsigned int is too long.
			//I used unsigned int, because I will never use any negative number

ZN CATNUM = 200; //up to which Catalan Number

vector<LargeInteger> ctl(CATNUM+1);//holds calculated Catalan Numbers up to CATNUM

void catalan(int n)//catalan number calculator
{	
    LargeInteger sum(LargeIntUnit(0));
    for(int i=0;i<n/2;i++) // since there is symmetry on calculation
    {	      	      

            sum=sum+LargeInteger(ctl[i]*ctl[n-i-1]);
    }
    sum=sum+sum; //calculate just until middle then add sum to sum and
    if(n%2!=0){//if there is middle add it too.
        sum=sum+LargeInteger(ctl[n/2]*ctl[n/2]);
    }
    ctl[n]=sum;	
}


int main(){
    ctl[0]=LargeInteger(LargeIntUnit(1));//default catalan number
    cout<<0<<' '<<ctl[0]<<endl;
    for(ZN i=1;i<CATNUM+1;i++){//you can not find CATNUMth catalan number
        catalan(i);			   //without finding previous ones
        cout<<i<<' '<<ctl[i]<<endl;         //prints nicely
     }
     return 0;
}
