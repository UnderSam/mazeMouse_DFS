#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
#include<Windows.h>
using namespace std;
vector<string> maze;
fstream inputFile;

int visit[51][51] = { 0 };
int flag = 0;
void SetColor(int f = 7, int b = 0)
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}
void DFS(int x, int y)
{
	if (flag == 1) return;
	visit[x][y] = true;
	maze[x][y] = '2';

	if (x == 50 && y == 50) flag = 1;

	if (x - 1 >= 0 && !visit[x - 1][y] && maze[x - 1][y] == '0') DFS(x - 1, y);			 //0
	if (x - 1 >= 0 && y + 1 <= 51 && !visit[x - 1][y + 1] && maze[x - 1][y + 1] == '0') DFS(x - 1, y + 1);//1
	if (y + 1 <= 51 && !visit[x][y + 1] && maze[x][y + 1] == '0') DFS(x, y + 1);			 //2
	if (x + 1 <= 50 && y + 1 <= 51 && !visit[x + 1][y + 1] && maze[x + 1][y + 1] == '0') DFS(x + 1, y + 1);//3
	if (x + 1 <= 50 && !visit[x + 1][y] && maze[x + 1][y] == '0')DFS(x + 1, y);		     //4
	if (x + 1 <= 50 && y - 1 >= 0 && !visit[x + 1][y - 1] && maze[x + 1][y - 1] == '0') DFS(x + 1, y - 1);//5
	if (y - 1 >= 0 && !visit[x][y - 1] && maze[x][y - 1] == '0') DFS(x, y - 1);			 //6
	if (x - 1 >= 0 && y - 1 >= 0 && !visit[x - 1][y - 1] && maze[x - 1][y - 1] == '0') DFS(x - 1, y - 1);//7
}
void show()
{
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			cout << setw(1) << visit[i][j];
		}
		cout << endl;
	}
}
int main() {
	string row;

	inputFile.open("input.txt", ios::in);
	while (!inputFile.eof())
	{
		getline(inputFile, row);
		maze.push_back(row);
		row.clear();
	}

	DFS(1, 1);
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			if (maze[i][j] == '2') {
				SetColor(2, 0);
				cout << maze[i][j];
				SetColor();
			}
			else
			{
				cout << maze[i][j];
			}
		}
		cout << endl;
	}

}