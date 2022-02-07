#pragma once

#include<stdbool.h>

#define SIZE 100
void printArray(int* arr, int length);
int mySum(int* arr, int length);
void Sort(int* arr, int length);
unsigned long long Fibonacci(int num);
unsigned long long Exist(unsigned long long num);
unsigned long long lazyFibonacci(unsigned long long num);
void printMatrix(int m[SIZE][SIZE], int S);
void transposeMatrix(int m[SIZE][SIZE], int S);
void upgradedTransposeMatrix(int m[SIZE][SIZE], int S);
bool checkSymmetry(int m[SIZE][SIZE], int S);
bool checkSkewSymmetry(int m[SIZE][SIZE], int S);


