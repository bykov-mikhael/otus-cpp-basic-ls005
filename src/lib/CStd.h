#pragma once

#include <cmath>
#include <cstddef>
#include <limits>
#include <vector>
#include <numeric>

#include "IStatistics.h"

class CStd : public IStatistics {
public:
	CStd() = default;

	void update(double next) override {
		m_val.push_back(next);
	}

	double eval() const override {
		// <м> - среднее значение
		// суммируем все переменные в списке, делим полученную сумму на кол-во элементов
		double m_val_avg = std::accumulate(m_val.begin(), m_val.end(), 0.0) / m_val.size();
		double dd = 0;
		// суммируем квадрат разности i-го элемента и <м>
		for (auto i_val : m_val) {
			dd += std::pow(i_val - m_val_avg, 2);
		}
	// полученный результат делим на кол-во элементов в списке и извлекаем квадратный корень
		return std::sqrt(dd/(m_val.size()-1));
	}

	const std::string name() const override {
		return "std";
	}

private:
	std::vector<double> m_val;
	double m_std;
	double m_mean;
	double m_count = 0;
};