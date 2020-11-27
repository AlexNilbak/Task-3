#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
using namespace std;

struct Var {
    string name;
    string meaning;
};

class CStack {
    int n, size;
    Var* V;
public:
    CStack();
    CStack(const CStack& b);
    ~CStack();
    CStack& operator=(const CStack& b);
    void Clean();
    void Reset();
    void Copy(const CStack& b);
    int GetN();
    int Empty();
    int Filled();
    int Push(const Var& x);
    int Get(Var& x);
    int Pop();
    int Change(int i, Var& x);
    Var& operator[](int i);
    int Join(CStack& b);
};

int FileTest(const char* filename) {
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "Cannot open 'config.cfg'" << endl;
        input.close();
        return 1;
    }
    int i = 0;
    string l;
    while (getline(input, l)) {
        i++;
    }
    if (i == 0) {
        cout << "File is empty" << endl;
        input.close();
        return 2;
    }
    input.close();
    return 0;
};

int Simple(string& str, Var& V) {
    int k = 0;
    int len = str.length();
    int f = str.find("#");
    if(f!=-1){
        str.erase(f);
    }
    f = str.find("=");
    int p = str.find("+");
    if (f <= 0 && p == -1) {
        return -1;
    }
    if (f == -1 && p == 0) {
        return -1;
    }
    else {
        if ((f > 0 && p != -1 && f < p) || (f > 0 && p == 0)) {
            V.name.assign(str, 0, f);
            V.meaning.assign(str, f + 1, len - 1);
            k = 1;
        }
        if (f > 0 && p == -1) {
            V.name.assign(str, 0, f);
            V.meaning.assign(str, f + 1, len - 1);
            k = 1;
        }
        if (f > 0 && p > 0 && f > p) {
            V.name.assign(str, 0, p);
            V.meaning.assign(str, p + 1, len - 1);
            k = 2;
        }
        if (f == -1 && p > 0) {
            V.name.assign(str, 0, p);
            V.meaning.assign(str, p + 1, len - 1);
            k = 2;
        }
    }

    while (V.meaning[0] == ' ') {
        V.meaning.erase(0, 1);
    }

    len = V.name.length();
    for (int i = len - 1;V.name[i] == ' ';i--) {
        V.name.erase(i, 1);
    }
    len = V.name.length();
    for (int i = len - 1;i>=0;i--) {
        if (V.name[i] == ' ') {
            cout << "Problems with names?" << endl;
            throw - 4;
        }
    }
    return k;
};

int Equality(Var& V, CStack& S) {
    int k = -1;
    for (int i = 0; i < S.GetN(); i++) {
        if (S[i].name == V.name) {
            k = i;
        }
    }
    if (k != -1) {
        S.Change(k, V);
    }
    else {
        S.Push(V);
    }
    return 0;
};

int Addition(Var& V, CStack& S) {
    int k = -1;
    for (int i = 0; i < S.GetN(); i++) {
        if (S[i].name == V.name) {
            k = i;
        }
    }
    if (k != -1) {
        string z = V.meaning;
        V.meaning = S[k].meaning;
        V.meaning = V.meaning + z;
        S.Change(k, V);
    }
    else {
        return -1;
    }
    return 0;
};

CStack Parser(const char* filename) {
    ifstream input(filename);
    CStack S;
    Var V;
    int f, r;
    string str;
    while (getline(input, str)) {
        f = Simple(str, V);
        if (f != -1) {
            if (f == 1) {
                Equality(V, S);
            }
            if (f == 2) {
                Addition(V, S);
                /*
                r = Addition(V, S);
                if (r != 0) {
                    throw - 4;
                }
                */
            }
        }
    }
    input.close();
    return S;
};
