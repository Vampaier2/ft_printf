/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:26:29 by xalves            #+#    #+#             */
/*   Updated: 2025/05/16 12:21:34 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	detect_conversion(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	if (c == 'p')
		return (ft_handle_point(va_arg(arg, unsigned long), 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	if (c == 'u')
		return (ft_putdecimal_int(va_arg(arg, unsigned int), 1));
	if (c == 'x')
		return (ft_handle_hex(va_arg(arg, int), 1, 0));
	if (c == 'X')
		return (ft_handle_hex(va_arg(arg, int), 1, 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		count;

	count = 0;
	i = 0;
	if (!str || write(1, 0, 0) == -1)
		return (-1);
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (va_end(arg), -1);
			count += detect_conversion(str[i + 1], arg);
			i += 2;
		}
		else
		{
			count += ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	return (va_end(arg), count);
}

/*
//cc ft_printf.c ft_putstr_fd.c ft_putnbr_fd.c
//ft_handle_hex.c ft_putchar_fd.c ft_handle_point.c ft_putdecimal_int.c
int main(void)
{
	int ret1, ret2;

	// Test case 1: Single % at the end of the string (invalid format)
	ret1 = ft_printf("\nft: This ends with a percent sign: %");
	ret2 = printf("\nog: This ends with a percent sign: %");
	printf("\nReturn ft: %d | og: %d\n\n", ret1, ret2);
	// Should return an error code (e.g. -1)

	return (0);
}*/

/*
//cc -Wall -Werror -Wextra ft_printf.c ft_putstr_fd.c ft_putnbr_fd.c
//ft_handle_hex.c ft_putchar_fd.c ft_handle_point.c ft_putdecimal_int.c
int	main(void)
{
	int	ret1, ret2;

	ret1 = ft_printf("ft: Char: %c\n", 'A');
	ret2 = printf("og: Char: %c\n", 'A');
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");
	ret1 = ft_printf("ft: String: %s\n", "Hello");
	ret2 = printf("og: String: %s\n", "Hello");
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");
		printf("\n\n");

	ret1 = ft_printf("ft: Empty string: %s\n", "");
	ret2 = printf("og: Empty string: %s\n", "");
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	int a = 42;
	ret1 = ft_printf("ft: Pointer: %p\n", &a);
	ret2 = printf("og: Pointer: %p\n", &a);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: Null ptr: %p\n", NULL);
	ret2 = printf("og: Null ptr: %p\n", NULL);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: Signed: %d\n", -12345);
	ret2 = printf("og: Signed: %d\n", -12345);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: INT_MIN: %d\n", INT_MIN);
	ret2 = printf("og: INT_MIN: %d\n", INT_MIN);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: Unsigned: %u\n", 4294967295u);
	ret2 = printf("og: Unsigned: %u\n", 4294967295u);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: Hex lower: %x\n", 48879);
	ret2 = printf("og: Hex lower: %x\n", 48879);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: Hex upper: %X\n", 48879);
	ret2 = printf("og: Hex upper: %X\n", 48879);
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);
	printf("\n\n");

	ret1 = ft_printf("ft: Percent sign: %%\n");
	ret2 = printf("og: Percent sign: %%\n");
	printf("Return ft: %d | og: %d\n\n", ret1, ret2);

	return (0);
} */
