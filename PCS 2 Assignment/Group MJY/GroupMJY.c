#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#pragma warning(disable:4996)

void logo();
void endlogo();

void mainMenu();

//staff function
void addStaff();
int choice(int mchoice);
void loginStaff();
void staffMenu();
void searchStaff();
void displayStaff();
void modifyStaff();
void modifyStaffInfo(int mdid);
void removeStaff();
void yesOrNo(char yesno, int* c);
void checkExistStaffIc(char addIc[13], int* ii);
void checkExistStaffTel(char addTel[12], int* tt);
int checStaffName(char addName[51]);

//stock function
void mainStock();
void restock();
void selectChoice(char choice, int* u);
void stockRefund();
void stockModify();
void stockView();
void stockSearch();
void stockReport();

//sales main module
void salesmain();
void salesAdd();
void salesSearch();
void salesModify();
void salesDisplay();
void salesReport();
void salesDelete();
//sales sub functions
void calsales(int qty, double price, double* salessubttl, double* salesttlprice);

//member function
void memMenu();
void memStat();
void memReg();
void topupMem();
void memberList();
void modifyMem();
void deleteMem();
int validationMem(char conT);


//staff structure
typedef struct {
	int id;
	char name[51];
}staffInfor;

struct staff{
	staffInfor staffBase;
	char IC[13];
	char telNum[12];
	char gender[7];
	char psw[31];
};

//stock structure


struct total {
	char tCode[6];
	int tqty;
};

struct stock {
	char sCode[6];
	int sqty;
	int date;
	int	month;

};



//sales structure
typedef struct {
	int d, m, y;
}Date;

typedef struct {
	Date date;
	char salesOrderId[5], itemCode[5], time[5], vouId[6];
	int qtyOrdered;
	double price;
}Salesinfo;

//member structure
typedef struct {
	int memID, expDate, memPt;
	char memStat[10];
}memSpecialINFO;

typedef struct {
	char memIC[13], name[31], gender, memEmail[51];
	int contactNum, age;
	memSpecialINFO inspect;
}member;

void logo() {
	printf("================================================================================================================\n");
	printf("    ____                             ____               _  _                           __  __             \n");
	printf("   [__  '.    ___ _     ____        F ___J   ____      FJ  LJ   ___ _    _ ___        F  \\/  ]     ____   \n");
	printf("   `--7 .'   F __` L   F __ J      J |___:  F __ J     J \\/ F  F __` L  J '__ J      J |\\__/| L   F __ J  \n");
	printf("    .'.'.'  | |--| |  | |--| |     | _____|| |--| |    J\\  /L | |--| |  | |--| |     | |`--'| |  | |--| | \n");
	printf("  .' (_(__  F L__J J  F L__J J     F |____JF L__J J     F  J  F L__J J  F L__J J     F L    J J  F L__J J \n");
	printf(" J________LJ\\____,__LJ\\______/F   J__F    J\\______/F   |____|J\\____,__LJ  _____/L   J__L    J__LJ\\______/F\n");
	printf(" |________| J____,__F J______F    |__|     J______F    |____| J____,__F|_J_____F    |__L    J__| J______F \n");
	printf("                                                                       L_J                                \n");
	printf("                                ______                              \n");
	printf("                               / _____)             _               \n");
	printf("                              ( (____  _   _  ___ _| |_ _____ ____  \n");
	printf("                               \\____ \\| | | |/___|_   _) ___ |    \ \n");
	printf("                               _____) ) |_| |___ | | |_| ____| | | |\n");
	printf("                              (______/ \\__  (___/   \\__)_____)_|_|_|\n");
	printf("                                      (____/                        \n");
	printf("================================================================================================================\n");
}

void endlogo() {
	printf(":'######::::'#######:::'#######::'########::'########::'##:::'##:'########:\n");
	printf("'##... ##::'##.... ##:'##.... ##: ##.... ##: ##.... ##:. ##:'##:: ##.....::\n");
	printf(" ##:::..::: ##:::: ##: ##:::: ##: ##:::: ##: ##:::: ##::. ####::: ##:::::::\n");
	printf(" ##::'####: ##:::: ##: ##:::: ##: ##:::: ##: ########::::. ##:::: ######:::\n");
	printf(" ##::: ##:: ##:::: ##: ##:::: ##: ##:::: ##: ##.... ##:::: ##:::: ##...::::\n");
	printf(" ##::: ##:: ##:::: ##: ##:::: ##: ##:::: ##: ##:::: ##:::: ##:::: ##:::::::\n");
	printf(". ######:::. #######::. #######:: ########:: ########::::: ##:::: ########:\n");
	printf(":......:::::.......::::.......:::........:::........::::::..:::::........::\n");
}

void main() {
	int mchoice, ch;//mchoice mean staff main function choice and ch mean return choice value

	logo();
	do {
		rewind(stdin);
		printf("\nEnter number (1-3) to select your choice:\n");
		printf("1. Register new staff.\n");
		printf("2. Login staff.\n");
		printf("3. Member Menu.\n");
		printf("4. Exit.\n");
		printf("choice:");
		scanf("%d", &mchoice);

		ch = choice(mchoice);

		if (ch == 1) {
			system("cls");
			addStaff();
		}

		else if (ch == 2) {
			system("cls");
			loginStaff();
		}
		else if (ch == 3) {
			system("cls");
			memMenu();
		}
		else if (ch == 4) {
			printf("\n\n");
			endlogo();
			system("pause");
			exit(-1);
		}
		else {
			printf("\nInvalid choice. Please enter (1 to 4) only!! \n\n");
			system("pause");
			system("cls");
			logo();
		}

	} while (mchoice > 4 || mchoice < 1);
}

int choice(int mchoice) {

	int q;
	q = mchoice;
	return q;
}

void addStaff() {

	char yesno, addGender, addName[51];//yesno for ask user choice yes or no and store to pointer//addGender for store user input data 
	char addIc[13], addtel[12];//use to identify is digit or not and the length no
	int icDigits, telDigits, i, ch, check;//ch for file pointer , icDigits and telDigits is for identidy digit or not
	struct staff stf;
	FILE* st;
	st = fopen("staff.txt", "a");
	if (st == NULL) {
		printf("Can't open file.\n");
		exit(-1);
	}
	printf("Register Staff\n");
	printf("---------------------\n");
	do {
		rewind(st);
		rewind(stdin);
		printf("\nEnter staff name(enter xxx to exit): ");
		scanf("%[^\n]", addName);

		if (strcmp(addName, "xxx") == 0 || strcmp(addName, "XXX") == 0) {
			system("cls");
			main();
			break;
		}
		check = checStaffName(addName);

		if (check == 1) {
			printf("Please enter alphabet only for the name.\n");
		}
	} while (check == 1);
	strcpy(stf.staffBase.name, addName);

	do {
		int ii = 0;
		check = 0;
		icDigits = 0;
		rewind(st);
		rewind(stdin);
		printf("\nEnter staff IC number (exactly 12 digits): ");
		scanf("%s", addIc);

		if (strlen(addIc) != 12) {
			printf("Please enter exactly 12 digits without dashes!\n");
		}

		else {
			for (i = 0; i < 12; i++) {
				if (!isdigit(addIc[i])) {
					icDigits = 1;
					printf("Please enter only digits!\n");
					break;
				}
			}
		}

		checkExistStaffIc(addIc, &ii);

		if (ii == 1) {
			printf("Staff IC already exist.\n");
			check = 1;
		}

	} while (strlen(addIc) != 12 || icDigits == 1 || check == 1);
	strcpy(stf.IC, addIc);

	do {
		int tt = 0;
		check = 0;
		telDigits = 0;
		rewind(st);
		rewind(stdin);
		printf("\nEnter staff telephone number:");
		scanf("%s", addtel);

		if (strlen(addtel) != 11 && strlen(addtel) != 10) {
			printf("Please enter exactly 10 or 11 digits without dashes!\n");
		}

		else {
			if (strlen(addtel) == 11) {
				for (i = 0; i < 11; i++) {
					if (!isdigit(addtel[i])) {
						telDigits = 1;
						printf("Please enter only digits!\n");
						break;
					}
				}
			}

			else if (strlen(addtel) == 10) {
				for (i = 0; i < 10; i++) {
					if (!isdigit(addtel[i])) {
						telDigits = 1;
						printf("Please enter only digits!\n");
						break;
					}
				}
			}
		}

		checkExistStaffTel(addtel, &tt);

		if (tt == 1) {
			printf("Telephone number already exist.\n");
			check = 1;
		}

	} while (strlen(addtel) != 11 && strlen(addtel) != 10 || telDigits == 1 || check == 1);
	strcpy(stf.telNum, addtel);

	printf("\nEnter your password:");
	rewind(stdin);
	scanf("%s", stf.psw);

	do {
		rewind(stdin);
		printf("\nEnter your gender(M or F):");
		scanf("%c", &addGender);

		if (addGender == 'm' || addGender == 'M') {
			strcpy(stf.gender, "Male");
			break;
		}
		if (addGender == 'f' || addGender == 'F') {
			strcpy(stf.gender, "Female");
			break;
		}
		else {
			printf("Please enter 'm' or 'f' only.\n");
		}
	} while (addGender != 'm' || addGender != 'M' || addGender != 'f' || addGender != 'F');

	srand(time(NULL));
	stf.staffBase.id = rand() % 9000 + 1000;

	do {
		rewind(stdin);
		printf("\nSure to add staff?");
		printf("\ny=yes, n=no:");
		scanf("%c", &yesno);

		yesOrNo(yesno, &ch);

		if (ch == 1) {
			printf("\nAdd staff successful.\n");
			printf("\nYour staff ID is %d\n", stf.staffBase.id);

			fprintf(st, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);

			system("pause");
			system("cls");
			break;
		}
		else if (ch == 2) {
			printf("\nFailed to register new staff.\n");
			system("pause");
			system("cls");
			break;
		}
		else if (ch == 3) {
			printf("\nPlease enter 'Y' or 'N' only.\n");
		}
	} while (ch == 3);

	fclose(st);
	main();
}

