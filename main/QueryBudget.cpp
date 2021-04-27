#include "QueryBudget.h"

QueryBudget::QueryBudget(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}

uint32_t QueryBudget::Query(const year_month_day &startDate, const year_month_day &endDate) {
    uint32_t sum = 0;

    for (const auto &item : budgetRepo.FindAll()) {
        sum += 10 * getOverlappingDayCount(startDate, endDate, item);
    }

    return sum;
}

int
QueryBudget::getOverlappingDayCount(const year_month_day &startDate, const year_month_day &endDate,
                                    const Budget &budget) const {
    auto overlappingStart = startDate > budget.month / 1 ? startDate : budget.month / 1;
    auto overlappingEnd = endDate < budget.month / last ? endDate : budget.month / last;
    if (overlappingStart > overlappingEnd) {
        return 0;
    }
    return (overlappingEnd.day() - overlappingStart.day()).count() + 1;
}

