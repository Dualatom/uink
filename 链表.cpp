#include<bits/stdc++.h>
using namespace std;
#define OK 1
typedef int DataType;
typedef struct Node{
	DataType data;
	struct Node *next;
}Node,*LinkList;

void CreateList_L(LinkList &L, int n){
	L=new Node;
	L->next=NULL;
	LinkList p;
	for(int i=0;i<n;i++){
		p=new Node;
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
    }
}
int GetElem_L(LinkList L, int a, DataType &e){
	LinkList p=L;
	int j=0;
	if(a<=0)return 0;
	while(p->next&&j<a)p=p->next,j++;
	if(j==a){
		e=p->data;
		return OK;
	}
	return 0;
}
int ListInsert_L(LinkList L, int a, DataType e){
	LinkList p=L;
	int j=0;
	while(p&&j<a-1){
		p=p->next;
		j++;
	}
	if(!p||j>a-1)return 0;
	LinkList q=new Node;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK;
}
int ListDelete_L(LinkList L, int a, DataType &e){
	LinkList p=L,q;
	int j=0;
	while(p->next&&j<a-1){
		p=p->next;j++;
	}
	if(!p->next||j>a-1)return 0;
	q=p->next;
	e=q->data;
	p->next=q->next;
	delete q;
	return OK;
}
int ShowList_L(LinkList L){
	if(!L->next)return 0;
	for(LinkList p=L->next;p;p=p->next){
		if(p!=L->next)printf(" ");
		printf("%d",p->data);
	}
	printf("\n");
	return 1;
}
int main() {
int n; // ³õÊ¼Ê±ÔªËØµÄÊýÄ¿
int m; // Ö¸ÁîµÄÊýÄ¿
char strInst[30]; // ´æ´¢Ö¸Áî:instruction
int a; // ´æ´¢Î»ÖÃÊý¾Ý
LinkList L; // Á´±í
int e; // ¶¨Òå½Úµã£¬ÓÃÀ´´æ´¢»ñÈ¡µÄ½Úµã»òÕßÉ¾³ýµÄ½Úµã
scanf("%d", &n); // ¶ÁÈëÔªËØµÄÊýÄ¿
CreateList_L(L, n); // ´´½¨Á´±í
scanf("%d", &m); // ¶ÁÈ¡Ö¸ÁîµÄÊýÄ¿
while(m--) { // ×ö m ´ÎÑ­»·
scanf("%s", strInst); // ¶ÁÈ¡Ö¸Áî
if(strcmp(strInst,"get") == 0) { // Èç¹ûÊÇÐèÒª»ñÈ¡Ä³¸öÔªËØ
scanf("%d", &a); // ¶ÁÈ¡ÔªËØµÄÎ»ÖÃ
if(GetElem_L(L, a, e) == OK) { // Èç¹û»ñÈ¡ÔªËØ³É¹¦
printf("%d\n", e); // Êä³öÔªËØµÄÖµ
} else { // Èç¹û»ñÈ¡ÔªËØÊ§°Ü
puts("get fail"); // Êä³ö»ñÈ¡ÔªËØµÄ³ö´íÐÅÏ¢
}
} else if(strcmp(strInst, "insert") == 0) { // Èç¹ûÊÇ²åÈëÄ³¸öÔªËØ
scanf("%d%d", &a, &e); // »ñÈ¡´ý²åÈëµÄÎ»ÖÃÒÔ¼°´ý²åÈëµÄÖµ
if(ListInsert_L(L, a, e) == OK) { // Èç¹û²åÈëÔªËØ³É¹¦
puts("insert OK"); // Êä³ö²åÈë³É¹¦µÄÐÅÏ¢
} else {
puts("insert fail"); // ·ñÔòÊä³ö²åÈëÊ§°ÜµÄÐÅÏ¢
}
} else if(strcmp(strInst, "delete") == 0) { // Èç¹ûÊÇÉ¾³ýÄ³¸öÔªËØ
scanf("%d",&a); // »ñµÃ´ýÉ¾³ýÔªËØµÄÎ»ÖÃ
if(ListDelete_L(L, a, e) == OK) { // Èç¹ûÉ¾³ý³É¹¦
puts("delete OK"); // Êä³öÉ¾³ý³É¹¦µÄÐÅÏ¢
} else {
puts("delete fail"); // ·ñÔòÊä³öÉ¾³ýÊ§°ÜµÄÐÅÏ¢
}
} else if(strcmp(strInst, "show") == 0) { // Èç¹ûÊÇÏÔÊ¾Á´±í
if(ShowList_L(L) == 0) { // Èç¹ûÁ´±íÎª¿Õ
puts("Link list is empty"); //ÏÔÊ¾Á¿±íÎª¿ÕµÄÐÅÏ¢
}
}
}
return 0;
}
