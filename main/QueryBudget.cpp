#include "QueryBudget.h"

QueryBudget::QueryBudget(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}

uint32_t QueryBudget::Query(const year_month_day &startDate, const year_month_day &endDate) {
    if (budgetRepo.FindAll().size() == 0)
        return 0;

    return 10 * getDayCount(startDate, endDate);
}

int
QueryBudget::getDayCount(const year_month_day &startDate, const year_month_day &endDate) const {
    return (endDate.day() - startDate.day()).count() + 1;
}

