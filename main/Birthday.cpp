#include "Birthday.h"

Birthday::Birthday(TodayProvider &todayProvider) : todayProvider(todayProvider) {

}

bool Birthday::IsBirthday() {
    return todayProvider.GetToday().month() == date::month{4} && todayProvider.GetToday().day() == date::day{9};
}
