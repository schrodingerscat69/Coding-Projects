#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int NTRANS,NSTEPS,i;
    double r, x0, x1, sum;
    string buf;

    // Ask user for input:
    cout << "# Enter NTRANS, NSTEPS, r, x0:\n";
    cin >> NTRANS >> NSTEPS >> r >> x0;  getline(cin,buf);

    cout << "# NTRANS = " << NTRANS << endl;
    cout << "# NSTEPS = " << NSTEPS << endl;
    cout <<"# r = " << r << endl;
    cout << "# x0 = " << x0 << endl;

    for (int i = 1; i <= NTRANS; i++)
    {
        x1 = r * x0 * (1.0 - x0);
        x0 = x1;
    }

    sum = log(abs(r*(1.0 - 2.0*x0)));

    // Initialize
    ofstream myfile("lia.dat");
    myfile.precision(17);

    myfile << 1 << " " << x0 << " " << sum << "\n";

    for (i = 2; i <= NSTEPS; i++)
    {
        x1 = r * x0 * (1.0-x0);
        sum += log(abs(r*(1.0-2.0*x1)));
        myfile << i << " " << x1 << " " << sum/i << "\n";
        x0 = x1;
    }
    myfile.close();
}