void staffMenu() {

	int option;
	printf("Welcome to staff system.\n");
	do {
		rewind(stdin);
		printf("1. Search staff.\n");
		printf("2. Display staff.\n");
		printf("3. Modify staff.\n");
		printf("4. Remove staff.\n");
		printf("5. Back To Main Menu.\n");
		printf("6. Log out staff.\n");
		printf("Select your choice(1-6):");
		scanf("%d", &option);

		switch (option) {
		case 1:
			system("cls");
			searchStaff();
			break;
		case 2:
			system("cls");
			displayStaff();
			break;
		case 3:
			system("cls");
			modifyStaff();
			break;
		case 4:
			system("cls");
			removeStaff();
			break;
		case 5:
			system("pause");
			system("cls");
			mainMenu();
			break;
		case 6:
			printf("Logging out...\n");
			system("pause");
			system("cls");
			main();
			break;
		default:
			system("cls");
			printf("\nIncorrect choice!\n\n");
			printf("Only can select 1 until 6 for your choice.\n");
		}
	} while (option > 6 || option < 1);
}

void loginStaff() {

	int logid, registerNew;//logid is user input data to identify with text file //registerNew to ask user want to register new staff or not
	char psw[31];
	struct staff stf;
	FILE* st;
	st = fopen("staff.txt", "r");
	if (st == NULL) {
		printf("Can't open file.");
		exit(-1);
	}
	do {
		rewind(stdin);
		printf("Login Staff\n");
		printf("---------------------\n");
		printf("Enter staff ID(0 to exit):");
		scanf("%d", &logid);

		if (logid == 0) {
			system("cls");
			fclose(st);
			main();
		}

		while (fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw) != EOF) {
			if (logid == stf.staffBase.id) {
				printf("Enter staff password:");
				scanf("%s", psw);

				if (strcmp(psw, stf.psw) == 0) {
					printf("Login sucessful!\n");
					system("pause");
					system("cls");
					fclose(st);
					mainMenu();
				}
				else {
					printf("\nIncorrect password!\n");
					printf("Please enter again.\n\n");
					fclose(st);
					loginStaff();
				}
			}
		}
		if (logid != stf.staffBase.id) {
			printf("Incorrect staff ID!\n\n");
			do {
				rewind(stdin);
				printf("Do you want to register new staff?\n");
				printf("1.Register new staff.\n");
				printf("2.Login staff again.\n");
				printf("Enter your choice:");
				scanf("%d", &registerNew);
				if (registerNew == 1) {
					system("cls");
					fclose(st);
					addStaff();
				}
				else if (registerNew == 2) {
					system("cls");
					fclose(st);
					loginStaff();
				}
				else
				{
					printf("\nPlease enter 1 or 2 only.\n\n");
				}
			} while (registerNew < 1 || registerNew > 2);
		}
	} while (!feof(st));
	fclose(st);
}

void mainMenu() {

	int select;

	do {
		rewind(stdin);
		printf("Welcome !!!\n");
		printf("Pls Enter The Number Between 1 to 5 : \n");
		printf("1.Staff Function\n");
		printf("2.Stock Function\n");
		printf("3.Sales Function\n");
		printf("4.Member Function\n");
		printf("5.Log Out Staff\n");
		printf("\nPls Enter Your Choice : ");
		scanf("%d", &select);

		if (select < 1 || select > 5) {
			printf("Error!! Please enter between 1 to 5 only.\n");
			system("pause");
			system("cls");
		}

	}while(select < 1 || select > 5);

	switch (select) {
	case 1:
		system("cls");
		staffMenu();
		break;
	case 2:
		system("cls");
		mainStock();
		break;
	case 3:
		system("cls");
		salesmain();
		break;
	case 4:
		system("cls");
		memMenu();
		break;
	case 5:
		system("cls");
		main();
		break;
	default:
		printf("Pls Enter The Number Between 1 to 5 : \n");
	}





}

void searchStaff() {

	int schoice, id;//schoice is search function choice//id is to check is that same with the text data
	struct staff stf;
	FILE* st;
	st = fopen("staff.txt", "r");
	if (st == NULL) {
		printf("Can't open file.");
		exit(-1);
	}

	do {
		rewind(stdin);
		printf("\nPlease enter staff ID to search the staff information(0 to go back staff menu):");
		scanf("%d", &id);

		if (id == 0) {
			system("cls");
			fclose(st);
			staffMenu();
			break;
		}

		int search = 0;
		while (!feof(st)) {
			fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
			if (stf.staffBase.id == id) {
				search = 1;
				printf("\nStaff ID %d information is", stf.staffBase.id);
				printf("\nStaff Name: %s", stf.staffBase.name);
				printf("\nStaff Gender: %s", stf.gender);
				printf("\nStaff IC no: %s", stf.IC);
				printf("\nStaff telephone no: %s\n", stf.telNum);
				system("pause");
				system("cls");
				fclose(st);
				searchStaff();
			}
		}
		rewind(st);

		if (search == 0) {
			printf("\nNot ID found!!\n");
			do {
				rewind(stdin);
				printf("\nDo you want to search other staff ID?.");
				printf("\n1. To search other staff ID.");
				printf("\n2. To go back staff menu.");
				printf("\nYour choice:");
				scanf("%d", &schoice);
				if (schoice == 1) {
					system("cls");
					fclose(st);
					searchStaff();
					break;
				}

				else if (schoice == 2) {
					system("cls");
					fclose(st);
					staffMenu();
					break;
				}
				else
					printf("Please choice 1 or 2 only.\n");
			} while (schoice != 1 && schoice != 2);
		}
	} while (id != stf.staffBase.id);
	fclose(st);
}

void displayStaff() {

	struct staff stf;
	FILE* st;
	st = fopen("staff.txt", "r");
	if (st == NULL) {
		printf("Can't open file.");
		exit(-1);
	}

	printf("Staff ID\tStaff Name\t  Staff gender\t\t Staff IC\t  Staff telephone no\t\n");

	while (!feof(st)) {
		fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
		printf(" %d\t\t%s\t\t%s\t\t%s\t  \t%s\t\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum);
	}

	system("pause");
	system("cls");
	fclose(st);
	staffMenu();
}

void modifyStaff() {

	int mdid;//modify function id
	struct staff stf;
	FILE* st;
	FILE* md;
	md = fopen("modify.txt", "w");
	st = fopen("staff.txt", "r+");
	if (st == NULL || md == NULL) {
		printf("Can't open file.");
		exit(-1);
	}
	printf("Modify staff information.\n");
	printf("-----------------------------\n");
	printf("Enter staff ID(0 to stop):");
	scanf("%d", &mdid);
	rewind(st);
	while (fscanf(st, "%d %[^\=]= %s %s %d %s\n", &stf.staffBase.id, stf.staffBase.name, &stf.gender, stf.IC, &stf.telNum, stf.psw) != EOF) {
		rewind(stdin);
		if (mdid == stf.staffBase.id) {
			fclose(st);
			fclose(md);
			modifyStaffInfo(mdid);
		}
	}
	if (mdid == 0) {
		system("cls");
		fclose(st);
		fclose(md);
		staffMenu();
	}
	if (mdid != stf.staffBase.id) {
		printf("No staff founded!\n\n");
		system("pause");
		system("cls");
		fclose(st);
		fclose(md);
		modifyStaff();
	}
	fclose(st);
	fclose(md);

	remove("staff.txt");
	rename("modify.txt", "staff.txt");
}

void modifyStaffInfo(int mdid) {

	int chmoin, choice, newIcDigits, newTelDigits, m, ch, mcheck;  //ch is for file pointer //m as a condition for a for loop
	//choice for let user choose with part want to change//chmoin to ask user comfirm to modify the data or not
	char yesno, newGender;//yesno for ask user choice yes or no and store to pointer//newGender is the user input data
	char newIc[13], newTel[12], newName[51];
	struct staff stf;
	FILE* st;
	FILE* md;
	st = fopen("staff.txt", "r+");
	md = fopen("modify.txt", "w");
	if (st == NULL || md == NULL) {
		printf("Can't open file.");
		exit(-1);
	}
	do {
		rewind(stdin);
		rewind(st);
		while (fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw) != EOF) {
			rewind(stdin);
			if (mdid == stf.staffBase.id) {
				printf("\nStaff ID %d information is", stf.staffBase.id);
				printf("\nStaff Name: %s", stf.staffBase.name);
				printf("\nStaff Gender: %s", stf.gender);
				printf("\nStaff IC no: %s", stf.IC);
				printf("\nStaff telephone no: %s\n", stf.telNum);
				printf("\nWhat you want to modify?");
				printf("\nStaff ID is cannot be modify.\n");
				printf("-------------------------------\n");
				printf("1.Name\n");
				printf("2.Gender\n");
				printf("3.IC no\n");
				printf("4.Telephone no\n");
				printf("5.Password\n");
				printf("6.Close and back to menu.\n");
				printf("Enter your choice:");
				scanf("%d", &choice);

				if (choice == 1) {
					printf("\nThe current name is %s", stf.staffBase.name);
					do {
						rewind(stdin);
						printf("\nNew name is :");
						scanf(" %[^\n]", newName);

						mcheck = checStaffName(newName);

						if (mcheck == 1) {
							printf("Please enter alphabet only for the name.\n");
						}
					} while (mcheck == 1);
					strcpy(stf.staffBase.name, newName);

					fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
				}

				else if (choice == 2) {
					printf("\nThe current gender is %s", stf.gender);

					do {
						rewind(stdin);
						printf("\nNew gender is :");
						scanf("%c", &newGender);
						if (newGender == 'm' || newGender == 'M') {
							strcpy(stf.gender, "Male");
							break;
						}
						else if (newGender == 'f' || newGender == 'F') {
							strcpy(stf.gender, "Female");
							break;
						}
						else {
							printf("Please enter 'm' or 'f' only.\n");
						}
					} while (newGender != 'm' || newGender != 'M' || newGender != 'f' || newGender != 'F');

					fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
				}

				else if (choice == 3) {
					printf("\nThe current IC no is %s", stf.IC);
					do {
						int mii = 0;
						mcheck = 0;
						newIcDigits = 0;
						rewind(stdin);
						printf("\nNew IC no is :");
						scanf("%s", newIc);

						if (strlen(newIc) != 12) {
							printf("Please enter exactly 12 digits without dashes!\n");
							newIcDigits = 1;
						}
						else {
							for (m = 0; m < 12; m++) {
								if (!isdigit(newIc[m])) {
									newIcDigits = 1;
									printf("Please enter only digits!\n");
									break;
								}
							}
						}

						checkExistStaffIc(newIc, &mii);

						if (mii == 1) {
							printf("Staff IC already exist.\n");
							mcheck = 1;
						}

					} while (strlen(newIc) != 12 || newIcDigits == 1 || mcheck == 1);
					strcpy(stf.IC, newIc);

					fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
				}

				else if (choice == 4) {
					printf("\nThe current telephone no is %s", stf.telNum);
					do {
						int mtt = 0;
						mcheck = 0;
						newTelDigits = 0;
						rewind(stdin);
						printf("\nNew telephone no is :");
						scanf("%s", newTel);

						if (strlen(newTel) != 11 && strlen(newTel) != 10) {
							printf("Please enter exactly 10 or 11 digits without dashes!\n");
						}

						else {
							if (strlen(newTel) == 11) {
								for (m = 0; m < 11; m++) {
									if (!isdigit(newTel[m])) {
										newTelDigits = 1;
										printf("Please enter only digits!\n");
										break;
									}
								}
							}
							else if (strlen(newTel) == 10) {
								for (m = 0; m < 10; m++) {
									if (!isdigit(newTel[m])) {
										newTelDigits = 1;
										printf("Please enter only digits!\n");
										break;
									}
								}
							}
						}

						checkExistStaffTel(newTel, &mtt);

						if (mtt == 1) {
							printf("Telephone num already exist.\n");
							mcheck = 1;
						}

					} while (strlen(newTel) != 11 && strlen(newTel) != 10 || newTelDigits == 1 || mcheck == 1);
					strcpy(stf.telNum, newTel);

					fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
				}

				else if (choice == 5) {
					printf("\nThe current password no is %s", stf.psw);
					printf("\nNew password no is :");
					rewind(stdin);
					scanf("%s", stf.psw);
					fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
				}

				else if (choice == 6) {
					system("pause");
					system("cls");
					fclose(st);
					fclose(md);
					staffMenu();
				}

				else {
					printf("\nError!Please enter 1 to 6 only.\n");
					system("pause");
					system("cls");
				}
			}
			else
				fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
		}
	} while (choice > 6 || choice < 1);

	do {
		rewind(stdin);
		printf("\nDo you sure that you want to modify the information?\n");
		printf("1.Comfirm to modify.\n");
		printf("2.No change and go back staff menu.\n");
		printf("\nEnter your choice:");
		scanf("%d", &chmoin);
		if (chmoin == 1) {
			printf("\n\nModify staff information successful.\n\n");
			fclose(st);
			fclose(md);
			remove("staff.txt");
			rename("modify.txt", "staff.txt");

			do {
				rewind(stdin);
				printf("Are you want to modify other information? (Y/N) :");
				scanf("%c", &yesno);

				yesOrNo(yesno, &ch);

				if (ch == 1) {
					fclose(st);
					fclose(md);
					system("cls");
					modifyStaffInfo(mdid);
				}
				else if (ch == 2) {
					system("cls");
					fclose(st);
					fclose(md);
					staffMenu();
				}
				else if (ch == 3) {
					printf("\nError! Please enter 'Y' or 'N' only!\n\n");
				}
			} while (ch == 3);
		}
		else if (chmoin == 2) {
			system("cls");
			fclose(st);
			fclose(md);
			remove("modify.txt");
			staffMenu();
		}
		else {
			printf("\nError!!Please enter 1 or 2 only.\n\n");
		}
	} while (chmoin != 1 || chmoin != 2);
}

