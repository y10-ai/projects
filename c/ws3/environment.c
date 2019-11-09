/*********************************/
/*   			             	 */
/*				                 */
/*Implementing file work sheet 3 */
/*   Yonatan Zaken		         */
/*   Last Updated 4/11/19        */
/*   Reviewed by: Ben            */   
/*			                   	 */
/*			  	                 */
/*********************************/

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "environment.h"


static void *MyMalloc(size_t n, int flag, int random_num, int iteration);

/*****************************************/
/*			                             */
/*     CopyEnv function for WS 3         */
/*					                     */
/*****************************************/

/* This function copies the environment variables to buffer*/
char **CopyEnv(const char **buffer, int flag)
{
    /* random number related variable */
    time_t t;
    
    const char **temp = buffer;
    char **copy;       /* This is the pointer to the copied variables */
    char **header;     /* This pointer is used to rewind copy in line 52 */     
    int buff_size = 0;
    int string_size = 0;
    int random_num = 0;
    
    /* Check if buffer points to \0 in debug mode */
    assert(NULL != temp); 
    
    buff_size = BufferSize(temp) - 1;
    
    /* Lines 48 + 49 generate random number for MyMalloc use */
    srand((unsigned) time(&t));
    random_num = rand() % buff_size + 1;
    
    /* Allocate memory for pointer to pointer */
    copy = (char**)malloc(buff_size * sizeof(char*));
    header = copy;
    
    while(0 < buff_size)
    {
        string_size = strlen(*temp) + 1;
        
        /* Allocate memory before copying strings */
        *copy = (char*)MyMalloc(string_size, flag, random_num, buff_size); 
        
        if (NULL == *copy)
        {
            printf("Can't allocat memory.");
            copy = header;
            CleanEnvCopy(copy);
            return NULL;
        }
        
        strcpy(*copy, (char*)*temp);   /* <-- Copy strings from buffer */
        StringToLower(*copy);         /* <-- Convert strings to lowercase */
       
        ++temp;
        ++copy;
        --buff_size;
    }
         
    temp = buffer;
    copy = header;
    
    return copy; 
}

/*****************************************/
/*			                             */
/*     PrintEnv function for WS 3        */
/*					                     */
/*****************************************/

/* This function prints the copied environment variables from the argument*/
void PrintEnv(const char **buffer) 
{
    const char **runner = buffer;
    int buff_size = 0;
    
    /* Check if buffer points to \0 in debug mode */
    assert(NULL != runner); 
    
    buff_size = BufferSize(runner);  
    
    while (0 < buff_size)
    {
        printf("%s\n", *runner);
        ++runner;
        --buff_size;
    } 
}

/*****************************************/
/*			                             */
/*    StringToLower function for WS 3    */
/*					                     */
/*****************************************/

/* This function converts the environment variables to lower case */
void StringToLower(char *string)
{
    char *runner = string;
    
    /* Check if string points to \0 in debug mode */
    assert(NULL != runner);
    
    while ('\0' != *runner)
    {
        *runner = tolower(*runner);
        ++runner;
    }
}

/*****************************************/
/*			                             */
/*     BufferSize function for WS 3      */
/*					                     */
/*****************************************/

/* Counts the buffer size */ 
int BufferSize(const char **buffer)
{
    const char **runner = buffer;
    int count = 0;
    
    /* Check if buffer points to \0 in debug mode */
    assert(NULL != runner);
    
    while (NULL != *runner)
    {
        ++runner;
        ++count;
    }
    
    return count;
}

/*****************************************/
/*			                             */
/*      StrDup function for WS 3         */
/*					                     */
/*****************************************/

/* This function duplicates the string it gets as a argument */
char *StrDup(const char* string)
{
    int str_size = strlen(string) + 1; 
    char *temp = (char*)malloc(sizeof(char) * str_size);
    const char *runner = string;
    
    assert(NULL != string);
    assert(NULL != temp);
    
    if(NULL == temp) 
    {
        return NULL;
    }
    
    strcpy(temp, runner);
        
    return temp; 
}

/*****************************************/
/*			                             */
/*    CleanEnvCopy function for WS 3     */
/*					                     */
/*****************************************/

/* This function deallocates all the memory we allocated to store variables */
void CleanEnvCopy(char **buffer)
{
    char **runner = buffer;
    int buff_size = BufferSize((const char**)runner);
    
    /* Check if buffer points to \0 in debug mode */
    assert(NULL != buffer);
    
    while(0 < buff_size)
    {
        free(*runner);
        *runner = NULL;
        ++runner;
        --buff_size;
    }    
    
    free(buffer);
    buffer = NULL;
}

/*****************************************/
/*			                             */
/*    MyMalloc function for WS 3         */
/*					                     */
/*****************************************/

/* Wrapper function */

static void *MyMalloc(size_t n, int flag, int random_num, int iteration)
{
    void *ptr;
    
    if(0 != flag && iteration == random_num)
    { 
       ptr = NULL;
       return ptr;
    }
    
    else
    {
        ptr = malloc(n);
    }
    
    return ptr;
}

















