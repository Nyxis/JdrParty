
#ifndef MMADI_MOURTADHOI_RANDOMDRAW_H
#define MMADI_MOURTADHOI_RANDOMDRAW_H
#include <vector>
#include "RandomDrawResult.h"

class RandomDraw {
public:
    RandomDraw(const std::vector<RandomDrawResult>& results);

    RandomDrawResult::ResultType draw();

private:
    std::vector<RandomDrawResult> m_results;
};


#endif //MMADI_MOURTADHOI_RANDOMDRAW_H
