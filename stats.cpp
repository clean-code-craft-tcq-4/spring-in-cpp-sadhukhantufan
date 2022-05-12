#include "stats.h"

Statistics::resultStats Statistics::ComputeStatistics(const std::vector<float> &inputVector)
{

    Statistics::resultStats l_obj;

    l_obj.min = *min_element(inputVector.begin(), inputVector.end());
    l_obj.max = *max_element(inputVector.begin(), inputVector.end());
    l_obj.average = std::accumulate(inputVector.begin(), inputVector.end(), 0.0);

    return l_obj;
}

// int main()
// {
    // auto result = Statistics::ComputeStatistics({1.2, 4.5, 6.1, 7.7});
    // std::cout << "min: " << result.min << " max: " << result.max << " avg: " << result.average << std::endl;
    // return 0;
// }
