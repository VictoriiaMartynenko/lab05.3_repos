#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

double r(const double x);

int main()
{
    double hp, hk, m;
    int n;

    cout << "hp = "; cin >> hp;
    cout << "hk = "; cin >> hk;
    cout << "n  = "; cin >> n;

    cout << fixed;
    cout << "-----------------------------------------------" << endl;
    cout << "|" << setw(5) << "m" << "     |"
        << setw(20) << "result" << "              |"
        << endl;
    cout << "-----------------------------------------------" << endl;

    double dh = (hk - hp) / n;
    double h = hp;

    while (h <= hk)
    {
        m = r(1 + (h * h) - (2 * h)) + 2 * r(1 + r(pow(h,2)) - 2*pow(r(1), 2));
        cout << "|" << setw(7) << setprecision(2) << h << "   |"
            << setw(20) << setprecision(5) << m << "              |"
            << endl;
        h += dh;
    }
    cout << "-----------------------------------------------" << endl;
    return 0;
}

double r(const double x)
{
    if (abs(x) >= 1)
        return ((1-pow(sin(x),2)) / exp(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = x / 6;
        S = a;
        do
        {
            j++;
            double R = x/((4+2*j)*(5+2*j));
            a *= R;
            S += a;
        } while (j < 7);
        return (1 / (1+x) * S);
    }
}
