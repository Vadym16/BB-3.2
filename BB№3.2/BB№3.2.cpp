#include <iostream>

using namespace std;

class BoolVector {
public:
	BoolVector() :  data(NULL), size(0) {}
	BoolVector(int n) : size(n) {
		data = new bool[size];
		for (int i = 0; i < size; i++) {
			data[i] = false;
		}
	}
	BoolVector(const BoolVector& other) : size(other.size) {
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	~BoolVector() {
		delete[] data;
	}

	BoolVector operator&&(const BoolVector& other) {
		BoolVector res(size);
		for (int i = 0; i < size; i++) {
			res.data[i] = data[i] && other.data[i];
		}
		return res;
	}
	BoolVector operator||(const BoolVector& other) {
		BoolVector res(size);
		for (int i = 0; i < size; i++) {
			res.data[i] = data[i] || other.data[i];
		}
		return res;
	}
	BoolVector operator!() {
		BoolVector res(size);
		for (int i = 0; i < size; i++) {
			res.data[i] = !data[i];
		}
		return res;
	}
	BoolVector& operator=(const BoolVector& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new bool[size];
			for (int i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	bool operator==(const BoolVector& other) {
		if (size != other.size) return false;
		for (int i = 0; i < size; i++) {
			if (data[i] != other.data[i])return false;
		}
		return true;
	}

	int one_count() {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (data[i]) count++;
		}
		return count;
	}
	int zero_count() {
		return size - one_count();
	}
	void mod(const BoolVector& other) {
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	void set_bool(bool volue[], int n) {
		if (n > size) n = size;
		for (int i = 0; i < n; i++) {
			data[i] = volue[i];
		}
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}


private:
	bool* data;
	int size;
};




int main()
{
	setlocale(LC_ALL, "ukr");

	int n = 6, a0, b0, a1, b1;
	BoolVector A(n);
	BoolVector B(n);

	bool Avol[5] = { false, true, false, true, false };
	bool Bvol[5] = { true, false, true, false, true };

	A.set_bool(Avol, 5);
	B.set_bool(Bvol, 5);

	a0 = A.zero_count();
	a1 = A.one_count();
	cout << "В векторі А " << a0 << " нулів і " << a1 << " одиниць " << endl;
	b0 = B.zero_count();
	b1 = B.one_count();
	cout << "В векторі В " << b0 << " нулів і " << b1 << " одиниць " << endl;
	cout << "Вектор A: ";
	A.show();
	cout << "Вектор B: ";
	B.show();

	BoolVector C = A && B;
	cout << "A && B: ";
	C.show();

	BoolVector D = A || B;
	cout << "A || B: ";
	D.show();

	BoolVector E = !A;
	cout << "!A: ";
	E.show();

	cout << "Змінений Вектор A: " << endl;
	A.mod(B);
	A.show();

}

