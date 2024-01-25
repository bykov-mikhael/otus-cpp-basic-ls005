#pragma once

#include <limits>
#include "IStatistics.h"
/**
 * * Инициализация происходила минимальным значением double. В случае если последовательность была 0+,
 * * минимальное значение так и оставалось минимальным значением doule
*/
class CMin : public IStatistics {
public:
	CMin() : m_min{0} {
	}

	void update(double next) override {
		/**
		 * Проверка на первое число последовательности. Если первое число последовательно, оно принимается минимальным
		*/
		if (m_first)
		{
			m_min = next;
			m_first = false;
		}
		
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
	bool m_first = true;
};