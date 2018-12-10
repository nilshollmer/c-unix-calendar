//
//  inout.c
//  Calendar
//
//  Created by Nils Hollmer on 2018-11-22.
//  Copyright © 2018 Nils Hollmer. All rights reserved.
//

#include "inout.h"

// get user input and make sure the input is a valid number
int is_valid(void){
    int year;
    do {
        printf("Enter year: ");
        scanf("%d", &year);
    } while (year < 1);
    return year;
}
