#ifndef _PLCOMMON_H_ 
#define _PLCOMMON_H_  
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <list>
using namespace std;
#define MAX_VALUE	65536

void PrintArray(int arr[], int size);
void PrintArray(int arr[], int left,int right,bool bline = true);

void Swap(int& a, int& b);
#endif
