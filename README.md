# my_libc
*Epitech | Tek1*

## Build
```
$ make
```
This will create a static library named `my_libc.a` that you can include to your project:
```
$ gcc -o [outputfile] my_libc.a [sources]
```

## Tests
```
$ make tests_run
```

## Functions

#### my_strlen :
```c
size_t my_strlen(char const *);
```
Returns the number of characters in a string, delimited by `\0`.

#### my_cstrlen :
```c
size_t my_cstrlen(char const *, char);
```
Counts the number of characters in a string before the given character.
If the string don't contains the given character, return the number of characters in a string, delimited by `\0`.

#### my_strcpy :
```c
char *my_strcpy(char *, char const *);
```
Copies the second given string into the first.

#### my_strncpy :
```c
char *my_strncpy(char *, char const *, size_t);
```
Copies the given number of characters of the second given string into the first.

#### my_strdup :
```c
char *my_strdup(char const *);
```
Duplicates the string given as parameter.

#### my_strndup :
```c
char *my_strndup(char const *, size_t);
```
Duplicates the given size of the string given as parameter.

#### my_strcmp :
```c
bool my_strcmp(char const *, char const *);
```
Compares the both given strings between them.

#### my_strncmp :
```c
bool my_strncmp(char const *, char const *, size_t);
```
Compares the given size of the both given strings between them.

#### my_strcontains :
```c
bool my_strcontains(char const *, char);
```
Checks if the character in contained in the string.

#### my_stradd :
```c
char *my_stradd(char *, char const *);
```
Adds the second string to the first.

#### my_strnadd :
```c
char *my_strnadd(char *, char const *, size_t);
```
Adds the given number of character of the second string to the first.

#### my_addnchar :
```c
char *my_addnchar(char *, char, size_t);
```
Adds the given number of the given character at the end of the string.

#### my_strcat :
```c
char *my_strcat(char const *, char const *);
```
Concatenates the two string to create a new one.

#### my_strf :
```c
char *my_strf(char const *, ...);
```
Creates a string with the `printf` syntax.
###### Supported flags :
- `%d`
- `%i`
- `%u`
- `%f`
- `%e`
- `%c`
- `%s`
- `%x`
- `%X`
- `%o`
- `%b`
- `%p`

#### my_atoi :
```c
int my_atoi(char const *);
```
Converts a string into an integer.

#### my_itoa :
```c
char *my_itoa(int);
```
Converts an integer into a string.

#### my_atou :
```c
size_t my_atou(char const *);
```
Converts a string into an unsigned integer.

#### my_utoa :
```c
char *my_utoa(size_t);
```
Converts an unsigned integer into a string.

#### my_atof :
```c
double my_atof(char const *);
```
Converts a string into a floating point number.

#### my_ftoa :
```c
char *my_ftoa(double, size_t);
```
Converts a floating point number into a string with the given number of digits.

#### my_ftoa_sci :
```c
char *my_ftoa_sci(double, size_t);
```
Converts a floating point number into a string in scientific notation with the given number of digits.

#### my_tobase :
```c
char *my_tobase(size_t, char const *);
```
Converts a unsigned decimal number into a string in the given base.
###### Example:
```c
my_tobase(12, "01");
```
This will give `12` in binary => `1100` as a string.

#### my_power :
```c
size_t my_power(size_t, size_t);
```
Computes the power.

#### my_str_split :
```c
char **my_str_split(char const *, char);
```
Splits a string into a board, splitted by the given character.
