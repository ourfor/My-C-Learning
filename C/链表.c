#include<stdio.h>

struct LinkList{
  double data;
  char sex;
  char name;
  struct LinkList * next;
};

int main()
{
  int i;
  struct LinkList * head,*p;
  struct LinkList a,b,c;
  head=&a;
  a.next=&b;
  b.next=&c;
  c.next=NULL;
  a={2017 '男' '李明'},b={2023 '女' '唐蔚'},c={2109 '男' '赵四'};
  for(p=head;p!=NULL;p=p->next)
  {
    printf("%d%s%s\n",p->data,p->sex,p->name);
  }
  return 0;
}
