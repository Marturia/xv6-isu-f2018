/*
  Author: Brody Little
  Purpose: HW2b for CS471

  hw2b <maxNum> [base]

  What it does:
    Takes up to two arguments: a number in decimal to reach, and an optional base.  Prints powers of given base up to and including
    that number.  Defaults to base 2.
 */

#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

//Function to print when maxNum is reached and closes program
void maxReached(){
  printf(1, "Max value reached\n");
  exit();
}

//Calculates result and returns it
int calcNum(int num, int maxNum, int base){
  num*=base;
  if(num>maxNum){
    maxReached();
  }
  
  return num;
}

int main(int argc, char *argv[]) {
  int base = 2;
  int maxNum = atoi(argv[1]);
  int num;
  
  //Checking for correct invoking of program
  if (argc < 2){
    printf(1, "Please run program again in format: hw2b <num> [base]\n");
    exit();
  }

  //Checks for a user input base, then changes base if found
  if (argv[2] != NULL){
    base = atoi(argv[2]);
  }
 
  //Ensures that the number is at least 2
  if(maxNum<2){
    printf(1, "Number entered should be non-negative and at least 2\n");
    exit();
  }

  //value of first num in given base
  num = base;

  //Runs until maxNum is reached
  while(1){
    printf(1, "%d\n", num);
    num = calcNum(num, maxNum, base);
  }

  exit();
}
