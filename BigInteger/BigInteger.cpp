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

void DisplayWelcome(void) {
  puts("Welcome To Use This Program!");
  puts("*==================================================================*");
  puts("* @Author: \tJovianHuang");
  puts("* @StudentID: \t416125000301");
  puts("* @Unit: \tClass II, CS, School of IE, Hebei GEO University");
  puts("* @Description: This program can implement addition, subtraction");
  puts("*   and multiplication beteween two 'Big Integer' of any length.");
  puts("* @Version: \t1.10.9.181008_beta");
  puts("*==================================================================*");
}
// User Functions


// Input Functions
void ClearBuf(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

Status VerifyRange(int &size, char *source) {
  Status status = RUNNING;
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
  return status;
}

char * ReadFromKeyboard(int &size) {
  char * source = (char *)malloc(sizeof(char) * MAXLEN + 1);
  /* malloc a large enough temporary space to prevent overflow
     '+ 1' is to consider that the input just reaches the upper limit */
  int c;
  int i = 0;
  Status status = RUNNING;
  do {
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
          ReadFromKeyboard(size);
        } else {
          exit(ERROR);
        }
      }
    }
    source[i] = '\0';
  } while (status = VerifyRange(size, source));
  char * numInstr = (char *)malloc(sizeof(char) * size);
  strcpy(numInstr, source);
  free(source);
  return numInstr;
}

char * ReadFromFile(FILE * fp, int &size) {
  char *source = (char *)malloc(sizeof(char) * MAXLEN + 1);
  int c;
  int i = 0;
  Status status = RUNNING;
  do {
    while ((c = fgetc(fp)) != '\n' && c != EOF) {
      if (c >= '0' && c <= '9') {
        source[i++] = c;
      } else {
        puts("\nERROR:");
        puts("Contains illegal characters!\n");
        puts("Do you want to re-enter?");
        ClearBuf();
        status = YesOrNo();
        if (status == RUNNING) {
          ReadFromKeyboard(size);
        } else {
          exit(ERROR);
        }
      }
    }
    source[i] = '\0';
  } while (status = VerifyRange(size, source));
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
      if (current->num < 0) {
        printf("%-d", current->num);
      } else if (current->num){
        printf("%d", current->num);
      }
      if (current->num && current->prev->num != -1) {
        printf(",");  // if it's a '0'
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

void OutputToFile(Node *head) {
  FILE *fp;
  fp = fopen("result.txt", "w");
  Node * current = head->next;
  while (current->next) { // reach to the end
    current = current->next;
  }
  do {
    if (!current->next) {
      if (current->num < 0) {
        fprintf(fp ,"%-d", current->num);
      } else if (current->num) {
        fprintf(fp, "%d", current->num);
      }
      if (current->num && current->prev->num != -1) {
        fprintf(fp, ",");  // if it's a '0'
      }
      current = current->prev;
    } else {
      fprintf(fp, "%03d", current->num);
      current = current->prev;
      if (current->prev) {
        fprintf(fp, ",");  // ',' is no need in tha last
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


// Operation Functions
Node * Operate(Node *head1, Node *head2, Node *(*operation)(Node * , Node*)) {
  Node * result = CopyList(head1);
  result = (*operation)(result, head2);
  return result;
}

void CarryOrNot(numType &num, numType &carry) {
  if (num > 999) {
    carry = num / 1000;
    num %= 1000;
  } else if (num < 0){
    carry = 1;
    num += 1000;
  } else {
    carry = 0;
  }
}

Node * Add(Node *result, Node *head2) {
  Node * current0 = result->next;
  Node * current2 = head2->next;
  numType carry = 0;
  while (current0 && current2) {
    current0->num += current2->num + carry;
    CarryOrNot(current0->num, carry);
    current0 = current0->next;
    current2 = current2->next;
  }
  while (current0 && carry) {
    current0->num += carry;
    CarryOrNot(current0->num, carry);
    current0 = current0->next;
  }
  while (current2) {
    current2->num += carry;
    CarryOrNot(current2->num, carry);
    AddNode(current0, current2->num);
    current2 = current2->next;
  }
  return result;
}

bool Compare(Node *a, Node *b) {
  bool aIsgreater = true;
  if (a->length < b->length) {
    aIsgreater = false;
  } else if (a->length == b->length) {
    Node *aptr = a->next;
    Node *bptr = b->next;
    while (aptr->next) {
      aptr = aptr->next;
      bptr = bptr->next;
    }
    if (aptr->num < bptr->num) {
      aIsgreater = false;
    }
  }
  return aIsgreater;
}

Node * Subtract(Node *result, Node *head2) { 
  /*  Suppose there is an equation: a - b. 
    At this time, 'a' is called the minuend, and 'b' is called the subtrahend.*/
  Node * minuend = result->next;
  Node * subtrahend = head2->next;
  // if 'a' < 'b', let 'b' subtract 'a' and then change the sign
  bool changesign = false;
  if (!Compare(result, head2)) {
    minuend = head2->next;
    subtrahend = result->next;
    result = minuend->prev;
    // to let 'b' subtract 'a'
    changesign = true;
  }
  numType carry = 0;
  while (subtrahend) {
    minuend->num -= subtrahend->num - carry;
    CarryOrNot(minuend->num, carry);
    minuend = minuend->next;
    subtrahend = subtrahend->next;
  }
  while (minuend) {
    minuend->num -= carry;
    CarryOrNot(minuend->num, carry);
    minuend = minuend->next;
  }
  if (changesign) {
    minuend = result->next;
    while (minuend->next) {  // locate the higest digit
      minuend = minuend->next;
    }
    minuend->num = -minuend->num;
  }
  return result;
}

Node * Multiply(Node *head1, Node *head2) {
  // a bit different from "Add" and "Subtract"
  Node * result = NewHead();
  // The result of multiplying any number by 0 is 0
  if (head1->length == 1 && head1->next->num == 0) {
    AddNode(result, 0);
    return result;
  } else if (head2->length == 1 && head2->next->num == 0) {
    AddNode(result, 0);
    return result;
  }
  // Both are not zero
  Node * current1 = head1->next;
  int position = 0;
  while (current1) {
    Node * current0 = result;
    Node * current2 = head2->next;
    for (int i = 0; i < position; i++) {
      current0 = current0->next;
    } // To locate
    position++;
    numType num = 0;
    numType carry = 0;
    while (current2) {
      num = current1->num * current2->num + carry;
      CarryOrNot(num, carry);
      if (!current0->next) {
        // If there is no higher node, create a new one.
        AddNode(current0, num);
        current0 = current0->next;  // NOTE1 
      } else {                      /* NOTE1 and NOTE2 must be in this position
                                        cuz the node that wanna operate are different*/
        current0 = current0->next;  // NOTE2
        numType temp = carry;       // This is the carry from before operate
        num += current0->num;
        CarryOrNot(num, carry);     // Now we got a new carry
        carry += temp;              // add up two carry
        current0->num = num;
        current0->length++;
      }
      current2 = current2->next;
      if (!current2 && carry) {
        num = carry;
        CarryOrNot(num, carry);
        AddNode(current0, num);
      }
    }
    current1 = current1->next;
  }
  return result;
}
// Operation Functions
