//
//  main.c
//  file_input
//
//  Created by Blake Conrad on 10/7/16.
//  Copyright (c) 2016 Blake Conrad. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    

    FILE *fp;
    fp=fopen("/Users/bmc/Desktop/K\&R_Book_/ch1_file_input/bible.txt", "r");
    char c;
    while((c = fgetc(fp)) != EOF)
    {
        puts(c);
    }
    printf("\n");
    return 0;
}
