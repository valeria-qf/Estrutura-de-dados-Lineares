#include <iostream>
using namespace std;

struct Person
{
    int age;
    char name[20];
    float weight;
}

family_member;

int main()
{
    Person sister;
    Person brother;

    sister.age = 10;
    brother.age = 15;

    cout << "Sister Age: " <<  sister.age << endl;
    cout << "Brother Age: " <<  brother.age << endl;
}