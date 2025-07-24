#include <unistd.h>
#include "main.h"

/**
 * get_a_function - Sélectionne et retourne une fonction selon le spécifier.
 * @format_specifier: Le caractère représentant le type de format
 * (ex: 'c', 's', 'd', etc.).
 *
 * Cette fonction parcourt un tableau de structures composé de spécificateurs
 * de format et associe les fonctions correspondantes.
 * Si le caractère passé en argument correspond au
 * premier caractère d'un des spécificateurs du tableau,
 *  la fonction associée est retournée. Sinon, la fonction retourne NULL.
 *
 * Return: Un pointeur vers la fonction de traitement si trouvée, sinon NULL.
 */

int (*get_a_function(char format_specifier))(va_list)
{
	specifier_f array[] = {
		{"c", print_character},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	int i = 0;

	if (format_specifier == '\0')
		return (NULL);

	while (array[i].specifier != NULL)
	{
		if (array[i].specifier[0] == format_specifier)
		return (array[i].function);
		i++;
	}

	return (NULL);
}

/**
 * _putchar - Écrit un caractère sur la sortie standard.
 * @c: Le caractère à afficher.
 *
 * Cette fonction utilise l'appel système write pour afficher un caractère
 * sur la sortie standard (file descriptor 1).
 *
 * Return: 1 , indiquant qu'un caractère a été écrit.
 */

int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_character - Affiche un caractère passé par arguments via (va_list).
 * @args: La liste d'arguments variables contenant
 * le caractère (passer en int par _putchar car il utilise la table ASCII).
 *
 * Récupère un caractère depuis la liste d'arguments variables
 * (en tant qu'int, comme requis par la promotion d'arguments variadiques en C)
 * , puis l'affiche
 * en utilisant la fonction _putchar.
 *
 * Return: 1 (nombre de caractères affichés).
 */

int print_character(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - Affiche une chaîne de caractères passée via (va_list).
 * @args: Liste d'arguments variables contenant un pointeur vers la chaîne.
 *
 * Récupère une chaîne de caractères depuis la liste d'arguments
 * et l'affiche caractère par caractère en utilisant _putchar. Si la chaîne
 * est NULL, la chaîne devient "(NULL)" et est affichée à la place.
 *
 * Return: Le nombre de caractères affichés.
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
	str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_integer - Affiche un entier passé via (va_list).
 * @args: Liste d'arguments variables contenant l'entier à afficher.
 *
 * Cette fonction extrait un entier depuis (va_list), le convertis en long
 * si n = INT_MIN , puis
 * l'affiche chiffre par chiffre à l'aide de _putchar.
 *
 * Elle gère également les entiers négatifs en
 * affichant le signe '-' et en travaillant sur la
 * valeur absolue. Aucun appel à des fonctions de conversion n'est utilisé.
 *
 * Return: Le nombre de caractères affichés.
 */

int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	long num;
	long diviser = 1;
/*
 * On converti "n" en positif s'il est négatif pour eviter
 * d'avoir le signe "-" a chaque modulo.
 */

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -(long)n;
	}
	else
	{
		num = n;
	}
/*
 * On cherche la puissance de 10 qui divisera le plus efficacement.
 */

	while (num / diviser >= 10)
	diviser *= 10;

/*
 * Affiche chiffre par chiffre.
 */
	while (diviser != 0)
	{
		_putchar((num / diviser) % 10 + '0');
		count++;
		diviser /= 10;
	}

	return (count);
}
