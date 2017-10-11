#include <iostream>
#define MAX 8

using namespace std;

int arrX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int arrY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int chessBoard[MAX][MAX];
//kiem tra xem 1 con bat ki hien tai co o trong ban co hay khong
bool check(int x, int y)
{
	return x > 0 && x <= MAX && y > 0 && y <= MAX;
}
//khoi tao cho cac gia tri trong ban co la -1
void init()
{
	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j<= MAX; j++)
			chessBoard[i][j] = -1;
	}
}
//dem buoc di cua con ma de an duoc con cua doi phuong
int countStep(int Arows, int Acols, int Brows, int Bcols)
{
	chessBoard[Arows][Acols] = 0;
	int count = 0;
	int xTemp, yTemp;
	while (true)
	{
		for (int i =1; i<= MAX; i++)
		{
			for (int j = 1; j <= MAX; j++)
			{
				if (chessBoard[i][j] == count)
				{
					for (int k = 0; k < MAX; k++)
					{
						xTemp = i + arrX[k];
					    yTemp = j + arrY[k];
						if (check(xTemp, yTemp))
						{
							if (chessBoard[xTemp][yTemp] == -1)
								chessBoard[xTemp][yTemp] = count + 1;
						}
					}
				}
			}
		}
		if (chessBoard[Brows][Bcols] != -1)
			return chessBoard[Brows][Bcols];

		count++;
	}
}

int main()
{
	int Acols, Arows;
	int Bcols, Brows;	
	//nhap vi tri cua con ma A hien tai
	cin>>Arows;
	cin>>Acols;
	//nhap vi tri cua con B
	cin>>Brows;
	cin>>Bcols;
   //khoi tao chessBoard 
	init();
	cout << countStep(Arows,Acols,Brows,Bcols);
	system("pause");
	return 0;
}



