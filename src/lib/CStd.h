#pragma once

#include <cmath>
#include <cstddef>
#include <limits>
#include <vector>

#include "IStatistics.h"

class CStd : public IStatistics {
public:
	CStd() : m_std{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_val.push_back(next);
		m_mean = m_mean + next;
		m_count++;
	}

	double eval() const override {
		double dd = 0;

		for (size_t i=0; i<m_val.size(); i++) {
			dd = std::pow(m_val[i] - m_mean, 2) + dd; 
		}
		
		return std::sqrt(dd/(m_count-1));
	}

	const char * name() const override {
		return "std";
	}

private:
	std::vector<double> m_val;
	double m_std;
	double m_mean;
	double m_count = 0;
};

