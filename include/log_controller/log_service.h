#ifndef LOG_SERVICE_H
#define LOG_SERVICE_H

#include <string>

void addLog(std::string event, std::string name);
void warnLog(std::string event, std::string name);
void errorLog(std::string event, std::string name);


#endif // LOG_SERVICE_H