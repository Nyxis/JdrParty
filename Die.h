
#ifndef MMADI_MOURTADHOI_DIE_H
#define MMADI_MOURTADHOI_DIE_H
#include "RandomDrawResult.h"

class Die : public RandomDrawResult {

    Die(int numFaces);
    Die(const std::vector<int>& faces);

    int roll() override;

private:
    std::vector<int> m_faces;
};

#endif //MMADI_MOURTADHOI_DIE_H
