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
	int sectioncount[30]{}; // 각 구간 강화 횟수
	int successcount[30]{}; // 각 성공 횟수
	int failurecount[30]{}; // 각 실패 횟수
	int destorycount[30]{}; // 각 파괴 횟수
	float successCRate[30]{}; // 각 성공 횟수
	float failureCRate[30]{}; // 각 실패 횟수
	float destoryCRate[30]{}; // 각 파괴 횟수
	long long MoneyCount[30]{}; // 각 구간별 강화 비용 3번 기능에만 사용

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

