#ifndef H_TEST_LIB
#define H_TEST_LIB

//! This variable counts number of tests which were run by macro TEST
int number_of_tests = 0;

//! This variable counts number of successfully passed tests
int passed = 0;

//! This variable counts number of unsuccessfully passed tests
int failed = 0;

//! This varaible shows the current test state
bool test_state = true;

//! This should be written at the beginning of the each test
#define TEST_BEGIN \
    test_state = true;\
    number_of_tests++;

//! This macro compares the arguments and updates the test state
#define TEST(code, result) \
    if (code != result) {\
        test_state = false;\
    }

//! This macro means the end of the current test
#define TEST_END \
    if (test_state) {\
        std::cerr << COLOR_GREEN << "[PASSED]" << COLOR_WHITE;\
    } else {\
        failed++;\
        std::cerr << COLOR_RED << "[FAILED]" << COLOR_WHITE;\
    }\
    std::cerr << "Test # " <<  number_of_tests  << std::endl;\


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

#endif



void test_is_zero();
void test_solve_linear_equation();
void test_solve_quadratic_eqaution();
void test_discriminant_calculator();
