#ifndef UTILS
#define UTILS
#define ARDBUFFER 16
#include <stdarg.h>
#include <Arduino.h>

#include "utils.h"

int logme(const char *str, ...)
{
    int i, size = 0, j = 0, flag = 0;
    char temp[ARDBUFFER + 1];
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '%')
            size++;

    va_list argv;
    va_start(argv, size);
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '%')
        {
            temp[j] = '\0';
            Serial.print(temp);
            j = 0;
            temp[0] = '\0';

            switch (str[++i])
            {
            case 'd':
                Serial.print(va_arg(argv, int));
                break;
            case 'l':
                Serial.print(va_arg(argv, long));
                break;
            case 'f':
                Serial.print(va_arg(argv, double));
                break;
            case 'c':
                Serial.print((char)va_arg(argv, int));
                break;
            case 's':
                Serial.print(va_arg(argv, char *));
                break;
            default:;
            };
        }
        else
        {
            temp[j] = str[i];
            j = (j + 1) % ARDBUFFER;
            if (j == 0)
            {
                temp[ARDBUFFER] = '\0';
                Serial.print(temp);
                temp[0] = '\0';
            }
        }
    };
    Serial.println();
    return size + 1;
}
#undef ARDBUFFER
#endif
