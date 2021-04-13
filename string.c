#include <stdlib.h>
#include <stdio.h>

#include "string.h"

char *at(const String *s, const size_t pos){
    if(s == NULL){
        fprintf(stderr, "at : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    if(pos < 0){
        fprintf(stderr, "at : OOB access, index must be > 0.\n");
        exit(EXIT_FAILURE);
    }
    if(pos > s->length){
        fprintf(stderr, "at : OOB access, index must be < string length.\n");
        exit(EXIT_FAILURE);
    }
    if(pos > s->capacity){
        fprintf(stderr, "at : OOB access, index must be < string capacity.\n");
        exit(EXIT_FAILURE);
    }
    return s->str[pos];
}

char *front(const String *s){
    return at(s, 0);
}

char *back(const String *s){
    return at(s, s->length - 1);
}

char *data(const String *s){
    if(s == NULL){
        fprintf(stderr, "data : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    return *(s->str);
}

void insert(String *s, const char c, const size_t pos) {
    if(s == NULL){
        fprintf(stderr, "insert : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    if(pos < 0){
        fprintf(stderr, "insert : OOB access, index must be > 0.\n");
        exit(EXIT_FAILURE);
    }
    if(pos > s->length){
        fprintf(stderr, "insert : OOB access, index must be < string length.\n");
        exit(EXIT_FAILURE);
    }
    if(pos > s->capacity){
        fprintf(stderr, "insert : OOB access, index must be < string capacity.\n");
        exit(EXIT_FAILURE);
    }
    String tmp = *s;
    realloc(s->str, s->length * sizeof(char) + 1);
    for(int i = 0; i < pos; ++i) {
        s->str[i] = tmp.str[i];
    }
    s->str[pos] = c;
    for(int i = pos + 1; i < s->length + 1; ++i) {
        s->str[i] = tmp.str[i] - 1;
    }
    s->length++;
    s->capacity++;
}

bool empty(const String *s){
     if(s == NULL){
        fprintf(stderr, "size : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    return (s->length > 0) ? false : true;
}

size_t size(const String *s) {
    if(s == NULL){
        fprintf(stderr, "size : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    return s->length;
}

void shrink_to_fit(String *s);
void clear(String *s) {
     if(s == NULL){
        fprintf(stderr, "clear : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    free(s->str);
    s->str = NULL;
    s->length = 0;
    s->capacity = 0;
}

void erase(String *s);
void push_back(String *s);
void pop_back(String *s);
void append(String *s, const char c) {
    if(s == NULL){
        fprintf(stderr, "append : Can't access NULL string.\n");
        exit(EXIT_FAILURE);
    }
    String tmp = *s;
    realloc(s->str, s->length * sizeof(char) + 1);
    s->str[s->length] = c;
    s->length++;
    s->capacity++;
}

int compare(const String *s1, const String *s2) {
    if(s1 == NULL){
        fprintf(stderr, "compare : First String is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(s2 == NULL){
        fprintf(stderr, "size : Second string is NULL.\n");
        exit(EXIT_FAILURE);
    } 
    if(s1->length < s2->length){
        return 1;
    }  else if(s1->length > s2->length){
        return -1;
    }
    for(int i = 0; i < s1->length; ++i){
        if(s1->str[i] < s2->str[i]){
            return 1;
        } else if(s1->str[i] > s2->str[i]){
            return -1;
        }
    }
    return 0;
}

bool start_withs(const String *s, const String *p){
    if(s == NULL){
        fprintf(stderr, "starts_with: String is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(p == NULL){
        fprintf(stderr, "starts_with : Pattern string is NULL.\n");
        exit(EXIT_FAILURE);
    }  
    if(p->length > s->length){
        return false;
    }
    for(int i = 0; i < p->length; ++i){
        if(s->str[i] != p->str[i]){
            return false;
        }
    }
    return true;
}

bool ends_with(const String *s, const String *p){
    if(s == NULL){
        fprintf(stderr, "ends_with: String is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(p == NULL){
        fprintf(stderr, "ends_with : Pattern string is NULL.\n");
        exit(EXIT_FAILURE);
    }  
    if(p->length > s->length){
        return false;
    }
    for(int i = s->length - p->length; i < s->length; ++i){
        if(s->str[i] != p->str[i]){
            return false;
        }
    }
    return true;
}
bool contains_char(const String *s, const char p) {
    if(s == NULL){
        fprintf(stderr, "contains_char: string is NULL.\n");
        exit(EXIT_FAILURE);
    }
   
    for(int i = 0; i < s->length; ++i){
        if(s->str[i] == p){
            return true;
        }
    }
    return false;
}
bool contains_string(const String *s, const String *p){
    return true;
}

void replace_char_first(String *s, const char c, const char r){
    if(s == NULL){
        fprintf(stderr, "replace_charf_first: String is NULL.\n");
        exit(EXIT_FAILURE);
    }
   
    for(int i = 0; i < s->length; ++i){
        if(s->str[i] == c){
            s->str[i] = r;
            break;
        }
    }
}
void replace_char_all(String *s, const char c, const char r){
    if(s == NULL){
        fprintf(stderr, "replace_char_all: String is NULL.\n");
        exit(EXIT_FAILURE);
    }
   
    for(int i = 0; i < s->length; ++i){
        if(s->str[i] == c){
            s->str[i] = r;
        }
    }
}
void replace_substring_first(String *s, const String *m1, const String *m2){

}
void replace_substring_all(String *s, const String *m1, const String *m2){

}
String *substr(const String *s, const size_t start, const size_t end) {
    return "a";
}
void resize(String *s, const size_t n_size){

}
void swap(String *s1, String *s2){
    if(s1 == NULL){
        fprintf(stderr, "swap: First String is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(s2 == NULL){
        fprintf(stderr, "swap: Second String is NULL.\n");
        exit(EXIT_FAILURE);
    }
    String tmp = *s1;
    s1->str = s2->str;
    s2->str = tmp.str;
    s1->capacity = s2->capacity;
    s1->length = s2->length;
    s2->capacity = tmp.capacity;
    s2->length = tmp.length;
}