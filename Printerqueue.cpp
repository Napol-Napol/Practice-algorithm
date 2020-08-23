#include <iostream>
#include <queue>
using namespace std;

int main() {
	int CASE;
	cin >> CASE;

	for (int i = 0; i < CASE; i++) {

		int n, m;
		cin >> n >> m;
		int arrImportance[10];//�߿䵵�� 1~9�� �� ������ ������ ����. (�ε��� 5���� �߿䵵�� 5�� ���� ���� ����.)
		for (int i = 0; i < 10; i++) arrImportance[i] = 0;

		bool *arr = new bool[n]; //�� �������� ��¿��θ� ����.
		for (int i = 0; i < n; i++) arr[i] = false;

		queue<int>idx;
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			arrImportance[a]++;
			idx.push(a);
		}

		int k = 0; // ť�� ������
		int cnt = 0; // ���ϴ� ��
		bool finish=false;

		for (int h = 9; h > 0; h--) {
			while (arrImportance[h] != 0) {

				if (idx.front() == h) {
					cnt++;
					if (k == m) {
						cout << cnt<<endl;
						finish = true;
						break;
					}

					else {
						arrImportance[h]--;
						arr[k] = true;
						while(arr[k])
							k=(k+1)%n;
						idx.pop();
					}
				}
				else {
					k = (k + 1) % n;
					while(arr[k])
						k = (k + 1) % n;

					idx.push(idx.front());
					idx.pop();
				}

			}
			if (finish) break;
		}
		delete[] arr;
	}
}