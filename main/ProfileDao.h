#ifndef CPP_OTP_PROFILEDAO_H
#define CPP_OTP_PROFILEDAO_H

#include <string>

class ProfileDao {

public:
    std::string getPassword(const std::string userName);
};

#endif //CPP_OTP_PROFILEDAO_H
