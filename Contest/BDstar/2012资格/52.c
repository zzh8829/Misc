#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *JavaToCpp(const char *java, char *cpp);
char *CppToJava(const char *cpp, char *java);
int Check(const char *input);

int main()
{
    char input[101], output[101];
    scanf("%s", input);
    switch (Check(input))
    {
    case 0:
        printf("%s", CppToJava(input, output));
        break;
    case 1:
        printf("%s", JavaToCpp(input, output));
        break;
    case 2:
        printf("%s", input);
        break;
    case 3:
        printf("Error!");
        break;
    default:
        break;
    }
    return 0;
}

char *JavaToCpp(const char *java, char *cpp)
{
    char *str = cpp;
    while (*java != '\0')
    {
        if (isupper(*java))
        {
            *cpp++ = '_';
            *cpp++ = tolower(*java++);
        }
        else
        {
            *cpp++ = *java++;
        }
    }
    *cpp = '\0';
    return str;
}

char *CppToJava(const char *cpp, char *java)
{
    char *str = java;
    while (*cpp != '\0')
    {
        if (*cpp == '_')
        {
            *java++ = toupper(*(cpp + 1));
            cpp += 2;
        }
        else
        {
            *java++ = *cpp++;
        }
    }
    *java = '\0';
    return str;
}

int Check(const char *input)
{
    int line = 0, upcase = 0;

    if (isupper(*input) || *input == '_')
        return 3;

    while (*input != '\0')
    {
        if (isupper(*input))
            upcase = 1;
        if (*input == '_')
        {
            line = 1;
            if (*(input + 1) == '_')
                return 3;
        }
        ++input;
    }
    if (*(input - 1) == '_')
        return 3;

    if (line && !upcase)
        return 0;
    if (!line && upcase)
        return 1;
    if (!line && !upcase)
        return 2;
    return 3;
}
