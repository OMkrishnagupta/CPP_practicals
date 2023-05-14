#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
            throw "Invalid side length. All sides must be greater than 0.";
        }

        if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
            throw "Invalid side length. Sum of any two sides must be greater than the third side.";
        }

        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    double getArea() {
        if (side1 * side1 + side2 * side2 == side3 * side3 ||
            side1 * side1 + side3 * side3 == side2 * side2 ||
            side2 * side2 + side3 * side3 == side1 * side1) {
            return (side1 * side2) / 2;
        } else {
            double p = (side1 + side2 + side3) / 2;
            return sqrt(p * (p - side1) * (p - side2) * (p - side3));
        }
    }
};

int main() {
    try {
        Triangle t(5, 12, 13);
        cout << "Area of right angled triangle: " << t.getArea() << endl;

        Triangle t2(7, 8, 9);
        cout << "Area of triangle using Heron's formula: " << t2.getArea() << endl;

        Triangle t3(0, 4, 5);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
