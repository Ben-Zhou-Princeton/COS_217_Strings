#include <str.h>
#include <stddef.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength + 1;
}

char *Str_copy(char dest[], const char src[])
{
    size_t uLength = 0; 
    assert(src != NULL && dest != NULL);
    while(src[uLength != '\0']) {
        dest[uLength] = src[uLength];
        uLength++; 
    }
    return *dest; 
} 
char *Str_concat(char dest[], const char src[]) { 
    assert(dest != NULL && src != NULL);
    size_t destLength = Str_getLength(dest); 
    size_t srcLength = Str_getLength(src);
    size_t currentIndex = 0; 

    while (currentIndex < srcLength) {
        dest[srcLength + currentIndex] = src[currentIndex];
        currentIndex++;  
    }

    return *dest; 
}

int Str_compare(const char str1[], const char str2[])  { 
    size_t uLength = 0;
    size_t trueOrFalse = 1; 
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
    assert(haystack != NULL && needle != NULL);
    size_t uLength = 0; 
    size_t haystackSize = Str_getLength(haystack);
    size_t needleSize = Str_getLength(needle); 

    if (Str_getLength(needle) == 0) {
        return haystack; 
    }
    size_t marker = -1; 
    size_t isContained; 

    while (uLength < haystackSize) { 
        size_t needleIteration = 1; 
        if (haystack[uLength] == needle[0]) { 
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
                marker = uLength; 
                break; 
            }

        uLength++; 
    }

    if (marker == -1) { 
        return NULL; 
    }
    char *returnArray [haystackSize - marker]; 
    while (marker < haystackSize) {
        returnArray[marker] = haystack[marker]; 
        marker++; 
    }

    return returnArray; 

} 

 

