#include <iostream>
#include "test_lib.h"
#include "quadratic_equations.h"
#include <typeinfo>

int 
main()
{
    double first_root, second_root;

    TEST(solve_quadratic_equation(0, 0, 0, first_root, second_root), -1);
    TEST(solve_quadratic_equation(1, 2, 1, first_root, second_root), 1);
    TEST(is_zero(first_root + 1), true);
    
    TEST(solve_quadratic_equation(1, 0, 0, first_root, second_root), 1);
    TEST(is_zero(first_root), true);

    TEST(solve_quadratic_equation(0, 1, 0, first_root, second_root), 1);
    TEST(is_zero(first_root), true);

    TEST(solve_quadratic_equation(0, 1, 2, first_root, second_root), 1);
    TEST(is_zero(first_root + 2), true);
    
    TEST(solve_quadratic_equation(0, 0, 1, first_root, second_root), 0);
    TEST(solve_quadratic_equation(1, 0, -1, first_root, second_root), 2);
    TEST(is_zero(first_root - 1), true);
    TEST(is_zero(second_root + 1), true);

    TEST(solve_quadratic_equation(0.123, 0.456, 0.789, first_root, second_root), 0);
    
    TEST(solve_quadratic_equation(12.5, -100, 1, first_root, second_root), 2);
    TEST(is_zero(second_root - 0.01001253134799), true);
    TEST(is_zero(first_root - 7.98998746865), true);

    TEST(solve_quadratic_equation(1, 0.0003, 0, first_root, second_root), 2);
    TEST(is_zero(first_root), true);
    TEST(is_zero(second_root + 0.0003), true);

    TEST(solve_quadratic_equation(-12, 144, -1, first_root, second_root), 2);
    TEST(is_zero(second_root - 11.99305153212173), true);
    TEST(is_zero(first_root - 0.00694846787826601), true);

    TEST_SUMMARY;
    return 0;
}
