#pragma once
#include "stdafx.h"
inline int RandInt(int a,int b)
{
	return rand()%(b-a)+a;
}
inline wstring itos(int i)
{
	wostringstream s;
	s<<i;
	return s.str();
}