#include "MY_DEFINE.h"
#include "MY_FUNC.h"
#include "MY_STRUCT.h"


void print_all(student **st, int count) {
   int i;
   for (i = 0; i < count; i++)
      printf("%s %s %s\n", st[i]->name, st[i]->phone, st[i]->birth);
}
