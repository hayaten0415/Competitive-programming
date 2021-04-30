#include <iostream>
using namespace std;

int A, B, E[1 << 18];

int main() {
	// Input
	cin >> A >> B;

	// Make "God Array"
	if (A >= B) {
		for (int i = 0; i < A; i++) E[i] = i + 1;
		for (int i = A; i < A + B - 1; i++) E[i] = -(i - A + 1);
		for (int i = 0; i < A + B - 1; i++) E[A + B - 1] -= E[i];
	}
	else {
		for (int i = 0; i < A - 1; i++) E[i] = i + 1;
		for (int i = A; i < A + B; i++) E[i] = -(i - A + 1);
		for (int i = 0; i < A + B; i++) { if (i != A - 1) E[A - 1] -= E[i]; }
	}

	// Output
	for (int i = 0; i < A + B; i++) {
		if (i) cout << " ";
		cout << E[i];
	}
	cout << endl;
	return 0;
}
