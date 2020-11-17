#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int **mt = nullptr, n, m, i, j, k, zam = 0;
	do {
		printf_s("Вводите параметры матрицы.\nКол-во строк: n = ");               //Блок проверки ввода
		i = scanf_s("%d", &n);
		if (i < 1 || n<1) {
			system("CLS");
			printf_s("Неправильный ввод, повтори попытку.\n");
			rewind(stdin);
			continue;
		}	
		printf_s("Кол-во столбцов: m = ");
		i = scanf_s("%d", &m);
		if (i < 1 || m<1) {
			system("CLS");
			printf_s("Неправильный ввод, повтори попытку.\n");
			rewind(stdin);
			continue;
		}
		if (!(mt = (int**)malloc(sizeof(int) * n))) {                //Блок проверки выделенной памяти под матрицу (сначала для каждого указателя, а затем и на массив,
			printf_s("No memory\n");                                 //созданный указателями)
			fflush(stdin);
			continue;
		}
		for (i = 0; i < m; i++) {
			if (!(*(mt+i) = (int*)malloc(sizeof(int) * m))) {
				printf_s("No memory\n");
				for (j = 0; j < i; j++) {
					free(*(mt + j));
					free(mt);
				}
			}
		}
	} while (!mt);
	printf_s("Вводите элементы матрицы:\n");
	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++) {
			printf_s("mt[%d][%d] = ", i, j);
			k = scanf_s("%d", *(mt+j)+i);
			if (k < 1) {
				j--;
				rewind(stdin);
			}
		}
	printf_s("Ваша матрица:");
	for (i = 0; i < n; i++) {
		printf_s("\n");
		for (j = 0; j < m; j++) {
			printf_s("%d ", *(*(mt + j) + i));
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (k = 0; k < n; k++) {
				if (*(*(mt + j) + k) > * (*(mt + j) + i) && (*(*(mt + j) + i) < 0) && (*(*(mt + j) + k) < 0)) {
					zam = *(*(mt + j) + i);
					*(*(mt + j) + i) = *(*(mt + j) + k);
					*(*(mt + j) + k) = zam;
				}
			}
		}
	}
	printf_s("\nВаша отсотрированная матрица:");
	for (i = 0; i < n; i++) {
		printf_s("\n");
		for (j = 0; j < m; j++) {
			printf_s("%d ", *(*(mt + j) + i));
		}
	}
}