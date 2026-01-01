#define APPROVALS_CATCH2_V3
#include <ApprovalTests.hpp>
#include "Game.h"
#include "GameRunner_ForTesting.h"

// This puts "received" and "approved" files in approval_tests/ sub-directory,
// keeping the test source directory tidy:
auto directoryDisposer =
    ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests");

TEST_CASE("GameRunner_ForTesting::runMain RS 0", "Main test run: random seed 0")
{
    ApprovalTests::Approvals::verify(wrapperForMain(0));
}

TEST_CASE("GameRunner_ForTesting::runMain RS -586", "Main test run: random seed -586")
{
    ApprovalTests::Approvals::verify(wrapperForMain(-586));
}