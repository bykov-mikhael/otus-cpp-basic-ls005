#pragma once

#include <limits>
#include <map>
#include <iostream>

#include "IStatistics.h"

/**
 * ! переделать формулу перцентиля опциональное задание
*/

class CPct : public IStatistics {
public:
	CPct(double pct) : m_pct{pct} {
	}

	void update(double next) override {
		m_data.insert(std::pair(next, next));
	}

	double eval() const override {
		double m_sum = 0;
		
		for (auto &[name, val] : m_data) {
			std::cout << val << " ";
  	}
		
		std::cout << std::endl;
		return {};
	}

	const std::string name() const override {
		return "pct" + std::to_string(m_pct);
	}

private:
	std::map<double, double, std::less<double>> m_data;
	size_t m_count = 0;
	double m_pct;
};