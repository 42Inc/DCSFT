#include <iostream>
#include <fstream>
using namespace std;

void tasksGenerate(int n) {
	int m = 500;
	for (int i = 0; i < 10; i++) {
		string str = "./result/task" + to_string(i) + "n" + to_string(n);
		ofstream fout(str);

		fout << n << " " << m << endl;

		for (int i = 0; i < m; i++)
			fout << 1 + rand() % 100 << " " << 1 + rand() % n << endl;

		fout.close();
		m += 500;
	}
}

int main(int argc, char* argv[]) {
	int n = 0;
	cin >> n;
	srand(time(0));
	tasksGenerate(n);

	return 0;
}
