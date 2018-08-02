#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include <string>

class AuthenticationService {

public:
    bool isValid(const std::string userName, const std::string password);
};


#endif //CPP_OTP_AUTHENTICATIONSERVICE_H
