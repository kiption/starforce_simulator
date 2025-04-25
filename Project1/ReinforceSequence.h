#include <iostream>
#include <random>
#include <iomanip>
#include <locale>
#include <fstream>
#include "StarforceRate.h"
#include "Cost.h"

using namespace std;
struct optionCheck {
	bool Onstarcatch = false;
	bool Onantidestroy = false;
	bool Oncomparecheck = false;
};


class Reinforce {
private:
	

public:
	Reinforce();
	~Reinforce();
	
	Rate PercentageRate;
	Cost resultcost;

	// Counting
	int sectioncount[30]{}; // �� ���� ��ȭ Ƚ��
	int successcount[30]{}; // �� ���� Ƚ��
	int failurecount[30]{}; // �� ���� Ƚ��
	int destorycount[30]{}; // �� �ı� Ƚ��
	float successCRate[30]{}; // �� ���� Ƚ��
	float failureCRate[30]{}; // �� ���� Ƚ��
	float destoryCRate[30]{}; // �� �ı� Ƚ��
	long long MoneyCount[30]{}; // �� ������ ��ȭ ��� 3�� ��ɿ��� ���

	//  PerList
	int m_success_per = 0;
	int m_failure_per = 0;
	int m_destory_per = 0;

	//Parse
	float m_success_rate, m_failure_rate, m_destroy_rate{};

	// Count_seq
	int m_suc_cnt{};
	int m_fail_cnt{};
	int m_destory_cnt{};
	long long m_money_cnt{};
	
public:
	int calcCnt();
	string Determine_Outcome();

	int reinforce_sequence(int c_lv, int g_lv, int e_lv, bool antikey, bool starcatch);
	void reinforc_repeat_sequence(int c_lv, int e_lv, bool antikey, bool starcatch);
	int reinforce_costCSV_sequence(int c_lv, int g_lv, int e_lv, bool antikey, bool starcatch);

	void Arranged_Percentage(int curlv, int elv, bool antikey, bool starcatch);
	void repeat_Arranged_Percentage(int curlv, int elv, bool antikey, bool starcatch);
	void costCSV_Arranged_Percentage(int curlv, int elv, bool antikey, bool starcatch);

	void compareRate(int copylv, int g_lv, bool starcatch);
	void repeat_compareRate(int copylv, bool starcatch);
	void repeat_csv_compareRate(int copylv, int g_lv, bool starcatch);

	void export_result_to_csv(const float success[], const float fail[], const float destroy[], int from, int to);
	void export_costresult_to_csv(int from, int to, int e_lv, bool antikey);

	void reset_all_data();
	void printresult(int i);	
};

