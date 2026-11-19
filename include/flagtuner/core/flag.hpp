#pragma once

#include <optional>
#include <string>

class Flag {
public:
    Flag(std::string name, bool enabledAtO3);

    std::string getName() const;
    bool isEnabledAtO3() const;

    std::optional<std::string> optionFor(bool wantEnabled) const;

private:
    std::string name_;
    bool enabledAtO3_;
};