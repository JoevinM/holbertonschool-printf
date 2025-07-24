#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct specifier_f - Structure pour associer un spécificateur
 * à une fonction d'affichage.
 * @specifier: Chaîne représentant le spécificateur
 * (ex: "c", "s", "d", etc.).
 * @function: Pointeur de fonction correspondant prenant va_list en argument.
 *
 * Cette structure permet de faire correspondre un caractère de format
 * (comme ceux utilisés dans printf) à une fonction chargée d’afficher
 * l’argument correspondant depuis une liste d’arguments.
 */

typedef struct specifier_f
{
	char *specifier;
	int (*function)(va_list args);
} specifier_f;
int _printf(const char *format, ...);
int (*get_a_function(char s))(va_list);
int _putchar(char c);
int print_character(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
#endif
