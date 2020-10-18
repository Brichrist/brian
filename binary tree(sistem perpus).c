#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

void clrscr(){
	system("@cls||clear");
}

struct node{
	struct node *left;
	char book_name[100];
	int book_number;
	struct node *right;
};

struct node *root=NULL;

void insert(){
	struct node *ptr,*node;
	struct node *new_node=(struct node*)malloc(sizeof(struct node)); 
	int BookNumber;
	char BookName[100];
	do{
		printf("Input Book's Name [3..50]:");fflush(stdin);
		scanf("%[^\n]",&BookName);
	}while(strlen(BookName)<3||strlen(BookName)>50);
	do{
		printf("Input Book's Number [1..100]:");
		scanf("%d",&BookNumber);
	}while(BookNumber<1||BookNumber>100);
	strcpy(new_node->book_name,BookName);
  	new_node->book_number=BookNumber; 
	new_node->right=NULL;
	new_node->left=NULL;
	if(root==NULL){
		root=new_node;
		root->right=NULL;
		root->left=NULL;
		printf("\n---Add Book Success---\n");
	}	
	else{
		int count=1;
		ptr=root;
		char milih[10];
		while(ptr!=NULL){
			node=ptr;
			do{
				printf("Will He Be in 'left' or 'right' %s ?: ",ptr->book_name);
				fflush(stdin);
				scanf("%s",&milih);
			}while(strcmp("left",milih)!=0&&strcmp("right",milih)!=0);
			if(strcmp("left",milih)==0){
				ptr=ptr->left;
			}
			else{
				ptr=ptr->right;
			}
			count++;		
		}
		if(count>4){
			printf("---Maximum Tree Level is 4!!---\n");
		}
		else{
			if(strcmp("left",milih)==0){
				node->left=new_node;
			}
			else{
				node->right=new_node;
			} 
			printf("\n---Add Book Success---\n");	
		}
	}
}

void *display(struct node *root){
	if(root!=NULL){
		display(root->left);
		printf("\n-[%s]",root->book_name);
		printf("\t\t\t([%d])",root->book_number);
		display(root->right);
	}
	return root;
}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->book_number);
		inorder(root->right);
	}
}

void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->book_number);
	}
}

void preorder(struct node *root){
	if(root!=NULL){
		printf("%d\t",root->book_number);
		preorder(root->left);
		preorder(root->right);
	}
}

void *deleteTree(struct node* root)  { 
    if(root!=NULL){
    	deleteTree(root->left); 
   	 	deleteTree(root->right); 
    	free(root); 
	}
	return root;
}  

void *Find(struct node*root, int book_number){
   	if(root==NULL){
    	return NULL;
   	}
  	if(book_number>root->book_number){
    	return Find(root->right, book_number);
   	}
   	else if(book_number<root->book_number){
    	return Find(root->left, book_number);
   	}
   	else{
    	return root;
   	}
}

void *Delete(struct node *root, int book_number){
    struct node *temp;
    if(root==NULL){
        printf("---The Book Doesn't Exist---");
    }
    else if(book_number<root->book_number){
        root->left=Delete(root->left, book_number);
    }
    else if(book_number>root->book_number){
        root->right=Delete(root->right, book_number);
    }
    else{
    	if(root->right && root->left){
        	temp=Find(root->right,book_number);
            root->book_number=temp->book_number; 
            root->right=Delete(root->right,temp->book_number);
        }
        else{
            temp=root;
            if(root->left==NULL){
             	root=root->right;
			}   
            else if(root->right==NULL){
             	root=root->left;
			} 
            free(temp); 
        }
        printf("---The Book Has Been Removed---");
    }
    return root;
}


int main(){
	int pilih;
	do{
		clrscr();
		printf("PINK LIBRARY\n");
		printf("*************\n\n");
		printf("1. View All Book\n");
		printf("2. Add Book\n");
		printf("3. Remove Book\n");
		printf("4. Inorder, Preorder, Postorder\n");
		printf("5. Exit and Remove All\n");
		do{
			printf(">> Input choice :");
			scanf("%d",&pilih);
		}while(pilih<1||pilih>5);
		switch(pilih){
			case 1:{
				clrscr();
				if(root==NULL){
					printf("---There is No Book in The Tree---");
				}
				else{
					printf("Book List:\n\n");
					root=display(root);
				}
				getch();
				break;
			}
			case 2:{
				clrscr();
				insert();
				getch();
				break;
			}
			case 3:{
				if(root==NULL){
					printf("---There is No Book in The Tree---");
				}
				else{
					int book_number;
					do{
						printf("Input Book's Number[1..100]: ");
   						scanf("%d",&book_number);
					}while(book_number<1||book_number>100);
					root=Delete(root,book_number);
					
					root=display(root);
				}
				getch();
				break;
			} 
			case 4:{
				if(root!=NULL){
					printf("Preorder : \n");
					preorder(root);
					printf("\nInorder : \n");
					inorder(root);
					printf("\nPostorder : \n");
					postorder(root);
				}
				else{
					printf("--- There is No Book in The Tree ---");
				}
				getch();
				break;
			}
			case 5:{
				if(root==NULL){
					printf("---There is No Book in The Tree---");
				}
				else{
					root=deleteTree(root);
				}
				break;
			}
		}
	}while(pilih!=5);
}
