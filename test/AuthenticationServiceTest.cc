#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"

namespace {

    TEST(AuthenticationService, IsValid) {
        AuthenticationService target;

        bool actual = target.isValid("joey", "91000000");

        ASSERT_TRUE(actual);
    }

}