
#include "RandomDraw.h"

RandomDraw::RandomDraw(const std::vector<RandomDrawResult>& results) :
        m_results(results) {}

RandomDrawResult::ResultType RandomDraw::draw() {

    int index = std::rand() % m_results.size();


    return m_results[index].draw();
}
