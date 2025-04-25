#pragma once
#include <iostream>

using namespace std;

class Cost {
public:
	Cost();
	~Cost();

public:
	int result_cost{};

	int calculteCost(int s_lv, int i_lv, bool antikey);
};