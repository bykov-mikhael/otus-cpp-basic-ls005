#pragma once

#include <limits>
#include <vector>
#include <numeric>
#include "IStatistics.h"

class CMean : public IStatistics {
public:
	CMean() : m_mean{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_val.push_back(next);
	}

	double eval() const override {
		double m_val_avg = std::accumulate(m_val.begin(), m_val.end(), 0);
		return m_val_avg / m_val.size();
	}

	const char * name() const override {
		return "mean";
	}

private:
	std::vector<double> m_val;
	double m_mean;
	double m_count = 0;
};

