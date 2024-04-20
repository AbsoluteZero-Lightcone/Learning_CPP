/**
  ******************************************************************************
  * @file    Clock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Clock class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Clock.h"

/* Constructors & Deconstructor --------------------------------------------- */
Clock::Clock() :
	m_nHour(0),
	m_nMinute(0),
	m_nSecond(0)
{}

Clock::Clock(int t_nHour, int t_nMinute, int t_nSecond) {
	if (isValid(t_nHour, t_nMinute, t_nSecond)) {
		m_nHour = t_nHour;
		m_nMinute = t_nMinute;
		m_nSecond = t_nSecond;
	}
	else {
		m_nHour = 0;
		m_nMinute = 0;
		m_nSecond = 0;
		cout << "Incorrect Time Format." << endl;
	}
}

Clock::Clock(const Clock& source) :
	m_nHour(source.m_nHour),
	m_nMinute(source.m_nMinute),
	m_nSecond(source.m_nSecond)
{}

Clock::~Clock() {}

/* Getters & Setters -------------------------------------------------------- */
int Clock::get_nHour() { return m_nHour; }
void Clock::set_nHour(int t_nHour) {
	if (t_nHour >= 24 || t_nHour < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nHour = t_nHour;
}
int Clock::get_nMinute() { return m_nMinute; }
void Clock::set_nMinute(int t_nMinute) {
	if (t_nMinute >= 60 || t_nMinute < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nMinute = t_nMinute;
}
int Clock::get_nSecond() { return m_nSecond; }
void Clock::set_nSecond(int t_nSecond) {
	if (t_nSecond >= 60 || t_nSecond < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nSecond = t_nSecond;
}

void Clock::setTime(int t_nHour, int t_nMinute, int t_nSecond) {
	if (isValid(t_nHour, t_nMinute, t_nSecond)) {
		m_nHour = t_nHour;
		m_nMinute = t_nMinute;
		m_nSecond = t_nSecond;
	}
	else {
		cout << "Incorrect Time Format." << endl;
	}
}

// �涨����
/**
  * @brief ��ʾʱ�书��
  * @param None
  * @retval None
  */
void Clock::Show() const {
	cout << *this;
}
/**
  * @brief ��ʱ���ܣ�ÿһ��Tick��ʱ����ǰ��1��
  * @param None
  * @retval None
  */
void Clock::Tick() {
	(*this)++;
}

/* Exported functions ------------------------------------------------------- */

bool isValid(int t_nHour, int t_nMinute, int t_nSecond) {
	if (
		t_nHour >= 24 || t_nHour < 0 ||
		t_nMinute >= 60 || t_nMinute < 0 ||
		t_nSecond >= 60 || t_nSecond < 0
		)return 0;
	else return 1;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Clock& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Clock& source) {
	out << setw(2) << setfill('0') << source.m_nHour << ":"
		<< setw(2) << setfill('0') << source.m_nMinute << ":"
		<< setw(2) << setfill('0') << source.m_nSecond;
	return out;
}

/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Clock& source : ������ֵ
  * @retval ��
  */
void Clock::operator=(const Clock& source) {
	m_nHour = source.m_nHour;
	m_nMinute = source.m_nMinute;
	m_nSecond = source.m_nSecond;
}

/**
  * @brief �����������������������һ��
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::operator++(int) {
	m_nSecond++;
	if (m_nSecond == 60) {
		m_nSecond = 0;
		m_nMinute++;
		if (m_nMinute == 60) {
			m_nMinute = 0;
			m_nHour++;
			if (m_nHour == 24) {
				m_nHour = 0;
				// m_nDay++; //todo ��Date�м̳�
			}
		}
	}
	return *this;
}

/**
  * @brief ��������+=����������϶�Ӧ������
  * @param n : ���ӵ�����
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::operator+=(int n) {
	for (int i = 0; i < n; i++)
		(*this)++;
	return *this;
}

/**
  * @brief ���ش��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const Clock& n1, const Clock& n2) {
	if (n1.m_nHour > n2.m_nHour)return true;
	else if (n1.m_nMinute > n2.m_nMinute)return true;
	else if (n1.m_nSecond > n2.m_nSecond)return true;
	else return false;
}

/**
  * @brief ���ص��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Clock& n1, const Clock& n2) {
	if (n1.m_nHour != n2.m_nHour)return false;
	else if (n1.m_nMinute != n2.m_nMinute)return false;
	else if (n1.m_nSecond != n2.m_nSecond)return false;
	return true;
}

/**
  * @brief ���ؼ����������������������
  * @param const Clock& n1 : ������
  * @param const Clock& n2 : ����
  * @retval ��������
  */
int operator-(const Clock& n1, const Clock& n2) {
	// todo : �̳�Date��Ҫ�޸���Σ�����ͬ���ڿ��ǽ���

	return
		(n1.m_nHour - n2.m_nHour) * 60 * 60 +
		(n1.m_nMinute - n2.m_nMinute) * 60 +
		(n1.m_nSecond - n2.m_nSecond);
}
/**
  * @brief ��������+=����������϶�Ӧ������
  * @param c : Clock Object
  * @param n : ���ӵ�����
  * @retval ������������ʵ����ʽ���
  */
Clock operator+(Clock c, int n) {
	for (int i = 0; i < n; i++)
		c++;
	return c;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/