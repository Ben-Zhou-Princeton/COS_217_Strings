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
    char *destEnd; 
    const char *srcEnd; 
    assert(src != NULL && dest != NULL); 
    destEnd = dest; 
    srcEnd = src; 
    while (*srcEnd != '\0') { 
        *destEnd = *srcEnd; 
        srcEnd++; 
        destEnd++;
    } 
    *destEnd = '\0'; 

    return dest; 
} 
char *Str_concat(char *dest, const char *src) { 
    char *destEnd; 
    const char *srcEnd; 
    assert(src != NULL && dest != NULL);
    destEnd = dest;
    srcEnd = src; 
    while (*destEnd != '\0') { 
        destEnd++; 
    }
    while (*srcEnd != '\0') { 
        *destEnd = *srcEnd; 
        destEnd++;
        srcEnd++; 
    }
    *destEnd = '\0';
    return dest; 
}
int Str_compare(const char *str1, const char *str2) { 
    const char *str1End; 
    const char *str2End; 
    assert(str1 != NULL && str2 != NULL); 
    str1End = str1;
    str2End = str2; 
    while (*str1End != '\0' && *str2End != '\0') { 
        if (*str1End != *str2End) {
            if (*str1End > *str2End) {
                return 1; 
            }
            else return -1; 
        }
        str1End++;
        str2End++; 
    }
    if (*str1End > *str2End) return 1; 
    else if (*str1End < *str2End) return -1;
    return 0;

}
char *Str_search(const char *haystack, const char *needle) { 
    const char *haystackEnd; 
    const char *needleEnd; 
    const char **haystackTracker; 
    size_t haystackSize = Str_getLength(haystack);
    size_t needleSize = Str_getLength(needle); 
    size_t isContained; 
    assert(haystack != NULL && needle != NULL); 
    haystackEnd = haystack; 
    needleEnd = needle; 
    
    if (needleSize == 0) return (char*) haystackEnd; 
    if (haystackSize < needleSize) return NULL;
    while (*haystackEnd != '\0') { 
        if (*haystackEnd == *needleEnd) { 
            isContained = 1; 
            haystackTracker = haystackEnd; 
            while (*haystackTracker != '\0' && *needleEnd != '\0') { 
                if (*haystackEnd != *needleEnd) { 
                    isContained = 0; 
                    break; 
                } 
                needleEnd++;
                haystackTracker++; 
            }
        }
        if (isContained == 1) { 
            return (char*) haystackEnd; 
        }
        haystackEnd++; 
    }
    return NULL; 





}
 /*
 const char* pc = haystack;  
    size_t isContained = 0;
    size_t needleIteration = 1; 
    size_t uLength = 0; 
    size_t haystackSize = Str_getLength(haystack);
    size_t needleSize = Str_getLength(needle); 
    
    assert(haystack != NULL && needle != NULL);

    if (needleSize == 0) return (char*)pc; 
    if (haystackSize < needleSize) return NULL;
    while (uLength <= haystackSize - needleSize) {
        if (*pc == needle[0]) { 
            needleIteration = 1;
            isContained = 1; 
            while (needleIteration < needleSize ) { 
                if (needle[needleIteration] != haystack[needleIteration + uLength]) { 
                    isContained = 0; 
                }
                needleIteration++; 
            }
        }
        if (isContained == 1) { 
            return (char*)pc;  
        }
        pc++; 
        uLength++; 
    }

    return NULL; 
} */


 