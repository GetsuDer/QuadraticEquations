#include <iostream>
#include <cstdlib>
#include <cmath>

#include "test_lib.h"
#include "../Include/quadratic_equations.h"

void
test_solve_quadratic_equation()
{
    double first_root = NAN, second_root = NAN, a = NAN, b = NAN, c = NAN;
    int root_number = 0, returned_root_number = 0;
    double tmp1 = NAN, tmp2 = NAN;

    while (scanf("%lf%lf%lf", &a, &b, &c) == ARG_NUM) {
        if (scanf("%d", &root_number) != 1) {
            printf("error in test file\n");
            break;
        }
        TEST_BEGIN;
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
        TEST_END;
    }

    return;
}

void
test_is_zero()
{
    TEST_BEGIN;
    TEST(is_zero(0), true);
    TEST_END;

    TEST_BEGIN;
    TEST(is_zero(1), false);
    TEST_END;

    TEST_BEGIN;
    TEST(is_zero(1e-7), true);
    TEST_END;

    TEST_BEGIN;
    TEST(is_zero(2 * (1e-6)), false);
    TEST_END;
    
    return;
}

void
test_solve_linear_equation()
{
    int roots_number = 0;
    double root = NAN;

    TEST_BEGIN;
    roots_number = solve_linear_equation(0, 0, root);
    TEST(roots_number, INF_ROOTS);
    TEST_END;
    
    TEST_BEGIN;
    roots_number = solve_linear_equation(0, 1, root);
    TEST(roots_number, ZERO_ROOTS);
    TEST_END;
    
    TEST_BEGIN;
    roots_number = solve_linear_equation(2, 4, root);
    TEST(is_zero(root + 2), true);
    TEST_END;

}

void 
test_discriminant_calculator()
{
    double discr = NAN;

    TEST_BEGIN;
    discr = discriminant_calculator(0, 0, 0);
    TEST(is_zero(discr), true);
    TEST_END;

    TEST_BEGIN;
    discr = discriminant_calculator(1, 1, 1);
    TEST(is_zero(discr + 3), true);
    TEST_END;

    TEST_BEGIN;
    discr = discriminant_calculator(3, 4, -5);
    TEST(is_zero(discr - 76), true);
    TEST_END;
    
    TEST_BEGIN;
    discr = discriminant_calculator(0, 0, 1);
    TEST(is_zero(discr), true);
    TEST_END;
    
    TEST_BEGIN;
    discr = discriminant_calculator(0, 2, 0);
    TEST(is_zero(discr - 4), true);
    TEST_END;
    
    TEST_BEGIN;
    discr = discriminant_calculator(0.001, 2, 0.05);
    TEST(is_zero(discr - 3.9998), true);
    TEST_END;
    
}

int
main()
{
    test_solve_quadratic_equation();
    test_is_zero();
    test_solve_linear_equation();
    test_discriminant_calculator();
    return 0;
}
