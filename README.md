## Part1 Scanner
先创建一个简单的扫描器，只针对四项基本运算符和十个数字
待扫描的Token定义在`defs.h`中，分为token和intvalue部分
```
enum {
  T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// Token structure
struct token {
  int token;
  int intvalue;
};
```

### `scan.c`中的函数
`scan.c`包含了词汇扫描函数，我们需要追踪当前扫描的行号以及回退功能(读过头了)，这些功能在`next()`中实现

`data.h`导出了几个全局变量，这些全局变量在main中使用

`putback()`用于设定不想要的词，把它**放回输入流**

### 忽略空格
`skip()`用于跳过空白字符

### 扫描tokens
`scan()`扫描并返回下一个token，如果token合法返回1，如果没有token则返回0

### 投入使用
`main.c`
