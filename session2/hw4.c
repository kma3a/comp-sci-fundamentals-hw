#include <stdio.h>

/*
 * struct for the day
 */
struct day {
  int day;
  int month;
  int year;
};

/*
 * calculates the year that you multiply 1461 against 
 */
int yearModCalc ( int year , int month ) {
  if ( month <= 2) {
    year -= 1;
  }
  return year;
}

/*
 * calculates the month modifier 
 */
int monthModCalc ( int month ) {
  if (month <= 2) {
    month += 13;
  } else {
    month += 1;
  }

  return month;
}

/*
 * calculates N which is the number date that you use before you calculate the date differences
 */
int calculateN (struct day current) {
  int n;
  int yearMod;
  int monthMod;

  yearMod = yearModCalc(current.year, current.month);
  monthMod = monthModCalc(current.month);

  n = 1461 * yearMod  /  4 + 153 * monthMod / 5 + current.day;

  return n;
}

/*
 * get the absolute value
 */

int absoluteValue(int number) {
  if ( number >=0 ) {
    return number;
  } else {
    return -number;
  }
}

/*
 * calculates March 1, 1900 (1 must be added to N for dates from March 1, 1800, to February 28, 1900, and 2 must be added for dates between March 1, 1700, and February 28, 1800
 */
int calculateOldMod(struct day current) {
  int month = current.month;
  int day = current.day;
  int year = current.year;
  int mod = 0;

  if( (year < 1900 && year > 1800) || (year == 1800 && month > 3) || (year == 1800 && month == 3 && day >=1) || (year == 1900 && month < 2) || (year == 1900 && month == 2 && day <= 20)){
    mod += 1;
  } else if ( (year > 1700 && year < 1800) || ( year == 1700 && month > 3) || ( year == 1700 && month == 3 && day >=1) || (year == 1800 && month < 2) || ( year == 1800 && month == 2 && day <=28)){
    mod += 2;
  }

  return mod;
}


/* 
 * get the two dates and caldulate the difference in dates
 */

void getDateDifference(void) {
  int n[2];
  int difference;
  int yearMod;
  yearMod = 0;

  for(int i = 0; i <= 1; i++) {
    struct day userInput;
    printf("What is the day in integer (mm/dd/yyyy)? \n");
    scanf("%d/%d/%d", &userInput.month, &userInput.day, &userInput.year);
    
    yearMod += calculateOldMod(userInput);

    n[i] = calculateN(userInput);
  }

  difference = n[0] - n[1];

  printf("I am the difference %d \n", absoluteValue(difference + yearMod));
}


/* main function
 *
 */
int main (void) {

  getDateDifference();


  return 0;
}

