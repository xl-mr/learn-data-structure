#ifndef SORT_H

#define SORT_H
#define MAXSIZE 10

typedef int KeyType;
typedef struct {
    KeyType key;
    int otherInfo;
} RecType;

typedef RecType SeqList[MAXSIZE];

#endif
