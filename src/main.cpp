/**
 * 
 * Формулировка задания
 * На вход (стандартный ввод) приложению подаётся последовательность (заранее неизвестного
 * размера) числовых значений. Приложение должно в ходе своей работы считать всю
 * последовательность из стандартного ввода и вывести на экран набор следующих статистических
 * характеристик:
 * - min – минимальное значение из последовательности
 * - max – максимальное значение из последовательности
 * - mean – арифметическое среднее, посчитанное на основе всех элементов последовательности
 * - std - среднеквадратическое отклонение
 * - [опционально] pct90 - 90-й процентиль
 * - [опционально] pct95 - 95-й процентиль
 * Остановка ввода последовательности предполагается путём передачи признака EOF (End Of File). В
 * Windows это делается путём следующего набора команд: Ctrl+Z, Enter. В Linux это делается путём
 * нажатия Ctrl+D.
 * Пример работы приложения:
 * > statistics
 * 0 1 2 3 4 5 6 7 8 9 10
 * min = 0
 * max = 10
 * mean = 5
 * std = 3.162277
 * pct90 = 9
 * pct95 = 10
 * Стоит заметить, что результаты могут отличаться в зависимости от реализации. Так, например,
 * некоторые реализации могут выдать значение pct95 = 9.5. Или значения std, отличные от того, что
 * указано выше, за счёт иного округления результата.
 * Уточнения по реализации - расчёт каждого вида статистики должен представлять собой отдельный класс,
 * представляющий собой наследника класса IStatistics и реализующий чисто виртуальную функции последнего
 **/


#include <iostream>

#include "class/IStatistics.h"
//Минимальное значение
#include "class/CMin.h"
//Максимальное значение
#include "class/CMax.h"
//Среднее значение
#include "class/CMean.h"
//Дисперсия
#include "class/CStd.h"
//Процентиль 90%
#include "class/CPct90.h"
//процентиль 95%
#include "class/CPct95.h"

int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count] = {new CMin{},	//минимальное значение
												 new CMax{},	//максимальное значение
												 new CMean{},	//среднее значение
												 new CStd{},	//ср кв отклонение
												 new CPct90{},	//процентиль 90%
												 new cPct95{}};	//процентиль 95%

	double val = 0.0;
	
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}
			
	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}
