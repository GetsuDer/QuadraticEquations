//!This variable means the distance between two float numbers when there are interpreted as the same one
constexpr double EPS = 0.000001;

//! Values for number of roots
constexpr int TWO_ROOTS = 2, ONE_ROOT = 1, ZERO_ROOTS = 0, INF_ROOTS = -1;

//! Number of input arguments
constexpr int ARG_NUM = 3;

bool is_zero(double d, double eps = EPS);
void in_and_out();
int solve_quadratic_equation(double a, double b, double c, double &first_root, double &second_root);
