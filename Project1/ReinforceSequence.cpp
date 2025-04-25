#include "ReinforceSequence.h"

random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int>urd(0, 1'000'000);

Reinforce::Reinforce()
{

}

Reinforce::~Reinforce()
{

}

int Reinforce::calcCnt()
{
	return m_suc_cnt + m_fail_cnt + m_destory_cnt;
}

string Reinforce::Determine_Outcome()
{
	float randomValue = urd(dre);

	if (randomValue <= m_success_per) {
		return "Success";
	}
	else if (randomValue <= m_success_per + m_failure_per) {
		return "Fail";
	}
	else {
		return "Destroy";
	}
}

int Reinforce::reinforce_sequence(int c_lv, int g_lv, int e_lv, bool antikey, bool starcatch)
{
	Arranged_Percentage(c_lv, e_lv, antikey, starcatch);

	string resultMsg = Determine_Outcome();

	sectioncount[c_lv]++;

	if (resultMsg == "Success") {
		successcount[c_lv]++;
		c_lv++;

		m_suc_cnt++;
	}
	else if (resultMsg == "Fail") {

		failurecount[c_lv]++;
		m_fail_cnt++;
	}
	else {

		destorycount[c_lv]++;
		c_lv = 12;


		m_destory_cnt++;
	}

	return c_lv;
}

void Reinforce::Arranged_Percentage(int curlv, int elv, bool antikey, bool starcatch)
{
	int money{};
	if (starcatch) {
		m_success_per = PercentageRate.CatchData[curlv].m_successRate;
		m_failure_per = PercentageRate.CatchData[curlv].m_failureRate;
		m_destory_per = PercentageRate.CatchData[curlv].m_destroyRate;
	}
	else {
		m_success_per = PercentageRate.basicData[curlv].m_successRate;
		m_failure_per = PercentageRate.basicData[curlv].m_failureRate;
		m_destory_per = PercentageRate.basicData[curlv].m_destroyRate;
	}

	if (antikey && (15 <= curlv && curlv <= 17)) {
		m_failure_per += m_destory_per;
		m_destory_per = 0;
	}

	money = resultcost.calculteCost(curlv, elv, antikey);

	m_success_rate = ((float)m_success_per / 1'000'000) * 100;
	m_failure_rate = ((float)m_failure_per / 1'000'000) * 100;
	m_destroy_rate = ((float)m_destory_per / 1'000'000) * 100;

	//cout << fixed << setprecision(2);
	//cout << "성공 확률: " << m_success_rate << ", 실패 확률: " << m_failure_rate << ", 파괴 확률: " << m_destroy_rate << endl;
	if (antikey && (15 <= curlv && curlv <= 17)) {
	//	cout << "파괴방지 사용으로 200% 추가 증가 --> ";
	}
	locale::global(locale(""));
	cout.imbue(locale());

	//cout << "현재 강화 비용: " << money << endl;

	m_money_cnt += money;
}

