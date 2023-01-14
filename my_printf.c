#include<stdio.h> 
#include <stdlib.h>
#include<stdarg.h> 
#include<string.h>                     

void Myprintf(char *,...);              
char* onvert(unsigned long int, int);       
char* concat(const char *s1, const char *s2);

int main() 
{ 
    char *a = "as";
    Myprintf(" SUCCESS \n %p", a); 
    printf(" SUCCESS \n %p", a);

    return 0;
} 

void Myprintf(char* format,...) 
{ 
    char *traverse; 
    unsigned long int i; 
    char *s; 

    va_list arg; 
    va_start(arg, format); 

    for(traverse = format; *traverse != '\0'; traverse++) 
    { 
        while( *traverse != '%' ) 
        { 
            putchar(*traverse);
            traverse++; 
        } 

        traverse++; 

        switch(*traverse) 
        { 
            case 'c' : i = va_arg(arg,int);     
                        putchar(i);
                        break; 

            case 'd' : i = va_arg(arg,int);        
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(onvert(i,10));
                        break; 

            case 'o': i = va_arg(arg,unsigned int); 
                        puts(onvert(i,8));
                        break; 

            case 's': s = va_arg(arg,char *);       
                        puts(s); 
                        break; 

            case 'x': i = va_arg(arg,unsigned long int); 
                        puts(onvert(i,16));
                        break; 
            case 'p': i = va_arg(arg,unsigned long int);
                        puts(concat("0x", onvert(i,16)));
                        break;
        }   
    } 

    va_end(arg); 
} 

char *onvert(unsigned long int num,  int base) 
{ 
    static char Representation[]= "0123456789abcdef";
    static char buffer[50]; 
    char *ptr; 

    ptr = &buffer[49]; 
    *ptr = '\0'; 

    do 
    { 
        *--ptr = Representation[num%base]; 
        num /= base; 
    }while(num != 0); 

    return(ptr); 
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); 
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}