#include<iostream>
#include<stack>
using namespace std;
bool visited[10] = { false };
int printArr[10] = { 0 };
int N, M;
void dfs(int count) {

	if (count == M)
	{
		for (int i = 0; i < M; i++)
			cout << printArr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				printArr[count] = i;
				dfs(count + 1);
				printArr[count] = 0;
				visited[i] = false;
			}
		}
	}
}
int main() 
{
	cin >> N >> M;
	dfs(0);
	

}