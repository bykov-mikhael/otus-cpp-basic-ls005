#pragma once

#include <cmath>
#include <cstddef>
#include <limits>
#include <vector>
#include <numeric>

#include "IStatistics.h"

class CStd : public IStatistics {
public:
	CStd() : m_std{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_val.push_back(next);
	}

	double eval() const override {
		double m_val_avg = std::accumulate(m_val.begin(), m_val.end(), 0) / m_val.size();
		double dd = 0;
		for (size_t i=0; i<m_val.size()-1; i++) {
			dd = std::pow(m_val[i] - m_val_avg, 2); 
		}

		return std::sqrt(dd/m_val.size());
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