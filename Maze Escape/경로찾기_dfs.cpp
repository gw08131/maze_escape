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
bool visited[MAX_COL_SIZE][MAX_ROW_SIZE] = { false };
int Min = 100000;

int main()
{
  
    stack<pair<int, int>> s;
    s.push({ 1, 1});
    
    while (!s.empty())
    {
        int x = s.top().first;
        int y = s.top().second;
        arr[x][y] = 5;
        visited[x][y] = true;

        if (x == 23 && y == 17)
        {
            break;
        }
        if (x + 1 < MAX_COL_SIZE && arr[x + 1][y] == 0 && visited[x + 1][y] != true)
        {
            s.push({ x + 1,y });
        }
       else if (y - 1 >= 0 && arr[x][y - 1] == 0 && visited[x][y - 1] != true)
        {
            s.push({ x ,y - 1 });
        } 
        else if (x - 1 >= 0 && arr[x - 1][y] == 0 && visited[x - 1][y] != true)
        {
            s.push({ x - 1,y });
        }
        else if (y + 1 < MAX_ROW_SIZE && arr[x][y + 1] == 0 && visited[x][y + 1] != true)
        {
            s.push({ x ,y + 1 });

        }
        else
        {
            s.pop();
            arr[x][y] = 0;
        }

    }
   
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
            else if (arr[i][j] == 5) // 경로 출력
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