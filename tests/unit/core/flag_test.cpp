#include "flagtuner/core/flag.hpp"

#include <gtest/gtest.h>

// Each TEST(GroupName, TestName) checks one behaviour.

TEST(FlagTest, StoresNameAndDefaultState) {
    const Flag flag("unroll-loops", false);
    EXPECT_EQ(flag.getName(), "unroll-loops");
    EXPECT_FALSE(flag.isEnabledAtO3());
}

TEST(FlagTest, TurningOnAFlagThatO3LeavesOffGivesDashF) {
    const Flag flag("unroll-loops", false);
    EXPECT_EQ(flag.optionFor(true), "-funroll-loops");
}

TEST(FlagTest, TurningOffAFlagThatO3TurnsOnGivesDashFNo) {
    const Flag flag("tree-vectorize", true);
    EXPECT_EQ(flag.optionFor(false), "-fno-tree-vectorize");
}

TEST(FlagTest, NothingToAddWhenO3AlreadyMatches) {
    const Flag onAtO3("tree-vectorize", true);
    const Flag offAtO3("unroll-loops", false);
    EXPECT_FALSE(onAtO3.optionFor(true).has_value());
    EXPECT_FALSE(offAtO3.optionFor(false).has_value());
}