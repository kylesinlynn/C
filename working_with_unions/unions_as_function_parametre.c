#include <stdio.h>

union id
{
   int id_num;
   char name[20];
};

void set_id(union id *item)
{
  item->id_num = 42;
}

void show_id(union id item)
{
  printf("ID is %d\n", item.id_num);
}

int main()
{
  union id tw;
  set_id(&tw);
  show_id(tw);

  return 0;
}