void removeStaff() {

	int removeId, ch, found;//ch is for file pointer 
	char yesno; //yesno for ask user choice yes or no and store to pointer
	struct staff stf;
	FILE* st;
	FILE* md;
	st = fopen("staff.txt", "r+");
	md = fopen("modify.txt", "w");
	if (st == NULL || md == NULL) {
		printf("Can't open file.");
		exit(-1);
	}
	printf("What staff you want to delete?\n");

	rewind(stdin);
	printf("Please enter the staff ID you want to delete(0 to exit):");
	scanf("%d", &removeId);

	if (removeId == 0) {
		fclose(st);
		fclose(md);
		system("cls");
		staffMenu();
	}

	found = 0;
	while (fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw) != EOF) {
		if (removeId == stf.staffBase.id) {
			found = 1;
			printf("\nStaff ID %d information is", stf.staffBase.id);
			printf("\nStaff Name: %s", stf.staffBase.name);
			printf("\nStaff Gender: %s", stf.gender);
			printf("\nStaff IC no: %s", stf.IC);
			printf("\nStaff telephone no: %s\n", stf.telNum);
		}
		else {
			fprintf(md, "%d %s= %s %s %s %s\n", stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw);
		}
	}
	if (!found) {
		printf("No staff founded.\n");
		system("pause");
		system("cls");
		fclose(st);
		fclose(md);
		removeStaff();
	}

	do {
		rewind(stdin);
		printf("\nAre you sure want to delete this staff?(Y/N):");
		scanf("%c", &yesno);

		yesOrNo(yesno, &ch);

		if (ch == 1) {
			printf("Staff delete successful.\n");
		}
		else if (ch == 2) {
			printf("Staff have no delete.\n");
			system("pause");
			system("cls");
			fclose(st);
			fclose(md);
			remove("modify.txt");
			removeStaff();
		}
		else if (ch == 3) {
			printf("\nError! Please enter 'Y' or 'N' only!\n");
		}
	} while (ch == 3);


	fclose(st);
	fclose(md);
	remove("staff.txt");
	rename("modify.txt", "staff.txt");
	system("pause");
	system("cls");
	removeStaff();
}

void yesOrNo(char yesno, int* c) {

	if (yesno == 'Y' || yesno == 'y') {
		*c = 1;
	}
	else if (yesno == 'N' || yesno == 'n') {
		*c = 2;
	}
	else {
		*c = 3;
	}
}

void checkExistStaffIc(char addIc[13], int* ii) {
	struct staff stf;
	FILE* st;
	st = fopen("staff.txt", "r");
	if (st == NULL) {
		printf("Can't open file.\n");
		exit(-1);
	}

	while (fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw) != EOF) {
		if (strcmp(addIc, stf.IC) == 0) {
			*ii = 1;
			break;
		}
		else if (strcmp(addIc, stf.IC) != 0) {
			*ii = 0;
		}
	}
	fclose(st);
}

void checkExistStaffTel(char addTel[13], int* tt) {
	struct staff stf;
	FILE* st;
	st = fopen("staff.txt", "r");
	if (st == NULL) {
		printf("Can't open file.\n");
		exit(-1);
	}

	while (fscanf(st, "%d %[^\=]= %s %s %s %s\n", &stf.staffBase.id, stf.staffBase.name, stf.gender, stf.IC, stf.telNum, stf.psw) != EOF) {
		if (strcmp(addTel, stf.telNum) == 0) {
			*tt = 1;
			break;
		}
		else if (strcmp(addTel, stf.telNum) != 0) {
			*tt = 0;
		}
	}
	fclose(st);
}

int checStaffName(char addName[51]) {
	int i;

	for (i = 0; addName[i]; i++) {
		if (!isalpha(addName[i]) && addName[i] != ' ') {
			return 1;
		}
	}
	return 0;
}

void mainStock() {

	int choice;
	printf("=========================\n");
	printf("Welcome to Stock System !\n");
	printf("=========================\n");
	printf("1.Restock Page\n");
	printf("2.Stock Refund Page\n");
	printf("3.Stock Modify Page\n");
	printf("4.Stock View Page\n");
	printf("5.Stock Search Page\n");
	printf("6.Stock Report Page\n");
	printf("7.Exit To The Main Menu\n\n");
	printf("Pls select the function (1-7) :");
	scanf("%d", &choice);

	if (choice > 7 || choice < 1) {
		printf("Error !!! Pls Enter (1-7) \n");
		system("pause");
	}


	while (choice >= 8 || choice <= 0) {
		rewind(stdin);
		system("cls");
		printf("==========================\n");
		printf("Pls Enter the number (1-7) \n");
		printf("==========================\n");
		printf("1.Restock Page\n");
		printf("2.Stock Refund Page\n");
		printf("3.Stock Modify Page\n");
		printf("4.Stock View Page\n");
		printf("5.Stock Search Page\n");
		printf("6.Stock Report Page\n");
		printf("7.Exit The Program\n\n");
		printf("Pls select the function (1-7) :");
		scanf("%d", &choice);

		if (choice > 7 || choice < 1) {
			printf("Error !!! Pls Enter (1-7) \n");
			system("pause");
		}
	}


	switch (choice) {

	case 1:
		restock(); break;
	case 2:
		stockRefund(); break;
	case 3:
		stockModify(); break;
	case 4:
		stockView(); break;
	case 5:
		stockSearch(); break;
	case 6:
		stockReport(); break;
	case 7:
		system("cls");
		mainMenu(); break;

	}

}

void restock() {

	struct stock stk;

	char choice;

	FILE* fp;
	fp = fopen("stock.bin", "ab");

	if (fp == NULL) {
		printf("Error !!! The File Cant Open !!! ");
		exit(-1);
	}

	system("cls");
	rewind(stdin);

	printf("==============");
	printf("\nRestock Page\n");
	printf("==============\n\n");

	printf("Pls Enter The Restock Stock Code ( Enter X To Go Back To Stock Menu ) :");
	rewind(stdin);
	scanf("%[^\n]", &stk.sCode);

	if (strcmp(stk.sCode, "x") == 0 || strcmp(stk.sCode, "X") == 0) {
		system("cls");
		fclose(fp);
		mainStock();
	}


	printf("\nPls Enter The Stock Quantity :");
	scanf("%d", &stk.sqty);
	while (stk.sqty < 1 || stk.sqty > 99999999) {
		rewind(stdin);
		printf("\nError!!! Pls Reenter The Quantity Of Stock :");
		scanf("%d", &stk.sqty);
	}

	printf("\nPls Enter The Restock Date :");
	rewind(stdin);
	scanf("%d", &stk.date);

	while (stk.date < 1 || stk.date > 31) {
		rewind(stdin);
		printf("\nPls Reenter The Restock Date (1-31) :");
		scanf("%d", &stk.date);
	}

	printf("\nPls Enter The Restock Month :");
	scanf("%d", &stk.month);

	while (stk.month < 1 || stk.month > 12) {
		rewind(stdin);
		printf("\nPls Reenter The Restock Month (1-12) :");
		scanf("%d", &stk.month);
	}

	fwrite(&stk, sizeof(stk), 1, fp);
	fclose(fp);

	char ch;

	printf("\nEnter X To Continue Restock, Y To Back To Menu, Z to Exit The Program : ");
	rewind(stdin);
	scanf("%c", &choice);

	selectChoice(choice, &ch);

	if (ch == 1) {
		restock();
	}
	if (ch == 2) {
		system("cls");
		fwrite(&stk, sizeof(stk), 1, fp);
		fclose(fp);
		mainStock();
	}
	if (ch == 3) {
		exit(-1);
	}
	if (ch == 4) {
		printf("\nError\n");
		system("pause");
		system("cls");
		mainStock();
	}
	
}