void Reinforce::compareRate(int copylv, int g_lv, bool starcatch)
{
	if (starcatch) {
		cout << copylv << "레벨 부터 " << g_lv << "레벨 까지 스타캐치 적용된 각 구간 별 강화 횟수 및 확률 비교" << endl;
		for (int i = copylv; i < g_lv; ++i) {
			cout << "================" << endl;
			cout << "현재 " << i << "단계에서의 전체 강화 횟수: " << sectioncount[i] << endl;
			cout << "현재 " << i << "단계에서의 성공 횟수: " << successcount[i] << endl;
			cout << "현재 " << i << "단계에서의 실패 횟수: " << failurecount[i] << endl;
			cout << "현재 " << i << "단계에서의 파괴 횟수: " << destorycount[i] << endl;

			successCRate[i] = (float)(successcount[i]) / (float)(sectioncount[i]) * 100;
			failureCRate[i] = (float)(failurecount[i]) / (float)(sectioncount[i]) * 100;
			destoryCRate[i] = (float)(destorycount[i]) / (float)(sectioncount[i]) * 100;

			m_success_rate = ((float)PercentageRate.CatchData[i].m_successRate / 1'000'000) * 100;
			m_failure_rate = ((float)PercentageRate.CatchData[i].m_failureRate / 1'000'000) * 100;
			m_destroy_rate = ((float)PercentageRate.CatchData[i].m_destroyRate / 1'000'000) * 100;

			cout << "현재 " << i << "단계에서 표기된 성공 확률: " << m_success_rate << ", 시뮬레이터 확률: " << successCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 실패 확률: " << m_failure_rate << ", 시뮬레이터 확률: " << failureCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 파괴 확률: " << m_destroy_rate << ", 시뮬레이터 확률: " << destoryCRate[i] << endl;
			cout << "================" << endl;
		}
	}
	else {
		cout << copylv << "레벨 부터 " << g_lv << "레벨 까지 스타캐치 적용된 각 구간 별 강화 횟수 및 확률 비교" << endl;
		for (int i = copylv; i < g_lv; ++i) {
			cout << "================" << endl;
			cout << "현재 " << i << "단계에서의 전체 강화 횟수: " << sectioncount[i] << endl;
			cout << "현재 " << i << "단계에서의 성공 횟수: " << successcount[i] << endl;
			cout << "현재 " << i << "단계에서의 실패 횟수: " << failurecount[i] << endl;
			cout << "현재 " << i << "단계에서의 파괴 횟수: " << destorycount[i] << endl;

			successCRate[i] = (float)(successcount[i]) / (float)(sectioncount[i]) * 100;
			failureCRate[i] = (float)(failurecount[i]) / (float)(sectioncount[i]) * 100;
			destoryCRate[i] = (float)(destorycount[i]) / (float)(sectioncount[i]) * 100;

			m_success_rate = ((float)PercentageRate.basicData[i].m_successRate / 1'000'000) * 100;
			m_failure_rate = ((float)PercentageRate.basicData[i].m_failureRate / 1'000'000) * 100;
			m_destroy_rate = ((float)PercentageRate.basicData[i].m_destroyRate / 1'000'000) * 100;

			cout << "현재 " << i << "단계에서 표기된 성공 확률: " << m_success_rate << ", 시뮬레이터 확률: " << successCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 실패 확률: " << m_failure_rate << ", 시뮬레이터 확률: " << failureCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 파괴 확률: " << m_destroy_rate << ", 시뮬레이터 확률: " << destoryCRate[i] << endl;
			cout << "================" << endl;
		}
	}
	export_result_to_csv(successCRate, failureCRate, destoryCRate, copylv, g_lv);
}

void Reinforce::reinforc_repeat_sequence(int c_lv, int e_lv, bool antikey, bool starcatch)
{
	repeat_Arranged_Percentage(c_lv, e_lv, antikey, starcatch);

	string resultMsg = Determine_Outcome();

	sectioncount[c_lv]++;

	if (resultMsg == "Success") {
		successcount[c_lv]++;
		m_suc_cnt++;
	}
	else if (resultMsg == "Fail") {
		failurecount[c_lv]++;
		m_fail_cnt++;
	}
	else {
		destorycount[c_lv]++;
		m_destory_cnt++;
	}
}

void Reinforce::repeat_Arranged_Percentage(int curlv, int elv, bool antikey, bool starcatch)
{
	int money{};
	if (starcatch) {
		m_success_per = PercentageRate.CatchData[curlv].m_successRate;
		m_failure_per = PercentageRate.CatchData[curlv].m_failureRate;
		m_destory_per = PercentageRate.CatchData[curlv].m_destroyRate;
	}
	else {
		m_success_per = PercentageRate.basicData[curlv].m_successRate;
		m_failure_per = PercentageRate.basicData[curlv].m_failureRate;
		m_destory_per = PercentageRate.basicData[curlv].m_destroyRate;
	}

	if (antikey && (15 <= curlv && curlv <= 17)) {
		m_failure_per += m_destory_per;
		m_destory_per = 0;
	}

	money = resultcost.calculteCost(curlv, elv, antikey);

	m_success_rate = ((float)m_success_per / 1'000'000) * 100;
	m_failure_rate = ((float)m_failure_per / 1'000'000) * 100;
	m_destroy_rate = ((float)m_destory_per / 1'000'000) * 100;

	MoneyCount[curlv] += money;

	m_money_cnt += money;
}

