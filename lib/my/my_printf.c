/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** take args and print them
*/

#include "my.h"

void display_octal(int src)
{
    int res = 0;
    int mem = 0;
    int space = 1;

    while (src) {
        res = res + ((src % 8) * space);
        src = src / 8;
        space = space * 10;
    }
    my_put_nbr(res);
}

void display_bin(int src)
{
    unsigned int res = 0;
    int mem = 0;
    unsigned int space = 1;

    while (src) {
        res = res + ((src % 2) * space);
        src = src / 2;
        space = space * 10;
    }
    my_put_nbr(res);
}

char *hexa_in_maj(char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] >= 'a' && src[i] <= 'f')
            src[i] = src[i] - 32;
    }
    return (src);
}

void display_hexa(int src, int is_maj)
{
    int mem = 0;
    char *res = malloc(sizeof(char) * 10);

    for (int i = 0; src; i++) {
        mem = src % 16;
        src = src / 16;
        if (mem < 10)
            res[i] = mem + '0';
        else
            res[i] = mem + 'a' - 10;
    }
    if (is_maj == 1)
        res = hexa_in_maj(res);
    my_putstr(my_revstr(res));
    free(res);
}

void my_printf(char *args, ...)
{
    va_list ap;
    unsigned int i;
    char *s;

    va_start(ap, args);
    for (char *format = args; *format != '\0'; format++) {
        if (*format == '%') {
            *format++;
            switch (*format) {
                case '%' :
                    my_putchar('%');
                    break;
                case 'c' :
                    my_putchar(va_arg(ap, int));
                    break;
                case 's' :
                    my_putstr(va_arg(ap, char *));
                    break;
                case 'S' :
                    my_putstr(va_arg(ap, char *));
                    break;
                case 'd' :
                    my_put_nbr(va_arg(ap, int));
                    break;
                case 'i' :
                    my_put_nbr(va_arg(ap, int));
                    break;
                case 'o' :
                    display_octal(va_arg(ap, int));
                    break;
                case 'x' :
                    display_hexa(va_arg(ap, int), 0);
                    break;
                case 'X' :
                    display_hexa(va_arg(ap, int), 1);
                    break;
                case 'b' :
                    display_bin(va_arg(ap, int));
                    break;
            }
        } else if (*format == '\\'){
            *format++;
            switch(*format) {
                case '\\' :
                    my_putchar('\\');
                    break;
                case '\"' :
                    my_putchar('\"');
                    break;
                case 'b' :
                    break;
            }
        } else {
            my_putchar(*format);
        }
    }
    va_end(ap);
}