void selectChoice(char choice, int *u) {

	struct stock stk;

	if (choice == 'x' || choice == 'X') {
		*u = 1;
	}
	else if (choice == 'y' || choice == 'Y') {
		*u = 2;
	}
	else if (choice == 'z' || choice == 'Z') {
		*u = 3;
	}
	else {
		*u = 4;
	}
}

void stockRefund() {

	struct stock stk;
	char rcode[6];
	int qty = 0, rdate, rmonth;
	int found = 0;
	char choice, select;

	FILE* fp;
	FILE* fb;
	fp = fopen("stock.bin", "rb");
	fb = fopen("nstock.bin", "wb");

	if (fp == NULL || fb == NULL) {
		printf("Error !!! The File Cant Open !!! ");
		exit(-1);
	}

	system("cls");
	remove("nstock.bin");
	printf("=================");
	printf("\nStock Refund Page\n");
	printf("=================\n\n");

		rewind(stdin);
		printf("Enter stock code to delete ( Enter x to go back to menu ): ");
		rewind(stdin);
		scanf("%s", rcode);

		if (strcmp(rcode, "x") == 0 || strcmp(rcode, "X") == 0) {
			system("cls");
			fclose(fp);
			fclose(fb);
			mainStock();
		}

		printf("\nEnter the restock date : ");
		scanf("%d", &rdate);
		while (rdate < 1 || rdate > 31) {
			rewind(stdin);
			printf("\nPlease enter a valid restock date (1-31) : ");
			scanf("%d", &rdate);
		}

		printf("\nEnter the restock month : ");
		scanf("%d", &rmonth);
		while (rmonth < 1 || rmonth > 12) {
			rewind(stdin);
			printf("\nPlease enter a valid restock month (1-12) : ");
			scanf("%d", &rmonth);
		}

		found = 0;

		rewind(fp);


		while (fread(&stk, sizeof(stk), 1, fp) == 1) {

			if (strcmp(rcode, stk.sCode) == 0 && rdate == stk.date && rmonth == stk.month) {

				found = 1;


				printf("\nStock details:\n");
				printf("Stock Code: %s\n", stk.sCode);
				printf("Stock Quantity: %d\n", stk.sqty);
				printf("Restock Day: %d\n", stk.date);
				printf("Restock Month: %d\n\n", stk.month);

				printf("\nAre you sure you want to delete this stock? (Y/N): ");
				rewind(stdin);
				scanf("%c", &choice);

				system("cls");
				if (choice == 'N' || choice == 'n') {
					remove("nstock.bin");
					rewind(fp);
					rewind(fb);
					stockRefund();
				}


			}
			else
				fwrite(&stk, sizeof(stk), 1, fb);
		}


	

		if (!found) {
			printf("Error Stock Not Found\n\n");
			remove("nstock.bin");
			memset(rcode, '\0', sizeof(rcode));
			fclose(fp);
			fclose(fb);
			system("pause");
			stockRefund();
		}

		if (choice == 'y' || choice == 'Y') {
			printf("Stock Delete Succesful\n\n");
			fclose(fp);
			fclose(fb);
			remove("stock.bin");
			rename("nstock.bin", "stock.bin");

			printf("\nEnter X To Delete Other Stock, Enter B to Back to Menu : ");
			rewind(stdin);
			scanf("%c", &select);

			if (select == 'x' || select == 'X') {
				stockRefund();
			}
			else if (select == 'b' || select == 'B') {
				fclose(fp);
				fclose(fb);
				system("cls");
				system("pause");
				mainStock();
			}
			else {
				fclose(fp);
				fclose(fb);
				printf("\nError\n");
				system("pause");
				system("cls");
				mainStock();
			}
		}


	fclose(fp);
	fclose(fb);
	system("pause");
}

void stockModify() {
	struct stock stk;
	char hcode[6];
	int found = 0, mdate = 0, mmonth = 0, num = 1;
	char choice;

	FILE* fp;
	FILE* fb;
	fp = fopen("stock.bin", "rb");
	fb = fopen("nstock.bin", "wb");

	if (fp == NULL || fb == NULL) {
		printf("Error !!! The File Cant Open !!! ");
		exit(-1);
	}

	system("cls");
	remove("nstock.bin");
	printf("=================");
	printf("\nStock Modify Page\n");
	printf("=================\n\n");
	printf("Enter stock code need to modify (Enter X To Go Back Menu) : ");
	rewind(stdin);
	scanf("%[^\n]", hcode);

	if (strcmp(hcode, "x") == 0 || strcmp(hcode, "X") == 0) {
		system("cls");
		fclose(fp);
		fclose(fb);
		mainStock();
	}

	printf("\nEnter the restock date : ");
	scanf("%d", &mdate);
	while (mdate < 1 || mdate > 31) {
		rewind(stdin);
		printf("\nPlease enter a valid restock date (1-31) : ");
		scanf("%d", &mdate);
	}

	printf("\nEnter the restock month : ");
	scanf("%d", &mmonth);
	while (mmonth < 1 || mmonth > 12) {
		rewind(stdin);
		printf("\nPlease enter a valid restock month (1-12) : ");
		scanf("%d", &mmonth);
	}

	rewind(fp);

	while (fread(&stk, sizeof(stk), 1, fp) == 1) {
		rewind(stdin);
		if (strcmp(hcode, stk.sCode) == 0 && mdate == stk.date && mmonth == stk.month) {
			found = 1;


				printf("\nCurrent stock details:\n");
				printf("Stock Code: %s\n", stk.sCode);
				printf("Stock Quantity: %d\n", stk.sqty);
				printf("Restock Day: %d\n", stk.date);
				printf("Restock Month: %d\n\n", stk.month);

				printf("Enter new stock code: ");
				rewind(stdin);
				scanf("%[^\n]", stk.sCode);
				printf("Enter new stock quantity: ");
				scanf("%d", &stk.sqty);
				printf("Enter new restock day: ");
				scanf("%d", &stk.date);
				printf("Enter new restock month: ");
				scanf("%d", &stk.month);

				fwrite(&stk, sizeof(stk), 1, fb);
		}
		else {
			fwrite(&stk, sizeof(stk), 1, fb);
		}
	}

	if (!found) {
		printf("Error: Stock not found.\n");
		system("pause");
		system("cls");
		fclose(fp);
		fclose(fb);
		stockModify();
	}

	printf("\nDo you confirm you want to modify the data? (Y/N): ");
	rewind(stdin);
	scanf(" %c", &choice);

	if (choice == 'Y' || choice == 'y') {
		printf("\nStockModify Complete!!!\n");
		system("pause");
		fclose(fp);
		fclose(fb);
		system("cls");
		remove("stock.bin");
		rename("nstock.bin", "stock.bin");
		mainStock();
	}
	else if (choice == 'n' || choice == 'N') {
		printf("\nStock Modify Unsuccessful!!!\n");
		system("pause");
		fclose(fp);
		fclose(fb);
		stockModify();
	}
	else {
		printf("\nError\n");
		fclose(fp);
		fclose(fb);
		system("pause");
		stockModify();
	}
}

void stockView() {

	struct stock stk;

	char choice;

	FILE* fp;
	fp = fopen("stock.bin", "rb");

	if (fp == NULL) {
		printf("Error !!! The File Cant Open !!! ");
		exit(-1);
	}

	system("cls");
	printf("===============");
	printf("\nStock View Page\n");
	printf("===============\n\n");
	printf("\n\nStock Code\tStock Quantity\tRestock Date\tRestock Month\n\n");

	while (fread(&stk, sizeof(stk), 1, fp) == 1) {

		printf("%s\t\t%d\t\t%d\t\t%d\n", stk.sCode, stk.sqty, stk.date, stk.month);

	}

	fclose(fp);

	printf("\n\nEnter X Go back To The Stock Menu : ");
	rewind(stdin);
	scanf("%c", &choice);

	if (choice == 'x' || choice == 'X') {
		system("cls");
		fclose(fp);
		mainStock();
	}
	else {
		printf("\n\nError, Go Back Stock Menu Now");
		system("pause");
		system("cls");
		fclose(fp);
		mainStock();
	}
}

void stockSearch() {

	struct stock stk;

	FILE* fp;
	fp = fopen("stock.bin", "rb");

	if (fp == NULL) {
		printf("Error !!! The File Cant Open !!! ");
		exit(-1);
	}

	char search[6];
	char yon;
	int found = 0;

	fread(&stk, sizeof(stk), 1, fp);

	do {
		system("cls");
		printf("=================");
		printf("\nStock Search Page\n");
		printf("=================\n\n");
		int found = 0;

		printf("Pls Enter The Stock Code You Want To Search (Enter X To Go Back To Stock Menu) : ");
		rewind(stdin);
		scanf("%[^\n]", &search);
		if (strcmp(search, "x") == 0 || strcmp(search, "X") == 0) {
			system("cls");
			fclose(fp);
			mainStock();
		}


		printf("\n\nStock Code\tStock Quantity\tRestock Date\tRestock Month\n\n");

		rewind(fp);

		while (fread(&stk, sizeof(stk), 1, fp) == 1) {

			if (strcmp(stk.sCode, search) == 0) {

				printf("%s\t\t%d\t\t%d\t\t%d\n", stk.sCode, stk.sqty, stk.date, stk.month);
				found = 1;

			}

		}

		if (!found) {

			printf("Error No Have Any Data Of Your Choice In File\n");

		}

		printf("\n");

		printf("Need To Find Another Stock? (Press 'x' To Find Another Stock Press Another Key To Go Back Stock Menu) : ");
		rewind(stdin);
		scanf("%c", &yon);

		while (getchar() != '\n'); //clear input buffer

	} while (yon == 'x' || yon == 'X');

	fclose(fp);

	if (yon != 'x' && yon != 'X') {

		system("pause");
		system("cls");
		fclose(fp);
		mainStock();

	}
}

