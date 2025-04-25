#pragma once
#include <iostream>

using namespace std;

class Cost {
public:
	Cost();
	~Cost();

public:
	uint32_t result_cost{};

	uint32_t calculteCost(uint32_t s_lv, uint32_t i_lv, bool antikey);
};