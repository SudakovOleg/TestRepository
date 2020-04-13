#include "myclass.h"

MyClass::MyClass()
{

}

int MyClass::max(int a, int b)
{
    int m;
    if (a<b)
        m=a;
    else
        m=b;
    return m;
}
