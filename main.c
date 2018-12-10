//
//  main.c
//  Calendar
//
//  Created by Nils Hollmer on 2018-11-22.
//  Copyright © 2018 Nils Hollmer. All rights reserved.
//

#include <stdio.h>
#include "calculate.h"
#include "inout.h"
#include "create.h"

int main() {
    int year = is_valid();
    int day = calculate(year);
    printCal(year, day);
    
    return 0;
}
