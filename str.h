#ifndef STR_INCLUDED
#define STR_INCLUDED

size_t Str_getLength(const char *str);
char *Str_copy(char *dest, const char *src); 
char *Str_concat(char *dest, const char *src);
int Str_compare(const char *str1, const char *str2);
char *Str_search(const char *haystack, const char *needle); 

#endif 