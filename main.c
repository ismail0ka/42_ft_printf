# include "ft_printf.h"
# include <stdio.h>

int	main(void)
{
    // Test with a simple string
    ft_printf("Hello, World!\n");
    printf("Hello, World!\n");
    ft_printf("Hello, %s!\n", NULL);

    // Test with integers
    ft_printf("Number: %d\n", 42);
    printf("Number: %d\n", 42);

    // Test with multiple arguments
    ft_printf("Multiple: %d, %s, %c\n", 42, "test", 'A');
    printf("Multiple: %d, %s, %c\n", 42, "test", 'A');

    // Test with hexadecimal
    ft_printf("Hex: %x\n", 255);
    printf("Hex: %x\n", 255);

    // Test with pointers
    int a = 42;
    ft_printf("Pointer: %p\n", &a);
    printf("Pointer: %p\n", &a);
    ft_printf("Pointer: %p\n", NULL);

    // Test with unsigned integers
    ft_printf("Unsigned: %u\n", 3000000000U);
    printf("Unsigned: %u\n", 3000000000U);

    //Test with char
    ft_printf("Char: %c\n", 'A');
    printf("Char: %c\n", 'A');

    // Test with special characters
    ft_printf("Special: %%\n");
    printf("Special: %%\n");
    return (0);
}