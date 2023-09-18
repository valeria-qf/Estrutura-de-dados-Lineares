#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Digite o tamanho do vetor:"<< endl;
    cin >> n;

    int V[n];

    for(int i = 0; i < n; i++)
    {
        V[i] = rand()%100;
        cout << "\n" << V[i];
    }

}