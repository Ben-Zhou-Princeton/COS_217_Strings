#include "str.h"
#include <stddef.h>

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
        dest = *srcEnd; 
        srcEnd++; 
        destEnd++;
    } 
    return dest; 
} 
 