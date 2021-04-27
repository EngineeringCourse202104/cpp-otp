#ifndef CPP_OTP_BUDGETREPO_H
#define CPP_OTP_BUDGETREPO_H

#include <vector>
#include "Budget.h"

class BudgetRepo {

public:
    virtual std::vector<Budget> FindAll();
};


#endif //CPP_OTP_BUDGETREPO_H
