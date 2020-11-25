#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Var;

class CStack;

int FileTest(const char* filename);

int Simple(string& str, Var& V);

int Equality(Var& V, CStack& S);

int Addition(Var& V, CStack& S);

CStack Parser(const char* filename);
