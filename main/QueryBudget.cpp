#include "QueryBudget.h"

QueryBudget::QueryBudget(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}

uint32_t QueryBudget::Query(const year_month_day &startDate, const year_month_day &endDate) {
    if (budgetRepo.FindAll().size() == 0)
        return 0;

    return 10;
}
