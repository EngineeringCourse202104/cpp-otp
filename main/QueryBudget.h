#ifndef CPP_OTP_QUERYBUDGET_H
#define CPP_OTP_QUERYBUDGET_H


#include "BudgetRepo.h"
#include "date.h"

using namespace date;

class QueryBudget {

public:
    QueryBudget(BudgetRepo &budgetRepo);

    uint32_t Query(const year_month_day &startDate, const year_month_day &endDate);
};


#endif //CPP_OTP_QUERYBUDGET_H