# Projet `_printf`

Un programme simplifié de la fonction standard `printf` en C.  
Ce projet met en œuvre des concepts fondamentaux comme les **fonctions variadiques**, les **pointeurs de fonction**, et les **structures**, dans un but pédagogique.

---

## Table des matières

- [Fonctionnalités](#fonctionnalités)
- [Spécificateurs supportés](#spécificateurs-supportés)
- [Structure du projet](#structure-du-projet)
- [Compilation](#compilation)
- [Requirements](#requirements)
- [Page de manuel](#page-de-manuel)
- [Exemples d'utilisation](#exemples-dutilisation)
- [Les tests](#les-tests)
- [Auteur](#auteur)

---

## Fonctionnalités

- Gestion de plusieurs spécificateurs de format :
  - `%c` (caractère)
  - `%s` (chaîne)
  - `%d`, `%i` (entiers)
  - `%%` (symbole `%`)
- Affichage caractère par caractère avec `_putchar`
- Comportement similaire à `printf`

---

## Spécificateurs supportés

| Spécificateur | Description                        |
|---------------|------------------------------------|
| `%c`          | Affiche un caractère                |
| `%s`          | Affiche une chaîne                  |
| `%%`          | Affiche le symbole `%`              |
| `%d`          | Affiche un entier  |
| `%i`          | Alias de `%d`                       |

---

## Structure du projet

| Fichier                | Rôle                                                  |
|------------------------|--------------------------------------------------------|
| `main.h`               | Déclarations des fonctions et structure `specifier_f` |
| `_printf.c`            | Fonction principale qui gère le formatage             |
| `get_print_function.c` | Associe un spécificateur à sa fonction                |
| `handlers.c`           | Contient `print_char`, `print_string`, `print_integer` |
| `_putchar.c`           | Écriture d’un caractère via `write`                   |
| `main.c`               | Cas de test                                            |

---

## Compilation

Compile tous les fichiers avec :

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```
---

## Exigences

- Éditeurs autorisés : `vi`, `vim`, `emacs`
- Tous les fichiers seront compilés sous **Ubuntu 20.04 LTS** avec `gcc`, utilisant les options suivantes :  
  `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Tous vos fichiers doivent se terminer par une **nouvelle ligne** (ligne vide finale)
- Un fichier **README.md** à la racine du dossier du projet est **obligatoire**
- Votre code doit respecter la **norme de style Betty**.  
  Elle sera vérifiée avec les scripts `betty-style.pl` et `betty-doc.pl`
- **Aucune variable globale** n’est autorisée
- **Pas plus de 5 fonctions par fichier**
- Les prototypes de toutes vos fonctions doivent être inclus dans un fichier d’en-tête appelé **main.h**
- Tous vos fichiers d’en-tête doivent être protégés par des **gardes d’inclusion** (`#ifndef` / `#define` / `#endif`)

 Fonctions et macros autorisées

- `write` (voir `man 2 write`)
- `malloc` (voir `man 3 malloc`)
- `free` (voir `man 3 free`)
- `va_start` (voir `man 3 va_start`)
- `va_end` (voir `man 3 va_end`)
- `va_copy` (voir `man 3 va_copy`)
- `va_arg` (voir `man 3 va_arg`)

---

## Page de manuel

Pour lire la manpage locale du projet :

```bash
man ./man_3_printf
```
---

## Exemples d'utilisation

_printf("Let's try to printf a simple sentence.\n");
// → Let's try to printf a simple sentence.

_printf("Length:[%d, %i]\n", 42, 42);
// → Length:[42, 42]

_printf("Character:[%c]\n", 'H');
// → Character:[H]

_printf("String:[%s]\n", "I am a string !");
// → String:[I am a string !]

_printf("Percent:[%%]\n");
// → Percent:[%]

---

## Les tests

| Appel `_printf`                                        | Sortie affichée                                               |
| ------------------------------------------------------ | ------------------------------------------------------------- |
| `_printf("Let's try to printf a simple sentence.\n");` | `Let's try to printf a simple sentence.` (avec saut de ligne) |
| `_printf("Length:[%d, %i]\n", len, len);`              | `Length:[39, 39]` (avec saut de ligne)                        |
| `_printf("Negative:[%d]\n", -762534);`                 | `Negative:[-762534]` (avec saut de ligne)                     |
| `_printf("Character:[%c]\n", 'H');`                    | `Character:[H]` (avec saut de ligne)                          |
| `_printf("String:[%s]\n", "I am a string !");`         | `String:[I am a string !]` (avec saut de ligne)               |
| `_printf("Percent:[%%]\n");`                           | `Percent:[%]` (avec saut de ligne)                            |
| `_printf("Len:[%d]\n", len);`                          | `Len:[12]` (avec saut de ligne)                               |

---

## Auteur

- [@joevinM](https://www.github.com/joevinM)