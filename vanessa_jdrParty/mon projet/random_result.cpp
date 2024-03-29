#include "random_result.hpp"

RandomResult::RandomResult(ResultType type) : type(type) {}

RandomResult::ResultType RandomResult::getType() const {
    return type;
}

std::string RandomResult::getTypeString() const {
    switch (type) {
        case SUCCESS: return "Success";
        case CRIT_SUCCESS: return "Critical Success";
        case FAILURE: return "Failure";
        case FUMBLE: return "Fumble";
        default: return "Unknown";
    }
}
