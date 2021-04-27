#include "gtest/gtest.h"
#include "../main/Birthday.h"

using namespace date;

class FakeTodayProvider : public TodayProvider {
public:
    date::year_month_day GetToday() override {
        return 2013_y / 4 / 9;
    }
};

TEST(Birthday, IsBirthday) {
    FakeTodayProvider fakeTodayProvider;
    Birthday birthday(fakeTodayProvider);

    ASSERT_TRUE(birthday.IsBirthday());
}