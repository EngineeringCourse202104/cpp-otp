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

class QueryBudgetTest : public Test {
protected:
    StubBudgetRepo stubBudgetRepo;
    QueryBudget queryBudget = QueryBudget(stubBudgetRepo);

    void givenBudgets(const vector<Budget> &budgets) {
        ON_CALL(stubBudgetRepo, FindAll()).WillByDefault(Return(budgets));
    }
};

TEST_F(QueryBudgetTest, NoBudget) {
    givenBudgets({});

    auto actual = queryBudget.Query(2013_y / 4 / 7, 2013_y / 4 / 7);

    ASSERT_EQ(0, actual);
}

TEST_F(QueryBudgetTest, StartEndSameDay) {
    givenBudgets({
                         {2013_y / 4, 300}
                 });

    auto actual = queryBudget.Query(2013_y / 4 / 7, 2013_y / 4 / 7);

    ASSERT_EQ(10, actual);
}

TEST_F(QueryBudgetTest, StartEndSameMonth) {
    givenBudgets({
                         {2013_y / 4, 300}
                 });

    auto actual = queryBudget.Query(2013_y / 4 / 7, 2013_y / 4 / 8);

    ASSERT_EQ(20, actual);
}
