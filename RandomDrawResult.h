
#ifndef MMADI_MOURTADHOI_RANDOMDRAWRESULT_H
#define MMADI_MOURTADHOI_RANDOMDRAWRESULT_H


class RandomDrawResult {
public:
    enum class ResultType {
        SUCCESS,
        FAILURE,
        CRITICAL_SUCCESS,
        FUMBLE
};
RandomDrawResult(int successRate, int criticalRate, int fumbleRate);

    ResultType draw();

private:
    int m_successRate;
    int m_criticalRate;
    int m_fumbleRate;
};

#endif //MMADI_MOURTADHOI_RANDOMDRAWRESULT_H
