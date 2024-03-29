#ifndef RANDOM_RESULT_HPP
#define RANDOM_RESULT_HPP

#include <string>

class RandomResult {
public:
    enum ResultType { SUCCESS, CRIT_SUCCESS, FAILURE, FUMBLE };

    RandomResult(ResultType type);

    ResultType getType() const;
    std::string getTypeString() const;

private:
    ResultType type;
};

#endif
