#ifndef AUTH_H
#define AUTH_H

#include <string>

extern bool isLogined;
extern std::string username;

void login(std::string username, std::string password);

#endif // AUTH_H