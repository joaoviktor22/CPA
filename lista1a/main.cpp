#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#include <stdio.h>

int foo(int a) {
    return (a>>31);
}
int main()
{
    int a = -2102039;
    cout << foo(a);
}


