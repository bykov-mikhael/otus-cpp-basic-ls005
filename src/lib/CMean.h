#pragma once

#include <limits>

class CMean : public IStatistics {
public:
	CMean() : m_mean{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_mean = m_mean + next;
		m_count++;
	}

	double eval() const override {
		return m_mean/m_count;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean;
	double m_count = 0;
};

