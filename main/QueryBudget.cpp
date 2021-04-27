#include "QueryBudget.h"

QueryBudget::QueryBudget(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}

uint32_t QueryBudget::Query(const year_month_day &startDate, const year_month_day &endDate) {
    auto all = budgetRepo.FindAll();
    if (all.size() == 0)
        return 0;

    return 10 * getOverlappingDayCount(startDate, endDate, *all.begin());
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

