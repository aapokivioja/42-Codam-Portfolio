#include "ft_printf.h"

int main(void)
{
	printf("ft: %i\n", ft_printf("%%%"));
	printf("og: %i\n", printf("%%%"));
}