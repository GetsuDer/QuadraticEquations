#include <iostream>

#ifndef H_TEST_LIB
#define H_TEST_LIB
#include "test_lib.h"
#endif

#ifndef H_QUADRATIC_EQUATIONS
#define H_QUADRATIC_EQUATIONS
#include "quadratic_equations.h"
#endif

int 
main()
{
    double first_root = 0, second_root = 0, a = 0, b = 0, c = 0;
    int root_number = 0, returned_root_number = 0;
    double tmp1, tmp2;

    while (scanf("%lf%lf%lf", &a, &b, &c) == ARG_NUM) {
        if (scanf("%d", &root_number) != 1) {
            printf("error in test file\n");
            break;
        }
        returned_root_number = solve_quadratic_equation(a, b, c, first_root, second_root);
        TEST(returned_root_number, root_number);

        switch (root_number)
        {
            case ONE_ROOT:
                if (scanf("%lf", &tmp1) != ONE_ROOT) {
                    printf("error in test file\n");
                }
                TEST(is_zero(first_root - tmp1, TEST_EPS), true);
                break;
            case TWO_ROOTS:
                if (scanf("%lf%lf", &tmp1, &tmp2) != TWO_ROOTS) {
                    printf("error in test file\n");
                }
                if (tmp1 > tmp2) {
                    std::swap(tmp1, tmp2);
                }
                if (first_root > second_root) {
                    std::swap(first_root, second_root);
                }
                TEST(is_zero(first_root - tmp1, TEST_EPS), true);
                TEST(is_zero(second_root - tmp2, TEST_EPS), true);
                break;
            default:
                break;
        }
    }

    TEST_SUMMARY;
    return 0;
}
