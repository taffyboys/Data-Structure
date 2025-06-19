#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 255

// 动态内存分配
// typedef struct {
// 	char *ch;
// 	int length;
// }string;

// char *initString() {
// 	string *s;
// 	s->ch = (char *)malloc(MAXSIZE * sizeof(char))
// 	s->length = 0;
// 	return s;
// }

// 链式存储
// typedef struct stringNode{
// 	char ch[4];
// 	struct stringNode * next;
// }stringNode;

typedef struct{
    char ch[MAXSIZE];
    int length;
}string;

int StrAssign(string *s, char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        s->ch[i+1] = string[i];
        i++;
    }
    s->length = i;
    return 1;
}

string *SubString(string *s, int pos, int len) {
    string *sub = (string *)malloc(sizeof(string));
    if (pos+len-1 > s->length) {
        printf("No such string\n");
        return 0;
    }
    for (int i=pos ; i<pos+len; i++) {
        sub->ch[i-pos+1] = s->ch[i];
    }
    sub->length = len;
    return sub;
}

int StrCmp(string *s, string *t) {
    int result = 0;
    for (int i=1; i<=s->length && i<= t->length; i++) {
        if (s->ch[i] != t->ch[i]) {
            return s->ch[i] - t->ch[i];
        }
    }
    return s->length - t->length;   
}

int LocateSub(string *s, string *t) {
    int i = 1, sLen = s->length, tLen = t->length;
    while(i < sLen - tLen + 1) {
        string *sub = SubString(s, i, tLen);
        if (StrCmp(sub, t)!=0) {
            i++;
        } else {
            return i;
        }
    }
    return 0;
}

int NaiveMatch(string *s, string *t) {
    int i=1, j=1;
    while (i<=s->length && j<=t->length) {
        if (t->ch[j] == s->ch[i]) {
            i++;
            j++;
        } else {
            i = i-j+2;
            j = 1;
        }
    }
    if (j > t->length) {
        return i - t->length;
    } else {
        return 0;
    }
}

int KmpMatch(string *s, string *t, int next[]) {
    int i=1, j=1;
    while (i<=s->length && j<=t->length) {
        if (j==0||s->ch[i]==t->ch[j]) {
            ++i;
            ++j;
        } else {
            j==next[j];
        }
    }
    if (j>t->length) {
        return i - t->length;
    } else {
        return 0;
    }
}

int main() {
    printf("Hello string\n");
    string s;
    string t;
    char chs[] = "hello st ring";
    char cht[] = "hello string ";
    StrAssign(&s, chs);
    StrAssign(&t,cht);
    string *sub = SubString(&s, 3, 4);
    printf("%d\n",StrCmp(&s, &t));
    char a[] = "helloworld";
    char b[] = "owo";
    StrAssign(&s, a);
    StrAssign(&t, b);
    printf("Locate sub:%d\n", LocateSub(&s, &t));
    printf("Naive match:%d\n", NaiveMatch(&s, &t));
    return 0;
}