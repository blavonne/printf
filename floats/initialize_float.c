#include "printf.h"

typedef union			u_xray
{
	long double			long_double;
	struct
	{
		unsigned char	b0 : 1;
		unsigned char	b1 : 1;
		unsigned char	b2 : 1;
		unsigned char	b3 : 1;
		unsigned char	b4 : 1;
		unsigned char	b5 : 1;
		unsigned char	b6 : 1;
		unsigned char	b7 : 1;
		unsigned char	b8 : 1;
		unsigned char	b9 : 1;
		unsigned char	b10 : 1;
		unsigned char	b11 : 1;
		unsigned char	b12 : 1;
		unsigned char	b13 : 1;
		unsigned char	b14 : 1;
		unsigned char	b15 : 1;
		unsigned char	b16 : 1;
		unsigned char	b17 : 1;
		unsigned char	b18 : 1;
		unsigned char	b19 : 1;
		unsigned char	b20 : 1;
		unsigned char	b21 : 1;
		unsigned char	b22 : 1;
		unsigned char	b23 : 1;
		unsigned char	b24 : 1;
		unsigned char	b25 : 1;
		unsigned char	b26 : 1;
		unsigned char	b27 : 1;
		unsigned char	b28 : 1;
		unsigned char	b29 : 1;
		unsigned char	b30 : 1;
		unsigned char	b31 : 1;
		unsigned char	b32 : 1;
		unsigned char	b33 : 1;
		unsigned char	b34 : 1;
		unsigned char	b35 : 1;
		unsigned char	b36 : 1;
		unsigned char	b37 : 1;
		unsigned char	b38 : 1;
		unsigned char	b39 : 1;
		unsigned char	b40 : 1;
		unsigned char	b41 : 1;
		unsigned char	b42 : 1;
		unsigned char	b43 : 1;
		unsigned char	b44 : 1;
		unsigned char	b45 : 1;
		unsigned char	b46 : 1;
		unsigned char	b47 : 1;
		unsigned char	b48 : 1;
		unsigned char	b49 : 1;
		unsigned char	b50 : 1;
		unsigned char	b51 : 1;
		unsigned char	b52 : 1;
		unsigned char	b53 : 1;
		unsigned char	b54 : 1;
		unsigned char	b55 : 1;
		unsigned char	b56 : 1;
		unsigned char	b57 : 1;
		unsigned char	b58 : 1;
		unsigned char	b59 : 1;
		unsigned char	b60 : 1;
		unsigned char	b61 : 1;
		unsigned char	b62 : 1;
		unsigned char	b63 : 1;
		unsigned int	exponent : 15;
		unsigned char	b79 : 1;
	} 					parts;
}						t_xray;

static void					set_mantissa3(int *i, t_float *res, t_xray *arg)
{
	res->mantissa[(*i)++] = (char)(arg->parts.b20 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b19 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b18 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b17 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b16 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b15 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b14 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b13 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b12 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b11 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b10 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b9 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b8 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b7 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b6 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b5 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b4 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b3 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b2 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b1 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b0 + 48);
}

static void					set_mantissa2(int *i, t_float *res, t_xray *arg)
{
	res->mantissa[(*i)++] = (char)(arg->parts.b43 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b42 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b41 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b40 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b39 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b38 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b37 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b36 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b35 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b34 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b33 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b32 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b31 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b30 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b29 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b28 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b27 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b26 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b25 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b24 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b23 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b22 + 48);
	res->mantissa[(*i)++] = (char)(arg->parts.b21 + 48);
	set_mantissa3(i, res, arg);
}

static void					set_mantissa(t_xray *arg, t_float *res)
{
	int			i;

	i = 0;
	res->mantissa[i++] = (char)(arg->parts.b63 + 48);
	res->mantissa[i++] = (char)(arg->parts.b62 + 48);
	res->mantissa[i++] = (char)(arg->parts.b61 + 48);
	res->mantissa[i++] = (char)(arg->parts.b60 + 48);
	res->mantissa[i++] = (char)(arg->parts.b59 + 48);
	res->mantissa[i++] = (char)(arg->parts.b58 + 48);
	res->mantissa[i++] = (char)(arg->parts.b57 + 48);
	res->mantissa[i++] = (char)(arg->parts.b56 + 48);
	res->mantissa[i++] = (char)(arg->parts.b55 + 48);
	res->mantissa[i++] = (char)(arg->parts.b54 + 48);
	res->mantissa[i++] = (char)(arg->parts.b53 + 48);
	res->mantissa[i++] = (char)(arg->parts.b52 + 48);
	res->mantissa[i++] = (char)(arg->parts.b51 + 48);
	res->mantissa[i++] = (char)(arg->parts.b50 + 48);
	res->mantissa[i++] = (char)(arg->parts.b49 + 48);
	res->mantissa[i++] = (char)(arg->parts.b48 + 48);
	res->mantissa[i++] = (char)(arg->parts.b47 + 48);
	res->mantissa[i++] = (char)(arg->parts.b46 + 48);
	res->mantissa[i++] = (char)(arg->parts.b45 + 48);
	res->mantissa[i++] = (char)(arg->parts.b44 + 48);
	set_mantissa2(&i, res, arg);
}


t_float					initialize_float(long double arg)
{
	t_xray		tmp;
	t_float		res;

	tmp.long_double = arg;
	res.sign = (char)(tmp.parts.b79 + 48);
	res.exponent = (int)(tmp.parts.exponent - (unsigned)16383);
	ft_bzero(res.mantissa, 65);
	set_mantissa(&tmp, &res);
	return (res);
}
