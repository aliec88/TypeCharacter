#include "StdAfx.h"
#include "MyObject.h"


CMyObject::CMyObject(void)
{
	for(int i=0;i<CHAR_NUM;i++)
	{
		m_vecVB.push_back(SChar());
	}
	m_cGetChar=NULL;
	m_iScore=0;
}


CMyObject::~CMyObject(void)
{
}

void CMyObject::Rander(HDC surface)
{
	SetBkColor(surface,RGB(0,0,0));
	SetTextColor(surface,RGB(255,0,0));
	for (int i=0;i<m_vecVB.size();i++)
	{
		TextOutA(surface,m_vecVB[i].pos.x,m_vecVB[i].pos.y,&m_vecVB[i].c,1);
	}
	wstring s=TEXT("µÃ·Ö£º")+itos(m_iScore);
	TextOut(surface,WINDOW_WIDTH-200,0,s.c_str(),s.size());
}

void CMyObject::Update(double timeelapsed)
{
	for (int i=0;i<m_vecVB.size();i++)
	{
		m_vecVB[i].asseleration+=THRUST*timeelapsed/m_vecVB[i].mass;
		m_vecVB[i].velocity.y+=m_vecVB[i].asseleration*timeelapsed;
		m_vecVB[i].pos.y+=m_vecVB[i].velocity.y;
		if (m_vecVB[i].pos.y>WINDOW_HEIGHT)
		{
			m_vecVB[i].pos.y=0;
			m_vecVB[i].c=RandInt(97,97+26);
			m_vecVB[i].asseleration=0;
			m_vecVB[i].velocity=0;
			m_iScore--;
		}
		if (m_cGetChar==m_vecVB[i].c)
		{
			m_vecVB[i].c=RandInt(97,97+26);
			m_vecVB[i].pos.y=0;
			m_vecVB[i].asseleration=0;
			m_vecVB[i].velocity=0;
			m_iScore++;
		}
	}

}
