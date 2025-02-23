#include "str.h"
#include <stddef.h>
#include <assert.h>


size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *dest, const char *src) { 
    const char *srcEnd; 
    const char *destEnd; 
    assert(src != NULL && dest != NULL); 
    srcEnd = src; 
    while (*srcEnd != '\0') { 
        destEnd = *srcEnd; 
        srcEnd++; 
        destEnd++;
    } 
    return dest; 
} 
char *Str_concat(char *dest, const char *src) { 
    return "abcde"; 

}
int Str_compare(const char *str1, const char *str2) { 
    return 0; 

}
char *Str_search(const char *haystack, const char *needle) { 
    return "abcde"; 

}



 