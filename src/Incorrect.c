#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char word[30];
	int count;
	struct node * next;
};

struct pqueue{
	struct node * front;
	struct node * last;
	int length;
};

struct pqueue * create_queue(){
	struct pqueue * PQ = (struct pqueue *)malloc(sizeof(struct pqueue));
	PQ -> front = NULL;
	PQ -> last = NULL;
	PQ -> length = 0;
	return PQ;
};

void queue_insert(struct pqueue* PQ, char * word, int count_m){
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	strcpy(new_node -> word, word);
	new_node -> count = count_m;
	new_node -> next = NULL;
	if (PQ -> length == 0){
		PQ -> front = new_node;
		PQ -> last = new_node;
		PQ -> length = 1;
		return;
	}
	PQ -> last -> next = new_node;
	PQ -> last = new_node;
	(PQ -> length)++;

}

void pq_insert(struct pqueue * PQ, char * word){
	struct node * p = PQ -> front;
	struct node * prev = NULL;
	while (p != NULL && (strcmp(p -> word, word) != 0)){
		prev = p;
		p = p -> next;
	}
	if (p == NULL){
		queue_insert(PQ, word, 1);
		return;
	}
	(p -> count)++;
	if (prev == NULL)
		return;
	prev -> next = p -> next;
	struct node * f = PQ -> front;
	prev = NULL;
	while (f -> count > p -> count){
		prev = f;
		f = f -> next;
	}
	if (prev == NULL){
		p -> next = PQ -> front;
		PQ -> front = p;
		return;
	}
	if (f == NULL){
		queue_insert(PQ, word, p -> count);
		return;
	}
	p -> next = prev -> next;
	prev -> next = p;

}

void display(struct pqueue * PQ){
	int i;
	struct node * p = PQ -> front;
	for (i = 0; i < PQ -> length; i++){
		printf("%s\n", p -> word);
		p = p -> next;
	}
}

void write_file(struct pqueue * PQ, FILE * fp){
	struct node * p = PQ -> front;
	char line[35];
	char c[5];
	while (p != NULL){
		strcpy(line, "");
		strcat(line, p -> word);
		strcat(line, ",");
		sprintf(c, "%d", p -> count);
		strcat(line, c);
		strcat(line, "\n");
		fwrite(line, 1, strlen(line), fp);
		p = p -> next;
	}
	fwrite("END\n", 1, 4, fp);
}

int main(int argc, char *argv[]){
	FILE * fp = fopen("IncorrectWords.txt", "r");
	char line[35];
	char word[30];
	int count_misspell;
	struct pqueue * PQ = create_queue();
	while (1){
		fgets(line, 35, fp);
		char *token = strtok(line, ",");
		strcpy(word, token);
		token = strtok(NULL, ",");
		if (strcmp(word, "END\n")==0)
			break;
		count_misspell = atoi(token);
		queue_insert(PQ, word, count_misspell);
	}
	fclose(fp);
	pq_insert(PQ, argv[1]);
	display(PQ);

	FILE * fp2 = fopen("IncorrectWords.txt", "w");
	write_file(PQ, fp2);
	fclose(fp2);


}
