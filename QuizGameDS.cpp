#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct node{
	char corr_ans;
	int ques;
	int flag;
	struct node *next;	
};

struct NS_node{				//NS node : Name Score Node
	char *name;
	int score;
	struct NS_node *next;
    struct node *down;
}*start;
struct NS_node* head = NULL;


void insert(char* str) {
    struct NS_node* newNode = (struct NS_node*) malloc(sizeof(struct NS_node));
    newNode->name = (char*) malloc(strlen(str) + 1);
    strcpy(newNode->name, str);
    newNode->next = head;
    newNode->score = 0;
    newNode->down = NULL;
    head = newNode;
}
bool sortbysec(const pair<string,int> &a,const pair<string,int> &b)
{
    return (a.second > b.second);
}
int main(){
	int players, temp, ctr=0, pcount=1, pcounter=0, posi=1;
	char names[30], a1, a2, a3, a4, a5;
	cout<<"\t\t\t\t-------------------------------------\n";
	cout<<"\t\t\t\tDATA STRUCTURE QUIZ GAME\n";
	cout<<"\t\t\t\t-------------------------------------\n";
	cout<<"Hey! Welcome to DS quiz game.\nEnter the number of players: ";
	cin>>players;
	temp = players;
	cout<<"Enter names of all players: \n\n";
	while(players>0){
		cout<<"Enter Player "<<pcount<<":";
		cin>>names;
		insert(names);
		pcount++;
		players--;
	}
	struct NS_node* ptr;
    ptr= head;
	while(ptr!=NULL){			//check
		
		cout<<"\n\nLets Begin "<< ptr->name<<"!!"<<endl<<endl ;
		cout<< "Q1.  A procedure that calls itself is called: \nA. Illegal Call\nB. Reverse Polish\nC. Recursive\nD. None\nAnswer:" ;
		cin>>a1;
		cout<<"\n";
		struct node* ques1;
		ques1 = (struct node *)malloc(sizeof(struct node));
		ques1->ques = 1;
		ques1->corr_ans = NULL;
		ques1->next = NULL;
		ptr->down = ques1;

		if (a1=='c' || a1=='C'){
			ques1->flag = 1;
			ctr++;
			
		}
		else{
			ques1->flag = 0;
			ques1->corr_ans = 'C';
		}
		
		cout<< "Q2.  What data structure is used for depth first traversal of a graph?: \nA. Queue\nB. Stack\nC. List\nD. None\nAnswer:" ;
		cin>>a2;
		cout<<endl;
		struct node* ques2;
		ques2 = (struct node *)malloc(sizeof(struct node));
		ques2->next = NULL;
		ques1->next = ques2;
		ques2->ques = 2;
		ques2->corr_ans = NULL;
		if (a2=='b' || a2=='B'){
			ques2->flag = 1;
			ctr++;
			
		}
		else{
			ques2->flag = 0;
			ques2->corr_ans = 'B';
		}
		cout<< "Q3.  Which one of the below is not divide and conquer approach?: \nA. Insertion Sort\nB. Merge Sort\nC. Shell Sort\nD. Heap Sort\nAnswer:" ;
		cin>>a3;
		cout<<endl;
		struct node* ques3;
		ques3 = (struct node *)malloc(sizeof(struct node));
		ques3->next = NULL;
		ques2->next = ques3;
		ques3->ques = 3;
		ques3->corr_ans = NULL;
		if (a3=='b' || a3=='B'){
			ques3->flag = 1;
			ctr++;
		}
		else{
			ques3->flag = 0;
			ques3->corr_ans = 'B';
		}
		cout<< "Q4.  Program with highest run-time complexity is: \nA. Tower of Hanoi\nB. Fibonacci Series\nC. Prime Number Series\nD. None of the above\nAnswer:" ;
		cin>>a4;
		cout<<endl;
		struct node* ques4;
		ques4 = (struct node *)malloc(sizeof(struct node));
		ques4->next = NULL;
		ques3->next = ques4;
		ques4->ques = 4;
		ques4->corr_ans = NULL;
		if (a4=='a' || a4=='A'){
			ques4->flag = 1;
			ctr++;
			
		}
		else{
			ques4->flag = 0;
			ques4->corr_ans = 'A';
		}
		cout<< "Q5.  Stack is used for: \nA. CPU Resource Allocation\nB. Breadth First Traversal\nC. Recursion\nD. None of the above\nAnswer:" ;
		cin>>a5;
		cout<<endl;
		struct node* ques5;
		cout<<"-------------------------------------------------------------------------"<<endl;
		ques5 = (struct node *)malloc(sizeof(struct node));
		ques5->next = NULL;
		ques4->next = ques5;
		ques5->ques = 5;
		ques5->corr_ans = NULL;
		if (a5=='c' || a5=='C'){
			ques5->flag = 1;
			ctr++;
			
		}
		else{
			ques5->flag = 0;
			ques5->corr_ans = 'C';
		}
		ptr->score = ctr;
		ctr = 0;
		ptr=ptr->next;
		
    }
    struct NS_node* save = head;
    cout<<"--------------"<<endl;
    cout<<"RESULTS:"<<endl;
    while(save!=NULL){
    	
    	cout<<"--------------"<<endl;
	    cout<<"\nName: "<<save->name<<"\n";
	    cout<<"Score: "<<save->score<<"\n"<<endl;
	    if (save->score != 5){	
	        struct node *movedown;
	        movedown = save->down;
	        cout<<"Corrections: ";
    	    while(movedown!=NULL){
	    	    if(movedown->flag == 0)
		        {
    	    	    cout<<"\nQuestion "<<movedown->ques<<":";
	    	        cout<<movedown->corr_ans;
		        }
		        
	            movedown=movedown->next;
	        }
        }
        save=save->next;
        cout<<endl;
    }
    //getting all the names
    ptr=head;
    string namez[1000];
    for(int i=0;i<temp;i++){
        namez[i]=ptr->name;
        ptr=ptr->next;
    }
   
    ptr=head;
    int finalScore[temp];
    for(int i=0;i<temp;i++){
        finalScore[i]=ptr->score;
        ptr=ptr->next;
    }
    vector< pair <string, int> > vect;
    for (int i=0; i<temp; i++)
        vect.push_back( make_pair(namez[i],finalScore[i]) );

    sort(vect.begin(), vect.end(), sortbysec);
    cout<<endl;
    cout << "\nLEADERBOARD: \n"<<endl ;
    for (int i=0; i<temp; i++){
        cout <<posi<<". "<< vect[i].first << " "<< vect[i].second << endl;
        posi++;
    }
    return 0;

}
