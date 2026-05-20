#include <iostream>
#include <cmath>

using namespace std;


float evaluatePolynomial(float x, float coefficients[], int degree) {
    float result = coefficients[degree];
    for (int i = degree - 1; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

float findRoots(float x0, float x1, float coefficients[], int degree, float tolerance) {
    float mid, f0, f1, fm;
    int maxIterations = 1000; 

    for (int i = 0; i < maxIterations; ++i) {
        mid = (x0 + x1) / 2;
        f0 = evaluatePolynomial(x0, coefficients, degree);
        f1 = evaluatePolynomial(x1, coefficients, degree);
        fm = evaluatePolynomial(mid, coefficients, degree);

        if (fm == 0 || (x1 - x0) / 2 < tolerance) {
            
            return mid;
        }

        if ((fm > 0 && f0 > 0) || (fm < 0 && f0 < 0)) {
            
            x0 = mid;
        } else {
            
            x1 = mid;
        }
    }

    
    cout << "No root found within tolerance.\n";
    return mid;
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    float coefficients[degree + 1];
    cout << "Enter the Coefficients:\n";
    for (int i = degree; i >= 0; --i) {
        cout << "A[" << i << "]: ";
        cin >> coefficients[i];
    }

    float lowerLimit, upperLimit, incrementSize;
    cout << "Enter the lower limit: ";
    cin >> lowerLimit;
    cout << "Enter the upper limit: ";
    cin >> upperLimit;
    cout << "Enter the increment size: ";
    cin >> incrementSize;

    float tolerance = 0.0000001;
    float x0, x1, root;
    int maxRoots = 0;

    for (float x = lowerLimit; x <= upperLimit; x += incrementSize) {
        x0 = x;
        x1 = x + incrementSize;

        float f0 = evaluatePolynomial(x0, coefficients, degree);
        float f1 = evaluatePolynomial(x1, coefficients, degree);

        if ((f0 > 0 && f1 < 0) || (f0 < 0 && f1 > 0)) {
            
            root = findRoots(x0, x1, coefficients, degree, tolerance);
            cout << "Root found at x = " << root << endl;
            maxRoots++;
        }
    }

    cout << "Max number of roots found: " << maxRoots << endl;

    return 0;
}