void Reinforce::repeat_compareRate(int copylv, bool starcatch)
{
	if (starcatch) {
		cout << copylv << "레벨의 강화 횟수 및 확률 빈도" << endl;

		cout << "================" << endl;
		cout << "현재 " << copylv << "단계에서의 전체 강화 횟수: " << sectioncount[copylv] << endl;
		cout << "현재 " << copylv << "단계에서의 성공 횟수: " << successcount[copylv] << endl;
		cout << "현재 " << copylv << "단계에서의 실패 횟수: " << failurecount[copylv] << endl;
		cout << "현재 " << copylv << "단계에서의 파괴 횟수: " << destorycount[copylv] << endl;

		successCRate[copylv] = (float)(successcount[copylv]) / (float)(sectioncount[copylv]) * 100;
		failureCRate[copylv] = (float)(failurecount[copylv]) / (float)(sectioncount[copylv]) * 100;
		destoryCRate[copylv] = (float)(destorycount[copylv]) / (float)(sectioncount[copylv]) * 100;

		m_success_rate = ((float)PercentageRate.CatchData[copylv].m_successRate / 1'000'000) * 100;
		m_failure_rate = ((float)PercentageRate.CatchData[copylv].m_failureRate / 1'000'000) * 100;
		m_destroy_rate = ((float)PercentageRate.CatchData[copylv].m_destroyRate / 1'000'000) * 100;

		cout << fixed << setprecision(2);

		cout << "현재 " << copylv << "단계에서 표기된 성공 확률: " << m_success_rate << ", 시뮬레이터 확률: " << successCRate[copylv] << endl;
		cout << "현재 " << copylv << "단계에서 표기된 실패 확률: " << m_failure_rate << ", 시뮬레이터 확률: " << failureCRate[copylv] << endl;
		cout << "현재 " << copylv << "단계에서 표기된 파괴 확률: " << m_destroy_rate << ", 시뮬레이터 확률: " << destoryCRate[copylv] << endl;
		cout << "================" << endl;
	}
	else {
		cout << copylv << "레벨의 강화 횟수 및 확률 빈도" << endl;

		cout << "================" << endl;
		cout << "현재 " << copylv << "단계에서의 전체 강화 횟수: " << sectioncount[copylv] << endl;
		cout << "현재 " << copylv << "단계에서의 성공 횟수: " << successcount[copylv] << endl;
		cout << "현재 " << copylv << "단계에서의 실패 횟수: " << failurecount[copylv] << endl;
		cout << "현재 " << copylv << "단계에서의 파괴 횟수: " << destorycount[copylv] << endl;

		successCRate[copylv] = (float)(successcount[copylv]) / (float)(sectioncount[copylv]) * 100;
		failureCRate[copylv] = (float)(failurecount[copylv]) / (float)(sectioncount[copylv]) * 100;
		destoryCRate[copylv] = (float)(destorycount[copylv]) / (float)(sectioncount[copylv]) * 100;

		m_success_rate = ((float)PercentageRate.basicData[copylv].m_successRate / 1'000'000) * 100;
		m_failure_rate = ((float)PercentageRate.basicData[copylv].m_failureRate / 1'000'000) * 100;
		m_destroy_rate = ((float)PercentageRate.basicData[copylv].m_destroyRate / 1'000'000) * 100;

		cout << fixed << setprecision(2);

		cout << "현재 " << copylv << "단계에서 표기된 성공 확률: " << m_success_rate << ", 시뮬레이터 확률: " << successCRate[copylv] << endl;
		cout << "현재 " << copylv << "단계에서 표기된 실패 확률: " << m_failure_rate << ", 시뮬레이터 확률: " << failureCRate[copylv] << endl;
		cout << "현재 " << copylv << "단계에서 표기된 파괴 확률: " << m_destroy_rate << ", 시뮬레이터 확률: " << destoryCRate[copylv] << endl;
		cout << "================" << endl;
	}
}

