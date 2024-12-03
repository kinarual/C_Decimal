# Тип decimal

Реализация собственной библиотеки s21_decimal.h для возможности работы с типом «decimal».

Тип Decimal представляет десятичные числа в диапазоне от положительных 79,228,162,514,264,337,593,543,950,335 до отрицательных 79,228,162,514,264,337,593,543,950,335. Значение Decimal по умолчанию равно 0. Decimal подходит для финансовых расчетов, которые требуют большого количества значимых целых и дробных цифр и отсутствия ошибок округления.

Decimal число - это значение с плавающей точкой, состоящее из знака, числового значения, где каждая цифра находится в диапазоне от 0 до 9, и коэффициента масштабирования, который указывает положение десятичной точки, разделяющей целые и дробные части числового значения.

Двоичное представление Decimal состоит из 1-разрядного знака, 96-разрядного целого числа и коэффициента масштабирования, используемого для деления 96-разрядного целого числа и указания того, какая его часть является десятичной дробью. Коэффициент масштабирования неявно равен числу 10, возведенному в степень в диапазоне от 0 до 28. Следовательно, двоичное представление Decimal имеет вид ((от -2^96 до 2^96) / 10^(от 0 до 28)), где -(2^96-1) равно минимальному значению, а 2^96-1 равно максимальному значению.

Коэффициент масштабирования также может сохранять любые конечные нули в Decimal. Эти конечные нули не влияют на значение в арифметических операциях или операциях сравнения.

### Арифметические операторы

| Название оператора | Оператор | Функция                                                                     |
| ------------------ | -------- | --------------------------------------------------------------------------- |
| Сложение           | +        | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal \*result) |
| Вычитание          | -        | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal \*result) |
| Умножение          | \*       | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal \*result) |
| Деление            | /        | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal \*result) |

### Операторы сравнение

| Название оператора | Оператор | Функция                                               |
| ------------------ | -------- | ----------------------------------------------------- |
| Меньше             | <        | int s21_is_less(s21_decimal, s21_decimal)             |
| Меньше или равно   | <=       | int s21_is_less_or_equal(s21_decimal, s21_decimal)    |
| Больше             | \>       | int s21_is_greater(s21_decimal, s21_decimal)          |
| Больше или равно   | \>=      | int s21_is_greater_or_equal(s21_decimal, s21_decimal) |
| Равно              | ==       | int s21_is_equal(s21_decimal, s21_decimal)            |
| Не равно           | !=       | int s21_is_not_equal(s21_decimal, s21_decimal)        |

### Преобразователи

| Преобразователь | Функция                                                     |
| --------------- | ----------------------------------------------------------- |
| Из int          | int s21_from_int_to_decimal(int src, s21_decimal \*dst)     |
| Из float        | int s21_from_float_to_decimal(float src, s21_decimal \*dst) |
| В int           | int s21_from_decimal_to_int(s21_decimal src, int \*dst)     |
| В float         | int s21_from_decimal_to_float(s21_decimal src, float \*dst) |

### Другие функции

| Описание                                                                                                   | Функция                                                   |
| ---------------------------------------------------------------------------------------------------------- | --------------------------------------------------------- |
| Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности.        | int s21_floor(s21_decimal value, s21_decimal \*result)    |
| Округляет Decimal до ближайшего целого числа.                                                              | int s21_round(s21_decimal value, s21_decimal \*result)    |
| Возвращает целые цифры указанного Decimal числа; любые дробные цифры отбрасываются, включая конечные нули. | int s21_truncate(s21_decimal value, s21_decimal \*result) |
| Возвращает результат умножения указанного Decimal на -1.                                                   | int s21_negate(s21_decimal value, s21_decimal \*result)   |
