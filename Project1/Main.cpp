#include <iostream>
#include <string>
#include "ReinforceSequence.h"

using namespace std;

Reinforce rf_func;

optionCheck checkbox{};

int main()
{
	// 입력 키

	// 시뮬레이터 형태 선택
	int selectOption{};

	// 필요 정보
	int cur_level{};	// 현재 스타포스 수치
	int goal_level{};	// 목표 스타포스 수치
	int equip_level{};	// 장비 아이템 레벨
	int copy_cur_lv{};	// 초기 스타포스 수치

	bool antiDestroyCheck = false;
	bool compareKeyCheck = false;

	string inputkey{};

	int repeattime{};

	while (true) {
		system("cls");
		cout << "====================" << endl;
		cout << "확률/비용 시뮬레이터" << endl;
		cout << "====================" << endl;

		cout << "시뮬레이터 형태를 설정해주세요. 1. 기본 강화, 2. 한 구간 반복 강화, 3. 모든 구간 반복 강화(csv추출), 4. 기본 강화 비용 추출, 5. 종료" << endl;
		cin >> selectOption;
		switch (selectOption)
		{
		case 1:
			cout << "현재 강화 성을 입력해 주세요. >>";
			cin >> cur_level;
			copy_cur_lv = cur_level;
			cout << "목표 성을 입력해 주세요. >>";
			cin >> goal_level;
			cout << "장비 레벨을 입력해 주세요. >>";
			cin >> equip_level;
			cout << "반복 횟수를 설정해주세요." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "스타 캐치를 사용합니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			cout << "자동 파괴 방지를 사용합니까? Y/N" << endl;
			cin >> inputkey;

			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onantidestroy = true;
			}
			for (int i{}; i < repeattime; ++i) {
				while (true) {
					cur_level = rf_func.reinforce_sequence(cur_level, goal_level, equip_level, checkbox.Onantidestroy, checkbox.Onstarcatch);
					if (cur_level == goal_level) {
						//rf_func.printresult(selectOption);
						cur_level = copy_cur_lv;
						break;
					}
				}
			}
			cout << "확률 비교 하겠습니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;
				rf_func.compareRate(copy_cur_lv, goal_level, checkbox.Onstarcatch);
			}

			rf_func.reset_all_data();
			cout << "시퀀스 종료" << endl;


			cout << "종료하시려면 q를 누르면 되고 계속 하시려면 다른 키를 누르면 됩니다." << endl;
			cin >> inputkey;
			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;

		case 2:
			cout << "현재 강화 성을 입력해 주세요. >>";
			cin >> cur_level;
			cout << "장비 레벨을 입력해 주세요. >>";
			cin >> equip_level;
			cout << "반복 횟수를 설정해주세요." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "스타 캐치를 사용합니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			if (cur_level >= 15 && cur_level <= 17) {
				cout << "파괴 방지를 사용합니까? Y/N" << endl;
				cin >> inputkey;
				if (inputkey == "y" || inputkey == "Y") {
					checkbox.Onantidestroy = true;
				}
			}

			cout << "해당 기능은 결과 출력으로 넘어갑니다." << endl;
			for (int i{}; i < repeattime; ++i) {
				rf_func.reinforc_repeat_sequence(cur_level, equip_level, checkbox.Onantidestroy, checkbox.Onstarcatch);
			}
			rf_func.printresult(selectOption);

			cout << "확률 비교 하겠습니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;

				rf_func.repeat_compareRate(cur_level, checkbox.Onstarcatch);
			}
			rf_func.reset_all_data();
			cout << "시퀀스 종료" << endl;

			cout << "종료하시려면 q를 누르면 되고 계속 하시려면 다른 키를 누르면 됩니다." << endl;
			cin >> inputkey;

			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;
		case 3:
			cout << "장비 레벨을 입력해 주세요. >>";
			cin >> equip_level;
			cout << "반복 횟수를 설정해주세요." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "스타 캐치를 사용합니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			cout << "파괴 방지를 사용합니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onantidestroy = true;
			}

			cout << "해당 기능은 결과 출력으로 넘어갑니다." << endl;
			for (int starlv{}; starlv < 30; starlv++) {
				for (int i{}; i < repeattime; ++i) {
					rf_func.reinforc_repeat_sequence(starlv, equip_level, checkbox.Onantidestroy, checkbox.Onstarcatch);
				}
			}
			rf_func.printresult(selectOption);

			cout << "확률 비교 하겠습니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;
				rf_func.repeat_csv_compareRate(0, 30, checkbox.Onstarcatch);
			}
			rf_func.reset_all_data();
			cout << "시퀀스 종료" << endl;

			cout << "종료하시려면 q를 누르면 되고 계속 하시려면 다른 키를 누르면 됩니다." << endl;
			cin >> inputkey;

			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;

		case 4:
			cout << "현재 강화 성을 입력해 주세요. >>";
			cin >> cur_level;
			copy_cur_lv = cur_level;
			cout << "목표 성을 입력해 주세요. >>";
			cin >> goal_level;
			cout << "장비 레벨을 입력해 주세요. >>";
			cin >> equip_level;
			cout << "반복 횟수를 설정해주세요." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "스타 캐치를 사용합니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			cout << "자동 파괴 방지를 사용합니까? Y/N" << endl;
			cin >> inputkey;

			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onantidestroy = true;
			}

			for (int i{}; i < repeattime; ++i) {
				while (true) {
					cur_level = rf_func.reinforce_costCSV_sequence(cur_level, goal_level, equip_level, checkbox.Onantidestroy, checkbox.Onstarcatch);

					if (cur_level == goal_level) {
						break;
					}
				}
			}
			//rf_func.printresult(selectOption);

			cout << "비용 비교 하겠습니까? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;
				rf_func.export_costresult_to_csv(copy_cur_lv, goal_level, equip_level, checkbox.Onantidestroy);
			}

			rf_func.reset_all_data();
			cout << "시퀀스 종료" << endl;

			cout << "종료하시려면 q를 누르면 되고 계속 하시려면 다른 키를 누르면 됩니다." << endl;
			cin >> inputkey;
			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;

		case 5:
			cout << "종료합니다." << endl;
			exit(0);
			break;

		default:
			cout << "잘못 입력하였습니다. 다시 입력해주세요." << endl;
			break;
		}
	}
}