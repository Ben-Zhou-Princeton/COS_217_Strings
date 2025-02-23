#include "str.h"
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *Str_copy(char dest[], const char src[])
{   
    size_t uLength = 0; 
    assert(src != NULL && dest != NULL);
    while(src[uLength] != '\0') {
        dest[uLength] = src[uLength];
        uLength++; 
    }
    return dest; 
} 
char *Str_concat(char dest[], const char src[]) { 
    size_t srcLength = Str_getLength(src);
    size_t currentIndex = 0; 
    assert(dest != NULL && src != NULL);
    while (currentIndex < srcLength) {
        dest[srcLength + currentIndex] = src[currentIndex];
        currentIndex++;  
    }

    return dest; 
}

int Str_compare(const char str1[], const char str2[])  { 
    size_t uLength = 0;
    int trueOrFalse = 1; 
    assert(str1 != NULL && str2 != NULL);
    while (str1[uLength] != '\0') { 
    
        if (str1[uLength] != str2[uLength]) {
            trueOrFalse = 0; 
        } 
        if (Str_getLength(str1) != Str_getLength(str2)) { 
            trueOrFalse = 0; 
        }
        uLength++; 
        
    }
    return trueOrFalse;
}

char *Str_search(const char haystack[], const char needle[]) { 
    const char* pc = haystack; 
    size_t isContained;
    size_t needleIteration; 
    size_t uLength = 0; 
    size_t haystackSize = Str_getLength(haystack);
    size_t needleSize = Str_getLength(needle); 
    
    assert(haystack != NULL && needle != NULL);

    if (needleSize == 0) {
        return (char*)pc; 
    } 
    while (uLength < haystackSize) {
        needleIteration = 1; 
        if (*pc == needle[0]) { 
            isContained = 1; 
            while (needleIteration < needleSize 
            && needleIteration + uLength < haystackSize) { 
                if (needle[needleIteration] != haystack[needleIteration + uLength]) { 
                    isContained = 0; 
                }
                needleIteration++; 
            }
        }
        if (isContained == 1) { 
            pc = haystack + uLength; 
            return (char*)pc;  
        }
        uLength++; 
    }

    return NULL; 



} 

 

