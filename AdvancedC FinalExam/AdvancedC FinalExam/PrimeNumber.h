#pragma once

/**
*  @doxdocgen
* Generate Doxygen
* comments in VS
*/


#include<stdbool.h>
#include"TestProgram.h"

//! checks if the integer is a prime number
bool IsPrime(int num);
//! return the next prime number after the passed integer
int CalculateNextPrime(int num);
//! prints prime numbers as long as the user calls onto the function by pressing enter key
void GetNextPrime();