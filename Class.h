#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
	CStack(const CStack&b);
    ~CStack();
    CStack &operator=(const CStack&b);
    void Clean();
    void Reset();
    void Copy(const CStack&b);
    int GetN();
    int Empty();
    int Filled();
    int Push(const Var&x);
    int Get(Var&x);
    int Pop();
    int Change(int i, Var&x);
    Var &operator[](int i);
    int Join(CStack& b);
};