void Reinforce::repeat_csv_compareRate(int copylv, int g_lv, bool starcatch)
{
	if (starcatch) {
		cout << copylv << "레벨 부터 " << g_lv - 1 << "레벨 까지 스타캐치 적용된 각 구간 별 강화 횟수 및 확률 비교" << endl;
		for (int i = copylv; i < g_lv; ++i) {
			cout << "================" << endl;
			cout << "현재 " << i << "단계에서의 전체 강화 횟수: " << sectioncount[i] << endl;
			cout << "현재 " << i << "단계에서의 성공 횟수: " << successcount[i] << endl;
			cout << "현재 " << i << "단계에서의 실패 횟수: " << failurecount[i] << endl;
			cout << "현재 " << i << "단계에서의 파괴 횟수: " << destorycount[i] << endl;

			successCRate[i] = (float)(successcount[i]) / (float)(sectioncount[i]) * 100;
			failureCRate[i] = (float)(failurecount[i]) / (float)(sectioncount[i]) * 100;
			destoryCRate[i] = (float)(destorycount[i]) / (float)(sectioncount[i]) * 100;

			m_success_rate = ((float)PercentageRate.CatchData[i].m_successRate / 1'000'000) * 100;
			m_failure_rate = ((float)PercentageRate.CatchData[i].m_failureRate / 1'000'000) * 100;
			m_destroy_rate = ((float)PercentageRate.CatchData[i].m_destroyRate / 1'000'000) * 100;

			cout << "현재 " << i << "단계에서 표기된 성공 확률: " << m_success_rate << ", 시뮬레이터 확률: " << successCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 실패 확률: " << m_failure_rate << ", 시뮬레이터 확률: " << failureCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 파괴 확률: " << m_destroy_rate << ", 시뮬레이터 확률: " << destoryCRate[i] << endl;
			cout << "현재 " << i << "에서 사용된 비용: " << MoneyCount[i] << endl;
			cout << "================" << endl;
		}
	}
	else {
		cout << copylv << "레벨 부터 " << g_lv << "레벨 까지 스타캐치 적용된 각 구간 별 강화 횟수 및 확률 비교" << endl;
		for (int i = copylv; i < g_lv; ++i) {
			cout << "================" << endl;
			cout << "현재 " << i << "단계에서의 전체 강화 횟수: " << sectioncount[i] << endl;
			cout << "현재 " << i << "단계에서의 성공 횟수: " << successcount[i] << endl;
			cout << "현재 " << i << "단계에서의 실패 횟수: " << failurecount[i] << endl;
			cout << "현재 " << i << "단계에서의 파괴 횟수: " << destorycount[i] << endl;
			cout << "현재 " << i << "에서 사용된 비용: " << MoneyCount[i] << endl;


			successCRate[i] = (float)(successcount[i]) / (float)(sectioncount[i]) * 100;
			failureCRate[i] = (float)(failurecount[i]) / (float)(sectioncount[i]) * 100;
			destoryCRate[i] = (float)(destorycount[i]) / (float)(sectioncount[i]) * 100;

			m_success_rate = ((float)PercentageRate.basicData[i].m_successRate / 1'000'000) * 100;
			m_failure_rate = ((float)PercentageRate.basicData[i].m_failureRate / 1'000'000) * 100;
			m_destroy_rate = ((float)PercentageRate.basicData[i].m_destroyRate / 1'000'000) * 100;

			cout << "현재 " << i << "단계에서 표기된 성공 확률: " << m_success_rate << ", 시뮬레이터 확률: " << successCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 실패 확률: " << m_failure_rate << ", 시뮬레이터 확률: " << failureCRate[i] << endl;
			cout << "현재 " << i << "단계에서 표기된 파괴 확률: " << m_destroy_rate << ", 시뮬레이터 확률: " << destoryCRate[i] << endl;

			cout << "================" << endl;
		}
	}
	export_result_to_csv(successCRate, failureCRate, destoryCRate, copylv, g_lv);
}

int Reinforce::reinforce_costCSV_sequence(int c_lv, int g_lv, int e_lv, bool antikey, bool starcatch)
{
	costCSV_Arranged_Percentage(c_lv, e_lv, antikey, starcatch);

	string resultMsg = Determine_Outcome();

	sectioncount[c_lv]++;

	if (resultMsg == "Success") {
		successcount[c_lv]++;
		c_lv++;
		m_suc_cnt++;
	}
	else if (resultMsg == "Fail") {
		failurecount[c_lv]++;
		m_fail_cnt++;
	}
	else {
		destorycount[c_lv]++;
		c_lv = 12;
		m_destory_cnt++;
	}

	return c_lv;
}

