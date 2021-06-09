#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

//1309 ������ ���α׷��� ������ <<���� ���� ���α׷�>>>

typedef struct booklist
{
	int value, i;// i�� �����ϴ����� ���� ����, ���� arr[1].i == 1�̸� arr[1]�� �����ϴ� å
	char name[30], stat[30];
}LIST;



LIST arr[1000] = { 0, };
LIST* ptr = arr;


void save();
int borrow();
int srch();



int main() {
	int c;
	while (1) {
		printf("======== <<< ���� ���� ���α׷� >>> ========\n\n���� �۾��� ���Ͻó���?\n(���� �� ���ϴ� �۾��� ��ȣ�� �Է��ϼ���.)\n1: �˻�\n2. å ��� �� ����\n3. ����\n�ٸ� ����: ����\n");
		scanf("%d", &c);

		if (c == 1) {
			srch();
		}
		else if (c == 2) {
			save();
		}
		else if (c == 3) {
			borrow();
		}
		else {
			printf("�����մϴ�. ");
			return 0;
		}
		printf("\n=================================\n");
	}
}




void save() {
	int i, n, j, m;
	printf("å ����� �ۼ����ּ���.\n");
	printf("�� ���� å�� �Է��Ͻðڽ��ϱ�?\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("å ��ȣ�� �Է��ϼ���.( 0~999�� ����)\n");
		scanf("%d", &m);
		if (arr[m].i) {
			printf("���� ��ȣ�� �ٸ� å�� �����մϴ�. �����Ͻðڽ��ϱ�?\n(���ϽŴٸ� 1, �׷��� �ʴٸ� �ƹ� ���ڳ� �Է�)\n");
			scanf("%d", &j);
			if (j != 1) {
				printf("���α׷��� ����Ǿ����ϴ�.");
				break;
			}
			

		}
		printf("å �̸��� �Է��ϼ���.(30�� �̳�)\n");
		scanf("%s", &arr[m].name);
		printf("å�� ������ �Է��ϼ���.(������ �Է����� �ʽ��ϴ�.)\n");
		scanf("%d", &arr[m].value);
		arr[m].i = 1;
		strcpy(arr[m].stat, "���Ⱑ��");
		
	}

}

int srch() {

	int type;
	printf("������ ���� ã���ðڽ��ϱ�?(������ ���ڷ� �Է����ּ���.)\n");
	printf("1. ��ȣ\n2. �̸�\n3. ����\n");

	scanf("%d", &type);


	int n, i = 1, j = 0, value = 0;
	char nm[30] = "\0";
	if (type == 1) {

		printf("��ȣ�� �Է��ϼ���\n");
		scanf("%d", &n);
		printf("å ��ȣ : %d\nå �̸� : %s\nå ����:%d\nå ����:%s",
			n, ptr[n].name, ptr[n].value, ptr[n].stat);
	}
	else if (type == 2) {
		n = 0;
		printf("�̸��� �Է��ϼ���\n");
		scanf("%s", nm);
		while (1) {
			if (!(strcmp(nm, &ptr[n].name))) {
				printf("å ��ȣ : %d\nå �̸� : %s\nå ����:%d\nå ����:%s",
					n, ptr[n].name, ptr[n].value, ptr[n].stat); 
				break; 
			}
			else {
				n++;
				if (n == 1000) {
					printf("�׷� å�� �����ϴ�!!");
					break;
				}
				continue;
			}
		}


	}
	else {
		n = 0;
		printf("������ �Է��ϼ���\n");
		scanf("%d", &value);
		while (1) {
			if (value == ptr[n].value) {
				printf("å ��ȣ : %d\nå �̸� : %s\nå ����:%d\nå ����:%s\n\n",
					n, ptr[n].name, ptr[n].value, ptr[n].stat);
				n++;
			}
			else {
				n++;
				if (n == 1000) {
					printf("�Է��� ������ å���� ��� ����߽��ϴ�!\n\n\n");
					break;
				}
				continue;
			}
		}

	}
	return 0;
}

int borrow() {
	int num, j;
	printf("\n���� �۾��� �Ͻðڽ��ϱ�?\n(������ �Ͻ÷��� 1��, �ݳ��� �ٸ� ���ڸ� �Է����ּ���!)\n");
	scanf("%d", &j);
	if (j == 1) {
		printf("\n\n\n���� å�� ��ȣ�� �Է��ϼ���\n");
		scanf("%d", &num);
		if (!(arr[num].i)) {
			printf("\n�Է��� ��ȣ�� å�� �������� �ʽ��ϴ�.\n(�޴��� ���ư��ϴ�)\n");
			return 0;
		}
		strcpy(arr[num].stat, "������...");
		printf("%d�� ������ ������ �Ϸ�Ǿ����ϴ�! >,<\n", num);
		return 0;
	}

	else {
		printf("\n\n�� �� ������ �ݳ��Ͻðڽ��ϱ�?\n");
		scanf("%d", &num);
		if (!(arr[num].i)) {
			printf("\n�Է��� ��ȣ�� å�� �������� �ʽ��ϴ�.\n(�޴��� ���ư��ϴ�)\n");
			return 0;
		}
		if (arr[num].stat != "������...") {
			printf("�������� �ƴմϴ�!");
			borrow();
			return 0;
		}
		strcpy(arr[num].stat, "���Ⱑ��");
		printf("%d�� ������ �ݳ��� �Ϸ�Ǿ����ϴ�! >,~\n", num);
		return 0;
	}
}
