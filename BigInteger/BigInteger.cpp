#include "BigInteger.h"

// User Functions
Status YesOrNo(void) {
  Status status = RUNNING;
  char temp;
  while (1) {
    puts("Enter 'Y' for YES and 'N' for NO:");
    scanf("%c%*c", &temp);
    if (temp != 'Y' && temp != 'N') {
      puts("Invalid input! Please try again.");
    } else if (temp == 'N') {
      status = DONE;
      break;
    } else {
      break;
    }
  }
  return status;
}
// User Functions


// Input Functions
char * ObtainedAsStr(int &size) {
  char * source = (char *)malloc(sizeof(char) * MAXLEN + 1);
  /* malloc a large enough temporary space to prevent overflow
     '+ 1' is to consider that the input just reaches the upper limit */
  Status status = RUNNING;
  while (status) {
    ReadStr(source);
    size = strlen(source);
    if (size == 0) {
      puts("\nERROR:");
      puts("You have entered nothing.");
      puts("Do you want to re-enter?");
      status = YesOrNo();
      if (status == DONE) {
        exit(DONE);
      }
    } else if (size > MAXLEN) {
      puts("\nERROR:");
      puts("The number you entered is beyond the range of calculations");
      puts("that this program can accept.\n");
      puts("Do you want to re-enter?");
      status = YesOrNo();
      if (status == DONE) {
        exit(OVERFLOW);
      }
    } else {
      status = DONE;
    }
  }
  char * numInstr = (char *)malloc(sizeof(char) * size);
  strcpy(numInstr, source);
  free(source);
  return numInstr;
}
// Input Functions


// Output Functions
void PrintList(BigIntNode * head) {
  BigIntNode * current = head->next;
  while (current->next) { // reach to the end
    current = current->next;
  }
  do {
    if (!current->next) {
      printf("%-d", current->num);
      current = current->prev;
    } else {
      printf("%03d", current->num);
      current = current->prev;
    }
  } while (current->prev);  // util to the head
}
// Output Functions


// Linked List Operation
BigIntNode * NewHead(void) {
  BigIntNode *head = (BigIntNode *)malloc(sizeof(BigIntNode));
  head->next = NULL;
  head->prev = NULL;
  head->num = -1;
  return head;
}

void AddNode(BigIntNode *current, int num) {
  BigIntNode * node = (BigIntNode *)malloc(sizeof(BigIntNode));
  node->num = num;
  current->next = node;
  node->prev = current;
  node->next = NULL;
}

BigIntNode * StrToNum(int size, char * str) {
  int i;
  int temp = 0, coefficient = 1;
  int position = size - 1;
  BigIntNode * head = NewHead();
  BigIntNode * current = head;
  for (position; position >= 0; ) {
    for (i = 0; i < 3; i++) {
      if (!(str[position] >= '0' && str[position] <= '9')) {
        break;  // In case of less than three digits
      }
      temp += (str[position] - '0') * coefficient;
      coefficient *= 10;
      position--;
    }
    AddNode(current, temp);
    current = current->next;
    temp = 0;
    coefficient = 1;
  }
  return head;
}
// Linked List Operation


// Process Functions
void ClearBuf(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void ReadStr(char * source) {
  int c;
  int i = 0;
  Status status = RUNNING;
  puts("Please enter:");
  while ((c = getchar()) != '\n' && c != EOF) {
    if (c >= '0' && c <= '9') {
      source[i++] = c;
    } else {
      puts("\nERROR:");
      puts("Contains illegal characters!\n");
      puts("Do you want to re-enter?");
      ClearBuf();
      status = YesOrNo();
      if (status == RUNNING) {
        ReadStr(source);
      } else {
        exit(ERROR);
      }
    }
  }
  source[i] = '\0';
}

BigIntNode * Addition(BigIntNode *head1, BigIntNode *head2) {
  BigIntNode * result = NewHead();
  BigIntNode * current0 = result;
  BigIntNode * current1 = head1->next;
  BigIntNode * current2 = head2->next;
  int carry = 0;
  
  int temp = 0;
  temp = current1->num + current2->num;
  if (temp > 999) {
    carry = temp / 1000;
    temp -= 1000;
  }
  AddNode(current0, temp);
  

  return result;
}

// Process Functions
