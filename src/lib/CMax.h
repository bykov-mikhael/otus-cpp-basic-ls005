#pragma once

#include <limits>
#include "IStatistics.h"

class CMax : public IStatistics {
public:
	CMax() : m_max{0} {
	}

	void update(double next) override {
		/**
		 * Проверка на первое число последовательности. Если первое число последовательно, оно принимается максимальным
		*/
		if (m_first)
		{
			m_max = next;
			m_first = false;
		}
		
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const std::string name() const override {
		return "max";
	}

private:
	double m_max;
	bool m_first = true;
};