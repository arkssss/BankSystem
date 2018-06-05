#include "StdAfx.h"
#include "Function.h"


//字符串转化
string ConvertCStringToString(CString str){
	char buf[255]={0};
	WideCharToMultiByte(CP_ACP,0,str.GetString(),str.GetLength(),buf,255,0,0);
	return buf;
}


CString ConvertStringToCString(string str){
	wchar_t buf[255]={0};
	MultiByteToWideChar(CP_ACP,0,str.c_str(),str.length(),buf,255);
	return buf;

}

//实现一个CString 类型和 double 类型的加法 最后为CString 类型返回
//i=0 则加法 i=1 则减法
CString AddCStringAnddouble(CString str,double tmp,int i){
	
		double AfterOp=_ttof(str);
		if(!i) AfterOp+=tmp;
		else AfterOp-=tmp;
		CString res;
		res.Format(_T("%f"),AfterOp);
		return res;

}