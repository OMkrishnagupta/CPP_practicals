#include <iostream>
using namespace std;

int main()
{
    int n;
    double sum = 0.0;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum -= (1.0 / i);
        }
        else
        {
            sum += (1.0 / i);
        }
    }
    cout << "The sum of the first " << n << " terms of the series is: " << sum << endl;
    return 0;
}
