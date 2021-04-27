#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/BudgetRepo.h"
#include "../main/QueryBudget.h"
#include "../main/date.h"

using namespace testing;
using namespace std;
using namespace date;

class StubBudgetRepo : public BudgetRepo {

public:
    MOCK_METHOD0(FindAll, vector<Budget>());
};

TEST(QueryBudget, NoBudget) {
    StubBudgetRepo stubBudgetRepo;
    ON_CALL(stubBudgetRepo, FindAll()).WillByDefault(Return(vector<Budget>()));
    QueryBudget queryBudget(stubBudgetRepo);

    auto actual = queryBudget.Query(2013_y / 4 / 7, 2013_y / 4 / 7);

    ASSERT_EQ(0, actual);
}