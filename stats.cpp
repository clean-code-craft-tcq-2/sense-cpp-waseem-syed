#include "stats.h"
#include<algorithm>

Stats Statistics::computeStatistics(const std::vector<float>& scoreVector)
{
	Stats computedStats(-1, -1, -1);

	if(false == scoreVector.empty())
	{
	   computedStats.m_max = computedStats.m_min = *scoreVector.begin();
	   float sum = 0;
	   for(unsigned int it = 0; it < scoreVector.size() ; it++)
	   {
	      	sum += scoreVector[it];
		computedStats.m_max = std::max(computedStats.m_max, scoreVector[it]);
		computedStats.m_min = std::min(computedStats.m_min, scoreVector[it]);
	   }
	   computedStats.m_average = sum / scoreVector.size();
	}
	return computedStats;
}

StatsAlerter::StatsAlerter(const float maxThreshold, Alerter alerter)
     : m_maxThreadshold(maxThreshold)
     , m_alerter(alerter)
{
}

void StatsAlerter::checkAndAlert(const std::vector<float>& scoreVector)
{
	float maxValue = *scoreVector.begin();
	for(unsigned int it = 0; it < scoreVector.size() ; it++)
	{
		maxValue = std::max(maxValue, scoreVector[it]);
	}
    if(maxValue > m_maxThreadshold)
	{
        m_alerter.m_emailAlert.m_emailSent = true;
        m_alerter.m_LEDAlert.m_ledGlows = true;
	}

}
