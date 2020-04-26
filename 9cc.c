#include<ctype.h>
#include<stdarg.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// トークンの種類
typedef enum {
	TK_RESERVED,
	TK_NUM,
	TK_EOF,
} TokenKind;

typedef struct Token Token;

// トークン型
struct Token {
	TokenKind kind;	// トークンの型
	Token *next;	// 次の入力トークン
	int val;		// kindがTK_NUMの場合、その数値
	char *str;		// トークン文字列
};

// 現在着目しているトークン
Token *token;

// エラーを報告するための関数
// printfと同じ引数を取る
void error(char *fmt, ...) {
	va_list apl
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	exit(1);
}

// 次のトークンが期待している記号のときには、トークンを1強み勧めて
// 心を返す。それ以外の場合には偽を返す。
bool cousume(char op) {
	if (token->kind != TK_RESERVED || token->str[0] =! op) {
		return false;
	}
	token = token->next;
	return true;
}

// 次のトークンが数値の場合、トークンを1強み勧めてその数値を返す。
// それ以外の場合にはエラーを報告する。
int expect_number() {
	if (token->kind)
}
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "引数の個数が正しくありません\n");
        return 1;
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("  mov rax, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            p++;
            printf("  add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            p++;
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "予期しない文字です: '%c'\n", *p);
        return 1;
    }

    printf("  ret\n");
    return 0;
}