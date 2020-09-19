#ifndef H_QUADRATIC_EQUATIONS
#define H_QUADRATIC_EQUATIONS

//!This variable means the distance between two float numbers when there are interpreted as the same one
constexpr double EPS = 1e-6;

//! Values for number of roots
constexpr int TWO_ROOTS = 2, ONE_ROOT = 1, ZERO_ROOTS = 0, INF_ROOTS = -1, TOO_BIG_NUMBERS = -2;

//! Number of input arguments
constexpr int ARG_NUM = 3;

#define HELLO "# Write the coefficients of equation ax ^ 2 + bx + c = 0, please\n"
#define WRONG_INPUT "# Sorry, your input is wrong, try again, please\n"
#define ROOT_NUMBER "# The equation is solved, the number of roots is:\n"
#define ROOTS "# These roots are:\n"
#define INF "INF"
#define SORRY "Sorry, your integers are too big for me. Try another equation."

bool is_zero(double d, double eps = EPS);
void in_and_out();
int solve_quadratic_equation(double a, double b, double c, double &first_root, double &second_root);
double discriminant_calculator(double a, double b, double c);
int solve_linear_equation(double a, double b, double &root);

#endif
