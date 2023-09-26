#include<iostream>
#include<stack>
using namespace std;
#define MAX_COL_SIZE 25
#define MAX_ROW_SIZE 19 


//미로 배열
int arr[MAX_COL_SIZE][MAX_ROW_SIZE] =
{
   {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
   {2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,2},
   {2,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,2},
   {2,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,2},
   {2,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,2},
   {2,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,2},
   {2,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,2},
   {2,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,2},
   {2,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,2},
   {2,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,2},
   {2,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,2},
   {2,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,2},
   {2,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,2},
   {2,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,2},
   {2,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,2},
   {2,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,2},
   {2,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,2},
   {2,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2},
   {2,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,2},
   {2,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,2},
   {2,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,2},
   {2,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2},
   {2,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,2},
   {2,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,2},
   {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};
bool answer[MAX_COL_SIZE][MAX_ROW_SIZE] = { false };
bool visited[MAX_COL_SIZE][MAX_ROW_SIZE] = { false };
int Min = 100000;
void dfs(int x, int y, int count)
{
    if (x == 23 && y == 17)
    {
        if (count < Min)
        {
            Min = count;
            memcpy(answer, visited, sizeof(bool) * MAX_COL_SIZE * MAX_ROW_SIZE);
        }
        return;
    }
    if (x + 1 < MAX_COL_SIZE && arr[x + 1][y] == 0 && visited[x + 1][y] != true)
    {
        visited[x + 1][y] = true;
        dfs(x + 1, y, count + 1);
        visited[x + 1][y] = false;
    }
    if (y + 1 < MAX_ROW_SIZE && arr[x][y + 1] == 0 && visited[x][y + 1] != true)
    {
        visited[x][y + 1] = true;
        dfs(x, y + 1, count + 1);
        visited[x][y + 1] = false;
    }

    if (y - 1 >= 0 && arr[x][y - 1] == 0 && visited[x][y - 1] != true)
    {
        visited[x][y - 1] = true;
        dfs(x, y - 1, count + 1);
        visited[x][y - 1] = false;
    }

    if (x - 1 >= 0 && arr[x - 1][y] == 0 && visited[x - 1][y] != true)
    {
        visited[x - 1][y] = true;
        dfs(x - 1, y, count + 1);
        visited[x - 1][y] = false;
    }
    return;

}
int main()
{
    visited[1][1] = true;
    dfs(1, 1, 0);

    for (int i = 0; i < MAX_COL_SIZE; i++)
    {
        for (int j = 0; j < MAX_ROW_SIZE; j++)
        {
            if (arr[i][j] == 1)
            {
                printf("■"); // 미로 벽 출력
            }
            else if (arr[i][j] == 2) // 미로 테두리 출력
            {
                printf("■");

            }
            else if (i == 1 && j == 1) // 시작 지점 출력
            {
                printf("ⓢ");
            }
            else if (i == 23 && j == 17) // 도착 지점 출력
            {
                printf("ⓔ");
            }
            else if (answer[i][j] == 1) // 경로 출력
            {
                printf("○");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }





    return 0;
}