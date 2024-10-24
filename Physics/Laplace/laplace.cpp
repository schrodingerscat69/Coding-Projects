#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

const int L = 31;
bool isConductor[L][L];
double V[L][L];

void initialize_lattice(const double& V1, const double& V2);
void laplace(const double& epsilon);
void print_results();

int main()
{
    string buf;
    double V1, V2, epsilon;

    cout << "Enter V1, V2:" << endl;
    cin >> V1 >> V2; getline(cin,buf);

    cout << "Enter epsilon:" << endl;
    cin >> epsilon; getline(cin,buf);

    cout << "Starting Laplace:" << endl;
    cout << "Grid Size = " << L << endl;
    cout << "Conductors set at V1 = " << V1 << "V2 = " << V2 << endl;
    cout << "Relaxing with accuracy epsilon = " << epsilon << endl;

    // Initialize V and isConductor
    initialize_lattice(V1,V1);

    laplace(epsilon);

    print_results();
}

void initialize_lattice(const double& V1, const double& V2)
{
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
        {
            V[i][j] = 0.0;
            isConductor[i][j] = false;
        }
    
    for (int i = 0; i < L; i++)
    {
        isConductor[0][i] = true;
        isConductor[i][0] = true;
        isConductor[L-1][i] = true;
        isConductor[i][L-1] = true;
    }

    for (int i = 4; i < L-5; i++)
    {
        V[L/3][i] = V1;
        isConductor[L/3][i] =true;
        V[2*L/3][i] = V2;
        isConductor[2*L/3][i] = true;
    }
}

void laplace(const double& epsilon)
{
    int icount;
    double Vav, error, dV;

    icount = 0;
    while(icount < 10000)
    {
        icount++;
        error = 0.0;
        
        for (int i = 1; i < L-1;i++)
        {
            for (int j = 1; j < L-1; j++)
            {
                if (!isConductor[i][j])
                {
                    Vav = 0.25*(V[i-1][j]+V[i+1][j]+V[i][j-1]+V[i][j+1]);
                    dV = abs(V[i][j] - Vav);
                    if (error < dV) error = dV;
                    V[i][j] = Vav;
                }  
            }
        }
        cout << icount << "err = " << error << endl;
        if (error < epsilon) return;
    }

    cerr << "Warning: laplace did not converge.\n";
}

void print_results()
{
    ofstream myfile("data");
    myfile.precision(16);
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
        {
            myfile << i+1 << " " << j+1 << " " << V[i][j] << endl;
        }

        myfile << " " << endl;
    }

    myfile.close();
}