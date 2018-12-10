//
//  calculate.c
//  Calendar
//
//  Created by Nils Hollmer on 2018-11-22.
//  Copyright © 2018 Nils Hollmer. All rights reserved.
//

#include "calculate.h"

int calculate(int year) {
    int i, dayNumber;
    int totalDays = 1;

// add every year to the totalDays variable depending on if
// it’s a leap year or not
    for (i = 1; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
            totalDays += 366;
        } else {
            totalDays +=365;
        }
    }
    // calculate the weekday of the first day of the year and print it out.
    dayNumber = totalDays % 7;
    return dayNumber;
}


