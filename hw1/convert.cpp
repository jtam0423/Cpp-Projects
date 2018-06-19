#include <iostream>
using namespace std;
double convert(int knot)
{
    double nmph = (knot * 6076);
    double mph = 5280;
    return nmph/mph/60;
}

int main( int argc, char *argv[] )
{
    cout << "How many knots?\n";	
    cin >> argc;
    cout << convert(argc) << " mile(s) per minute\n";
    return 0;
}
