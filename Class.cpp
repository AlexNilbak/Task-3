#include "Class.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

CStack::CStack(){
    Reset();
    V=new Var[size=1];
};

CStack::CStack(const CStack&b){
    Copy(b);
};

CStack::~CStack(){
    Clean();
};

CStack& CStack::operator=(const CStack&b){
    if(this!=&b){
        Clean();
        Copy(b);
    }
    return *this;
};

void CStack::Clean(){
    delete[] V;
    Reset();
};

void CStack::Reset(){
    V=NULL;
    n=0;
    size=0;
};

void CStack::Copy(const CStack&b){
    n = b.n;
    V = new Var[size=b.size];
    for (int i = 0; i < n; i++) {
        V[i] = b.V[i];
    }
};

int CStack::GetN(){
    return n;
};

int CStack::Empty(){
    return n==0;
};

int CStack::Filled(){
    return n==size;
};

int CStack::Push(const Var&x){
    if(Filled()){
        size = size * 2 + 1;
        Var *W=new Var[size];
        for (int i = 0; i < n; i++) {
            W[i] = V[i];
        }
        delete[] V;
        V=W;
    }
    V[n++]=x;
    return 0;
};

int CStack::Get(Var &x){
    if(Empty()){
        return -1;
    }
    x=V[n-1];
    return 0;
};

int CStack::Pop(){
    if(Empty()){
        return -2;
    }
    n--;
    return 0;
};

int CStack::Change(int i, Var &x){
    V[i]=x;
    return 0;
}

Var& CStack::operator[](int i){
    if(i<0 || i>=n)
        throw -3;
    return V[i];
}

int CStack::Join(CStack& b) {
    for (int i = 0; i < b.n; i++) {
        Push(b[i]);
    }
    return 0;
};
