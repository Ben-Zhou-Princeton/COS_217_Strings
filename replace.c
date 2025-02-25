/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Ben Zhou                                                        */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char pcLine [],
                              const char pcFrom [], const char pcTo [])
{
   size_t numberOfPcFroms = 0; 
   size_t pcFromSize = Str_getLength(pcFrom); 
   const char *pLine; 
   const char *foundPointer;
   assert(pcLine != NULL && pcFrom != NULL && pcTo != NULL); 
   pLine = pcLine;
   if (pcFromSize == 0) {
      printf("%s",pcLine ); 
      return 0; 
   }
   foundPointer = Str_search(pLine, pcFrom); 
   while (foundPointer != NULL ) { 
      printf("%.*s", (int)(foundPointer - pLine), pLine); 
      printf("%s", pcTo); 
      numberOfPcFroms++; 
      pLine = foundPointer + pcFromSize; 
      foundPointer = Str_search(pLine, pcFrom); 
   }
   return numberOfPcFroms; 

    

   /*
   size_t isContained = 0;
   size_t uLength = 0; 
   assert(pcLine != NULL && pcFrom != NULL && pcTo != NULL); 
   size_t pcLineSize = Str_getLength(pcLine); 
   size_t pcFromSize = Str_getLength(pcFrom); 
   size_t pcToSize = Str_getLength(pcTo); 
   size_t iterator = 0; 
   size_t numberOfPcFroms = 0; 

   if (pcFromSize == 0) {
      printf("%s",pcLine ); 
      return 0; 
   }

   while (uLength < pcLineSize) {
      if (pcLine[uLength] == pcFrom[0]) { 
         isContained = 1; 
         iterator = 1; 
         while (iterator < pcFromSize && uLength + iterator < pcLineSize) { 
            if (pcFrom[iterator] != pcLine[uLength + iterator]) { 
               isContained = 0; 
            }
            iterator++; 
         }

         
         if (isContained == 1 && iterator == pcFromSize) { 
            uLength = uLength + pcFromSize; 
            numberOfPcFroms++; 
            iterator = 0; 
             while (iterator < pcToSize) {
               printf("%c", pcTo[iterator]); 
               iterator++; 
            }
         }
         else {
            printf("%c", pcLine[uLength]); 
            uLength++; 
         } 
          
      } 


      else { 
      printf("%c", pcLine[uLength]); 
      uLength++; 
      } 

   }

   return numberOfPcFroms;   

*/ 
} 

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) 
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);    

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