void stockReport() {

	struct total ttl[100] = {{"", 0}};
	struct stock stk;

	int i;
	char choice;

	FILE* fp;
	FILE* ft;

	fp = fopen("stock.bin", "rb");
	ft = fopen("sum.bin", "wb");

	if (fp == NULL || ft == NULL) {
		printf("Error !!! The File Cant Open !!! ");
		exit(-1);
	}

	while (fread(&stk, sizeof(stk), 1, fp) != 0) {
		for (i = 0; i < 100; i++) {
			if (strcmp(stk.sCode, ttl[i].tCode) == 0) {
				ttl[i].tqty += stk.sqty;
				break;
			}
			else if (strcmp(ttl[i].tCode, "") == 0) {
				strcpy(ttl[i].tCode, stk.sCode);
				ttl[i].tqty = stk.sqty;
				break;
			}
		}
		if (i >= 100) {
			printf("Error: Maximum number of stocks exceeded\n");
			exit(-1);
		}
	}

	if (ft != NULL) {
		fwrite(ttl, sizeof(ttl[0]), 100, ft);
		fclose(ft);
	}

	system("cls");
	printf("=================");
	printf("\nStock Report Page\n");
	printf("=================\n\n");

	printf("\nStock Code\t\tTotal Quantity\n");
	printf("-----------------------------------\n");

	for (i = 0; i < 10000 && strcmp(ttl[i].tCode, "") != 0; i++) {
		printf("%s\t\t\t%d\n", ttl[i].tCode, ttl[i].tqty);
	}

	fclose(fp);
	fclose(ft);

	printf("\n\nEnter X To Go Back Menu : ");
	rewind(stdin);
	scanf("%c", &choice);

	if (choice == 'x' || choice == 'X') {

		system("pause");
		system("cls");
		fclose(fp);
		mainStock();

	}
	else {
		printf("\nError\n");
		system("pause");
		system("cls");
		fclose(fp);
		mainStock();
	}
}

void salesmain() {
	system("cls");
	int selection;
	printf("please select a function\n 1.Add new record\n 2.Search a record\n 3.Modify a record\n 4.Display all record\n 5.Summary Report\n 6.Delete a record\n 7.Exit to menu\nSelection:");
	do {
		rewind(stdin);
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			system("cls");
			salesAdd();
			break;
		case 2:
			system("cls");
			salesSearch();
			break;
		case 3:
			system("cls");
			salesModify();
			break;
		case 4:
			system("cls");
			salesDisplay();
			break;
		case 5:
			system("cls");
			salesReport();
			break;
		case 6:
			system("cls");
			salesDelete();
			break;
		case 7:
			system("cls");
			mainMenu();
			break;
		default:
			printf("error value pls enter again");
			//return salesmain();
		}
	} while (selection<1 || selection>7);

}

