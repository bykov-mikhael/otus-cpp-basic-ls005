#pragma once

#include <limits>
#include "IStatistics.h"

class CPct90 : public IStatistics {
public:
	CPct90() : m_pct90{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_sum = m_sum + next;
	}

	double eval() const override {
		return 90*(m_sum+1)/100;
	}

	const char * name() const override {
		return "pct90";
	}

private:
	double m_sum;
	double m_pct90;
};

