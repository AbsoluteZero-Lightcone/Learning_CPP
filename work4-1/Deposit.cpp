/**
  ******************************************************************************
  * @file    Deposit.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Deposit class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Deposit.h"

/* Constructors & Deconstructor --------------------------------------------- */
Deposit::Deposit() :
	m_nAccount(++s_nCount),
	m_strName("ȱʡ"),
	m_strPassword("ȱʡ"),
	m_dDeposit(0),
	m_dateDate(0)
{}

Deposit::Deposit(
	string t_strName,
	string t_strPassword,
	double t_dDeposit,
	Date t_dateDate
) :
	m_nAccount(++s_nCount),
	m_strName(t_strName),
	m_strPassword(t_strPassword),
	m_dDeposit(t_dDeposit),
	m_dateDate(t_dateDate)
{}

Deposit::~Deposit() {}

/* Getters & Setters -------------------------------------------------------- */
int Deposit::get_nAccount()const { return m_nAccount; }
string Deposit::get_strName()const { return m_strName; }
string Deposit::get_strPassword()const { return m_strPassword; }
double Deposit::get_dInterest()const { return s_dInterest; }
double Deposit::get_dDeposit()const { return m_dDeposit; }
Date Deposit::get_dateDate()const { return m_dateDate; }
void Deposit::set_nAccount(int t_nAccount) { m_nAccount = t_nAccount; }
void Deposit::set_strName(string t_strName) { m_strName = t_strName; }
void Deposit::set_strPassword(string t_strPassword) { m_strPassword = t_strPassword; }
void Deposit::set_dInterest(double t_dInterest) { s_dInterest = t_dInterest; }
void Deposit::set_dDeposit(double t_dDeposit) { m_dDeposit = t_dDeposit; }
void Deposit::set_dateDate(Date t_dateDate) { m_dateDate = t_dateDate; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Deposit& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Deposit& source) {
	out << source.m_nAccount << "\t"
		<< source.m_strName << "\t"
		<< source.m_strPassword << "\t"
		<< source.m_dDeposit * 100.0 << "%" << "\t"
		<< source.m_dateDate;
	return out;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/