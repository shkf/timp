#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>
typedef struct node
{
  int data;
  struct node * left;
  struct node * right;
  struct node * parent;
} node;
typedef struct tree
{
  struct node * root;  
  int count;            
} tree;
void init(tree * t)
{
    struct tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}
int find(tree* t, int value, node* noddee)
{
  struct node * nod2;
  nod2 = t->root;
  if (t->root == NULL){
    return 1;
  }
  while (1){
    if (nod2 == NULL) {
      return 1;
    } else if (nod2->data == value){
      noddee->data = nod2->data;
      noddee->left = nod2->left;
      noddee->right = nod2->right;
      noddee->parent = nod2->parent;
      return 0;
    } else if (value > nod2->data){
      nod2 = nod2->right;
    } else {
      nod2 = nod2->left;
    }
  }
  return 1;
}
int insert(tree* t, int value)
{
  struct node * noddee, ** noddeenoddee, * last_noddee = NULL;
  struct node * e_n;
  e_n = malloc(sizeof * e_n);

  int err = find(t, value, e_n);
  if (err == 0){
    return 1;
  }
  noddeenoddee = &t->root;
  noddee = t->root;
  while (1){
    if (noddee == NULL) {
      noddee = *noddeenoddee = malloc(sizeof * noddee);
      if (noddee != NULL){
        noddee->data = value;
        noddee->left = NULL;
        noddee->right = NULL;
        noddee->parent = last_noddee;
        t->count++;
        return 0;
      } else
       {
        return 2; 
      }
    }
    last_noddee = noddee; 
    if (value > noddee->data){
      noddeenoddee = &noddee->right;
      noddee = noddee->right;
    } else {
      noddeenoddee = &noddee->left;
      noddee = noddee->left;
    }
  }
  return 0;
}
int _remove(tree* t, int value){
  node * noddee = t->root;
  if (t->root == NULL){
    return 1;
  }
  while (1){
    if (noddee == NULL) {
      break;
      return 1;
    } else if (noddee->data == value){
      break;
    } else if (value > noddee->data){
      noddee = noddee->right;
    } else {
      noddee = noddee->left;
    }
  }
  if ((noddee->left == NULL) && (noddee->right == NULL)){
    if (noddee->parent->right->data == noddee->data){
      noddee->parent->right = NULL;
    } else {
      noddee->parent->left = NULL;
    }
  } else if (noddee->right == NULL){
    *noddee = *noddee->left;
  } else if (noddee->left == NULL){
    *noddee = *noddee->right;
  } else {
    node * search = noddee->right;
    int min_value;
    node *min;
    while (1){
      if (search == NULL) {
        break;
      } else {
        min = search;
        min_value = search->data;
        search = search->left;
      }
    }
    noddee->data = min->data;
    noddee = min;
    if ((noddee->left == NULL) && (noddee->right == NULL)){
      if (noddee->parent->right->data == noddee->data){
        noddee->parent->right = NULL;
      } else {
        noddee->parent->left = NULL;
      }
    } else if (noddee->right == NULL){
      *noddee = *noddee->left;
    } else {
      *noddee = *noddee->right;
    }
  }
  t->count--;
  return 0;
}
int deepness(struct node * noddee, int deep){
  if (noddee == NULL){
    return deep;
  }
  int d1 = deepness(noddee->left, deep + 1);
  int d2 = deepness(noddee->right, deep + 1);
  return (d1 > d2) ? d1 : d2;
}
void printNode(struct node * noddee, int current, int deep, int first){
  if (current == deep){
      if (first > 0){
        printf(" ");
      }
    if (noddee == NULL){
      printf("_");
    } else{
      printf("%d", noddee->data);
    } 
  } else if (noddee != NULL){
    printNode(noddee->left, current + 1, deep, first);
    printNode(noddee->right, current + 1, deep, first + 1);
  } else {
    printNode(noddee, current + 1, deep, first);
    printNode(noddee, current + 1, deep, first + 1);
  }
}
void print(struct node * noddee)
{
  int m = deepness(noddee, 0);
  for (int i = 1; i <= m; i++){
    printNode(noddee, 1, i, 0);
    printf("\n");
  }
}   
void printTree(struct tree * t)
{
    print(t->root);
}
void dump(struct node * noddee){
  if (noddee != NULL){
    printf("%d ", noddee->data);
    dump(noddee->left);
    dump(noddee->right);
  } else {
  }
}
int removeMin(node* noddee){
  if (noddee->left == NULL){
    noddee = noddee->right;
  }
  while(1){
    if (noddee->left == NULL){
      if ((noddee->left == NULL) && (noddee->right == NULL)){
        if (noddee->parent->right->data == noddee->data){
          noddee->parent->right = NULL;
        } else {
          noddee->parent->left = NULL;
        }
      } else if (noddee->right == NULL){
        *noddee = *noddee->left;
      } else {
        *noddee = *noddee->right;
      }
      return noddee->data;
    } else {
      noddee = noddee->left;
    }
  }
}
int rotateRight(tree * t, node *x){
  node * y = x->left;
  if ((y != NULL) && (x != NULL)){
    x->left = y->right;
  
    if (y->right != NULL){
      y->right->parent = x;
    }
    y->parent = x->parent;

    if (x->parent != NULL){
      if (x->parent->left == x){
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
    }
    t->root = y;
    y->right = x;
    x->parent = y;
    return 0;
  } else {
    return 1;
  }
}

int rotateLeft(tree * t, node *x){
  node * y = x->right;
  if ((y != NULL) && (x != NULL)){
    x->right = y->left;
    if (y->left != NULL){
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != NULL){
      if (x->parent->right == x){
        x->parent->right = y;
      } else {
        x->parent->left = y;
      }
    }
    t->root = y;
    y->left = x;
    x->parent = y;
    return 0;
  } else {
    return 1;
  }
}
int main(){

  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 4; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  for (int i = 0; i < 3; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  int m1;
  scanf("%d", &m1);
  struct node * noddee;
  noddee = malloc(sizeof * noddee);
  find(t, m1, noddee);
  if (noddee->parent != NULL){
    printf("%d ", noddee->parent->data);
  } else {
    printf("_ ");
  }
  if (noddee->left != NULL){
    printf("%d ", noddee->left->data);
  } else {
    printf("_ ");
  }
  if (noddee->right != NULL){
    printf("%d\n", noddee->right->data);
  } else {
    printf("_\n");
  }
  int m2;
  scanf("%d", &m2);
  int err = find(t, m2, noddee);
  if (err == 1){
    printf("-\n");
  } else {
    if (noddee->parent != NULL){
      printf("%d ", noddee->parent->data);
    } else {
      printf("_ ");
    }
    if (noddee->left != NULL){
      printf("%d ", noddee->left->data);
    } else {
      printf("_ ");
    }
    if (noddee->right != NULL){
      printf("%d\n", noddee->right->data);
    } else {
      printf("_\n");
    }
  }
  int m3;
  scanf("%d", &m3);
  _remove(t, m3);
  printTree(t);
  while (rotateLeft(t, t->root) != 1);
  printTree(t);
  while (rotateRight(t, t->root) != 1);
  printTree(t);
  printf("%d\n", t->count);
  printf("-\n");
  return 0;
}
