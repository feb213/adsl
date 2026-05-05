#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
};

Node* createNode(char val){
	Node* temp = new Node();
	temp-> data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool isOperator(char c){
	return(c == '+' || c == '-' || c == '*'|| c == '/');
}

Node* buildExpTree(string exp){
	stack<Node*> stk;
	
	for(int i = exp.length() - 1 ; i >= 0 ; i--){
	    Node* temp = createNode(exp[i]);
        
        
        if(!isOperator(exp[i])){
            stk.push(temp);
        }
        else{
            temp->left = stk.top(); stk.pop();
            temp->right = stk.top(); stk.pop();
            stk.push(temp);		
        
        }
    }
    return stk.top();
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postOrder(Node* root){
	if(root == NULL) return;
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		Node* temp = s1.top(); s1.pop();
		s2.push(temp);

		if(temp->left) s1.push(temp->left);
		if(temp->right) s1.push(temp->right);
	}

	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}

int main(){
	string exp;
	Node* root = NULL;
	int choice = 0;
	
	while(choice != 5){
		cout<<"\n1.Enter Prefix Expression\n2.Build treee\n3.Inorder\n4.postorder\n5.Exit";
		cout<<"\nEnter choice:";
		cin>>choice;

		switch(choice){
			case 1: 
				cout<<"enter prefix:";
				cin>>exp;
				break;
			case 2:
				root = buildExpTree(exp);
				cout<<"tree created\n";
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postOrder(root);
				break;
			case 5:
				cout<<"Exit \n";
		}	

	}
}