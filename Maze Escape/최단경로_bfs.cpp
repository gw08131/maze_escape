#include <iostream>
#include <string>
#include <queue>
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

int main()
{
    queue<pair<pair<int, int>, pair<int,string>>> q;
    q.push({ { 1,1 }, {0,""} });
    bool visited[MAX_COL_SIZE][MAX_ROW_SIZE] = { false };
    bool answer[MAX_COL_SIZE][MAX_ROW_SIZE] = { false };
    int Min = 100000;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second.first;
        string cur_str = q.front().second.second;
        visited[x][y] = true;
        q.pop();



        if (x == 23 && y == 17)
        {
            //printArr();
            if (count < Min)
            {
                Min = count;
                memcpy(answer, visited, sizeof(bool) * MAX_COL_SIZE * MAX_ROW_SIZE);
            }
            break;
           
        }

        if (y + 1 < MAX_ROW_SIZE - 1 && arr[x][y + 1] == 0 && visited[x][y + 1] != true)
        {

            q.push({ { x, y + 1 }, {count + 1, cur_str+"("+to_string(x) + "," + to_string(y+1) + ")"} });

        }
        if (y - 1 >= 0 && arr[x][y - 1] == 0 && visited[x][y - 1] != true)
        {
            q.push({ { x, y - 1 }, {count + 1, cur_str + "(" + to_string(x) + "," + to_string(y-1) + ")"} });
        }
        if (x + 1 < MAX_COL_SIZE && arr[x + 1][y] == 0 && visited[x + 1][y] != true)
        {
            q.push({ { x + 1, y}, {count + 1, cur_str + "(" + to_string(x+1) + "," + to_string(y) + ")"} });
            
        }
        if (x - 1 >= 0 && arr[x - 1][y] == 0 && visited[x - 1][y] != true)
        {
            q.push({ { x - 1, y}, {count + 1, cur_str + "(" + to_string(x-1) + "," + to_string(y) + ")"} });
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