#include <vector>
#include <cmath>

struct Stats
{
	float m_average;
	float m_max;
	float m_min;

   Stats()
   {
   }
    
   Stats(float average,	float max, float min)
   : m_average(average)
   , m_max(max)
   , m_min(min)
   {
   }
};

class Statistics : public Stats
{
public:
	Statistics()
	{
	}
	static Stats computeStatistics(const std::vector<float>& scoreVector);
};
