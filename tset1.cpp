#include<stdio.h>
#include<string.h>
int maze[10][10];
int count = 0, min = 0, l = 0;
int n;
int flag;
int zou(int x, int y)
{
    if (x == n - 2 && y == n - 2)
    {
        flag = 1;
        if (l == 0)//��¼��һ���ߵ��յ�·�ߵĳ��ȣ�������ֵ��min�� 
        {
            min = count;
        }
        if (count < min)//���ߵ��յ�ĳ�����min���Ա� 
        {
            min = count;
        }
        l++;
        printf("%d", min);
        return 0;
    }
    maze[x][y] = 1;
    if (flag)return 0;
    if (maze[x][y - 1] == 0)
    {
        count++;
        zou(x, y - 1);
        count--;
    }
    if (maze[x + 1][y] == 0)
    {
        count++;
        zou(x + 1, y);
        count--;
    }
    if (maze[x - 1][y] == 0)
    {
        count++;
        zou(x - 1, y);
        count--;
    }
    if (maze[x][y + 1] == 0)
    {
        count++;
        zou(x, y + 1);
        count--;
    }
    return 0;
}
int main()
{

    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &maze[i][j]);
        }
    }
    flag = 0;
    zou(1, 1);
    if (!flag)
        printf("No solution");
    return 0;
}