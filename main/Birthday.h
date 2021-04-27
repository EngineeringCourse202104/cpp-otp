#ifndef CPP_OTP_BIRTHDAY_H
#define CPP_OTP_BIRTHDAY_H


#include "TodayProvider.h"

class Birthday {

public:
    Birthday(TodayProvider &todayProvider);

    bool IsBirthday();

private:
    TodayProvider &todayProvider;
};


#endif //CPP_OTP_BIRTHDAY_H
