#include "StdAfx.h"
#include "Function.h"


//�ַ���ת��
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

//ʵ��һ��CString ���ͺ� double ���͵ļӷ� ���ΪCString ���ͷ���
//i=0 ��ӷ� i=1 �����
CString AddCStringAnddouble(CString str,double tmp,int i){
	
		double AfterOp=_ttof(str);
		if(!i) AfterOp+=tmp;
		else AfterOp-=tmp;
		CString res;
		res.Format(_T("%f"),AfterOp);
		return res;

}