#include<iostream>

using namespace std;

void decToBinary(int n)
{
    // array to store binary number 
    int binaryNum[32];

    // counter for binary array 
    int k = 0;
    while (n > 0) {

        // storing remainder in binary array 
        binaryNum[k] = n % 2;
        n = n / 2;
        k++;
    }

    // printing binary array in reverse order 
    for (int l = k - 1; l >= 0; l--)
        cout << binaryNum[l];
}
void decToHexa(int j)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];

    // counter for hexadecimal number array
    int h = 0;
    while (j != 0) {
        // temporary variable to store remainder
        int temp = 0;

        // storing remainder in temp variable.
        temp = j % 16;

        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[h] = temp + 48;
            h++;
        }
        else {
            hexaDeciNum[h] = temp + 55;
            h++;
        }

        j = j / 16;
    }

    // printing hexadecimal number array in reverse order
    for (int j = h - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
}
int main()
{
    int j;
    cout << "Please input the last number you want to see in the table" << endl;
    cin >> j;
    cout << "\n";
    cout << "Decimal";
    cout << "\t";
    cout << "Binary";
    cout << "\t";
    cout << "Hexadecimal";
    cout << endl;
    for (int i = 1; i <= j; i++)
    {
        cout << i;
        cout << "\t";
        decToBinary(i);
        cout << "\t";
        decToHexa(i);
        cout << endl;
    }
    return 0;
}