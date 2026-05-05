#include<iostream>
using namespace std;

struct Node{
    string word, meaning;
    Node* left;
    Node* right;
};

// Create new node
Node* create(string w, string m){
    Node* temp = new Node();
    temp->word = w;
    temp->meaning = m;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert node
Node* insert(Node* root, string w, string m){
    if(root == NULL)
        return create(w, m);

    if(w < root->word)
        root->left = insert(root->left, w, m);
    else if(w > root->word)
        root->right = insert(root->right, w, m);

    return root;
}

// Display ascending (Inorder)
void displayAsc(Node* root){
    if(root){
        displayAsc(root->left);
        cout << root->word << " : " << root->meaning << endl;
        displayAsc(root->right);
    }
}

// Display descending (Reverse inorder)
void displayDesc(Node* root){
    if(root){
        displayDesc(root->right);
        cout << root->word << " : " << root->meaning << endl;
        displayDesc(root->left);
    }
}

// Search with comparison count
Node* search(Node* root, string key, int &count){
    if(root == NULL) return NULL;

    count++;

    if(key == root->word)
        return root;
    else if(key < root->word)
        return search(root->left, key, count);
    else
        return search(root->right, key, count);
}

// Update meaning
void update(Node* root, string key){
    int count = 0;
    Node* temp = search(root, key, count);

    if(temp){
        cout << "Enter new meaning: ";
        cin >> temp->meaning;
        cout << "Updated\n";
    }
    else{
        cout << "Word not found\n";
    }
}

// Max comparisons (height of left side)
int maxComparisons(Node* root){
    int count = 0;
    while(root){
        count++;
        root = root->left;
    }
    return count;
}

// Main
int main(){
    Node* root = NULL;
    int choice;
    string word, meaning;

    do{
        cout << "\n1.Insert\n2.Display Asc\n3.Display Desc\n4.Search\n5.Update\n6.Max Comparisons\n7.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter word & meaning: ";
                cin >> word >> meaning;
                root = insert(root, word, meaning);
                break;

            case 2:
                displayAsc(root);
                break;

            case 3:
                displayDesc(root);
                break;

            case 4:{
                int count = 0;
                cout << "Enter word: ";
                cin >> word;
                Node* res = search(root, word, count);
                if(res)
                    cout << "Found, Comparisons: " << count;
                else
                    cout << "Not Found";
                break;
            }

            case 5:
                cout << "Enter word: ";
                cin >> word;
                update(root, word);
                break;

            case 6:
                cout << "Max Comparisons: " << maxComparisons(root);
                break;
        }

    }while(choice != 7);

    return 0;
}