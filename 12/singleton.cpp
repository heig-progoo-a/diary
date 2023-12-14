#include <iostream>
#include <random>
class Logger {
    int logger_id;
    Logger() : logger_id(rand()%100) {}
public:
    static Logger* instance() {
        static Logger logger;
        return &logger;
    }

    void warning(std::string msg) {
        std::cout << "Logger " << logger_id << ": Warning: " << msg << std::endl;
    }
    void error(std::string msg) {
        std::cout << "Logger " << logger_id << ": Error: " << msg << std::endl;
    }
};

void foo() {
    Logger::instance()->error("oops");
}

int main() {
    
    Logger::instance()->warning("oops");
    foo();
    foo();
}