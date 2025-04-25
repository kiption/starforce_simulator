#include "Cost.h"

Cost::Cost()
{

}

Cost::~Cost()
{

}

int Cost::calculteCost(int s_lv, int i_lv, bool antikey)
{
	result_cost = 0;
	if (s_lv < 10) {
		result_cost = 1000 + ((pow(i_lv, 3) * (s_lv + 1)) / 36);
	}
	else if (s_lv > 21 && s_lv < 30) {
		result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 200);
	}
	else {
		switch (s_lv)
		{
		case 10:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 571);
			break;
		case 11:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 314);
			break;
		case 12:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 214);
			break;
		case 13:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 157);
			break;
		case 14:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 107);
			break;
		case 15:
		case 16:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 200);
			if (antikey) {
				result_cost *= 3;
			}
			break;
		case 17:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 150);
			if (antikey) {
				result_cost *= 3;
			}
			break;
		case 18:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 70);
			break;
		case 19:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 45);
			break;
		case 20:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 200);
			break;
		case 21:
			result_cost = 1000 + ((pow(i_lv, 3) * pow((s_lv + 1), 2.7)) / 125);
			break;
		default:
			break;
		}
	}

	result_cost = static_cast<int>(round(result_cost / 100)) * 100;;

	return result_cost;
}
