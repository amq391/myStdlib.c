#include <stdarg.h>
#include "mem.h"

/* 
 * strlen
 * 
 * Returns the length of a string s (not including \0)
 */
int strlen(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        ++s;
    }
    return length;
}

/* 
 * convIntToStr
 * 
 * Converts a long to its decimal representation in string form 
 * This is for signed ints and longs
 */
void convIntToStr(long i, char *b) {
    // if i is 0, the string is a 0 then a null terminator
    if (i == 0) {
        b[0] = '0';
        b[1] = '\0';
        return;
    }
    char temp[50];
    int index = 0;
    // remember sign and convert to positive if necessary
    int sign = 1;  
    if (i < 0) {
        sign = -1;
        i = i * sign;
    }
    while (i != 0) {
        long digit = i % 10;
        char letter = 48 + digit;
        temp[index] = letter;
        i = i / 10;
        index++;
    }
    // fill b array in reverse
    int d = 0;
    b[index] = '\0';
    if (sign == -1) {
        temp[index] = '-';
        b[index+1] = '\0';
        index++;
    }
    while (index != 0) {
        b[d] = temp[index-1];
        index--;
        d++;
    }
}

/* 
 * convUnsignedIntToStr
 * 
 * Converts an unsigned long to its decimal representation in string form 
 * This is for unsigned ints and longs
 */
void convUnsignedIntToStr(unsigned long i, char *b) {
    // if i is 0, the string is a 0 then a null terminator
    if (i == 0) {
        b[0] = '0';
        b[1] = '\0';
        return;
    }
    char temp[50];
    int index = 0;
    while (i != 0) {
        long digit = i % 10;
        char letter = 48 + digit;
        temp[index] = letter;
        i = i / 10;
        index++;
    }
    // fill b array in reverse
    int d = 0;
    b[index] = '\0';
    while (index != 0) {
        b[d] = temp[index-1];
        index--;
        d++;
    }
}

/* 
 * convUnsignedIntToHexStr
 * 
 * Converts an unsigned long to its hex representation in string form 
 */
void convUnsignedIntToHexStr(unsigned long i, char *b) {
    // begin with 0x header
    b[0] = '0';
    b[1] = 'x';
    // if i is 0, string is "0x0"
    if (i == 0) {
        b[2] = '0';
        b[3] = '\0';
        return;
    }
    char temp[50];
    int index = 0;
    while (i != 0) {
        long digit = i % 16;
        char letter;
        if (digit >= 10) {
            letter = 97 + (digit - 10);
        } else {
            letter = 48 + digit;
        }
        temp[index] = letter;
        i = i / 16;
        index++;
    }
    // fill b in reverse
    int d = 2;
    while (index != 0) {
        b[d] = temp[index-1];
        index--;
        d++;
    }
    b[d] = '\0';
}

