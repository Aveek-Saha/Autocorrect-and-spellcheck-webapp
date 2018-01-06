#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 struct node{

        char info;
        char Word[100];
        struct node* ptrs[256];
};

void init(struct node*n)
{
  strcpy(n->Word,"");
  n->info =0;
  int i;
  for(i=0;i<256;i++)
   {
    (n->ptrs)[i] = NULL;
   }
}

void insertword(char *word,int pos,struct node * root){
    if(strlen(word)==pos){
        strcpy(root->Word,word);
        return;
    }
    if( root-> ptrs[word[pos]]==NULL ){
        struct node *newnode = malloc(sizeof(struct node));
        init(newnode);
        newnode->info=word[pos];
        root->ptrs[word[pos]]=newnode;
        insertword(word,pos+1,root->ptrs[word[pos]]);
    }
    else
        insertword(word,pos+1,root->ptrs[word[pos]]);
}

void find(char *key,int pos, struct node * root, int * found){
    if((strcmp(key, root->Word)!=0) && (root->ptrs[key[pos]] != NULL))
        find(key,pos+1,root->ptrs[key[pos]], found);
    else if(strcmp(key, root->Word)==0){
        printf("The spelling of the word %s is correct \n" ,root->Word);
        *found = 1;
    }
}

void printall(struct node * root, int * number_of_words){
    if (*number_of_words >= 10)
        return;
    int i;
    for(i=0;i<256;i++)
        if(root->ptrs[i]!=NULL){
            printall(root->ptrs[i], number_of_words);
        }
    if(strlen(root->Word)){
        (*number_of_words) += 1;
        printf("%s\n" , root->Word);
    }
}

void suggest(char *key,int pos, struct node * root, int * number_of_words){
    if((key != root->Word) && (root->ptrs[key[pos]] != NULL)){
            suggest(key,pos+1,root->ptrs[key[pos]], number_of_words);
    }
    else{
            printall(root, number_of_words);
    }
}

void main(int argc, char *argv[]){
    int spell_check_mode = atoi(argv[2]);
    char word[100];

    FILE*fp = fopen("wordlist.txt","r");
    char key[30];
    struct node *root = malloc(sizeof(struct node));
    init(root);
    int count = 0;
    while(!feof(fp) && count < 375000){
        fscanf(fp,"%s",word);
        insertword(word,0, root);
        count++;
    }
    fclose(fp);

    FILE*fp2 = fopen("wordlist_important.txt","r");
    struct node *root2 = malloc(sizeof(struct node));
    init(root2);
    count = 0;
    while(!feof(fp2) && count < 1001){
        fscanf(fp,"%s",word);
        insertword(word,0, root2);
        count++;
    }
    fclose(fp2);

    int number_of_words = 0;
    int found = 0;
    if (spell_check_mode){
        find(argv[1], 0, root, &found);
        if (!found){
            find(argv[1], 0, root2, &found);
        }
        if (!found){
            printf("The spelling is incorrect \n");
        }
    }
    if (!spell_check_mode || !found){
        printf("Suggestions :\n");
        suggest(argv[1], 0, root2, &number_of_words);
        suggest(argv[1], 0, root, &number_of_words);
    }
}
