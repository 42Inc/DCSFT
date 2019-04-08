#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int n = 0; /* Число ЭМ в системе */
int m = 0; /* Число задач в наборе для обработки */

typedef struct TreeNode {
	int gap_size;/* Вместимость уровня */
	int start_time; /* Время запуска уровня */
	int type;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *top;
} TreeNode;

typedef struct tasks {
	int number,			/* Номер задачи */
	rank,				/* Ранг задачи */
	time,				/* Время выполнения задачи */
	start_time, 		/* Время запуска задачи */
	position;			/* Смещение размещения задачи на ЭМ */
	struct tasks *next; /* Поле для сортировки подсчётом */
} tasks;

int NFDH_sort(tasks *root) {

	int currentLevel = 0, nextLevel = 0, freeMachineNumber = 0;
	tasks *ptr = root;

	currentLevel = 0;
	freeMachineNumber = ptr->rank;
	ptr->start_time = currentLevel;
	nextLevel = ptr->time;

	ptr = ptr->next;
	while (ptr->next != NULL)
	{
		if (ptr->rank + freeMachineNumber > n)
		{
			currentLevel = nextLevel;
			nextLevel += ptr->time;
			ptr->start_time = currentLevel;
			freeMachineNumber = ptr->rank;
		} else {
			ptr->start_time = currentLevel;
			freeMachineNumber += ptr->rank;
		}
		ptr = ptr->next;
	}

	return nextLevel;
}

TreeNode* FFDH_Create_Node(TreeNode *top, int i, int depth) {
	TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
	if (i != 0)
		ptr->top = top;

	ptr->gap_size = n;
	if (i < depth) {
		ptr->left = FFDH_Create_Node(ptr, i+1, depth);
		ptr->right = FFDH_Create_Node(ptr, i+1, depth);
		ptr->type = 0;
	}
	else {
		ptr->start_time = -1;
		ptr->type = 1;
	}
	return ptr;
}

tasks* createNode(int number, int rank, int time) {
	tasks *ptr = (tasks *)malloc(sizeof(tasks));
	ptr->number = number;
	ptr->rank = rank;
	ptr->time = time;
	ptr->next = NULL;

	return ptr;
}

TreeNode* FFDH_Find_Node(TreeNode *root, int gapsize, int depth) {
	TreeNode *ptr = root, *b_ptr;
	do {
		if (ptr->left->gap_size >= gapsize)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	} while (--depth);

	ptr->gap_size -= gapsize;
	b_ptr = ptr;
	while (ptr != root) {
		if (ptr->top->left->gap_size >= ptr->top->right->gap_size)
			ptr->top->gap_size = ptr->top->left->gap_size;
		else
			ptr->top->gap_size = ptr->top->right->gap_size;

		ptr = ptr->top;
	}
	return b_ptr;
}

int FFDH_Compute(tasks *data)
{
	int depth, time = 0;
	TreeNode *root, *ptr;
	tasks *tptr = data;

	depth = ceil(log(m) / log(2));
	root = FFDH_Create_Node(NULL, 0, depth);

	while (tptr->next != NULL) {
		ptr = FFDH_Find_Node(root, tptr->rank, depth);
		if (ptr->start_time == -1) {
			ptr->start_time = time;
			time += tptr->time;
		}
		tptr->start_time = ptr->start_time;
		tptr->position = (n - ptr->gap_size - tptr->rank);

		tptr = tptr->next;
	}
	return time;
}



int main(int argc, char* argv[]) {
	int a = 0, b = 0;
	int TS = 0;
		double Tsh = 0.0, e = 0;

	string str;

	if (argc < 2) {
		cout << "Enter filename";
		return 0;
	}
		ifstream fin(argv[1]);

	fin >> n >> m;

	int mass[n+1], mass2[n+1];
	int myMap1[m], myMap2[m], mySortMap1[m], mySortMap2[m];

	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		myMap1[i] = a;
		myMap2[i] = b;
		Tsh += a*b;
	}

	Tsh /= n;
	for (int i = 0; i < n+1; i++) {
		mass[i] = 0;
		mass2[i] = 0;
	}

	for (int i = 0; i < m; i++)
		mass[myMap1[i]]++;

	mass2[0] = mass[0];
	for (int i = 1; i < n+1; i++)
		mass2[i] = mass2[i-1] + mass[i];

	mass[0] = 0;
	for (int i = 1; i < n+1; i++)
		mass[i] = mass2[i-1];

	for (int i = 0; i < m; i++) {
		mySortMap1[mass[myMap1[i]]] = myMap1[i];
		mySortMap2[mass[myMap1[i]]] = myMap2[i];
		mass[myMap1[i]]++;
	}

	tasks *root = createNode(0, mySortMap2[m-1], mySortMap1[m-1]);
	tasks *end = root;
	for (int i = m-2, j = 1; i >= 0; i--, j++) {
		end->next = createNode(j, mySortMap2[i], mySortMap1[i]);
		end = end->next;
	}

	unsigned int startTime =  clock();
	TS = NFDH_sort(root);
	unsigned int endTime =  clock() - startTime;
	e = (TS - Tsh)/Tsh;

	cout << m << " " << endTime/1000.0 << endl;
	startTime = clock();
	TS = FFDH_Compute(root);
	endTime = clock() - startTime;
	e = (TS - Tsh)/Tsh;
	cout << m << " " << endTime/1000.0 << endl;
	fin.close();
	return 0;
}
