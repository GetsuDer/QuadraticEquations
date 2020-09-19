#include <cstdio>
#include <cmath>
#include <cassert>

#include "../Include/quadratic_equations.h"

//! \brief This functions solves quadratic equation
//! \param [in] a, b, c Coefficients of the equation a * x ^ 2 + b * x + c = 0
//! \param [out] first_root The first root of the equation
//! \param [out] second_root The second root of the equation
//! \return Returns the number of roots of this equation (one, two, zero or inf (INF_ROOTS)

int
solve_quadratic_equation(double a, double b, double c, double &first_root, double &second_root)
{
    assert(std::isfinite(a));
    assert(std::isfinite(a));
    assert(std::isfinite(a));

    if (is_zero(a)) {
        return solve_linear_equation(b, c, first_root);
    } else {
        double discriminant = discriminant_calculator(a, b, c);
        
        if (std::isnan(discriminant)) {
           return TOO_BIG_NUMBERS;
        }

        assert(std::isfinite(discriminant));

        if (is_zero(discriminant)) {
            first_root = - b / (2 * a);
            return ONE_ROOT;
        } else {
            if (discriminant < -EPS) {
                return ZERO_ROOTS;
            } else {
                assert(discriminant > EPS);
                double discriminant_sqrt = sqrt(discriminant);

                assert(std::isfinite(discriminant_sqrt));
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
    printf(HELLO);

    if (scanf("%lf %lf %lf", &a, &b, &c) != ARG_NUM) {
        printf(WRONG_INPUT);
        return;
    }

    if (!std::isfinite(a) || !std::isfinite(b) || !std::isfinite(c)) {
        printf(WRONG_INPUT);
        return;
    }

    double first_root = NAN, second_root = NAN;
    int number_of_roots = solve_quadratic_equation(a, b, c, first_root, second_root);
    
    printf(ROOT_NUMBER);
    if (number_of_roots == TWO_ROOTS) {
        
        assert(std::isfinite(first_root));
        assert(std::isfinite(second_root));
        
        printf("%d\n", TWO_ROOTS);

        printf(ROOTS);
        printf("%lf %lf\n", first_root, second_root);
    } else {
        if (number_of_roots == ONE_ROOT) {
            
            assert(std::isfinite(first_root));
            assert(std::isnan(second_root));
            
            printf("%d\n", ONE_ROOT);
            printf(ROOTS);
            printf("%lf\n", first_root);
        } else {

            assert(std::isnan(first_root));
            assert(std::isnan(second_root));
            
            if (number_of_roots == ZERO_ROOTS) {
                printf("%d\n", ZERO_ROOTS);
            } else {
                if (number_of_roots == INF_ROOTS) {
                    printf(INF);
                } else {
                    printf(SORRY);
                }
            }
        }
    }
    return;
}

//! \brief This function calculates discriminant of quadratic equation ax^2 + bx + c = 0 by formule b ^ 2 - 4 * a * c
//! \param [in] a, b, c Coefficients of quadratic equation
//! \return Return the value of discriminant
double
discriminant_calculator(double a, double b, double c)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    return b * b - 4 * a * c;
}

//! \brief This function checks fractional number for proximity to zero
//! \param [in] d Number to check
//! \param [in] eps Max difference between values which are understood as same
//! \return Returns true, if the argument is pretty close to zero
bool 
is_zero(double d, double eps)
{

    assert(std::isfinite(d));
    assert(std::isfinite(eps));

    return fabs(d) < eps;
}

//! \brief This function solves linear equation ax + b = 0
//! \param [in] a, b - Coefficients of the equation
//! \return Returns the number of roots - ONE_ROOT, ZERO_ROOTS or INF_ROOTS
int
solve_linear_equation(double a, double b, double &root) 
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));

    if (is_zero(a)) {
        if (is_zero(b)) {
            return INF_ROOTS;
        }
        return ZERO_ROOTS;
    }
    
    root = - b / a;
    return ONE_ROOT;
}