void *memcpy(void *dest, const void *src, size_t n) {
    if (dest == 0 || src == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    char *cast_dest = (char *) dest;
    char *cast_src = (char *) src;
    for (int i = 0; i < n; i++) {
        cast_dest[i] = cast_src[i];
    }
    return dest;
}

void *memset(void *s, int c, size_t n) {
    if (s == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    char *cast_s = (char *) s;
    for (int i = 0; i < n; i++) {
        cast_s[i] = c;
    }
    return s;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    if (s1 == 0 || s2 == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    int retVal = 0;
    char *cast_s1 = (char *) s1;
    char *cast_s2 = (char *) s2;
    for (int i = 0; i < n; i++) {
        if (cast_s1[i] < cast_s2[i]) {
            retVal--;
            break;
        } else if (cast_s1[i] > cast_s2[i]) {
            retVal++;
            break;
        } 
    }
    return retVal;
}

char *strcat(char *dest, const char *src) {
    if (dest == 0 || src == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    int dest_len = strlen(dest);
    for (int i = 0; i <= strlen((char*)src); i++) {
        dest[i + dest_len] = src[i];
    }
    return dest;
}

char *strncat(char *dest, const char *src, size_t n) {
    if (dest == 0 || src == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    int dest_len = strlen(dest);
    int i;
    for (i = 0; i < n; i++) {
        //maybe check if src[i] == '\0' 
        if (src[i] == '\0') break;
        dest[i + dest_len] = src[i];
    }
    dest[i + dest_len] = '\0';
    return dest;
}

int strcmp(const char *s1, const char *s2) {
    if (s1 == 0 || s2 == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    int retVal = 0;
    int s1_len = strlen((char*)s1);
    int s2_len = strlen((char*)s2);
    if (s1_len < s2_len) {
        retVal--;
    } else if (s1_len > s2_len) {
        retVal++;
    } else {
        // We know the strings are the same length
        for (int i = 0; i < s1_len; i++) {
            if (s1[i] < s2[i]) {
                retVal--;
                break;
            } else if (s1[i] > s2[i]) {
                retVal++;
                break;
            } 
        }
    }
    return retVal;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    if (s1 == 0 || s2 == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    int retVal = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i]) {
            retVal--;
            break;
        } else if (s1[i] > s2[i]) {
            retVal++;
            break;
        } 
    }
    return retVal;
}

char *strcpy(char *dest, const char *src) {
    if (dest == 0 || src == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    
    for (int i = 0; i <= strlen((char*)src); i++) {
        dest[i] = src[i];
    }
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    if (dest == 0 || src == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    int src_len = strlen((char*)src);
    int i;
    for (i = 0; i < n; i++) {
        if (i <= src_len) {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
        
    }
    dest[i] = '\0';
    return dest;
}

/*
 * printf
 *
 * Takes a formatting string and an arbitrary number of
 * arguments and outputs to stdout
 */ 
int printf(const char *format, ...) {
    if (format == 0) {
        printf("ERROR: null parameter LINE: %d in FILE: %s\n", __LINE__, __FILE__);
        exit(1);
    }
    va_list l;
    va_start(l, format);
 
    while (*format != '\0') {
        if (*format == '%') {
            ++format;
            if (*format == 's') {
                // We have to output a string
                char *s = va_arg(l,char *);
                write(1,s,strlen(s)); 
            } else if (*format == 'd') {
                // We have to output a signed number in decimal
                int i = va_arg(l,int);
                char buff[50];
                convIntToStr((long)i, buff);
                write(1,buff,strlen(buff));
            } else if (*format == 'l') {
                // We have to output a long type
                ++format;
                if (*format == 'd') {
                    // We have to output a long signed number in decimal
                    long i = va_arg(l,long);
                    char buff[50];
                    convIntToStr(i, buff);
                    write(1,buff,strlen(buff));
                } else if (*format == 'x') {
                    // We have to output a long unsigned number in hexadecimal
                    unsigned long i = va_arg(l,unsigned long);
                    char buff[50];
                    convUnsignedIntToHexStr(i, buff);
                    write(1,buff,strlen(buff));
                } else if (*format == 'u') {
                    // We have to output a long unsigned number in decimal
                    unsigned long i = va_arg(l,unsigned long);
                    char buff[50];
                    convUnsignedIntToStr(i, buff);
                    write(1,buff,strlen(buff));
                }
            } else if (*format == 'u') {
                // We have to output an unsigned number in decimal
                unsigned int i = va_arg(l,unsigned int);
                char buff[50];
                convUnsignedIntToStr((unsigned long)i, buff);
                write(1,buff,strlen(buff));
            } else if (*format == 'x') {
                unsigned int i = va_arg(l,unsigned int);
                char buff[50];
                convUnsignedIntToHexStr((unsigned long)i, buff);
                write(1,buff,strlen(buff));
            }
        } else {
            write(1, format, 1);
        }
        ++format;
    }
 
    va_end(l);
}