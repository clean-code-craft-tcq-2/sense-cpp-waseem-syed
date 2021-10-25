#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <math.h> 

#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::computeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.m_average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.m_max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.m_min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    auto computedStats = Statistics::computeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
    
    REQUIRE(isnan(sqrt(computedStats.m_average)));
    REQUIRE(isnan(sqrt(computedStats.m_max)));
    REQUIRE(isnan(sqrt(computedStats.m_min)));
}

TEST_CASE("raises alerts when max is greater than threshold") {
   EmailAlert emailAlert;
   LEDAlert ledAlert;
   Alerter alerter(emailAlert, ledAlert);
    
    const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(maxThreshold, alerter);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    REQUIRE(statsAlerter.m_alerter.m_emailAlert.m_emailSent);
    REQUIRE( statsAlerter.m_alerter.m_LEDAlert.m_ledGlows);
}
