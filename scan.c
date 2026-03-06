#include "defs.h"
#include "data.h"

// 返回字符c在字符串中的位置
static int chrpos(char *s, int c)
{
    char *p;

    p = strchr(s, c);
    return p ? p - s : -1;
}

// 从输入文件中读取下一个字符
static int next(void)
{
    int c;

    if (Putback)
    { // 使用character put
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if (c == '\n')
    {
        Line++;
    }
    return c;
}

// 放回一个不想要的字符
static void putback(int c)
{
    Putback = c;
}

// 跳过无用字符
static int skip(void)
{
    int c;

    c = next();
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')
    {
        c = next();
    }
    return c;
}

// 扫描数字
static int scanint(int c)
{
    int k, val = 0;
    while ((k = chrpos("0123456789", c)) >= 0)
    {
        val = val * 10 + k;
        c = next();
    }

    // 读到了一个非int字符，把它放回输入流
    putback(c);
    return val;
}

// 扫描并返回下一个token，如果token合法返回1，如果没有token则返回0
int scan(struct token *t)
{
    int c;

    c = skip();
    switch (c)
    {
    case EOF:
        return 0;
    case '+':
        t->token = T_PLUS;
        break;
    case '-':
        t->token = T_MINUS;
        break;
    case '*':
        t->token = T_STAR;
        break;
    case '/':
        t->token = T_SLASH;
        break;
    default:
        // 如果是数字，扫描整个数字
        if (isdigit(c))
        {
            t->intvalue = scanint(c);
            t->token = T_INTLIT;
            break;
        }

        printf("Unrecongnised character %c on line %d\n", c, Line);
        exit(1);
    }

    // 找到一个token
    return 1;
}