void Reinforce::costCSV_Arranged_Percentage(int curlv, int elv, bool antikey, bool starcatch)
{
	int money{};
	if (starcatch) {
		m_success_per = PercentageRate.CatchData[curlv].m_successRate;
		m_failure_per = PercentageRate.CatchData[curlv].m_failureRate;
		m_destory_per = PercentageRate.CatchData[curlv].m_destroyRate;
	}
	else {
		m_success_per = PercentageRate.basicData[curlv].m_successRate;
		m_failure_per = PercentageRate.basicData[curlv].m_failureRate;
		m_destory_per = PercentageRate.basicData[curlv].m_destroyRate;
	}

	if (antikey && (15 <= curlv && curlv <= 17)) {
		m_failure_per += m_destory_per;
		m_destory_per = 0;
	}

	money = resultcost.calculteCost(curlv, elv, antikey);

	m_success_rate = ((float)m_success_per / 1'000'000) * 100;
	m_failure_rate = ((float)m_failure_per / 1'000'000) * 100;
	m_destroy_rate = ((float)m_destory_per / 1'000'000) * 100;

	MoneyCount[curlv] += money;

	m_money_cnt += money;
}

void Reinforce::reset_all_data()
{
	m_success_per = 0.0f;
	m_failure_per = 0.0f;
	m_destory_per = 0.0f;

	// Count_seq
	m_suc_cnt = {};
	m_fail_cnt = {};
	m_destory_cnt = {};
	m_money_cnt = {};

	memset(sectioncount, 0, 30 * sizeof(int));
	memset(successcount, 0, 30 * sizeof(int));
	memset(failurecount, 0, 30 * sizeof(int));
	memset(destorycount, 0, 30 * sizeof(int));
	memset(successCRate, 0, 30 * sizeof(int));
	memset(failureCRate, 0, 30 * sizeof(int));
	memset(destoryCRate, 0, 30 * sizeof(int));
	memset(MoneyCount, 0, 30 * sizeof(long long));

	m_success_rate = {};
	m_failure_rate = {};
	m_destroy_rate = {};
}

void Reinforce::printresult(int i)
{
	locale::global(locale(""));
	cout.imbue(locale());
	cout << "최종 결과" << endl;
	if (i == 1) {
		cout << "총 성공 횟수: " << m_suc_cnt << endl;
		cout << "총 실패 횟수: " << m_fail_cnt << endl;
		cout << "총 파괴 횟수: " << m_destory_cnt << endl;
		cout << "총 횟수: " << calcCnt() << endl;
	}
	cout << "사용 메소: " << m_money_cnt << endl;
}

void Reinforce::export_result_to_csv(const float success[], const float fail[], const float destroy[], int from, int to) {
	const string& filename = "starforce_compare_rate_result.csv";
	ofstream file(filename);

	if (!file.is_open()) {
		std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
		return;
	}

	// 헤더 작성
	file << "Level,Success,Fail,Destroy\n";
	file << std::fixed << std::setprecision(2);

	for (int i = from; i < to; ++i) {
		file << i << ","
			<< success[i] << ","
			<< fail[i] << ","
			<< destroy[i] << "\n";
	}

	file.close();
	std::cout << "CSV 파일 저장 완료: " << filename << std::endl;
}

void Reinforce::export_costresult_to_csv(int from, int to, int e_lv, bool antikey)
{
	const string& filename = "starforce_costresult.csv";
	ofstream file(filename);

	if (!file.is_open()) {
		std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
		return;
	}

	// 헤더 작성
	file << "Level,Cost,signedCost\n";
	int money{};
	long long tempm{};
	for (int i = from; i < to; ++i) {

		money = resultcost.calculteCost(i, e_lv, antikey);
		tempm = MoneyCount[i] / sectioncount[i];
		file << i << ","
			<< tempm << ","
			<< money << "\n";

	}

	file.close();
	std::cout << "CSV 파일 저장 완료: " << filename << std::endl;
}
