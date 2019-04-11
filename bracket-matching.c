//Stack's application
//No comment yet. I will add comment when I have time

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct _node{
	char num;
	struct _node* link;
}node;

int pop(node** top);
void push(node** top, char num);
void print(node* top);
void print_opr(node** top, char* opr);
int check_priority(char c);

int main(void){
	char num;
	node* top = NULL;
	
	char* opr = "((3+4)*5-6)/5";
	
	print_opr(&top, opr);
}

void push(node** top, char num){
	node* nnode = (node*)malloc(sizeof(node));
	nnode->num = num;
	nnode->link = *top;
	*top = nnode;
}

int pop(node** top){
	node* tmp = *top;
	char pop_v = (*top)->num;
	*top = (*top)->link;
	free(tmp);
	return pop_v;
}

void print(node* top){
	while(top != 0){
		printf("%c-->",top->num);
		top = top->link;
	}
	puts("bottom");
}

void print_opr(node** top, char* opr){ 
	int i = 0;
	int cout = 1;
	while(opr[i] != '\0'){
		if(!isdigit(opr[i]) && ((check_priority(opr[i]) - 1) == 0)){		//cai dieu kien nay kha la roi mat
			push(top,opr[i]);
			cout = 0;
		}
		else if(!isdigit(opr[i]) && ((check_priority(opr[i]) - 1) == 1)){
			if(cout != 0){
				push(top,opr[i]);
				cout = 0;
			}
			else{
				while(*top != NULL && (*top)->num != 40){				//sai rat nhieu cho nay vi nguyen ban laf (*top)->link != NULL
					printf("%c ",pop(top));
				}
				push(top,opr[i]);
			}//end inner else
		}//end else if
		else if(!isdigit(opr[i]) && (opr[i] >= 40)){
			if(opr[i] == 41){
				while((*top)->num != 40)
					printf("%c ", pop(top));
				pop(top);
			}
			else{
				push(top,opr[i]);
			}
		}
		else
			printf("%c ", opr[i]);
		i++;
	}//end while
		while(*top != NULL){
			printf("%c ",pop(top));
		}
}


int check_priority(char c){
	switch(c){
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 1;
		case '/':
			return 1;
		default:
			return 0;
	}
}
