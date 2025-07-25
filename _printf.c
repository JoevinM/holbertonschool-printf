#include <stdarg.h>
#include "main.h"

/**
 * _printf - Imprime une chaîne formatée sur la sortie standard.
 * @format: Chaîne de format contenant du texte et des spécificateurs.
 *
 * Cette fonction analyse la chaîne *format, affiche les caractères normaux,
 * et pour chaque spécificateur (précédé de '%'), elle appelle la fonction
 * appropriée pour afficher l'argument correspondant.
 * Si le spécificateur n'est pas reconnu,
 * elle affiche '%' suivi du caractère.
 * Les "%%" affichent un caractère '%'.
 *
 * Return: Le nombre total de caractères affichés.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				int (*f)(va_list) = get_a_function(format[i]);

				if (f)
				{
					count += f(args);
				}
				else
				{
					_putchar('%');
					_putchar(format[i]);
					count += 2;
				}
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
