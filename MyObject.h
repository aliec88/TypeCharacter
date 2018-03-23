#pragma once
struct SChar
{
	char c;
	SPoint pos;
	int mass;
	double asseleration;
	SVector2D velocity;
	SChar()
	{
		c=RandInt(97,97+26);
		pos.x=RandInt(0,WINDOW_WIDTH);
		pos.y=RandInt(0,WINDOW_HEIGHT-300);
		mass=RandInt(CHAR_MIN_MASS,CHAR_MAX_MASS);
		asseleration=0;
		velocity=0;
	}
};
class CMyObject
{
private:
	vector<SChar>m_vecVB;	
	char m_cGetChar;
	int m_iScore;
public:
	CMyObject(void);
	~CMyObject(void);
	void Rander(HDC surface);
	void Update(double timeelapsed);
	void GetChar(char c){m_cGetChar=c;}
};

