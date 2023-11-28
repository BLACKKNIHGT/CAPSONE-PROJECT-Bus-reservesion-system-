#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUSES 10
#define ROWS 8
#define COLS 4

static int p = 0;

struct Bus {
    char busn[5];
    char driver[10];
    char arrival[5];
    char depart[5];
    char from[10];
    char to[10];
    char seat[ROWS][COLS][10];
    float price;
};

struct Bus buses[MAX_BUSES];

void install() {
    printf("Enter bus no: ");
    scanf("%s", buses[p].busn);
    printf("\nEnter Driver's name: ");
    scanf("%s", buses[p].driver);
    printf("\nArrival time: ");
    scanf("%s", buses[p].arrival);
    printf("\nDeparture: ");
    scanf("%s", buses[p].depart);
    printf("\nFrom: \t\t\t");
    scanf("%s", buses[p].from);
    printf("\nTo: \t\t\t");
    scanf("%s", buses[p].to);
    printf("\nEnter Price: ");
    scanf("%f", &buses[p].price);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            strcpy(buses[p].seat[i][j], "Empty");
        }
    }

    p++;
}

void allotment() {
    int seat;
    char number[5];
    printf("Bus no: ");
    scanf("%s", number);
    int n;

    for (n = 0; n < p; n++) {
        if (strcmp(buses[n].busn, number) == 0) {
            break;
        }
    }

    if (n == p) {
        printf("Enter correct bus no.\n");
        return;
    }

    printf("\nSeat Number: ");
    scanf("%d", &seat);

    if (seat > ROWS * COLS) {
        printf("\nThere are only %d seats available in this bus.\n", ROWS * COLS);
        return;
    }

    if (strcmp(buses[n].seat[(seat - 1) / COLS][(seat - 1) % COLS], "Empty") == 0) {
        printf("Enter passenger's name: ");
        scanf("%s", buses[n].seat[(seat - 1) / COLS][(seat - 1) % COLS]);
    } else {
        printf("The seat no. is already reserved.\n");
    }
}

void show() {
    char number[5];
    printf("Enter bus no: ");
    scanf("%s", number);
    int n;

    for (n = 0; n < p; n++) {
        if (strcmp(buses[n].busn, number) == 0) {
            break;
        }
    }

    if (n == p) {
        printf("Enter correct bus no.\n");
        return;
    }

    printf("Bus no: \t%s\nDriver: \t%s\t\tArrival time: \t%s\tDeparture time: %s\nFrom: \t\t%s\t\tTo: \t\t%s\nPrice: \t\t%.2f\n",
        buses[n].busn, buses[n].driver, buses[n].arrival, buses[n].depart, buses[n].from, buses[n].to, buses[n].price);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (strcmp(buses[n].seat[i][j], "Empty") != 0) {
                printf("The seat no %d is reserved for %s.\n", i * COLS + j + 1, buses[n].seat[i][j]);
            }
        }
    }
}

void avail() {
    for (int n = 0; n < p; n++) {
        printf("Bus no: \t%s\nDriver: \t%s\t\tArrival time: \t%s\tDeparture Time: \t%s\nFrom: \t\t%s\t\tTo: \t\t%s\nPrice: \t\t%.2f\n",
            buses[n].busn, buses[n].driver, buses[n].arrival, buses[n].depart, buses[n].from, buses[n].to, buses[n].price);
    }
}

int main() {
    int w;

    while (1) {
        printf("\n\n\n\n\n");
        printf("\t\t\t1.Install\n\t\t\t2.Reservation\n\t\t\t3.Show\n\t\t\t4.Buses Available\n\t\t\t5.Exit\n");
        printf("\n\t\t\tEnter your choice:-> ");
        scanf("%d", &w);

        switch (w) {
            case 1:
                install();
                break;
            case 2:
                allotment();
                break;
            case 3:
                show();
                break;
            case 4:
                avail();
                break;
            case 5:
                exit(0);
        }
    }

    return 0;
}

