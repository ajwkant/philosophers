/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 11:47:16 by akant         #+#    #+#                 */
/*   Updated: 2021/11/18 13:17:50 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		atoi_failed(char *str, int x)
{
	if (x == 0 && str && str[0] != '0')
		return (1);
	else if (x == -1 && str && !(str[0] == '-' && str[1] == '1'))
		return (1);
	return (0);
}

int		whitespace_sign(const char *string, int *neg)
{
	int i;

	i = 0;
	*neg = 1;
	while (((unsigned char)string[i] >= 9 && (unsigned char)string[i] <= 13)
	|| (unsigned char)string[i] == 32)
		i++;
	if ((unsigned char)string[i] == '-' || (unsigned char)string[i] == '+')
	{
		if ((unsigned char)string[i] == '-')
			*neg = -1;
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	long int	num;
	int			neg;
	int			*negptr;
	int			i;

	negptr = &neg;
	num = 0;
	i = whitespace_sign(str, negptr);
	while ('0' <= (unsigned char)str[i] &&
	(unsigned char)str[i] <= '9' && num < 2147483648)
	{
		num = num * 10 + ((unsigned char)str[i] - '0');
		i++;
	}
	num *= neg;
	if (num < -2147483648)
		return (0);
	if (num > 2147483647)
		return (-1);
	return (num);
}