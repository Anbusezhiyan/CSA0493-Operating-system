#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct {
    int record_id;
    char data[100]; 
} Record;

Record file[MAX_RECORDS];
int total_records = 0; 

void add_record(int record_id, char *data) {
    if (total_records < MAX_RECORDS) {
        file[total_records].record_id = record_id;
        sprintf(file[total_records].data, "%s", data); 
        total_records++;
        printf("Record added successfully!\n");
    } else {
        printf("File is full. Cannot add more records.\n");
    }
}

void read_records() {
    printf("Reading all records:\n");
    for (int i = 0; i < total_records; i++) {
        printf("Record ID: %d, Data: %s\n", file[i].record_id, file[i].data);
    }
}

int main() {

    add_record(1, "Data of record 1");
    add_record(2, "Data of record 2");
    add_record(3, "Data of record 3");


    read_records();

    return 0;
}
