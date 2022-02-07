#pragma once


// test cases for bool IsPrime(int num);

void TCZeroBoundary();
void TCOneBoundary();
void TCNonPrimeBoundary();
void TCPrimeBoundary();
void TCExtremeNonPrimeBoundary();
void TCExtremePrimeBoundary();

//test cases for int CalculateNextPrime(int num);
void TCCalcForZero();
void TCCalcForOne();
void TCCalcForSmallNonPrime();
void TCCalcForSmallPrime();
void TCCalcForExtremeNonPrime();
void TCCalcForExtremePrime();

//test cases for void GetNextPrime();
void TCVersionGetNextPrime(int n);
void TCZeroLoop();
void TCOneLoop();
void TCFiftyLoop();
void TCTenThousandLoop();


void IntegralTesting();