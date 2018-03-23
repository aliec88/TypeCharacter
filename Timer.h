#pragma once
class CTimer
{
private:
	LONGLONG m_llNextTime;
	LONGLONG m_llFrameTime;
	LONGLONG m_llLastTime;
	double m_dFPS;
	double m_dTimeScale;
	double m_dTimeElapsed;
public:
	CTimer(double fps);
	~CTimer(void);
	void Start();
	bool ReadyForNextTime();
	double GetTimeElapsed(){return m_dTimeElapsed;}
};