void salesAdd() {
	Salesinfo add;
	char lapsap;

	FILE* fp1;
	fp1 = fopen("addsales.txt", "a");
	if (fp1 == NULL) {
		printf("error");
		exit(-1);
	}

	do {
		system("cls");
		printf("Enter sales orderid:\n ");
		rewind(stdin);
		while (scanf("%[^\n]", add.salesOrderId) != 1 || isalpha(add.salesOrderId[0]) != 0 || strlen(add.salesOrderId) != 3) {
			printf("please enter a valid value(Example:101)\n");
			rewind(stdin);
		}



		printf("Enter itemCode:\n");
		rewind(stdin);
		while (scanf("%[^\n]", add.itemCode) != 1 || isalpha(add.itemCode[0]) != 0 || strlen(add.itemCode) != 3) {
			printf("please enter a valid value(Example:201)\n");
			rewind(stdin);
		}

		printf("Enter voucherID(0000 = no voucher):\n");
		rewind(stdin);
		while (scanf("%[^\n]", add.vouId) != 1 || isalpha(add.vouId[0]) != 0 || strlen(add.vouId) != 4) {
			printf("please enter a valid value(Example:1001)\n");
			rewind(stdin);
		}

		printf("Enter qtyOrdered:\n");
		rewind(stdin);
		while (scanf("%d", &add.qtyOrdered) != 1 || add.qtyOrdered > 999 || add.qtyOrdered < 1) {
			printf("Enter a corect numeric value");
			rewind(stdin);
		}

		printf("Enter item price:\n");
		rewind(stdin);
		while (scanf("%lf", &add.price) != 1 || add.price > 999 || add.price < 1 ) {
			printf("Enter a corect numeric value");
			rewind(stdin);
		}

		printf("Enter Time(eg.1000):\n");
		rewind(stdin);
		while (scanf("%[^\n]", add.time) != 1 || isalpha(add.time[0]) != 0 || strlen(add.time) != 4) {
			printf("Enter a corect value(00-23)\n");
			rewind(stdin);
		}


		printf("Enter Date(day):");
		rewind(stdin);
		while (scanf("%d", &add.date.d) != 1 || add.date.d < 1 || add.date.d >30) {
			printf("Enter a corect value(1-30)");
			rewind(stdin);
		}

		printf("Enter Date(month):");
		rewind(stdin);
		while (scanf("%d", &add.date.m) != 1 || add.date.m < 1 || add.date.m >12) {
			printf("Enter a corect value(1-12)");
			rewind(stdin);
		}

		printf("Enter Date(year):");
		rewind(stdin);
		while (scanf("%d", &add.date.y) != 1 || add.date.y < 2000 || add.date.y >2050) {
			printf("Enter a corect value(2000-2050)");
			rewind(stdin);
		}

		fprintf(fp1, "a%s s%s d%s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);

		printf("press x to return menu\n");
		rewind(stdin);
		scanf("%c", &lapsap);
	} while (lapsap != 'x' && lapsap != 'X');

	fclose(fp1);
	system("pause");
	system("cls");
	salesmain();
}

void salesSearch() {
	Salesinfo add;
	char search[6];
	int found = 0;
	FILE* fp1;
	fp1 = fopen("addsales.txt", "r");
	if (fp1 == NULL) {
		printf("error");
		exit(-1);
	}
	printf("Enter a salesOrderId to search for record:");
	rewind(stdin);
	scanf("%[^\n]", &search);
	/*printf("OrderId Itemcode VoucherId  quantity    price   Time     Date \n");*/

	while (fscanf(fp1, "%s %s %s %d %lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, &add.qtyOrdered, &add.price, add.time, &add.date.d, &add.date.m, &add.date.y) != EOF) {

		if (strcmp(add.salesOrderId, search) == 0) {
			printf("\n\nOrderId Itemcode VoucherId  quantity    price   Time     Date \n");
			printf("%s \t%s   \t%s   \t%d \t%.2lf \t%s \t%2.d-%2.d-%2.d \n\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);

			
			found = 1;
		}
	}
	if (!found) {
		printf("norecord found\n\n");
	}
	system("pause");
	system("cls");
	salesmain();
	fclose(fp1);
}

void salesModify() {
	int selectmod, salesfound = 0, valid;
	int i;
	char search[6];
	char next, confirm;
	FILE* fp1;
	FILE* fp2;
	Salesinfo add;
	do {
		system("cls");
		fp1 = fopen("addsales.txt", "r");
		if (fp1 == NULL) {
			printf("error addsales.txt");
			exit(-1);
		}
		fp2 = fopen("edit.txt", "w");
		if (fp2 == NULL) {
			printf("error edit.txt");
			exit(-1);
		}
		printf("Enter the salesID:");
		rewind(stdin);
		scanf("%[^\n]", &search);
		printf("\n");
		while (fscanf(fp1, "%s %s %s %d %lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, &add.qtyOrdered, &add.price, add.time, &add.date.d, &add.date.m, &add.date.y) != EOF) {

			if (strcmp(add.salesOrderId, search) == 0) {
				printf("OrderId Itemcode VoucherId  quantity    price   Time     Date \n");
				printf("%s \t%s   \t%s   \t%d \t%.2lf \t%s \t%2.d-%2.d-%2.d \n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);


				salesfound = 1;

				do {
					printf("select the data to modify\n1.item code\n2.quantity ordered\n3.VoucherID\n4.Price\n5.Time\n6.Date\n7.Back to menu\nSelection:");
					scanf("%d", &selectmod);
					switch (selectmod) {
					case 1:
						printf("Enter a new value\n");
						rewind(stdin);

						while (scanf("%[^\n]", add.itemCode) != 1 || isalpha(add.itemCode[0]) != 0 || strlen(add.itemCode) != 3) {
							printf("please enter a valid value(Example:s101)\n");
							rewind(stdin);
						}
						fprintf(fp2, "%s s%s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
						printf("\nSales information updated.\n");
						break;

					case 2:
						printf("Enter new voucherID(0000 = no voucher):\n");
						rewind(stdin);
						while (scanf("%[^\n]", add.vouId) != 1 || isalpha(add.vouId[0]) != 0 || strlen(add.vouId) != 4) {
							printf("please enter a valid value(Example:1001)\n");
							rewind(stdin);
						}
						fprintf(fp2, "%s %s d%s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
						printf("Sales infomation updated\n");
						break;

					case 3:
						printf("Enter a new value\n");
						rewind(stdin);
				

						while (scanf("%d", &add.qtyOrdered) != 1 || add.qtyOrdered > 999 || add.qtyOrdered < 1) {
							printf("Enter a corect numeric value");
							rewind(stdin);
							
						}

						fprintf(fp2, "%s %s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
						printf("\nSales information updated.\n");
						break;

					case 4:
						printf("Enter a new value\n");
						rewind(stdin);

						while (scanf("%lf", &add.price) != 1 || add.price > 999 || add.price < 1) {
							printf("Enter a corect numeric value");
							rewind(stdin);
						}

						fprintf(fp2, "%s %s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
						printf("\nSales information updated.\n");
						break;

					case 5:
						printf("Enter Time(hour):\n");
						rewind(stdin);
						while (scanf("%[^\n]", add.time) != 1 || isalpha(add.time[0]) != 0 || strlen(add.time) != 4) {
							printf("Enter a corect value(00-23)\n");
							rewind(stdin);
						}
						fprintf(fp2, "%s %s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
						printf("\nSales information updated.\n");
						break;

					case 6:
						printf("Enter Date(day):");
						rewind(stdin);
						while (scanf("%d", &add.date.d) != 1 || add.date.d < 1 || add.date.d >30) {
							printf("Enter a corect value(1-30)");
							rewind(stdin);
						}

						printf("Enter Date(month):");
						rewind(stdin);
						while (scanf("%d", &add.date.m) != 1 || add.date.m < 1 || add.date.m >12) {
							printf("Enter a corect value(1-12)");
							rewind(stdin);
						}

						printf("Enter Date(year):");
						rewind(stdin);
						while (scanf("%d", &add.date.y) != 1 || add.date.y < 2000 || add.date.y >2050) {
							printf("Enter a corect value(2000-2050)");
							rewind(stdin);
						}

						fprintf(fp2, "%s %s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
						printf("\nSales information updated.\n");
						break;
					case 7:
						system("cls");
						salesmain();
						break;
					default:
						printf("Select a valid change");
						break;
					}
				} while (selectmod < 1 || selectmod>6);

			}
			else {
				fprintf(fp2, "%s %s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
			}

		}
		if (!salesfound) {
			printf("no record found\n");
		}

		fclose(fp1);
		fclose(fp2);

		remove("addsales.txt");
		rename("edit.txt", "addsales.txt");


		printf("Continue modify other record?(Press y to continue modify)");
		rewind(stdin);
		scanf("%c", &confirm);

	} while (confirm == 'y' || confirm == 'Y');
	system("pause");
	system("cls");
	salesmain();
}

void salesDisplay() {
	Salesinfo add;
	FILE* fp1;

	fp1 = fopen("addsales.txt", "r");
	if (fp1 == NULL) {
		printf("error addsales.txt");
		exit(-1);
	}

	printf("OrderId Itemcode VoucherId  quantity    price   Time     Date \n");
	while (fscanf(fp1, "%s %s %s %d %lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, &add.qtyOrdered, &add.price, add.time, &add.date.d, &add.date.m, &add.date.y) != EOF) {
		printf("%s \t%s   \t%s   \t%d \t%.2lf \t%s \t%2.d-%2.d-%2.d \n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);

	}
	printf("==================================================================\n\nPress enter to return sales menu\n");
	system("pause");
	system("cls");
	salesmain();
}

void salesReport() {
	Salesinfo add;
	FILE* fp1;
	double salessubttl, salesttlprice, subttl;

	fp1 = fopen("addsales.txt", "r");
	if (fp1 == NULL) {
		printf("error addsales.txt");
		exit(-1);
	}

	printf("OrderId Itemcode VoucherId  quantity    price   Time     Date \t\tsubtotal\n");
	while (fscanf(fp1, "%s %s %s %d %lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, &add.qtyOrdered, &add.price, add.time, &add.date.d, &add.date.m, &add.date.y) != EOF) {

		calsales(add.qtyOrdered, add.price, &salessubttl, &salesttlprice);
		printf("%s \t%s   \t%s   \t%d \t%.2lf \t%s \t%2.d-%2.d-%2.d \t%.2lf\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y, salessubttl);
	}
	printf("================================================================================\n");
	printf("Total\t\t\t\t\t\t\t\t\t%.2lf", salesttlprice);
	printf("\nPress any key to return sales menu");
	system("pause");
	system("cls");
	salesmain();
}

void calsales(int salesqty, double salesprice, double* salessubttl, double* salesttlprice) {
	*salessubttl = salesqty * salesprice;
	static double subttl;
	subttl += *salessubttl;
	*salesttlprice = subttl;
}

void salesDelete() {
	int selectmod, salesfound = 0;
	char search[6], confirm;
	FILE* fp1;
	FILE* fp2;
	Salesinfo add;
	do {
		system("cls");
		fp1 = fopen("addsales.txt", "r");
		if (fp1 == NULL) {
			printf("error addsales.txt");
			exit(-1);
		}
		fp2 = fopen("edit.txt", "w");
		if (fp2 == NULL) {
			printf("error edit.txt");
			exit(-1);
		}

		printf("Enter the salesID\n");
		rewind(stdin);
		scanf("%[^\n]", &search);
		salesfound = 0;


		while (fscanf(fp1, "%s %s %s %d %lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, &add.qtyOrdered, &add.price, add.time, &add.date.d, &add.date.m, &add.date.y) != EOF) {

			if (strcmp(add.salesOrderId, search) == 0) {
				printf("OrderId Itemcode VoucherId  quantity    price   Time     Date \n");
				printf("%s \t%s   \t%s   \t%d \t%.2lf \t%s \t%2.d-%2.d-%2.d \n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);

				salesfound = 1;
			}
			else {
				fprintf(fp2, "%s %s %s %d %.2lf %s %d %d %d\n", add.salesOrderId, add.itemCode, add.vouId, add.qtyOrdered, add.price, add.time, add.date.d, add.date.m, add.date.y);
			}

		}


		if (!salesfound) {
			printf("no record found\n");
			system("pause");
			fclose(fp1);
			fclose(fp2);
			remove("addsales.txt");
			rename("edit.txt", "addsales.txt");
			return salesmain();
		}


		printf("Confirm to delete?(Press y to confirm)");
		rewind(stdin);
		scanf("%c", &confirm);

	} while (confirm != 'y' && confirm != 'Y');

	fclose(fp1);
	fclose(fp2);

	remove("addsales.txt");
	rename("edit.txt", "addsales.txt");

	system("pause");
	system("cls");
	salesmain();
}

void memMenu()
{
	member mem;
	int choice;
	printf("#>Welcome to our Member Section<#\n");
	printf("\n\n");
	printf("Member Menu\n");
	printf("1.Log In Existing Member Account\n");
	printf("2.Register For Member\n");
	printf("3.Delete A Member Account\n");
	printf("4.Modify A Member Account\n");
	printf("5.Member List\n");
	printf("6.Exit\n");
	do {
		rewind(stdin);
		printf("\nPlease Enter Your Select : ");
		if (scanf("%d", &choice) == 1) {
			if (choice > 0) {
				if (choice == 1) {
					system("cls");
					memStat();
				}
				else if (choice == 2) {
					system("cls");
					memReg();
				}
				else if (choice == 3) {
					system("cls");
					deleteMem();
				}
				else if (choice == 4) {
					system("cls");
					modifyMem();
				}
				else if (choice == 5) {
					system("cls");
					memberList();
				}
				else if (choice == 6) {
					printf("Thanks For Using This Function\n");
					system("cls");
					main();
				}
				else {
					printf("Invalid Number, Please Enter Again\n");
				}
			}
			else {
				printf("Invalid Number, Please Enter Again\n");
			}
		}
		else {
			printf("Invalid Input, Please Enter a Number\n");
			rewind(stdin);
		}

	} while (choice >= 7 || choice <= 0);

}

void memReg()
{
	char newIc[13], newName[31];
	srand(time(NULL));
	int random_number = (rand() % 9999) + 1000;
	char conT;
	int selection, icCheck;
	member mem;
	FILE* fpm;
	fpm = fopen("members.bin", "ab+");


	if (fpm == NULL) {
		printf("Error: Failed to open members file.\n");
		exit(EXIT_FAILURE);
	}

	printf("[Register Section]\n");
	printf(">Please enter your IC number (Only 12 digits without -)   : ");
	while (scanf("%s", newIc) != 1 || strlen(newIc) != 12) // Read input into newIc and validate length
	{
		printf("\nPlease enter exactly 12 digits without dashes!\n");
		printf("Enter IC number     : ");
	}
	rewind(fpm); // Rewind the binary file

	icCheck = 0; // Initialize icCheck to 0

	while (fread(&mem, sizeof(mem), 1, fpm) == 1) // Read binary data from file into mem
	{
		if (strcmp(mem.memIC, newIc, sizeof(mem.memIC)) == 0) // Compare mem.memIC with newIc
		{
			icCheck = 1;
			printf("\nMember already exists. Please Try Again.\n\n");
			system("pause");
			system("cls");
			memReg();
		}
	}

	if (icCheck == 0) // If no match found, copy newIc to mem.memIC
	{
		strcpy(mem.memIC, newIc);
	}
	rewind(stdin);
	printf("\n>Please Enter Your Name: ");
	scanf("%[^\n]", newName);
	strcpy(mem.name, newName);

	do {
		rewind(stdin);
		printf(">Please Enter Your Gender:\n");
		printf("|M = Male       |\n|F = Female     |\n");
		scanf(" %c", &mem.gender);

		mem.gender = toupper(mem.gender);
		if (mem.gender != 'M' && mem.gender != 'F')
		{
			printf("Error: Invalid input. Please enter M or F.\n");
		}
	} while (mem.gender != 'M' && mem.gender != 'F');

	printf("\n>Enter Your Contact Number (without -): ");
	int contactNum;
	char contNum[20]; // assuming the maximum length of input for contact number is 20 characters
	while (1) {
		// Read input as string
		scanf("%s", contNum);
		int len = strlen(contNum);
		int valid = 1;
		// Validate input to ensure it contains only digits (0-9)
		for (int i = 0; i < len; i++) {
			if (!isdigit(contNum[i])) {
				valid = 0;
				break;
			}
		}
		if (valid && (len == 11 || len == 10)) { // Input is valid if it contains only digits and has exactly 10 characters
			contactNum = atoi(contNum); // Convert input string to integer
			break; // Exit loop if input is valid
		}
		else {
			printf("Invalid input. Please enter 10 to 11-digit contact number without dashes: ");
			fflush(stdin); // Clear input buffer before next iteration
		}
	}
	mem.contactNum = contactNum;
	rewind(stdin);
	printf("\n>Enter Your Age (minimum age is 18): ");
	do {
		if (scanf("%d", &mem.age) != 1) {
			printf("\nError: Invalid input. Please enter a valid age.\n");
			fflush(stdin);
			continue;
		}
		if (mem.age >= 18 && mem.age <= 150)
		{
			break;
		}
		else
		{
			printf("\nInvalid To Register. Try Again.\n");
			fflush(stdin);
		}
	} while (mem.age < 18 || mem.age > 150);
	rewind(stdin);
	printf("\n>Enter Your Email Address: ");
	scanf("%[^\n]", mem.memEmail);
	do {
		rewind(stdin);
		printf("\nDo You Wish To Re-enter Your Info? (Y / N) >");
		scanf(" %S", &conT);
		validateMem(conT);
		if (validateMem(conT) == 0)
		{
			system("cls");
			memReg();
		}
		else if (validateMem(conT) == 1)
		{
			srand(time(0));
			mem.inspect.memID = random_number;
			mem.inspect.expDate = 72;
			strcpy(mem.inspect.memStat, "Bronze");
			mem.inspect.memPt = 250;
			printf("\n>>>Registration Complete<<<\n");
			printf("\nYour Member Expired after %d Days\n", mem.inspect.expDate);
			printf("Your Current Member Tier is %s\n", mem.inspect.memStat);
			printf("Your Default Member Points is %d\n", mem.inspect.memPt);
			printf("\nRedirect back to member menu......\n");
			fwrite(&mem, sizeof(mem), 1, fpm);
			fseek(fpm, 0, SEEK_SET);
			fclose(fpm);
			system("pause");
			system("cls");
			memMenu();
		}
		else if (validateMem(conT) == 2)
		{
			printf("Error: Invalid input. Please enter Y or N.\n");
			rewind(stdin);
		}
	} while (validateMem(conT) != 0 && validateMem(conT) != 1);
}

void memStat() {
	char searchIC[13], conT;
	member mem;
	FILE* fpm;

	fpm = fopen("members.bin", "rb");
	if (fpm == NULL) {
		printf("Error: Failed to open members file.\n");
		exit(EXIT_FAILURE);
	}
	fflush(stdin);
	printf("LOG IN FOR DETAIL >>>>\n");
	do {
		rewind(stdin);
		printf("Continue? (Y / N) > ");
		scanf("%c", &conT);
		validateMem(conT);
		if (validateMem(conT) == 0)
		{
			break;
		}
		else if (validateMem(conT) == 1)
		{
			system("cls");
			memMenu();
		}
		else if (validateMem(conT) == 2){
			printf("Invalid Enter, Only (Y / N)\n");
		}
	} while (validateMem(conT) != 0 && validateMem(conT) != 1);
	printf("Enter the IC number to search: ");
	if (scanf("%12s", searchIC) != 1) {
		printf("Error: Failed to read input.\n");
		fclose(fpm);
		memStat();
	}

	int found = 0;
	while (fread(&mem, sizeof(mem), 1, fpm) == 1) {
		if (strcmp(mem.memIC, searchIC) == 0) {
			found = 1;
			printf("============================================\n");
			printf(">Member Details:\n");
			printf(">ID                : MB%d\n", mem.inspect.memID);
			printf(">Name              : %s\n", mem.name);
			printf(">IC Number         : %s\n", mem.memIC);
			printf(">Gender            : %c\n", mem.gender);
			printf(">Age               : %d\n", mem.age);
			printf(">Email             : %s\n", mem.memEmail);
			printf(">Contact Number    : 0%d\n", mem.contactNum);
			printf(">Member Expiry Date: %d days\n", mem.inspect.expDate);
			printf(">Member Status     : %s\n", mem.inspect.memStat);
			printf(">Member Points     : %d\n", mem.inspect.memPt);
			printf("============================================\n");
			int memberC;
			printf("1.Topup Member Point\n");
			printf("2.Delete Member\n");
			printf("3.Member Menu\n");
			printf("Enter your choice: ");
			if (scanf("%d", &memberC) != 1) {
				printf("Error: Invalid input. Please enter a number.\n");
				fclose(fpm);
				memStat();
			}

			if (memberC < 1 || memberC > 3) {
				printf("Error: Invalid menu option. Please choose a valid option.\n");
				fclose(fpm);
				memStat();
			}

			switch (memberC) {
			case 1:
				printf("Topup Member Point selected.\n");
				getchar(); // Pause program, wait for Enter key press
				system("cls");
				topupMem();
				break;
			case 2:
				printf("Delete Member selected.\n");
				getchar(); // Pause program, wait for Enter key press
				system("cls");
				deleteMem();
				break;
			case 3:
				printf("Member Menu selected.\n");
				printf("Redirect back to member menu...\n");
				getchar(); // Pause program, wait for Enter key press
				system("cls");
				memMenu();
				break;
			default:
				printf("Error: Invalid menu option.\n");
				memStat();
			}
		}
	}
	fclose(fpm);

	if (!found) {
		system("cls");
		printf("Error: Member with IC number %s not found.\n", searchIC);
		memStat();
	}
}

void topupMem()
{
	char conT;
	member mem;
	FILE* fpm;

	fpm = fopen("members.bin", "r+b");
	if (fpm == NULL) {
		printf("Error: Failed to open members file.\n");
		exit(EXIT_FAILURE);
	}
	do {
		rewind(stdin);
		printf("Continue? (Y / N) > ");
		scanf("%s", &conT);
		validateMem(conT);
		if (validateMem(conT) == 0)
		{
			break;
		}
		else if (validateMem(conT) == 1)
		{
			system("cls");
			memMenu();
		}
		else if (validateMem(conT) == 2) {
			printf("Invalid Enter, Only (Y / N)\n");
		}
	} while (validateMem(conT) != 0 && validateMem(conT) != 1);
	fread(&mem, sizeof(mem), 1, fpm);
	printf("WELCOME, member %s\n", mem.name);
	printf("[Top-Up Section]\n");
	printf(">Your Member Expired after   = %d\n", mem.inspect.expDate);
	printf(">Your Member Point is        = %d\n", mem.inspect.memPt);
	printf(">Your current Member Tier is = %s\n", mem.inspect.memStat);
	int addPt;
	char wishAdd = '\0';

	printf("\n10 point = 1 day expired && RM 1.00\n");
	printf("How many Points do you wish to top-up? >>> ");
	if (scanf("%d", &addPt) != 1) {
		printf("Invalid input. Please enter a number.>>> ");
		system("pause");
		system("cls");
		topupMem();

	}
	do {
		rewind(stdin);
		printf("Your wish to Topup %d points (Y = YES or N = NO)> ", addPt);
		scanf("%c", &wishAdd);
		wishAdd = toupper(wishAdd);
		if (wishAdd == 'Y')
		{
			double payment;
			int paymentMethod;
			payment = (double)addPt / 10;
			printf("\nTotal PAYMENT IS RM%.2lf\n", payment);
			printf("Payment Method\n");
			printf("1.Debit / Credit Card\n");
			printf("2.Online Banking\n");
			printf("3.E-Wallet\n");
			printf("4.Cash\n");
			printf("5.Back To Member Menu\n");
			do {
				printf("Enter payment method (1-5): ");
				if (scanf("%d", &paymentMethod) != 1) {
					printf("Invalid input. Please enter a number.\n");
					while (getchar() != '\n'); // consume remaining input
				}
				else {
					switch (paymentMethod) {
					case 1:
					case 2:
					case 3:
					case 4:
						mem.inspect.memPt += addPt;
						mem.inspect.expDate += (int)payment;
						printf("Proceesing the transaction.....\n");
						system("pause");
						printf("\nPayment Complete!!! Your new Member Point is %d\n", mem.inspect.memPt);
						if (mem.inspect.memPt >= 500 && mem.inspect.memPt <= 999) {
							strcpy(mem.inspect.memStat, "Silver");
						}
						else if (mem.inspect.memPt >= 1000 && mem.inspect.memPt <= 1999) {
							strcpy(mem.inspect.memStat, "Gold");
						}
						else if (mem.inspect.memPt >= 2000) {
							strcpy(mem.inspect.memStat, "Diamond");
						}
						fseek(fpm, -(long int)sizeof(mem), SEEK_CUR);
						fwrite(&mem, sizeof(mem), 1, fpm);
						fflush(fpm);
						break;
					case 5:
						printf("Redirecting back to main menu...\n");
						system("pause");
						system("cls");
						memMenu();
						break;
					default:
						printf("Invalid input. Please enter a number between 1 and 5.\n");
						break;
					}
				}
			} while (paymentMethod < 1 || paymentMethod > 5);


			printf("Congratulations, You are now a %s Member!!!\n", mem.inspect.memStat);
			printf("Do you wish to view your profile?\n");
			char goDetail;
			fflush(stdin);
			printf("(Y = Yes , N = No) > ");
			do {
				scanf(" %c", &goDetail);
				goDetail = toupper(goDetail);
				if (goDetail == 'Y')
				{
					printf("Redirect to Member Detail\n");
					system("pause");
					system("cls");
					memStat();
				}
				else if (goDetail == 'N')
				{
					printf("Redirect back to Main Menu...\n");
					system("pause");
					system("cls");
					memMenu();
				}
				else
				{
					printf("Invalid Input. Please enter again\n");
					continue;
				}
			} while (goDetail != 'Y' && goDetail != 'N');
		}
		else if (wishAdd == 'N')
		{
			printf("Redirect back to topup menu...\n");
			system("pause");
			system("cls");
			topupMem();
		}
		else
		{
			printf("Invalid Input. Please enter Y or N: \n");
			rewind(stdin);
			continue;
		}

	} while (wishAdd != 'Y' && wishAdd != 'N');

	fclose(fpm);
}

void modifyMem() {
	FILE* fpm;
	FILE* fpTemp;
	member mem;
	char wishModify, searchIC[13];
	char stop;

	fpm = fopen("members.bin", "rb");
	if (fpm == NULL) {
		printf("Error: Failed to open members file.\n");
		exit(EXIT_FAILURE);
	}

	fpTemp = fopen("temp.bin", "wb");
	if (fpTemp == NULL) {
		printf("Error: Failed to create temporary file.\n");
		fclose(fpm);
		exit(EXIT_FAILURE);
	}

	// Loop through the members in the binary file
	printf("Modify Section\n");
	printf("LOG IN FOR MODIFY >>>>\n");
	char conT;
	do {
		rewind(stdin);
		printf("Continue? (Y / N) > ");
		scanf("%s", &conT);
		if (validateMem(conT) == 0)
		{
			break;
		}
		else if (validateMem(conT) == 1)
		{
			system("cls");
			memMenu();
		}
		else if (validateMem(conT) == 2) {
			printf("Invalid Enter, Only (Y / N)\n");
		}
	} while (validateMem(conT) != 0 && validateMem(conT) != 1);

	printf("Enter the IC number to search: ");
	if (scanf("%12s", searchIC) != 1) {
		printf("Error: Failed to read input.\n");
		fclose(fpm);
		system("cls");
		modifyMem();
	}

	int found = 0;
	while (fread(&mem, sizeof(mem), 1, fpm) == 1) {
		if (strcmp(mem.memIC, searchIC) == 0) {

			found = 1;

			printf("============================================\n");
			printf(">Member Details:\n");
			printf(">ID                : MB%d\n", mem.inspect.memID);
			printf(">Name              : %s\n", mem.name);
			printf(">IC Number         : %s\n", mem.memIC);
			printf(">Gender            : %c\n", mem.gender);
			printf(">Age               : %d\n", mem.age);
			printf(">Email             : %s\n", mem.memEmail);
			printf(">Contact Number    : 0%d\n", mem.contactNum);
			printf(">Member Expiry Date: %d days\n", mem.inspect.expDate);
			printf(">Member Status     : %s\n", mem.inspect.memStat);
			printf(">Member Points     : %d\n", mem.inspect.memPt);
			printf("============================================\n");
			printf("Modify Section\n");
			printf("Do you wish to modify this member? (Y = YES or N = NO): ");
			fflush(stdin);
			scanf(" %c", &wishModify);
			wishModify = toupper(wishModify);
			if (wishModify == 'Y') {

				rewind(stdin);
				int choose;
				printf("What Info You Wish To Modify?\n");
				printf("1. IC Number\n");
				printf("2. Name\n");
				printf("3. Gender\n");
				printf("4. Email\n");
				printf("5. Contact Number\n");
				printf("6. Age\n");
				printf("7.Member Status & Point\n");
				printf("8. No Modify and Return Main Menu\n");
				while (1) {
					printf("Enter your choice (1-8): ");
					int input = scanf("%d", &choose);

					// Check for valid input
					if (input == 1) {
						break;
					}
					else {
						printf("Error: Invalid input! Please enter a valid choice.\n");
						fflush(stdin); // Clear input buffer
					}
				}

				switch (choose) {
				case 1:
					printf("Enter new Member IC Number: ");
					scanf("%s", mem.memIC);
					fwrite(&mem, sizeof(mem), 1, fpTemp);
					break;
				case 2:
					printf("Enter new Name: ");
					scanf(" %[^\n]", mem.name);
					fwrite(&mem, sizeof(mem), 1, fpTemp);
					break;
				case 3:
					do {
						rewind(stdin);
						printf("Enter new Gender:\n");
						printf("|M = Male       |\n|F = Female     |\n");
						scanf(" %c", &mem.gender);

						mem.gender = toupper(mem.gender);
						if (mem.gender != 'M' && mem.gender != 'F')
						{
							printf("Error: Invalid input. Please enter M or F.\n");
						}
					} while (mem.gender != 'M' && mem.gender != 'F');
					fwrite(&mem, sizeof(mem), 1, fpTemp);
					break;
				case 4:
					printf("Enter new Email: ");
					scanf(" %s", mem.memEmail);
					fwrite(&mem, sizeof(mem), 1, fpTemp);
					break;
				case 5:
					printf("Enter new Contact Number (without -): ");
					int contactNum;
					char contNum[20]; // assuming the maximum length of input for contact number is 20 characters
					while (1) {
						// Read input as string
						scanf("%s", contNum);
						int len = strlen(contNum);
						int valid = 1;
						// Validate input to ensure it contains only digits (0-9)
						for (int i = 0; i < len; i++) {
							if (!isdigit(contNum[i])) {
								valid = 0;
								break;
							}
						}
						if (valid && len == 10) { // Input is valid if it contains only digits and has exactly 10 characters
							contactNum = atoi(contNum); // Convert input string to integer
							break; // Exit loop if input is valid
						}
						else {
							printf("Invalid input. Please enter a 10-digit contact number without dashes: ");
							fflush(stdin); // Clear input buffer before next iteration
						}
					}
					fwrite(&mem, sizeof(mem), 1, fpTemp);
					break;
				case 6:
					printf("Enter new Age (minimum age is 18): ");
					do {
						if (scanf("%d", &mem.age) != 1) {
							printf("\nError: Invalid input. Please enter a valid age.\n");
							fflush(stdin);
							continue;
						}
						if (mem.age >= 18 && mem.age <= 150)
						{
							break;
						}
						else
						{
							printf("\nInvalid To Rewrite. Try Again.\n");
							fflush(stdin);
						}
					} while (mem.age < 18 || mem.age > 150);
					fwrite(&mem, sizeof(mem), 1, fpTemp);
					break;
				case 7:
					printf("It is topup function\n");
					printf("Directing to Topup.....");
					fclose(fpm);
					fclose(fpTemp);
					system("pause");
					system("cls");
					topupMem();
					break;
				case 8:
					printf("Redirect back to Main Menu.\n");
					break;

				default:
					printf("Error: Invalid choice!\n");
					fclose(fpm);
					fclose(fpTemp);
					system("pause");
					system("cls");
					memMenu();
				}

				printf("Member information has been modified.\n");
				printf("Do you wish to continue modify other data ? (Y = YES or N = NO): ");
				fflush(stdin);
				scanf(" %c", &stop);
				stop = toupper(stop);

				system("cls");
			}
		}
		else {
			fwrite(&mem, sizeof(mem), 1, fpTemp);
		}
	}

	if (stop == 'Y') {
		fclose(fpm);
		fclose(fpTemp);
		remove("members.bin");
		rename("temp.bin", "members.bin");
		system("cls");
		modifyMem();
	}
	else if (stop == 'N') {
		fclose(fpm);
		fclose(fpTemp);
		remove("members.bin");
		rename("temp.bin", "members.bin");
		system("cls");
		memMenu();


		if (wishModify == 'N') {
			printf("Returning to Main Menu.\n");
			fclose(fpm);
			fclose(fpTemp);
			system("pause");
			system("cls");
			memMenu();
		}
		else {
			printf("Invalid input! Please enter Y or N.\n");
		}
		printf("Member not found.\n");

		remove("temp.bin");
	}
}

void deleteMem() {
	FILE* fpm, * fpTemp;
	member mem;
	char confirm;
	char searchIC[13];

	fpm = fopen("members.bin", "rb");
	if (fpm == NULL) {
		printf("Error: Failed to open members file.\n");
		exit(EXIT_FAILURE);
	}

	fpTemp = fopen("temp.bin", "wb");
	if (fpTemp == NULL) {
		printf("Error: Failed to create temporary file.\n");
		fclose(fpm);
		exit(EXIT_FAILURE);
	}

	// Loop through the members in the binary file
	printf("LOG IN FOR DELETE >>>>\n");
	
	printf("Enter the IC number to search: ");
	if (scanf("%12s", searchIC) != 1) {
		printf("Error: Failed to read input.\n");
		fclose(fpm);
		fclose(fpTemp);
		deleteMem();
	}

	int found = 0;
	while (fread(&mem, sizeof(mem), 1, fpm) == 1) {
		if (strcmp(mem.memIC, searchIC) == 0) {
			found = 1;
			printf("============================================\n");
			printf(">Member Details:\n");
			printf(">ID                : MB%d\n", mem.inspect.memID);
			printf(">Name              : %s\n", mem.name);
			printf(">IC Number         : %s\n", mem.memIC);
			printf(">Gender            : %c\n", mem.gender);
			printf(">Age               : %d\n", mem.age);
			printf(">Email             : %s\n", mem.memEmail);
			printf(">Contact Number    : 0%d\n", mem.contactNum);
			printf(">Member Expiry Date: %d days\n", mem.inspect.expDate);
			printf(">Member Status     : %s\n", mem.inspect.memStat);
			printf(">Member Points     : %d\n", mem.inspect.memPt);
			printf("============================================\n");

			// Prompt for confirmation to delete
			printf("Are you sure you want to delete this member? (Y/N): ");
			scanf(" %c", &confirm);

			if (confirm == 'Y' || confirm == 'y') {
				// Do nothing, skip writing the member to temporary file to effectively delete the member
				printf("Member with IC Number %s has been deleted.\n", searchIC);
				printf("Redirect Back To Member Menu...\n");
				system("pause");
				system("cls");
				memMenu();
			}
			else {
				fwrite(&mem, sizeof(mem), 1, fpTemp); // Write the member to temporary file
				printf("Redirect Back To Member Menu...\n");
				system("pause");
				system("cls");
				memMenu();
			}
		}
		else {
			fwrite(&mem, sizeof(mem), 1, fpTemp); // Write the member to temporary file
		}
	}

	fclose(fpm);
	fclose(fpTemp);

	if (!found) {
		printf("Error: Member with IC number %s not found.\n", searchIC);
	}
	else {
		// Replace the original file with the temporary file
		remove("members.bin");
		rename("temp.bin", "members.bin");
	}
}

void memberList()
{
	char conT;
	FILE* fpm;
	member mem;

	fpm = fopen("members.bin", "rb+");
	if (fpm == NULL) {
		printf("Error: Failed to open members file.\n");
		exit(EXIT_FAILURE);
	}
	printf("LOG IN FOR MEMBER LIST SHOW >\n");
	do {
		rewind(stdin);
		printf("Continue? (Y / N) > ");
		scanf("%s", &conT);
		validateMem(conT);
		if (validateMem(conT) == 0)
		{
			break;
		}
		else if (validateMem(conT) == 1)
		{
			system("cls");
			memMenu();
		}
		else if (validateMem(conT) == 2) {
			printf("Invalid Enter, Only (Y / N)\n");
		}
	} while (validateMem(conT) != 0 && validateMem(conT) != 1);
	rewind(fpm);
	printf(">>> Member List <<<\n");
	printf("====================================================\n");
	printf("| %-12s | %-31s | %-3s | %-6s | %-s\n", "IC", "Name", "Age", "ID", "Status");
	printf("----------------------------------------------------\n");
	while (fread(&mem, sizeof(mem), 1, fpm) == 1) {
		printf("| %-12s | %-31s | %-3d | M%-6d | %-s\n", mem.memIC, mem.name, mem.age, mem.inspect.memID, mem.inspect.memStat);
	}
	printf("====================================================\n");

	fclose(fpm);
	system("pause");
	system("cls");
	memMenu();

}

int validateMem(char conT)
{
	conT = toupper(conT);
	// validate for the continue select in all the module expect register
	if (conT == 'Y')
	{
		return 0;
	}
	else if (conT == 'N') 
	{
		return 1;
	}
	else
	{
		return 2;
	}
}








