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
void PrintList(Node * head) {
  Node * current = head->next;
  while (current->next) { // reach to the end
    current = current->next;
  }
  do {
    if (!current->next) {
      printf("%-d", current->num);
      if (current->num) {
        printf(",");  // what if it's a '0'
      }
      current = current->prev;
    } else {
      printf("%03d", current->num);
      current = current->prev;
      if (current->prev) {
        printf(",");  // ',' is no need in tha last
      }
    }
  } while (current->prev);  // util to the head
}
// Output Functions


// Linked List Operation
Node * NewHead(void) {
  Node *head = (Node *)malloc(sizeof(Node));
  head->next = NULL;
  head->prev = NULL;
  head->num = -1;
  head->length = 0;
  return head;
}

void AddNode(Node *current, int num) {
  Node * node = (Node *)malloc(sizeof(Node));
  node->num = num;
  current->next = node;
  node->prev = current;
  node->next = NULL;
  node->length = -1;
}

Node * StrToNum(int size, char * str) {
  int i;
  int temp = 0, coefficient = 1;
  int position = size - 1;
  Node * head = NewHead();
  Node * current = head;
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
    head->length++;
    current = current->next;
    temp = 0;
    coefficient = 1;
  }
  return head;
}

Node * CopyList(Node *source) {
  Node * destination = NewHead();
  Node * current0 = destination;
  Node * current1 = source->next;
  while (current1) {
    AddNode(current0, current1->num);
    destination->length++;
    current0 = current0->next;
    current1 = current1->next;
  }

  return destination;
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

//Node * Operate(Node *head1, Node *head2, Node(*operation)(Node *, Node*)) {
//
//}

Node * Addition(Node *head1, Node *head2) {
  Node * result = NewHead();
  Node * current0 = result;
  Node * current1 = head1->next;
  Node * current2 = head2->next;
  int i = 0;
  int difference = head1->length - head2->length;
  if (difference > 0) {
    i = head2->length;
  } else{
    i = head1->length;
  }
  int temp = 0;
  int carry = 0;
  for (i; i > 0; i--) {
    temp = current1->num + current2->num + carry;
    if (temp > 999) {
      carry = temp / 1000;
      temp -= 1000;
    } else {
      carry = 0;
    }
    AddNode(current0, temp);
    result->length++;
    current0 = current0->next;
    current1 = current1->next;
    current2 = current2->next;
  }
  if (difference > 0) {
    while (current1) {
      temp = current1->num + carry;
      if (temp > 999) {
        carry = temp / 1000;
        temp -= 1000;
      } else {
        carry = 0;
      }
      AddNode(current0, temp);
      result->length++;
      current0 = current0->next;
      current1 = current1->next;
    }
  } else if (difference < 0) {
    while (current2) {
      temp = current2->num + carry;
      if (temp > 999) {
        carry = temp / 1000;
        temp -= 1000;
      } else {
        carry = 0;
      }
      AddNode(current0, temp);
      result->length++;
      current0 = current0->next;
      current1 = current2->next;
    }
  }
  return result;
}

//Node * Subtraction(Node *head1, Node *head2) {
//  Node * result = NewHead();
//  Node * current0 = result;
//  Node * current1 = head1->next;
//  Node * current2 = head2->next;
//  int carry = 0;
//  int temp = 0;
//  int i = 0;
//  int difference = head1->length - head2->length;
//  if (difference > 0) {
//    i = head2->length;
//  } else {
//    i = head1->length;
//  }
//
//  return result;
//}
//
//Node * Multiplication(Node *head1, Node *head2) {
//  Node * result = NewHead();
//  Node * current0 = result;
//  Node * current1 = head1->next;
//  Node * current2 = head2->next;
//  int carry = 1;
//  int temp = 0;
//  int i = 0;
//  int difference = head1->length - head2->length;
//  if (difference > 0) {
//    i = head2->length;
//  } else {
//    i = head1->length;
//  }
//}

// Process Functions
