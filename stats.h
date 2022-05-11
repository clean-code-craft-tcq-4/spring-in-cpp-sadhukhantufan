#include <vector>
#include <iostream>
#include <array>
#include <cstring>
#include <numeric>
#include <bits/stdc++.h>

namespace Statistics
{
    struct resultStats
    {
        float average{0};
        float max{0};
        float min{0};
    };
    // Stats ComputeStatistics(const std::vector<___> &);
    // void ComputeStatistics(std::vector<std::array<float, 4>> &inputVector);
    resultStats ComputeStatistics(const std::vector<float> &inputVector);
    // void ComputeStatistics(const computedStats &inputVector);

}
