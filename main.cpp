#include <iostream>
#include <fstream>
#include <string>
#include "Class.h"
#include "Parser.h"
#include "Autotest.h"
using namespace std;

int main(void) {
    int s=Autotest();
    if(s!=0){
        cout << "Autotest ¹ " << s << " failed" << endl;
        return s;
    }
    else{
        cout << "Autotest passed" << endl;
    }
    try {
        int n = FileTest("config.cfg");
        if (n != 0) {
            return n;
        }
        CStack S;
        S = Parser("config.cfg");
        n = S.GetN();
        if (n == 0) {
            cout << "There are no sensible lines" << endl;
        }
        else {
            cout << "I found " << n << " sensible lines" << endl;
            cout << "The result of parsing is" << endl;
            for (int j = 0; j < n; j++) {
                cout << S[j].name << " = " << S[j].meaning << endl;
            }
        }
    }
    catch (int x) {
        cout << "I found an exception" << x << endl;
    }
    return 0;
}
