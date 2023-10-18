#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable:4996)
#define PRC_A 69.00
#define PRC_B 70.00
#define PRC_C 55.50
#define PRC_D 58.00
#define PRC_E 65.00
#define PRC_F 89.00
#define PRC_G 73.50
#define PRC_H 80.00
#define PRC_I 50.00
#define DISCOUNT_RATE_MORE_THAN_200 0.05
#define DISCOUNT_RATE_MORE_THAN_300 0.10
#define DISCOUNT_RATE_MORE_THAN_500 0.15


int field();
int development();
int resit();

int qty, qtybooka, qtybookb, qtybookc, qtybookd, qtybooke, qtybookf, qtybookg, qtybookh, qtybooki, i, orderNo = 1;
int booka = 0, bookb = 0, bookc = 0, bookd = 0, booke = 0, bookf = 0, bookg = 0, bookh = 0, booki = 0;
char bookSales1, nextOrder;
double price1, price2, subtotal, discounts, total;

void main()
{
	int choice;
	double total, rate;



	printf("                   < LOGO, WELCOME message, etc >\n");
	printf("\n                           UMT POS System\n");
	field();
	system("pause");
}


int field() {
	int choice,choice2;

	do {
		printf("\nSelect an option (1 = View Menu, 2 = Sales Order, 3 = Exit) : ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("Select a field to view : \n");
			printf("1 = Software Development Programming\n");
			printf("2 = Web Programming\n");
			printf("3 = Mobile Programming\n");
			printf("Input :");
			scanf("%d", &choice2);

			if (choice2 == 1)
			{
				printf("\nSoftware Development Programming Books :\n");
				printf("A = Beginning with Programmming Logic and Design   RM%.2f\n", PRC_A);
				printf("B = C Programming                                  RM%.2f\n", PRC_B);
				printf("C = Programming Fundamentals                       RM%.2f\n", PRC_C);
				system("pause");
			}
			else if (choice2 == 2)
			{
				printf("\nWeb Programing field Books :\n");
				printf("D = HTML and CSS Design                            RM%.2f\n", PRC_D);
				printf("E = Web Programing                                 RM%.2f\n", PRC_E);
				printf("F = ASP .NET Programming                           RM%.2f\n", PRC_F);
				system("pause");
			}
			else if (choice2 == 3)
			{
				printf("\nMobile Programming field Books :\n");
				printf("G = Mobile Design and Programming                  RM%.2f\n", PRC_G);
				printf("H = Building Mobile App                            RM%.2f\n", PRC_H);
				printf("I = Android Programming                            RM%.2f\n", PRC_I);
				system("pause");
			}


		}
	} while (choice == 1);

	if (choice == 2)
		development();

	if (choice == 3)
		return 0;
}


int development() {

	char yorn;


	printf("\n\nSales Order No: %d\n", orderNo);

	do {
		printf("\nBook A,B,C,D,E,F,G,H,I (X = Exit):");
		rewind(stdin);
		scanf("%c", &bookSales1);
		bookSales1 = toupper(bookSales1);
		switch (bookSales1)
		{
		case'A':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_A;
			qtybooka += qty;
			booka++;
			break;
		case'B':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_B;
			qtybookb += qty;
			bookb++;
			break;
		case'C':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_C;
			qtybookc += qty;
			bookc++;
			break;
		case'D':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_D;
			qtybookd += qty;
			bookd++;
			break;
		case'E':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_E;
			qtybooke += qty;
			booke++;
			break;
		case'F':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_F;
			qtybookf += qty;
			bookf++;
			break;
		case'G':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_G;
			qtybookg += qty;
			bookg++;
			break;
		case'H':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_H;
			qtybookh += qty;
			bookh++;
			break;
		case'I':
			printf("Quantity     :");
			scanf("%d", &qty);
			price1 = qty * PRC_I;
			qtybooki += qty;
			booki++;
			break;

		case'X':
			printf("Comfirm the order?(Y = Yes, N = No) :");
			rewind(stdin);
			yorn = toupper(getchar());
			{
				if (yorn == toupper('Y')) {
					orderNo++;
					resit();
				}
				else if (yorn == toupper('N'))
					development();
				else
					return 0; break; }

		default:
			printf("Error");
			development(); break;

		}

		subtotal += price1;
	} while (bookSales1 != 'X');
}

int resit() {
	int  n;
	if (booka != 0) {
		printf("Book A: %d @ RM %.2lf                                       =  %.2lf\n", qtybooka, PRC_A, qtybooka * PRC_A);
	}
	if (bookb != 0) {
		printf("Book B: %d @ RM %.2lf                                       =  %.2lf\n", qtybookb, PRC_B, qtybookb * PRC_B);
	}
	if (bookc != 0) {
		printf("Book C: %d @ RM %.2lf                                       =  %.2lf\n", qtybookc, PRC_C, qtybookc * PRC_C);
	}
	if (bookd != 0) {
		printf("Book D: %d @ RM %.2lf                                       =  %.2lf\n", qtybookd, PRC_D, qtybookd * PRC_D);
	}
	if (booke != 0) {
		printf("Book E: %d @ RM %.2lf                                       =  %.2lf\n", qtybooke, PRC_E, qtybooke * PRC_E);
	}
	if (bookf != 0) {
		printf("Book F: %d @ RM %.2lf                                       =  %.2lf\n", qtybookf, PRC_F, qtybookf * PRC_F);
	}
	if (bookg != 0) {
		printf("Book G: %d @ RM %.2lf                                       =  %.2lf\n", qtybookg, PRC_G, qtybookg * PRC_G);
	}
	if (bookh != 0) {
		printf("Book H: %d @ RM %.2lf                                       =  %.2lf\n", qtybookh, PRC_H, qtybookh * PRC_H);
	}
	if (booki != 0) {
		printf("Book I: %d @ RM %.2lf                                       =  %.2lf\n", qtybooki, PRC_I, qtybooki * PRC_I);
	}
	printf("\nSubtotal                                                   : %.2lf\n", subtotal);

	if (subtotal > 500) {
		discounts = subtotal * DISCOUNT_RATE_MORE_THAN_500;
	}
	else if (subtotal > 300) {
		discounts = subtotal * DISCOUNT_RATE_MORE_THAN_300;
	}
	else if (subtotal > 200) {
		discounts = subtotal * DISCOUNT_RATE_MORE_THAN_200;
	}
	else {
		discounts = 0;
	}
	printf("Discounts                                                  : %.2lf\n", discounts);
	total = subtotal - discounts;
	printf("Total to pay                                               : %.2lf\n", total);
	printf("\tTHANK YOU, HAVE A NICE DAY !!\n\n");

	printf("Next order? (Y = Yes, N = No) : ");
	rewind(stdin);
	scanf("%c", &nextOrder);
	nextOrder = toupper(nextOrder);
	while (nextOrder == 'Y') {

		booka = 0, bookb = 0, bookc = 0, bookd = 0, booke = 0, bookf = 0, bookg = 0, bookh = 0, booki = 0;
		subtotal = 0;

		development();
	}
	system("pause");
}