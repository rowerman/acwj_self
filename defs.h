// 类型定义

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tokens
enum {
    T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// 当token.token为T_INTLIT时，token.intvalue存储int的值
struct token {
    int token;
    int intvalue;
};