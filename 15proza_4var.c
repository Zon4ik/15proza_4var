#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef struct Node {
	char lastName[50];
	char name[50];
	char city[50];
	char street[50];
	int numHouse;
	int numApartament;
	int accountNumb;
	int check;
	struct Node* next;
	struct Node* prev;

}Node;

// добавить в конец
void add(Node** head) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	int int_value;
	char str_value[50];

	system("cls");
	printf("Введи фамилию: ");
	scanf("%s", &str_value);
	strcpy(newNode->lastName, str_value);

	printf("Введи имя: ");
	scanf("%s", &str_value);
	strcpy(newNode->name, str_value);

	printf("Введи город: ");
	scanf("%s", &str_value);
	strcpy(newNode->city, str_value);

	printf("Введи улицу: ");
	scanf("%s", &str_value);
	strcpy(newNode->street, str_value);

	printf("Введи номер дома: ");
	scanf("%d", &int_value);
	newNode->numHouse = int_value;

	printf("Введи номер квартиры: ");
	scanf("%d", &int_value);
	newNode->numApartament = int_value;

	printf("Введи номер счета: ");
	scanf("%d", &int_value);
	newNode->accountNumb = int_value;

	printf("Введи средний сумма чека: "); // Переделать под float
	scanf("%d", &int_value);
	newNode->check = int_value;

	newNode->prev = NULL;
	newNode->next = *head;
	if (*head != NULL) {
		(*head)->prev = newNode;
	}
	*head = newNode;
	system("cls");
}
int printStack(Node* head) {
	printf("\nЭлементы списка: \n");
	while (head != NULL) {
		printf("Фамилия: %s \n", head->lastName);
		printf("Имя: %s \n", head->name);
		printf("Город: %s \n", head->city);
		printf("Улица: %s \n", head->street);
		printf("Номер дома: %d \n", head->numHouse);
		printf("Номер квартиры: %d \n", head->numApartament);
		printf("Номер счета: %d \n", head->accountNumb);
		printf("Средняя сумма чека: %d \n\n\n", head->check);
		head = head->next;
	}

	printf("\n\n");

	int ch;
	printf("Продолжить? (1 - yes, 0 - no): ");
	scanf("%d", &ch);
	return ch;
}

