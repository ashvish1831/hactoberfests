// TIME COMPLEXITY --> O(n)
// SPACE COMPLEXITY --> O(1)

#include<iostream>
using namespace std;
// function to print fibonacci series
void printFibonacciSeries(int n)
{
    int f1 = 0, f2 = 1;
 
    if (n < 1)
        return;

    cout << f1 << " ";
    for (int i = 1; i<n; i++) 
    {
        cout << f2 << " ";
        int next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
}
// Driver Code
int main()
{
    int n = 10;
    printFibonacciSeries(n);
    return 0;
}