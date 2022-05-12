#include "stats.h"

Statistics::resultStats Statistics::ComputeStatistics(const std::vector<float> &inputVector)
{

    Statistics::resultStats l_obj;

    if (!inputVector.empty())
    {
        l_obj.min = *min_element(inputVector.begin(), inputVector.end());
        l_obj.max = *max_element(inputVector.begin(), inputVector.end());
    }
    l_obj.average = (std::accumulate(inputVector.begin(), inputVector.end(), 0.0)) / inputVector.size();

    return l_obj;
}