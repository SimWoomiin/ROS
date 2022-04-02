#include<iostream>
#include<vector>
using namespace std;

struct Vector
{
	float x;
	float y;
	float z;
};

Vector ou(Vector a, Vector b) {
	Vector vt;
	vt.x = a.y * b.z - a.z * b.y;
	vt.y = a.z * b.x - a.x * b.z;
	vt.z = a.x * b.y - a.y * b.x;

	return vt;
}

float iu(Vector a, Vector b) {
	return a.x * b.x + a.y + b.y + a.z * b.z;
}

int main() {
	Vector v1, v2, v3;
	v1.x = 1, v1.y = 2, v1.z = 3;
	v2.x = 2, v2.y = 3, v2.z = 4;

	v3 = ou(v1, v2);

	cout << v3.x << ", " << v3.y << ", " << v3.z << endl;
	cout << iu(v1, v2);

	return 0;
}
