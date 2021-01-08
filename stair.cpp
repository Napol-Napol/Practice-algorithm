#include <iostream>
using namespace std;
int num[101][10] = { 0, };
long long ans = 0;

void upstairs(int cnt)
{
	if (cnt == 1)
		return;

	for (int i = 1; i < 10; i++)
		num[1][i] = 1;
	num[1][0] = 0;
		for (int i = 2; i <= cnt; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j == 0)//���� ��ܼ��� 0���� ������ ���. ��, �� �ڿ� 1�ۿ� �� ����.
				{
					num[i][j] += num[i - 1][j + 1] % 1000000000;
				}

				else if (j == 9)//���� ��ܼ��� 9�� ������ ���. ��, �� �ڿ� 8�ۿ� �� ����.
				{
					num[i][j] += num[i - 1][j - 1] % 1000000000;
				}

				else
				{
					num[i][j] += (num[i - 1][j - 1] + num[i - 1][j + 1]) % 1000000000;
				}
			}
		}
		
	
	return;
}

int main()
{
	int cnt; cin >> cnt;

	if (cnt == 1)
	{
		cout << 9;
		return 0;
	}

	upstairs(cnt);

	for (int j = 0; j < 10; j++)
		ans += num[cnt][j];
	cout << ans % 1000000000;
}