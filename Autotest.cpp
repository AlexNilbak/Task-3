#include "Autotest.h"
#include "Class.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Var;
class CStack;

int Autotest() {
    Var V;
    V.name = "name";
    V.meaning = "meaning";
	CStack A;
    if (A.GetN() != 0) {
        return 1;
    }

    A.Push(V);
    if (A.GetN() != 1) {
        return 2;
    }

    CStack B=A;
    if (B[0].name != "name" || B[0].meaning != "meaning") {
        return 3;
    }

    B.Pop();
    if (B.GetN() != 0) {
        return 4;
    }
    A.Join(B);
    if (A.GetN() != 1) {
        return 5;
    }

    //-------------------------------------------------------//

    Var W;
    string str;
    str = "Cogito ergo sum";
    int k = Simple(str, W);
    if(k!=-1){
        return 6;
    }

    str = "Cogito    = sum";
    k = Simple(str, W);
    if(k!=1){
        return 7;
    }
    if (W.name != "Cogito") {
        return 8;
    }

    str = "Cogito +    sum";
    k = Simple(str, W);
    if(k!=2){
        return 9;
    }
    if (W.meaning != "sum") {
        return 10;
    }
    
	return 0;

}
