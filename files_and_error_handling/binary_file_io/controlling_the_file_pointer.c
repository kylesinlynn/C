#include <stdio.h>
#include <string.h>

typedef struct
{
  int id;
  char name[20];
} item;

int main()
{
  /*
   * ftell(fp) returns a long int value corresponding to the fp file pointer
   * position in number of bytes from the start of the file
   *
   * fseek(fp, num_bytes, from_pos)
   * SEEK_SET start of file
   * SEEK_CUR current position
   * SEEK_END end of file
   */

  FILE *fptr;
  item first, second, secondf;

  /* create records */
  first.id = 10276;
  strcpy(first.name, "Widget");
  second.id = 11786;
  strcpy(second.name, "Gadget");

  /* write records to a file */
  fptr = fopen("info.dat", "wb");
  fwrite(&first, 1, sizeof(first), fptr);
  fwrite(&second, 1, sizeof(second), fptr);
  fclose(fptr);

  /* file contains 2 records of type item */
  fptr = fopen("info.dat", "rb");

  /* seek second record */
  fseek(fptr, 1*sizeof(item), SEEK_SET);
  fread(&secondf, 1, sizeof(item), fptr);
  printf("%d %s\n", secondf.id, secondf.name);
  fclose(fptr);

  return 0;
}
