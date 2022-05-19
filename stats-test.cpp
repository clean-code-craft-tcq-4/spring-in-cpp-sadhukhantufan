#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <cmath>

TEST_CASE("reports average, minimum and maximum")
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array")
{
    auto computedStats = Statistics::ComputeStatistics({});
    // All fields of computedStats (average, max, min) must be
    // NAN (not-a-number), as defined in math.h
    std::cout << computedStats.average << std::endl;
    REQUIRE(std::isnan(computedStats.average));
}

TEST_CASE("raises alerts when max is greater than threshold")
{
    StatsAlerter::EmailAlert emailAlert;
    StatsAlerter::LEDAlert ledAlert;
    // std::vector<bool *> alerters = {&emailAlert.emailSent, &ledAlert.ledGlows};

    const float maxThreshold = 10.2;
    // StatsAlerter::StatsAlerter statsAlerter(maxThreshold, alerters);

    StatsAlerter::checkAndAlert({99.8, 34.2, 4.5, 6.7}, emailAlert, ledAlert, maxThreshold);

    REQUIRE(emailAlert.emailSent);
    REQUIRE(ledAlert.ledGlows);
}
