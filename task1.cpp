#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char a[50][100], * b[50][7], year[4];
	int area, count, flag, n, flag1;
	
	do {
		printf("введите количество домов (не больше 50): ");
		scanf("%d", &n);
	} while ((n < 0) || (n > 50));
	while (getchar() != '\n'); 

	printf("\nВ каждой строчке укажите улицу, номер дома, год сдачи в эксплуатацию, количество этажей, количество квартир, общую жилую площадь, общую площадь дома:\n");
	
		for (int i = 0; i<n; i++) {
			gets_s (a[i]);
				b[i][0] = strtok(a[i], " ,");
				for (int k = 1; k < 7; k++) {
					b[i][k] = strtok(NULL, ", ");			
			}
		}	

	do {
		flag = 0;
		printf("\n|        Улица      | номер дома | год сдачи в эксплутацию | количество этажей | количество квартир | общая жилая площадь | общая площадь дома| \n");
		for (int i = 0; i < n; i++) {
			printf(" %-20.20s %-20.20s %-20.20s %-20.20s %-20.20s %-20.20s %-20.20s\n", b[i][0], b[i][1], b[i][2], b[i][3], b[i][4], b[i][5], b[i][6]);
		}
		printf("\nВведите год постройки:\n");
		scanf("%s", year);
		while (getchar() != '\n');

		printf("\nОбщая площадь дома должна быть не меньше:\n");
		scanf("%d", &area);

		printf("\nКоличество этажей должно быть меньше:\n");
		scanf("%d", &count);

		printf("\nСписок подходящих домов (их адреса):\n");
		for (int i = 0; i < n; i++) {
			if (((strcmp(year, b[i][2]) == 0) && (atoi(b[i][6]) >= area)) && (atoi(b[i][3]) < count)) {
				flag = 1;
				printf("%s,%s \n", b[i][0], b[i][1]);
			}
		}
		if (flag == 0) printf("По данному запросу не было найдено ни одного дома!");
		printf("\n\nЧтобы выйти нажмите Esc, чтобы сделать новый запрос нажмите другую клавишу\n");
	} while (_getch() != 27);
	
}
