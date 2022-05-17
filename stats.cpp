#include "stats.h"

Statistics::resultStats Statistics::ComputeStatistics(const std::vector<float> &inputVector)
{

    // Object to access resultStats structure member and store data in it.
    Statistics::resultStats l_obj;

    // Checks if inputVector is empty or not.
    if (!inputVector.empty())
    {
        l_obj.min = *min_element(inputVector.begin(), inputVector.end());
        l_obj.max = *max_element(inputVector.begin(), inputVector.end());
    }
    // If inputVector is empty average will result to NaN, otherwise it will calculate normal average.
    l_obj.average = (std::accumulate(inputVector.begin(), inputVector.end(), 0.0)) / inputVector.size();

    return l_obj;
}

void StatsAlerter::checkAndAlert(const std::vector<float> &inputVector, EmailAlert &email, LEDAlert &led, const float maxThreshold)
{
    // Stores the maximum/largest element from the vector.
    float max = *max_element(inputVector.begin(), inputVector.end());

    // Check if largest element from the vector is greater than maxThreshold.
    if (max > maxThreshold)
    {
        // Set emailSent and ledGlows to True.
        email.emailSent = true;
        led.ledGlows = true;
    }
    else
    {
        // Set emailSent and ledGlows to False.
        email.emailSent = false;
        led.ledGlows = false;
    }
}
