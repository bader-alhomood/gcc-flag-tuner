#include "flagtuner/core/flag.hpp"

Flag::Flag(std::string name, bool enabledAtO3)
    : name_(name), enabledAtO3_(enabledAtO3) {
}

std::string Flag::getName() const {
    return name_;
}

bool Flag::isEnabledAtO3() const {
    return enabledAtO3_;
}

std::optional<std::string> Flag::optionFor(bool wantEnabled) const {
    if (wantEnabled == enabledAtO3_) {
        return std::nullopt;    // Already in the desired state with nothing to add
    }
    if (wantEnabled) {
        return "-f" + name_;    // Turn flag on
    }

    return "-fno-" + name_;     // Turn flag off
}