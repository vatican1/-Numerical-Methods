#include <iostream>
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

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  float x[n];
  Statistics s;
  for(int i = 0; i < n; ++i)
  {
    float x =  atof(argv[i + 2]);
    std::cout << "add x = " << x << std::endl;
    s.update(x);
    std::cout << "count = "<< s.count() << ", min = " << s.min()
    << ", max = " << s.max() << ", sum = " << s.sum()
    << ", mean = " << s.mean() << ", variance = " << s.variance() << std::endl;
  }
}