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

struct EmailAlert
{
	bool m_emailSent;
	EmailAlert()
	: m_emailSent(false)
	{
	}
	
	EmailAlert(bool mailSent)
	: m_emailSent(mailSent)
	{
	}
};

struct LEDAlert
{
	bool m_ledGlows;
	LEDAlert()
	:m_ledGlows(false)
	{
	}
	
	LEDAlert(bool ledGlows)
	:m_ledGlows(ledGlows)
	{
	}
};

struct Alerter: public EmailAlert, public LEDAlert
{
    Alerter()
    {
    }
	Alerter(EmailAlert emailAlert, LEDAlert ledAlert)
	: m_emailAlert(emailAlert)
	, m_LEDAlert(ledAlert)
	{
	}

   EmailAlert m_emailAlert;
   LEDAlert m_LEDAlert;

};

struct StatsAlerter : public Alerter
{
	
public:
   
   StatsAlerter(const float maxThreshold, Alerter alerter);
   void checkAndAlert(const std::vector<float>& scoreVector);
   
   float m_maxThreadshold;
   Alerter m_alerter;
   
};
