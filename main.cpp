#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp_w = NULL;
	errno_t err_w = fopen_s(&fp_w, "C:/Users/YQ/Desktop/test.txt", "w");

	if (err_w != 0) {
		printf("Fail to open file\n");
		return 1; // ���ط���ֵ��ʾ�����쳣�˳�
	}
	for (int i = 0; i < 1000; ++i) {
		fputs("Hello world!", fp_w);
	}
	fclose(fp_w);

	FILE* fp_r = NULL;
	errno_t err_r = fopen_s(&fp_r, "C:/Users/YQ/Desktop/test.txt", "r");
	if (err_r != 0) {
		printf("Fail to open file\n");
		return 1; // ���ط���ֵ��ʾ�����쳣�˳�
	}
	fseek(fp_r, 16, SEEK_SET);
	char c = fgetc(fp_r);
	printf("�ַ���%c", c);
	fclose(fp_r);

	return 0;
}