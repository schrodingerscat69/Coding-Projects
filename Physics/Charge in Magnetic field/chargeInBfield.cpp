#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

#define PI 3.1415926535897932

int main()
{
    // Declaration of variables
    double x, y, z, vx, vy, vz, t, tf, dt;
    double x0, y0, z0, v0x, v0y, v0z, v0;
    double theta, omega;
    string buf;

    // Ask user for input
    cout << "# Enter omega:\n";
    cin >> omega; getline(cin, buf);
    
    cout << "# Enter v0, theta (degrees):\n";
    cin >> v0 >> theta; getline(cin, buf);
    
    cout << "# Enter tf, dt:\n";
    cin >> tf >> dt; getline(cin,buf);

    cout << "# omega = " << omega
        << " T = " << 2.0 * PI / omega << endl;
    cout << "# v0 = " << v0 
        << " theta = " << theta << " degrees" << endl;
    cout << "# t0 = " << 0.0 << " tf = " << tf
        << " dt = " << dt << endl;

    // Initialize
    if (theta < 0.0 || theta >= 90.0) exit(1);
    theta = (PI / 180.0) * theta;
    
    v0y = v0 * cos(theta);
    v0z = v0 * sin(theta);

    cout << "# v0x = " << 0.0
        << " v0y = " << v0y 
        << " v0z = " << v0z << endl;
    
    x0 = -v0y / omega;

    cout << "# x0 = " << x0 
        << " y0 = " << y0 
        << " z0 = " << z0 << endl;
    cout << "# xy plane: Circle with center at (0,0) and R = " << abs(x0) << endl;
    cout << "# step of helix: s = v0z * T = " << v0z * 2.0 * PI / omega << endl;

    ofstream myfile("ChargeInBfield.dat");
    myfile.precision(17);

    // Compute
    t = 0.0;
    vz = v0z;

    while (t <= tf)
    {
        x = x0 * cos(omega * t);
        y = -x0 * sin(omega * t);
        z = v0z * t;

        vx = v0y * sin(omega * t);
        vy = v0y * cos(omega * t);
        myfile << t << " "  
            << x << " " << y << " " << z << " "
            << vx << " " << vy << " " << vz << " " << endl;
        t = t + dt;
    } 

    return 0;
}