void pop(Node** head) {
	if (*head != NULL) {
		Node* temp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
}

void coutName(Node *head) {
	while (head != NULL) {
		printf("%s, ", head->name); 
		head = head->next;
	}
	printf("\n");
}


void deleteElement(Node** head) {
	system("cls");
	char choice[50];
	printf("Выбери покупателя из предложенных: "); coutName(*head);
	printf("\nВведи имя покупателя: ");
	scanf("%s", &choice);
	Node* temp = *head;
	Node* prev = NULL;
	while (temp != NULL) {
		if (!strcmp(temp->name, choice)) {
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Элемент не найден\n");
	}
	if (prev != NULL) {
		prev->next = temp->next;
		if (temp->next != NULL) {
			temp->next->prev = prev;
		}
		free(temp);
	}
	else if (prev == NULL && temp->next == NULL) {
		free(temp);
		*head = NULL;
	}
	else {
		pop(head);
	}
	printf("Список покупателя %s был удален\n", choice);
}

size_t findElement(Node* head) {
	char value[50];
	printf("Введи искомый элемент: ");
	scanf("%s", &value);
	printf("\n");
	while (head != NULL) {
		if (head->check == atoi(value)) {
			printf("Элемент %d найден\n", head->check);
			return head->check;
		}
		else if (head->numHouse == atoi(value)) {
			printf("Элемент %d найден\n", head->numHouse);
			return head->numHouse;
		}
		else if (head->numApartament == atoi(value)) {
			printf("Элемент %d найден\n", head->numApartament);
			return head->numApartament;
		}
		else if (head->accountNumb == atoi(value)) {
			printf("Элемент %d найден\n", head->accountNumb);
			return head->accountNumb;
		}
		else if (!strcmp(head->lastName, value)) {
			printf("Элемент %s найден\n", head->lastName);
			return head->lastName;
		}
		else if (!strcmp(head->name, value)) {
			printf("Элемент %s найден\n", head->name);
			return head->name;
		}
		else if (!strcmp(head->city, value)) {
			printf("Элемент %s найден\n", head->city);
			return head->city;
		}
		else if (!strcmp(head->street, value)) {
			printf("Элемент %s найден\n", head->street);
			return head->street;
		}
		else {
			head = head->next;
		}
	}
	printf("Элемент не найден\n\n");
}
int count_elements(Node* head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}

bool checkElemeent(Node* head, char value[50]) {
	while (head != NULL) {
		if (head->check == atoi(value)) {
			return true;
		}
		else if (head->numHouse == atoi(value)) {
			return true;
		}
		else if (head->numApartament == atoi(value)) {
			return true;
		}
		else if (head->accountNumb == atoi(value)) {
			return true;
		}
		else if (!strcmp(head->lastName, value)) {
			return true;
		}
		else if (!strcmp(head->name, value)) {
			return true;
		}
		else if (!strcmp(head->city, value)) {
			return true;
		}
		else if (!strcmp(head->street, value)) {
			return true;
		}
		return false;
	}
}

bool checkAdvancedFilter(char str[50], Node* head) {

	char* more = ">";
	char* less = "<";
	char* equal = "==";
	char* type;
	char* result;
	int num;
	sscanf(str, "%*s %*s %d", &num);
	
	result = strstr(str, more);
	if (result != NULL) {
		type = strtok(str, " ");
		if (!strcmp(type, "numberHouse")) {
			if (head->numHouse > num) {
				return true;
			}
		}
		else if (!strcmp(type, "numberApartament")) {
			if (head->numApartament > num) {
				return true;
			}
		}
		else if (!strcmp(type, "numberAccount")) {
			if (head->accountNumb > num) {
				return true;
			}
		}
		else if (!strcmp(type, "check")) {
			if (head->check > num) {
				return true;
			}
		}
		else {
			printf("\nНеправильно введен фильтр");
		}
	}
	result = strstr(str, less);
	if (result != NULL) {
		type = strtok(str, " ");
		if (!strcmp(type, "numberHouse")) {
			if (head->numHouse < num) {
				return true;
			}
		}
		else if (!strcmp(type, "numberApartament")) {
			if (head->numApartament < num) {
				return true;
			}
		}
		else if (!strcmp(type, "numberAccount")) {
			if (head->accountNumb < num) {
				return true;
			}
		}
		else if (!strcmp(type, "check")) {
			if (head->check < num) {
				return true;
			}
		}
		else {
			printf("\nНеправильно введен фильтр");
		}
	}
	result = strstr(str, equal);
	if (result != NULL) {
		type = strtok(str, " ");
		if (!strcmp(type, "numberHouse")) {
			int asd = head->numHouse;
			int sdsdf = num;
			if (head->numHouse == num) {
				return true;
			}
		}
		else if (!strcmp(type, "numberApartament")) {
			if (head->numApartament == num) {
				return true;
			}
		}
		else if (!strcmp(type, "numberAccount")) {
			if (head->accountNumb == num) {
				return true;
			}
		}
		else if (!strcmp(type, "check")) {
			if (head->check == num) {
				return true;
			}
		}
		else {
			printf("\nНеправильно введен фильтр");
		}
	}

	return false;
	
}
void insert(Node* head) {
	system("cls");
	int position;
	printf("Введи позицию на которую хотите добавить список: ");
	scanf("%d", &position);
	int count = count_elements(head) - position;
	if (position > 0 && position <= count_elements(head) + 1) { 
		if (position == count_elements(head) + 1) {
			printf(
				"Ты хочешь добавить элемент в конец. "
				"Используй команду 'add'\n"
			);
			return;
		}

		for (int i = 0; i < count; i++) {
			head = head->next;
		}

		Node* newNode = (Node*)malloc(sizeof(Node));
		int int_value;
		char str_value[50];
		system("cls");
		printf("Введи фамилию: ");
		scanf("%s", &str_value);
		strcpy(newNode->lastName, str_value);

		printf("Введи имя: ");
		scanf("%s", &str_value);
		strcpy(newNode->name, str_value);

		printf("Введи город: ");
		scanf("%s", &str_value);
		strcpy(newNode->city, str_value);

		printf("Введи улицу: ");
		scanf("%s", &str_value);
		strcpy(newNode->street, str_value);

		printf("Введи номер дома: ");
		scanf("%d", &int_value);
		newNode->numHouse = int_value;

		printf("Введи номер квартиры: ");
		scanf("%d", &int_value);
		newNode->numApartament = int_value;

		printf("Введи номер счета: ");
		scanf("%d", &int_value);
		newNode->accountNumb = int_value;

		printf("Введи средний сумма чека: "); // Переделать под float
		scanf("%d", &int_value);
		newNode->check = int_value;

		newNode->next = head->next;
		newNode->prev = head;
		head->next = newNode;
		
		system("cls");
		return;
	}

	printf("\nВышли за диапазон\n");
	return;

}

void saveFile(Node* head) {
	FILE* file = fopen("outfile.txt", "w");
	if (file == NULL) {
		ferror("Ошибка в файле");
		return 1;
	}
	char choice[50];
	char temp_str[50];
	printf(
		"Для фильтрации по тегу впиши тег\n"
		"Для фильтрации по велечинам используй структуру (<элемент> <условие> <значение элемента>)\n"
		"Элементы: numberHouse, numberApartament, numberAccount, check\n"
		"Добавить фильтр (n - not filter): "
	);
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { continue; }
	scanf("%[^\n]s", choice);
	strcpy(temp_str, choice);
	// lastName >10;

	int count = count_elements(head);
	fprintf(file, "Фильтр по тегу: %s\n\n", choice);
	while (head != NULL) {
		strcpy(choice, temp_str);
		if (checkElemeent(head, choice) || !strcmp(choice, "n") || checkAdvancedFilter(choice, head)) {
			fprintf(file, "Покупатель %d\n", count);
			fprintf(file, "Фамилия: %s\n", head->lastName);
			fprintf(file, "Имя: %s\n", head->name);
			fprintf(file, "Город: %s\n", head->city);
			fprintf(file, "Улица: %s\n", head->street);
			fprintf(file, "Номер дома: %d\n", head->numHouse);
			fprintf(file, "Номер квартиры: %d\n", head->numApartament);
			fprintf(file, "Номер среднего счета: %d\n", head->accountNumb);
			fprintf(file, "Средняя сумма чека: %d\n", head->check);
			fprintf(file, "\n\n");
			count--;
		}
		head = head->next;
	}
	printf("\nФайл создан и сохранен\n\n");
	fclose(file);
}

void loadFile(Node* head) {
	FILE* file = fopen("outfile.txt", "r");
	if (file == NULL) {
		ferror("Ошибка в файле");
		return 1;
	}
	wchar_t ch;
	while ((int)(ch = fgetc(file) ) != 65535) {
		printf("%c", ch);
	}
	

	fclose(file);
}

void freeStack(Node** head) {
	while (*head != NULL) {
		Node* temp = *head;
		*head = (*head)->next;
		free(temp);
	}

}
void mainMenu() {
	printf(
		"Выбери действие:\n"
		"1.Добавить данные покупателя\n"
		"2.Удалить данные покупателя\n"
		"3.Добавить конкретную позицию покупателя\n"
		"4.Найти и извлечь\n"
		"5.Сохранить все данные в файл\n"
		"6.Выгрузить все данные из файла\n"
		"7.Вывести все списки\n"
		"8.Выйти\n"
	);
}
main() {
	setlocale(0, "");
	Node* head = NULL;
	int choice; char ch;
start:
	mainMenu();
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		system("cls");
		add(&head);
		goto start;
		break;
	case 2:
		system("cls");
		deleteElement(&head);
		goto start;
		break;
	case 3:
		system("cls");
		insert(head);
		goto start;
		break;
	case 4:
		system("cls");
		size_t find_element = findElement(head);
		goto start;
		break;
	case 5:
		system("cls");
		saveFile(head);
		goto start;
		break;
	case 6:
		system("cls");
		loadFile(head);
		goto start;
		break;
	case 7:
		system("cls");
		int ch = printStack(head);
		if (ch == 1) {
			goto start;
		}
		else goto end;
		break;
	case 8:
		goto end;
		break;
	default:
		goto start;
		break;
	}
end:

	freeStack(&head);
	ch = printStack(head);
	return 0;
}