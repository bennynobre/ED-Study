#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<char> iniciar() {
    string linha {};
    getLine(cin, linha);

    list<char> text {};
    int count {};

    for(auto i = linha.begin(); i != linha.end(); i++) {
        if(count == 0) {
            if (*i == '<' || *i == '>' || *i == 'B' || *i == 'D') {
                text.push_back('|');
                count++;
            }
        }
         
        text.push_back(*i);

        if ((i + 1) == linha.end()) {
            if (count == 0) 
                text.push_back('|');
            break;
        }
    }

    return text;
}

void show(list<char>& text) {
    for(auto& element : text)
        cout << element;
}

void edit(list<char>& text) {
    auto cursor = text.begin();
    int count {};
    list<char> chars {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'w', 'z', '-'};

    for(auto i = text.begin(); i != text.end(); i++) {
        for(auto i = text.begin(); i != text.end(); i++) {
            if(*i == '|')
                cursor = i;
        }
        
        if(*i == 'R')
            *i = '\n';
        else if(*i == 'B') {
            if (*cursor != text.front()) {
                cursor = text.erase(--cursor);
                i = text.erase(i);
                --i;
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (*i == 'D') {
            if (*cursor != text.back()) {
                text.erase(++cursor);
                i = text.erase(i);
                --i;
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (*i == '>') {
            if(*cursor != text.back()) {
                if(*(next(cursor)) == '>') {
                    while (i != prev(text.end()))
                        i = text.erase(i);
                    break;
                }
                
                auto element = ++cursor;
                cursor = text.erase(cursor);
                text.insert(--cursor, *element);
                i = text.erase(i);
                --i;
                ++count; 
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (*i == '<') {
            if(*cursor != text.front()) {
                auto element = --cursor;
                cursor = text.erase(cursor);
                text.insert(++cursor, *element);
                i = text.erase(i);
                --i;
                ++count;
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (count >= 1) {
            if (find(chars.begin(), chars.end(), *i) != chars.end()) {
                text.insert(cursor, *i);
                i = text.erase(i);
                --i;
            }
        }
    }

    show(text);
}

int main() {
    auto text = iniciar();
    edit(text);
}