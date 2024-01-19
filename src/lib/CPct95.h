#pragma once

#include <limits>
#include "IStatistics.h"

class cPct95 : public IStatistics {
public:
	cPct95() : m_pct95{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_sum = m_sum + next;
	}

	double eval() const override {
		return 95*(m_sum+1)/100;
	}

	const char * name() const override {
		return "pct95";
	}

private:
	double m_sum;
	double m_pct95;
};

