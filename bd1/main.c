/* APL121 Bie daalt #1 - Code Quest
   Sedev #27: Zogsoolyn tulbur
   Ajilluulah: gcc main.c -o main && ./main */
#include <stdio.h>

int main(void) {
    int n, i;
    int inH, inM, outH, outM;      /* orson, garsan tsag, min */
    int minutes, fee;
    int entryT[10], exitT[10], mins[10], fees[10];  /* mashin bureer */
    int total = 0;
    int longestIdx = 0;            /* hamgiin udaan zogssonyg haih */

    /* 1. Mashinyg too (do-while: 1..10 hyazgaar shalgana) */
    do {
        printf("Mashinii too (1-10): ");
        scanf("%d", &n);
        if (n < 1 || n > 10) {
            printf("  Aldaa: 1-10 hoorond too oruulna uu.\n");
        }
    } while (n < 1 || n > 10);

    /* 2. Mashin bureer tsag unshih, tulbur toocoh */
    for (i = 0; i < n; i++) {
        printf("\n--- Mashin %d ---\n", i + 1);
        do {
            do {
                printf("Orson tsag (0-23): ");
                scanf("%d", &inH);
            } while (inH < 0 || inH > 23);
            do {
                printf("Orson minut (0-59): ");
                scanf("%d", &inM);
            } while (inM < 0 || inM > 59);
            do {
                printf("Garsan tsag (0-23): ");
                scanf("%d", &outH);
            } while (outH < 0 || outH > 23);
            do {
                printf("Garsan minut (0-59): ");
                scanf("%d", &outM);
            } while (outM < 0 || outM > 59);

            minutes = (outH * 60 + outM) - (inH * 60 + inM);
            if (minutes < 0) {
                printf("  Aldaa: garsan tsag orsnoos omno baij bolohgui.\n");
            }
        } while (minutes < 0);

        /* Tulburiin shatlal (minii togtoosoon durem) */
        if (minutes <= 30) {
            fee = 0;            /* ehnii 30 min unegui */
        } else if (minutes <= 60) {
            fee = 1000;
        } else if (minutes <= 180) {
            fee = 3000;
        } else if (minutes <= 480) {
            fee = 6000;
        } else {
            fee = 10000;        /* odriin deed hyazgaar */
        }

        entryT[i] = inH * 60 + inM;
        exitT[i]  = outH * 60 + outM;
        mins[i]   = minutes;
        fees[i]   = fee;
        total += fee;

        /* Hamgiin udaan zogssonyg haih (logic && , ||) */
        if (minutes > mins[longestIdx] || (minutes == mins[longestIdx] && fee > fees[longestIdx])) {
            longestIdx = i;
        }
    }

    /* 3. Husnegt hevleh */
    printf("\n%-4s %-8s %-8s %8s %10s\n", "No", "Orson", "Garsan", "Minut", "Tulbur");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-4d %02d:%02d    %02d:%02d    %8d %10d\n",
               i + 1, entryT[i] / 60, entryT[i] % 60,
               exitT[i] / 60, exitT[i] % 60, mins[i], fees[i]);
    }
    printf("---------------------------------------------\n");
    printf("Niit orlogo: %d tugrug\n", total);
    printf("Hamgiin udaan zogssoon: Mashin %d (%d minut)\n", longestIdx + 1, mins[longestIdx]);
    {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += mins[i];
        }
        printf("Dundaj zogsoltyn hugatsaa: %.1f minut\n", (double)sum / n);
    }

    return 0;
}
