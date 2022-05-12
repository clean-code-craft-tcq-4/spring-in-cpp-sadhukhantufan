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

    resultStats ComputeStatistics(const std::vector<float> &inputVector);

}
