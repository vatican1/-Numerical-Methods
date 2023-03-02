# Лаборатнорная 1

- Все сделанные задания упоминаются в readme
- Код задания с номером n находится в файле n.cpp
- Для запуска кода задания с номером n необходимо выполнить ./taskn.sh
- Для запуска скачать к себе

## Задание 1
![](/images/task1.jpg)

## Задание 2
Запуск ./task2.sh
```cpp
float polynomial (float x, const float* a, int n)
{
    float p = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        p = std::fma(x, p, a[i]);
    }
    return p;
}
```
![](/images/task2.jpg)

## Задание 3
Запуск ./task3.sh
```cpp
float kahan_sum(const float * x, int n)
{
	float s = 0;
    float c = 0;
    float y;
    float t;
	for (int i = 0; i < n; ++i){
		  y = x[i] - c;
		  t = s + y;
		  c = (t - s) - y;
		  s = t;
	}
	return s;
}
```

## Задание 4
Запуск ./task4.sh
```cpp
float pairwise_sum_simd(float* x, int n)
{
    int k = 2;
    while (k <= 2 * n)
    {
        #pragma omp simd
        for(int i = 0; i < n; i += k)
        {
            if(i + k / 2 < n) x[i] += x[i + k / 2];
        }
        k *= 2;
    }

    return x[0];
}
```
Как видно есть разница в ответе, и в случае большого теста быстрее работает обычная сумма с аккумулятором, что странно.

## Задание 5
Запуск ./task5.sh
```cpp
class Statistics {
private:
  bool start = false;
  int n = 0;
  float min_ = 0;
  float max_ = 0;
  float mean_ = 0;
  float square_ = 0;
  float variance_ = 0;
  float sum_ = 0;
public:
	void update(float x)
  {
    if (not start) min_ = x;
    if (not start) max_ = x;
    start = true;
    n++;
    sum_ += x;
		mean_ += (x - mean_) / n;
    float prev_mean = mean_;
    square_ += (x - prev_mean) * (x - mean_);
    variance_ = square_ / n;
	};
	int count() const noexcept { return n;}
	float min() const noexcept { return min_;}
	float max() const noexcept { return max_;}
	float sum() const noexcept { return sum_;}
	float mean() const noexcept { return mean_;}
	float variance() const noexcept { return variance_;}
};
```

## Задание 6
Запуск ./task6.sh
```cpp
float length(const float* x, int n){
    float max_ = x[0];
    float sq_sum = 1; 
    for (int i = 1; i < n; ++i)
    {
        if(abs(x[i]) > max_)
        {
            float prev_max = max_;
            max_ = abs(x[i]);
            float correction = prev_max / max_ * prev_max / max_;
            sq_sum *= correction;
            sq_sum += 1;
        }
        else
        {
            sq_sum += x[i] / max_ * x[i] / max_  ;
        }
    }
    return std::sqrt(sq_sum) * max_;
}
```