set(Main_SRCS main.cpp AuthenticationService.cpp AuthenticationService.h ProfileDao.cpp ProfileDao.h RsaTokenDao.cpp RsaTokenDao.h Context.cpp Context.h)

add_library(core ${Main_SRCS})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} core)
