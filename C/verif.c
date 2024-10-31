#include <stdlib.h>

char check_date(char* day, char* month, char* year) {
  if (atoi(day) != 0 && atoi(month) != 0 && atoi(year) != 0) {
      return 'T';
  }
  return 'F';
}
