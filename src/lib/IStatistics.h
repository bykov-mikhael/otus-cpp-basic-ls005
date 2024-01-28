#pragma once

/**
 * FIXME:
 * 1) В репозитории попали некоторые служебные и скрытые файлы (.cache/clangd/index, .clang-format, otus-cpp-basic-ls005.code-workspace) - лучше их тоже добавить в gitignore;
 * 2) Классы СPct90/CPct95 практически полностью идентичны друг другу за исключением констант (значением персентиля); возможно имеет смысл сделать единый класс, которому в конструкторе передавать значение персентиля;
 * 3) Значения статистик вычисляются не совсем корректно, например:
 * 1 2 3 4 5 6
 * ? min = 2.22507e-308 (очевидно, что должно быть 1)
 * max = 6
 * mean = 3.5
 * ? std = 19.2614 (значение слишком большое)
 * ? pct90 = 19.8 (должно попадать в отрезок [1;6])
 * ? pct95 = 20.9 (должно попадать в отрезок [1;6])
 * -4 -3 -2 -1 0
 * min = -4 
 * ? max = 2.22507e-308 (должно быть 0)
 * mean = -2 
 * ? std = 9.08295 (слишком большое)
 * ! pct90 = -8.1 (дожлно быть в отрезке [-4;0])
 * ! pct95 = -8.55 (дожлно быть в отрезке [-4;0])
 * Советую обратить внимание на число, которое инициализирует поля классов (std::numeric_limits<double>::min())
*/

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const std::string name() const = 0;
};