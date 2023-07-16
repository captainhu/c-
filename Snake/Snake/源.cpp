#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
//����
class Snake {
public:
	//��ʾ�ߵ�����
	int x;
	int y;
	Snake* next;
	Snake* s;
	int sign=0;
	int grade = 0;
	void generateSnake() {
		s = new Snake();
		int x[6] = {5,5,5,5,5,5};
		int y[6] = {3,4,5,6,7,8};
		Snake* p = s;
		for (int i = 0; i < 6; i++) {
			Snake* q = new Snake();
			q->x = x[i];
			q->y = y[i];
			q->next = nullptr;
			p->next = q;
			p = q;
		}
	}
	// ����
	void draw_snake(int **map) {
		
		Snake* p = s->next ;
		map[p->x][p->y] = 2; //��ʾ��ͷ
		//�����ǽ��ʾһ��
		p = p->next;
		while (p != nullptr) {
			map[p->x][p->y] = 1;
			p = p->next;
		}
	}
	void update_snake(int** map, char c) {
		sign = 0;
		Snake* newsnake;
		newsnake = new Snake();
		if (c == 'w') {
			newsnake->x = s->next->x - 1;
			newsnake->y = s->next->y; // ����֮����ͷ��λ��
			newsnake->next = s->next;
			s->next = newsnake; // �൱��ͷ��
			//cout << map[newsnake->x][newsnake->y] << endl;
			if (map[newsnake->x][newsnake->y] == 1)
				sign = 3;
			else if (map[newsnake->x][newsnake->y] == 3)
			{
				sign = 2;
				grade++;
			}
			else	
				map[newsnake->x][newsnake->y] = 2;
			Snake* q = s->next->next; //��λ����������ͷλ��

			while (q->next->next!= NULL) {
				map[q->x][q->y] = 1;
				q = q->next;
			}
			if (sign == 2)
				draw_star(map);
			else {
				map[q->next->x][q->next->y] = 0;
				free(q->next);
				q->next = NULL;
			}
		}
		else if (c == 's') {
			newsnake->x = s->next->x + 1;
			newsnake->y = s->next->y;
			newsnake->next = s->next;
			s->next = newsnake;
			if (map[newsnake->x][newsnake->y] == 1)
				sign = 3;
			else if (map[newsnake->x][newsnake->y] == 3)
			{
				sign = 2;
				grade++;
			}
			else
				map[newsnake->x][newsnake->y] = 2;
			Snake* q = s->next->next;
			while (q->next->next != NULL) {
				map[q->x][q->y] = 1;
				q = q->next;
			}
			if (sign == 2)
				draw_star(map);
			else {
				map[q->next->x][q->next->y] = 0;
				free(q->next);
				q->next = NULL;
			}
			
		}
		else if (c == 'a') {
			newsnake->x = s->next->x;
			newsnake->y = s->next->y - 1;
			newsnake->next = s->next;
			s->next = newsnake;
			if (map[newsnake->x][newsnake->y] == 1)
				sign = 3;
			else if (map[newsnake->x][newsnake->y] == 3)
			{
				sign = 2;
				grade++;
			}
			else
				map[newsnake->x][newsnake->y] = 2;
			Snake* q = s->next->next;
			while (q->next->next != NULL) {
				map[q->x][q->y] = 1;
				q = q->next;
			}
			if (sign == 2)
				draw_star(map);
			else {
				map[q->next->x][q->next->y] = 0;
				free(q->next);
				q->next = NULL;
			}
		}
		else if(c=='d'){
			newsnake->x = s->next->x;
			newsnake->y = s->next->y + 1;
			newsnake->next = s->next;
			s->next = newsnake;
			if (map[newsnake->x][newsnake->y] == 1)
				sign = 3;
			else if (map[newsnake->x][newsnake->y] == 3)
			{
				sign = 2;
				grade++;
			}
			else
				map[newsnake->x][newsnake->y] = 2;
			Snake* q = s->next->next;
			while (q->next->next != NULL) {
				map[q->x][q->y] = 1;
				q = q->next;
			}
			if (sign == 2)
				draw_star(map);
			else {
				map[q->next->x][q->next->y] = 0;
				free(q->next);
				q->next = NULL;
			}
		}
	}

	void draw_star(int **map) {
		int x, y;
		//Ҫȡ��[a, b]�����������ʹ��(rand() % (b - a + 1)) + a;
		x = (rand() % (19 - 2 + 1)) + 2;
		y = (rand() % (19 - 2 + 1)) + 2;
		while (map[x][y]!=0) {
			x = (rand() % (19 - 2 + 1)) + 2;
			y = (rand() % (19 - 2 + 1)) + 2;
		}
		map[x][y] = 3;
	}
	
};
//���Ƶ�ͼ
class Map {
public:
	int** map;
	int hight;
	int wided;
	void draw_map(int high, int wide) {
		//��ͼ�Ƕ�̬���ɵģ���Ҫ��̬�����ڴ�
		hight = high;
		wided = wide;
		map = new int* [high];
		for (int i = 0; i < high; i++)
		{
			map[i] = new int[wide];
		}
		// ǽ�Ѷ�λ�����ֵ��Ϊ1
		//��һ�� ���һ��
		for (int i = 0; i < wide; i++)
		{
			map[0][i] = 1;
			map[high - 1][i] = 1;
		}
		//��һ�� ���һ��
		for (int i = 0; i < high; i++)
		{
			map[i][0] = 1;
			map[i][wide - 1] = 1;
		}
		for (int i = 1; i < high - 1; i++)
			for (int j = 1; j < wide - 1; j++) {
				map[i][j] = 0;
			}
		
	}
	void draw_map() {
		//����ͼ
		for (int i = 0; i < hight; i++)
		{
			for (int j = 0; j < wided; j++) {
				if (map[i][j] == 1)
					cout << "��";
				else if (map[i][j] == 2)
					cout << "��";
				else if (map[i][j] == 3)
					cout << "��";
				else
					cout << "��";
			}
			cout << endl;
		}
	}
	int** Getmap() {
		return map;
	}
};


int main() {
	
	Snake S;
	Map m;
	char c = ' ';
	
	m.draw_map(20, 20);
	
	S.generateSnake();
	S.draw_snake(m.map);
	S.draw_star(m.map);
		while (1) {
			cout << "��ķ�����" << S.grade << endl;
			//cout << S.sign << endl;
			if (S.sign == 3)	//����������û������
				break;
			if (_kbhit())
				c = _getch();
			S.update_snake(m.map, c);
			m.draw_map();
			Sleep(500);
			system("cls");
		}
		
		cout << "Game Over" << endl;
	//cout << m.hight << endl;
	
///	S.draw_snake(m.Getmap(), s);
	//m.draw_map(20, 20);
	
}