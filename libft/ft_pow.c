#include "printf.h"

double		ft_pow(double basis, int exponent)
{
	double			base;
	long long int	exp;

	if (exponent == 0)
		return (1);
	base = basis;
	exp = exponent;
	exp = exp < 0 ? -exp : exp;
	while (--exp)
		basis *= base;
	if (exponent < 0)
		return (1 / basis);
	else
		return (basis);
}
