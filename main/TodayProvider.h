#ifndef CPP_OTP_TODAYPROVIDER_H
#define CPP_OTP_TODAYPROVIDER_H

#include "date.h"

class TodayProvider {

public:
    virtual date::year_month_day GetToday();

};


#endif //CPP_OTP_TODAYPROVIDER_H
