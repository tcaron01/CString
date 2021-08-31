#ifndef __STRING_H__
#define __STRING_H__
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    size_t length;
    size_t capacity;
    char* str;
} String;

String *create(const char *s);
void free_string(String **s);

char at(const String *s, const size_t pos);
char front(const String *s);
char back(const String *s);
char *data(const String *s);
void insert(String *s, const char c, const size_t pos);
bool empty(const String *s);
size_t size(const String *s);
void shrink_to_fit(String *s);

void clear(String *s);

void remove_char(String *s, const size_t pos);
void remove_substring_by_index(String *s, const size_t b, const size_t e);
void remove_substring(String *s, const String *pattern);

void push_back(String *s);
void pop_back(String *s);
void append(String *s, const char c);
int compare(const String *s1, const String *s2);
bool starts_with(const String *s, const String *p);
bool ends_with(const String *s, const String *p);
bool contains_char(const String *s, const char p);
bool contains_string(const String *s, const String *p);
void replace_char_first(String *s, const char c, const char r);
void replace_char_all(String *s, const char c, const char r);

void replace_substring_first(String *s, const String *m1, const String *m2);
void replace_substring_all(String *s, const String *m1, const String *m2);

String *substr(const String *s, const size_t start, const size_t end);
void resize(String *s, const size_t n_size);
void swap(String *s1, String *s2);


#endif
