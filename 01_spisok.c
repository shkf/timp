#include <stdio.h>
#include <stdlib.h>

typedef struct spisok1
{
  signed long number;
  struct spisok1 * next;
} spisok1;

void push_back(spisok1 * head, signed long q)
{
  spisok1 * current = head;
  while (current->next != NULL)
  {current = current->next;}
  current->next = malloc(sizeof(spisok1));
  current->next->number = q;
  current->next->next = NULL;
}

int find(spisok1 * head, signed long q)
{
  spisok1 * current = head;
  do
  { current = current->next;
    if ( current->number == q) {return 1;}
  }while (current->next != NULL);
}

int clear(spisok1 * head)
{
  while (head != NULL)
  {
    spisok1 * current = head;
    head = head->next;
    free(current);
  }
  return 0;
}

spisok1* delite(spisok1 * head, signed long q) 
{
  spisok1 * tmp = head, *p = NULL;
  while (tmp && tmp->number != q)
  {
    p = tmp;
    tmp = tmp->next;
  }
   
  if (!tmp) return head;
  p->next = tmp->next;
  free(tmp);
}

void insertAfter(spisok1 * head, signed long n, signed long q)
{
  signed long i = 1;
  spisok1 *tmp = NULL;
  while (i<n && head->next)
  {
    head = head->next;
    i++;
  }
  tmp = malloc(sizeof(spisok1));
  tmp->number=q;
  if (head->next) {tmp->next = head->next;}
  else {tmp->next = NULL;}
  head->next=tmp;
}

void push_front(spisok1 ** head, signed long q)
{
  spisok1 * current;
  current = malloc(sizeof(spisok1));
  current->number = q;
  current->next = *head;
  *head = current;
}

void print(spisok1 * head)
{
  spisok1 * current = head;
  while (current != NULL)
  {
    printf("%ld ", current->number);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  spisok1 * head = NULL;
  head = malloc(sizeof(spisok1));
  signed long n, a, i=1;
  scanf ("%ld", &n);

  while (i<=n) 
  {
    scanf ("%ld", &a);
    if (i==1) {head->number=a;}
    else {push_back(head,a);}
    i++;
  }
  print(head);

  int f=0; i=1;
  signed long k;
  for (int p=0; p<3; p++)
  {
    scanf("%ld",&k);
    
    while (i<=n) 
    {
      if ((i==1) && (head->number==k)) {f=1;break;}
      else {f=find(head,k);}
      i++;
    }
    printf("%d ",f);
    f=0; i=1;
  }
  printf("\n");

  signed long m;
  scanf("%ld", &m);
  push_back(head,m);
  print(head);

  signed long t;
  scanf("%ld", &t);
  push_front(&head,t);
  print(head);

  signed long j,x;
  scanf("%ld%ld",&j,&x);
  insertAfter(head,j,x);
  print(head);

  signed long z;
  scanf("%ld",&z);
  delite(head,z);
  print(head);

  clear(head);

  return 0;
}
