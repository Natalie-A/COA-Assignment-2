#include<iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
#include<string>

using namespace std;
//converting decimal to binary number
string convert_tobinary(double num) {
    string binary = "";
    string result = "";
    //getting the integer part
    int Integral = num;
    //getting the fractional part
    double fractional = num - Integral;
    //converting integer to binary
    while (Integral) {
        int rem = Integral % 2;
        binary.push_back(rem + '0');
        Integral /= 2;
    }
    //reversing the string to get the
    //required binary number
    reverse(binary.begin(), binary.end());
    binary.push_back('.');
    int count = 0;
    //converting fraction to binary
    do {
        count = count + 1;
        fractional *= 2;
        int fract_bit = fractional;
        if (fract_bit == 1) {
            fractional -= fract_bit;
            binary.push_back(1 + '0');
        }
        else
            binary.push_back(0 + '0');
    } while (fractional != 0);
    if (count < 5) {
        result = "exact";
    }
    else
        result = "approximate";
    cout << result;
    return binary;
}
int main() {
    srand(static_cast <unsigned> (time(0)));
    float x = 100.0;
    cout << "Remarks" << "\t" << "\t" << "Decimal" << "\t" << "\t" << "Binary" << "\n";
    for (int i = 0; i < 10; i++) {
        int j = 3;
        float r2 = (float(rand()) / float((RAND_MAX)) * x);
        cout << "\t" << fixed << showpoint << setprecision(j) << r2 << "\t" << "\t" << convert_tobinary(r2) << endl;
    }
    return 0;
}