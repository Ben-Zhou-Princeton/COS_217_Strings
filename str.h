/* Interface for the str.h module, behaves identical to standard string functions*/
#include <stddef.h>
#ifndef STR_INCLUDED
#define STR_INCLUDED
/* Returns the length of the provided string *pcSRC */
size_t Str_getLength(const char *pcSrc);
/* Copies the string src to the destination dest*/
char *Str_copy(char *dest, const char *src); 
/* Takes the String src and adds to the end of 
the destination string dest */
char *Str_concat(char *dest, const char *src);
/* Compares the strings str1 and str2, and returns 0 if 
they are the same, -1 if str1 is lexiographically
less than str2, and 1 if str1 is greater than str2*/
int Str_compare(const char *str1, const char *str2);
/* Searches for the string needle in the haystack, 
returns the pointer to where the needle starts in the haystack
if there is no needle returns null*/
char *Str_search(const char *haystack, const char *needle); 

#endif 