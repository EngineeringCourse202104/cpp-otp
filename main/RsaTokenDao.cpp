#include <iostream>
#include <iomanip>
#include <sstream>
#include "RsaTokenDao.h"

using namespace std;

std::string RsaTokenDao::getRandom(const std::string userName) {
    srand((unsigned)time(nullptr));
    ostringstream oss;
    oss << setw(6) << setfill('0') << rand() % 1000000;
    auto result = oss.str();
    cout << "randomCode:" << result << endl;

    return result;
}
