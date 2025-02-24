/* Implmentatio of str.h using array notation*/
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
    /* adds the null terminator to the end, this is not 
    done in the while loop */
    dest[uLength] = '\0'; 
     
    return dest; 
} 
char *Str_concat(char dest[], const char src[]) { 
    size_t destLength = Str_getLength(dest); 
    size_t currentIndex = 0; 
    assert(dest != NULL && src != NULL);
    while (src[currentIndex] != '\0') {
        dest[destLength + currentIndex] = src[currentIndex];
        currentIndex++;  
    }

    dest[destLength + currentIndex] = '\0'; 

    return dest; 
}

int Str_compare(const char str1[], const char str2[])  { 
    size_t uLength = 0;
    assert(str1 != NULL && str2 != NULL); 
    while (str1[uLength] != '\0' && str2[uLength] != '\0') { 
        if (str1[uLength] != str2[uLength]) {
            if (str1[uLength] > str2[uLength]) { 
                return 1; 
            }
            else return -1;
        } 
        uLength++; 
    }
    /* Null terminator has a value of 0, so any other character
    here would make it greater than the null terminator, handling
    the case where the two strings are different lengths */
    if (str1[uLength] > str2[uLength]) return 1; 
    else if (str1[uLength] < str2[uLength]) return -1;
    return 0;
}

char *Str_search(const char haystack[], const char needle[]) { 
    size_t isContained = 0;
    size_t needleIteration = 1; 
    size_t uLength = 0; 
    size_t haystackSize = Str_getLength(haystack);
    size_t needleSize = Str_getLength(needle); 
    
    assert(haystack != NULL && needle != NULL);
    /* Corner case evaluation */
    if (needleSize == 0) return (char*)&haystack[0]; 
    if (haystackSize < needleSize) return NULL;
    /* Iterates through the haystack and when it identifies
    that the char is the same as the beginning of the needle
    if identifies if that segment is the same as the needle*/
    while (uLength <= haystackSize - needleSize) {
        if (haystack[uLength] == needle[0]) { 
            needleIteration = 1;
            isContained = 1; 
            /* If this a false lead, break and move on*/
            while (needleIteration < needleSize ) { 
                if (needle[needleIteration] != haystack[needleIteration + uLength]) { 
                    isContained = 0; 
                    break; 
                }
                needleIteration++; 
            }
        }
        if (isContained == 1) { 
            return (char*) &haystack[uLength];
        }
        uLength++; 
    }

    return NULL; 
} 

 

