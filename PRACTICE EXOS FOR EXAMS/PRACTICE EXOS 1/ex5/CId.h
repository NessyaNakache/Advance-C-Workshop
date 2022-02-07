#ifndef _CID_H_
#define _CID_H_
#include <stdbool.h>

void ArrID(int id, int arr[]);
int LuhnAlgorithm(int id);
void CheckId(int id);
bool CheckValidity(int checkDigit);

#endif