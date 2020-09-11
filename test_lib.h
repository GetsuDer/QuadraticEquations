
//! This variable counts number of tests which were run by macro TEST
int number_of_tests = 0;

//! This variable counts number of successfully passed tests
int passed = 0;

//! This variable counts number of unsuccessfully passed tests
int failed = 0;
//! This macro compares the arguments and prints the info about the test
#define TEST(code, result) \
{\
    number_of_tests++;\
    if (code == result) {\
        passed++;\
        std::cerr << COLOR_GREEN << "[PASSED]" << COLOR_WHITE;\
    } else {\
        failed++;\
        std::cerr << COLOR_RED << "[FAILED]" << COLOR_WHITE;\
    }\
    std::cerr << " in file " <<  __FILE__ << std::endl;\
}
//! This macro can be started to see the results of previous tests
#define TEST_SUMMARY \
{\
    std::cerr << "total tests: " << number_of_tests << std::endl;\
    std::cerr << "passed: " << passed << std::endl;\
    std::cerr << "failed: " << failed << std::endl;\
    if (failed) {\
        std::cerr << COLOR_RED << "testing unsuccessfull" << COLOR_WHITE << std::endl;\
    } else {\
        std::cerr << COLOR_GREEN << "testing successfull" << COLOR_WHITE << std::endl;\
    }\
}\
//! Change the console text color to green
#define COLOR_GREEN "\x1b[32m"

//! Change the console text color to red
#define COLOR_RED "\x1b[31m"

//! Change the console text color to white
#define COLOR_WHITE "\x1b[0m"

constexpr double TEST_EPS = 0.0001;
