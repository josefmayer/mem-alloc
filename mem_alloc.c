#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
typedef struct addr {
	char name[16];
	char street[16];
	char city[16];
} address;


void store(char *storefile, char *cptr, int struct_size, int data_len) {
	FILE *fp;

	if ((fp = fopen(storefile, "wb")) == NULL)
		{
		printf("Error in opening file..!!\n");
		return;
	}

	if (fwrite(cptr, struct_size, data_len, fp) != data_len) {
			printf("Error in writing to file..!!\n");
	}

	fclose(fp);
}


void load(char *loadfile, char *cptr, int struct_size, int data_len) {
		FILE *fpr;
	if ((fpr = fopen(loadfile, "rb")) == NULL)
	{
		printf("Error in opening file..!!\n");
		return;
	}

	if (fread(cptr, struct_size, data_len, fpr) != data_len) {
			printf("Error in reading from file..!!\n");
	}

	fclose(fpr);
}

void print_console(address *addr_arr, int data_len) {

	for (int i = 0; i < data_len; i++) {
		printf("%s\n", addr_arr[i].name);
		printf("%s\n", addr_arr[i].street);
		printf("%s\n", addr_arr[i].city);
	}
	printf("\n");
}

void data_mem_init(address *addr_arr) {

	strcpy(addr_arr[0].name, "name1");
	strcpy(addr_arr[0].street, "street1");
	strcpy(addr_arr[0].city, "city1234567");

	strcpy(addr_arr[1].name, "name2");
	strcpy(addr_arr[1].street, "street2");
	strcpy(addr_arr[1].city, "city2");

}

void main() {

	char *storefile = "data_in";
	char *loadfile = "data_in";


	int mem_len = 10;
	int data_len = 2;
	
	address * addr_arr;
	addr_arr = malloc(mem_len * sizeof(address));
	
	//char * mem_ptr = malloc(1000);
	//addr_arr = mem_ptr;

	char *cptr;
	cptr = addr_arr[0].name;

	data_mem_init(addr_arr);

	print_console(addr_arr, data_len);

	store(storefile, cptr, sizeof(address), data_len);
	load(loadfile, cptr, sizeof(address), data_len);

	print_console(addr_arr, data_len);


	free(addr_arr);

	

}