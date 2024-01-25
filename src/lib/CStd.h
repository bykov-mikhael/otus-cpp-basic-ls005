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
		// <м> - среднее значение
		// суммируем все переменные в списке
		double m_val_avg = std::accumulate(m_val.begin(), m_val.end(), 0);
		// делим полученную сумму на кол-во элементов
		m_val_avg = m_val_avg / m_val.size();
		double dd = 0;
		// суммируем квадрат разности i-го элемента и <м>
		for (size_t i=0; i<m_val.size(); i++) {
			dd = std::pow(m_val[i] - m_val_avg, 2) + dd;
		}
	// полученный результат делим на кол-во элементов в списке и извлекаем квадратный корень
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