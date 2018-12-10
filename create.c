//
//  create.c
//  Calendar
//
//  Created by Nils Hollmer on 2018-11-23.
//  Copyright © 2018 Nils Hollmer. All rights reserved.
//

#include "create.h"
#include <stdlib.h>
#include <stdio.h>

void printDates(int array[12][31], int month1, int month2, int month3, int counter);

void printCal(int year, int day){
    int totalDaysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i,j;
    int months[12][31];
    
    //If statement adds 1 day to february if it's a leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        totalDaysInMonths[1] = 29;
    }
    
    //For-loop adds every day to it's month
    for(i=0; i<12;i++){
        for(j=0; j < totalDaysInMonths[i] ;j++){
            if (day==7){
                day = 0;
            }
            months[i][j] = day;
            day += 1;
        }
    }
    
    //The start of the printing
    printf("\n\t\t\t\t\t\t\t\t%d\n\n", year);
    printf("\t   January\t\t\t\t  February\t\t\t\t\tMarch\n");
    //For-loop prints out the days of the week for months 1-3
    for (i=0;i<3;i++){
        printf(" Su Mo Tu We Th Fr Sa\t");
    }
    printDates(months, totalDaysInMonths[0], totalDaysInMonths[1], totalDaysInMonths[2], 0);
    printf("\n");
    printf("\t\tApril \t\t\t\t\t May\t\t\t\t\tJune\n");
    //For-loop prints out the days of the week for months 4-6
    for (i=0;i<3;i++){
        printf(" Su Mo Tu We Th Fr Sa\t");
    }
    printDates(months, totalDaysInMonths[3], totalDaysInMonths[4], totalDaysInMonths[5], 3);
    printf("\n");
    printf("\t\tJuly\t\t\t\t\tAugust\t\t\t\t  September\n");
    //For-loop prints out the days of the week for months 7-9
    for (i=0;i<3;i++){
        printf(" Su Mo Tu We Th Fr Sa\t");
    }
    printDates(months, totalDaysInMonths[6], totalDaysInMonths[7], totalDaysInMonths[8], 6);
    printf("\n");
    printf("\t   October\t\t\t\t   November\t\t\t\t   December\n");
    //For-loop prints out the days of the week for months 10-12
    for (i=0;i<3;i++){
        printf(" Su Mo Tu We Th Fr Sa\t");
    }
    printDates(months, totalDaysInMonths[9], totalDaysInMonths[10], totalDaysInMonths[11], 9);
    printf("\n");

    return;
}

void printDates(int array[12][31], int month1, int month2, int month3, int counter){
    static int a ,b, c;
    int i,j;
    int dateRow[6][21];
    a = b = c = 1;
    printf("\n");
    for(i = 0; i < 6; i++){
        for(j=0; j<21;j++){
// The a,b,c variables keeps track of the days of the individual months,
// the j variable loops through the row and assigns the dates of the months.
// The first 7 columns are reserved to the first month in the row,
// the second 7 columns to the second month etc.
            if (j < 7){
                if (a<=month1) {
                    if (a==1){
                        for(int g = 0;g < array[counter][0];g++){
                            printf("   ");
                            j++;
                        }
                        dateRow[i][j] = a++;
                        printf("  %d", dateRow[i][j]);
                    } else {
                        dateRow[i][j] = a++;
                        if (a<=10) {
                            printf("  %d", dateRow[i][j]);
                        }else{
                            printf(" %d", dateRow[i][j]);
                        }
                    }
                } else {
                    printf("   ");
                }
            }
            if (j==7) {
                printf("\t");
            }
            if (j >=7 && j < 14 ){
                if (b<=month2) {
                    if (b==1){
                        for(int g = 0;g < array[counter + 1][0];g++){
                            printf("   ");
                            j++;
                        }
                        dateRow[i][j] = b++;
                        printf("  %d", dateRow[i][j]);
                    } else {
                        dateRow[i][j] = b++;
                        if (b<=10) {
                            printf("  %d", dateRow[i][j]);
                        }else{
                            printf(" %d", dateRow[i][j]);
                        }
                    }
                } else {
                    printf("   ");
                }    
            }
            if (j==14) {
                printf("\t");
            }
            if (j>=14 && j < 21){
                if (c<=month3) {
                    if (c==1){
                        for(int g = 0;g < array[counter + 2][0];g++){
                            printf("   ");
                            j++;
                        }
                        dateRow[i][j] = c++;
                        printf("  %d", dateRow[i][j]);
                    } else {
                        dateRow[i][j] = c++;
                        if (c<=10) {
                            printf("  %d", dateRow[i][j]);
                        }else{
                            printf(" %d", dateRow[i][j]);
                        }
                    }
                } else {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }
}

