#include "StdAfx.h"
#include "Timer.h"


CTimer::CTimer(double fps)
{
	LONGLONG performance;
	QueryPerformanceFrequency((LARGE_INTEGER*)&performance);
	m_llFrameTime=(LONGLONG)(performance/fps);
	m_dTimeScale=1.0f/performance;
	m_llLastTime=0;
	m_dTimeElapsed=0;
}


CTimer::~CTimer(void)
{
}

void CTimer::Start()
{
	LONGLONG current;
	QueryPerformanceCounter((LARGE_INTEGER*)&current);
	m_llNextTime=current+m_llFrameTime;
	m_llLastTime=current;
}

bool CTimer::ReadyForNextTime()
{
	LONGLONG current;
	QueryPerformanceCounter((LARGE_INTEGER*)&current);
	if (current>m_llNextTime)
	{
		m_llNextTime=current+m_llFrameTime;
		m_dTimeElapsed=(current-m_llLastTime)*m_dTimeScale;
		m_llLastTime=current;
		return true;
	}
	return false;
}
