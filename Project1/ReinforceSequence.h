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
	uint32_t sectioncount[30]{}; // �� ���� ��ȭ Ƚ��
	uint32_t successcount[30]{}; // �� ���� Ƚ��
	uint32_t failurecount[30]{}; // �� ���� Ƚ��
	uint32_t destorycount[30]{}; // �� �ı� Ƚ��
	float successCRate[30]{}; // �� ���� Ƚ��
	float failureCRate[30]{}; // �� ���� Ƚ��
	float destoryCRate[30]{}; // �� �ı� Ƚ��
	uint64_t MoneyCount[30]{}; // �� ������ ��ȭ ��� 3�� ��ɿ��� ���

	//  PerList
	uint32_t m_success_per = 0;
	uint32_t m_failure_per = 0;
	uint32_t m_destory_per = 0;

	//Parse
	float m_success_rate, m_failure_rate, m_destroy_rate{};

	// Count_seq
	uint32_t m_suc_cnt{};
	uint32_t m_fail_cnt{};
	uint32_t m_destory_cnt{};
	uint32_t m_money_cnt{};
	
public:
	uint32_t calcCnt();
	string Determine_Outcome();

	uint32_t reinforce_sequence(uint32_t c_lv, uint32_t g_lv, uint32_t e_lv, bool antikey, bool starcatch);
	void reinforc_repeat_sequence(uint32_t c_lv, uint32_t e_lv, bool antikey, bool starcatch);
	uint32_t reinforce_costCSV_sequence(uint32_t c_lv, uint32_t g_lv, uint32_t e_lv, bool antikey, bool starcatch);

	void Arranged_Percentage(uint32_t curlv, uint32_t elv, bool antikey, bool starcatch);
	void repeat_Arranged_Percentage(uint32_t curlv, uint32_t elv, bool antikey, bool starcatch);
	void costCSV_Arranged_Percentage(uint32_t curlv, uint32_t elv, bool antikey, bool starcatch);

	void compareRate(uint32_t copylv, uint32_t g_lv, bool starcatch);
	void repeat_compareRate(uint32_t copylv, bool starcatch);
	void repeat_csv_compareRate(uint32_t copylv, uint32_t g_lv, bool starcatch);

	void export_result_to_csv(const float success[], const float fail[], const float destroy[], uint32_t from, uint32_t to);
	void export_costresult_to_csv(uint32_t from, uint32_t to, uint32_t e_lv, bool antikey);

	void reset_all_data();
	void pruint32_tresult(uint32_t i);	
};

