#include <cstdio>
#include <cmath>

#ifndef H_QUADRATIC_EQUATIONS
#define H_QUADRATIC_EQUATIONS
#include "quadratic_equations.h"
#endif

//! \brief This functions solves quadratic equation
//! \param [in] a, b, c Coefficients of the equation a * x ^ 2 + b * x + c = 0
//! \param [out] first_root The first root of the equation
//! \param [out] second_root The second root of the equation
//! \return Returns the number of roots of this equation (one, two, zero or inf (INF_ROOTS)

int
solve_quadratic_equation(double a, double b, double c, double &first_root, double &second_root)
{
    if (is_zero(a)) {
        if (is_zero(b)) {
            if (is_zero(c)) {
                return INF_ROOTS;
            } else {
                return ZERO_ROOTS;
            }
        } else {
            first_root = - c / b;
            return ONE_ROOT;
        }
    } else {
        double discriminant = b * b - 4 * a * c;
        if (is_zero(discriminant)) {
            first_root = - b / (2 * a);
            return ONE_ROOT;
        } else {
            if (discriminant < -EPS) {
                return ZERO_ROOTS;
            } else {
                double discriminant_sqrt = sqrt(discriminant);
                first_root = (- b + discriminant_sqrt) / (2 * a);
                second_root = (- b - discriminant_sqrt) / (2 * a);
                return TWO_ROOTS;
            }
        }
    }
    return 0;
}


//!\brief This function reads coefficients and prints the answer in format \"number of roots, roots\"
void
in_and_out()
{
    double a = NAN, b = NAN, c = NAN;
    printf("Write the coefficients of equation ax^2 + bx + c = 0, please\n");

    while (scanf("%lf%lf%lf", &a, &b, &c) != ARG_NUM) {
        printf("Wrong input, try again, please\n");
    }

    double first_root = 0, second_root = 0;
    int number_of_roots = solve_quadratic_equation(a, b, c, first_root, second_root);
    if (number_of_roots == TWO_ROOTS) {
        printf("%d %lf %lf\n", TWO_ROOTS, first_root, second_root);
    } else {
        if (number_of_roots == ONE_ROOT) {
            printf("%d %lf\n", ONE_ROOT, first_root);
        } else {
            if (number_of_roots == ZERO_ROOTS) {
                printf("%d\n", ZERO_ROOTS);
            } else {
                printf("%d\n", INF_ROOTS);
            }
        }
    }
    return;
}

//! \brief This function checks fractional number for proximity to zero
//! \param [in] d Number to check
//! \param [in] eps Max difference between values which are understood as same
//! \return Returns true, if the argument is pretty close to zero
bool 
is_zero(double d, double eps)
{
    return fabs(d) < eps;
}
