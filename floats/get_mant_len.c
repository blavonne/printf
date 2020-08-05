int				get_mant_len(char *mantissa)
{
	int			i;
	int			end;

	i = 0;
	end = 0;
	while (mantissa && mantissa[i])
	{
		if (mantissa[i] == '1')
			end = i + 1;
		i++;
	}
	return (end);
}
