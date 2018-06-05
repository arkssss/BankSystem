#pragma once
#include <string>
using namespace std;

string ConvertCStringToString(CString str);
CString ConvertStringToCString(string str);
CString AddCStringAnddouble(CString str,double tmp,int sig);
int ConvertCharToInt(char * ch);

