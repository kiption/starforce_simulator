#include <iostream>
#include <string>
#include "ReinforceSequence.h"

using namespace std;

Reinforce rf_func;

optionCheck checkbox{};

int main()
{
	// �Է� Ű

	// �ùķ����� ���� ����
	int selectOption{};

	// �ʿ� ����
	int cur_level{};	// ���� ��Ÿ���� ��ġ
	int goal_level{};	// ��ǥ ��Ÿ���� ��ġ
	int equip_level{};	// ��� ������ ����
	int copy_cur_lv{};	// �ʱ� ��Ÿ���� ��ġ

	bool antiDestroyCheck = false;
	bool compareKeyCheck = false;

	string inputkey{};

	int repeattime{};

	while (true) {
		system("cls");
		cout << "====================" << endl;
		cout << "Ȯ��/��� �ùķ�����" << endl;
		cout << "====================" << endl;

		cout << "�ùķ����� ���¸� �������ּ���. 1. �⺻ ��ȭ, 2. �� ���� �ݺ� ��ȭ, 3. ��� ���� �ݺ� ��ȭ(csv����), 4. �⺻ ��ȭ ��� ����, 5. ����" << endl;
		cin >> selectOption;
		switch (selectOption)
		{
		case 1:
			cout << "���� ��ȭ ���� �Է��� �ּ���. >>";
			cin >> cur_level;
			copy_cur_lv = cur_level;
			cout << "��ǥ ���� �Է��� �ּ���. >>";
			cin >> goal_level;
			cout << "��� ������ �Է��� �ּ���. >>";
			cin >> equip_level;
			cout << "�ݺ� Ƚ���� �������ּ���." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "��Ÿ ĳġ�� ����մϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			cout << "�ڵ� �ı� ������ ����մϱ�? Y/N" << endl;
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
			cout << "Ȯ�� �� �ϰڽ��ϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;
				rf_func.compareRate(copy_cur_lv, goal_level, checkbox.Onstarcatch);
			}

			rf_func.reset_all_data();
			cout << "������ ����" << endl;


			cout << "�����Ͻ÷��� q�� ������ �ǰ� ��� �Ͻ÷��� �ٸ� Ű�� ������ �˴ϴ�." << endl;
			cin >> inputkey;
			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;

		case 2:
			cout << "���� ��ȭ ���� �Է��� �ּ���. >>";
			cin >> cur_level;
			cout << "��� ������ �Է��� �ּ���. >>";
			cin >> equip_level;
			cout << "�ݺ� Ƚ���� �������ּ���." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "��Ÿ ĳġ�� ����մϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			if (cur_level >= 15 && cur_level <= 17) {
				cout << "�ı� ������ ����մϱ�? Y/N" << endl;
				cin >> inputkey;
				if (inputkey == "y" || inputkey == "Y") {
					checkbox.Onantidestroy = true;
				}
			}

			cout << "�ش� ����� ��� ������� �Ѿ�ϴ�." << endl;
			for (int i{}; i < repeattime; ++i) {
				rf_func.reinforc_repeat_sequence(cur_level, equip_level, checkbox.Onantidestroy, checkbox.Onstarcatch);
			}
			rf_func.printresult(selectOption);

			cout << "Ȯ�� �� �ϰڽ��ϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;

				rf_func.repeat_compareRate(cur_level, checkbox.Onstarcatch);
			}
			rf_func.reset_all_data();
			cout << "������ ����" << endl;

			cout << "�����Ͻ÷��� q�� ������ �ǰ� ��� �Ͻ÷��� �ٸ� Ű�� ������ �˴ϴ�." << endl;
			cin >> inputkey;

			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;
		case 3:
			cout << "��� ������ �Է��� �ּ���. >>";
			cin >> equip_level;
			cout << "�ݺ� Ƚ���� �������ּ���." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "��Ÿ ĳġ�� ����մϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			cout << "�ı� ������ ����մϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onantidestroy = true;
			}

			cout << "�ش� ����� ��� ������� �Ѿ�ϴ�." << endl;
			for (int starlv{}; starlv < 30; starlv++) {
				for (int i{}; i < repeattime; ++i) {
					rf_func.reinforc_repeat_sequence(starlv, equip_level, checkbox.Onantidestroy, checkbox.Onstarcatch);
				}
			}
			rf_func.printresult(selectOption);

			cout << "Ȯ�� �� �ϰڽ��ϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;
				rf_func.repeat_csv_compareRate(0, 30, checkbox.Onstarcatch);
			}
			rf_func.reset_all_data();
			cout << "������ ����" << endl;

			cout << "�����Ͻ÷��� q�� ������ �ǰ� ��� �Ͻ÷��� �ٸ� Ű�� ������ �˴ϴ�." << endl;
			cin >> inputkey;

			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;

		case 4:
			cout << "���� ��ȭ ���� �Է��� �ּ���. >>";
			cin >> cur_level;
			copy_cur_lv = cur_level;
			cout << "��ǥ ���� �Է��� �ּ���. >>";
			cin >> goal_level;
			cout << "��� ������ �Է��� �ּ���. >>";
			cin >> equip_level;
			cout << "�ݺ� Ƚ���� �������ּ���." << endl;
			cin >> repeattime;

			checkbox.Onantidestroy = false;
			checkbox.Oncomparecheck = false;
			checkbox.Onstarcatch = false;

			cout << "��Ÿ ĳġ�� ����մϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Onstarcatch = true;
			}

			cout << "�ڵ� �ı� ������ ����մϱ�? Y/N" << endl;
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

			cout << "��� �� �ϰڽ��ϱ�? Y/N" << endl;
			cin >> inputkey;
			if (inputkey == "y" || inputkey == "Y") {
				checkbox.Oncomparecheck = true;
				rf_func.export_costresult_to_csv(copy_cur_lv, goal_level, equip_level, checkbox.Onantidestroy);
			}

			rf_func.reset_all_data();
			cout << "������ ����" << endl;

			cout << "�����Ͻ÷��� q�� ������ �ǰ� ��� �Ͻ÷��� �ٸ� Ű�� ������ �˴ϴ�." << endl;
			cin >> inputkey;
			if (inputkey == "q" || inputkey == "Q") {
				break;
			}
			break;

		case 5:
			cout << "�����մϴ�." << endl;
			exit(0);
			break;

		default:
			cout << "�߸� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���." << endl;
			break;
		}
	}
}