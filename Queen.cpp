#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int n; int res=0;
void map(int line, vector<int> check, int cnt)
{
	if (cnt == n)
	{
		res++;
		return;
	}


	for (int i = line; i < n; i++)
	{
		if (i > cnt)//�ð��� ���̱� ���� �߰���. �� �࿡ �� ���� �־�� �ϱ� ������ �� ������ ����.
			return;

		if (check[i] == -1)//(i+1)��° �ٿ� ���� ����.
		{

			for (int j = 0; j < n; j++)
			{
				bool isPossible = true;
				for (int k=0; k<line;k++)
				{
					if (check[k] != -1)
					{
						if (abs(i-k) == abs(j-check[k]) || check[k] == j)
						{
							isPossible = false;
							break;
						}
					}
				}

				if (isPossible)
				{
					check[i] = j;
					map(line + 1, check, cnt+1);
				}
				

			}

		}

	}




}

int main()
{
	vector<int> check;//check[0]�� �� ���ٿ��� ��� �ڸ��� ���� ���Ҵ��� �ǹ���. check[0]�� 2�̸� �� ���� ���ʿ��� �ι�° �ڸ��� ���� ����.
	cin >> n;

	for (int i = 0; i < n; i++)
		check.push_back(-1);

	map(0, check, 0);
	cout << res;
}