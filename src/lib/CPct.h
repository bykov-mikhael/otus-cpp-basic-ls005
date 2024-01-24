#pragma once

#include <limits>
#include "IStatistics.h"

/**
 * ! переделать формулу перцентиля
*/

class CPct : public IStatistics {
public:
	CPct(double pct) : m_pct{pct} {
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
	double m_pct;
};