//============================================================================
// Name        : LinkedList.cpp
// Author      : karthika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};
int count = 1;

struct Node* createNewNode(int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	count++;
	return newNode;
}
struct Node* insertNodeAtTop(Node *head, int data){
	Node *newNode = new Node;
	newNode = createNewNode(data);

	newNode->next = head;
	cout<<"New node added as head : "<<newNode->data<<endl;
	return newNode;
}
struct Node* insertNodeAtEnd(Node *head, int data){
	Node *temp = new Node;

	Node *newNode = new Node;
	newNode = createNewNode(data);

	//point head to new node
	if (head->next == NULL)
		head->next = newNode;
	else
		temp = head;

    //Traversing nodes
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	cout << "Added at End : " <<newNode->data << endl; return head;
}
struct Node* insertAtNPos(Node *head, int pos, int data){
	int index = 1;
	Node *temp = new Node;
	temp = head;

	Node *newNode = new Node;
	newNode = createNewNode(data);

	while(pos-1 > index){
		temp = temp->next;
		index++;
	}
	newNode->next = temp->next;
	if (pos == 1){
		count--;
		head = insertNodeAtTop(head, data);
	}
	else
		temp->next = newNode;
	cout<<"Node added at position "<<pos<<endl;
	return head;
}
void display(Node *head){
	Node *temp = new Node;
	temp = head;
	int i = 1;
	do{
		cout << "Node " << i << ": " << temp->data << " "<<temp->next<< endl;
		temp = temp->next;
		i++;
	}while(temp != NULL);
}
struct Node* deleteNodeAtHead(Node *head){
	Node *temp = new Node;
	temp = head->next;
	head = temp;
	cout << "Deleted head" <<endl;
	return head;
}
struct Node* deleteNodeAtEnd(Node *head){
	Node *temp = new Node;
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
		if (temp->next->next == NULL){
			temp->next = NULL;
			break;
		}
	}
	cout << "Deleted End Node"<<endl;
	return head;
}
struct Node* deleteNodeAtNPos(Node *head, int pos){
	/*int index = 1;
	Node *temp = new Node;
	temp = head;
	while(pos > index && temp->next != NULL){

		if (pos == index+1){
			cout<<"Deleting data : "<<temp->next->data << endl;
			temp->next = temp->next->next;
			//delete temp;
			break;
		} else{
			temp = temp->next;
			index++;
		}
	}
	return head;*/
	//Starting with position 0, head has data value
	int index = 0;
		Node *temp = new Node;
		temp = head;
		display(head);
		while(pos >= index && temp->next != NULL){
	        if(pos == index){
	            head = temp->next;
	            display(head);

	            break;
	        }
			else if (pos == index+1){
				temp->next = temp->next->next;
				break;
			} else{
				temp = temp->next;
				index++;
			}
		}
		return head;
}

void reversePrint(Node* head){
	Node *temp = new Node;
	temp = head;
	if(temp == NULL) return;
	else
		reversePrint(temp->next);
	cout << temp->data <<" ";
}
struct Node* reverseList(Node* head){
	Node *temp = new Node;
	Node *prev = new Node;
	Node *curr = new Node;
	prev = NULL;
	temp = head;
	curr = head->next;
	//head->next = NULL;
	while (temp->next != NULL){
		prev = temp;
		temp = temp->next;
		curr = curr->next;
		cout <<"*********" << endl;
		cout << prev->data <<" "<<temp->data << " "<<curr->data<<endl;
	}
	return head;
}
//n th node value
int GetNode(Node *head,int positionFromTail)
{
    Node *temp = new Node;
    temp = head;
    int i = 1, print;
    while(temp->next != NULL){
        temp = temp->next;
        i++;
    }
    //print = abs(i - positionFromTail);
    temp = head;
    i = 1;
    while(i < print){
        temp = temp->next;
        i++;
    }
    return temp->data;
}
Node* MergeLists(Node *headA, Node* headB)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
  	Node *newNode = new Node;
	newNode->next = NULL;

    Node *result = new Node;
    result->next = NULL;
    if(headA->next == NULL || headB->next == NULL)
    	temp1 = headA; temp2 = headB;
    if(headA->next != NULL && headB->next != NULL){
        if (headA->next->data > headB->next->data){
            temp1 = headB; temp2 = headA;
        } else{
             temp1 = headA; temp2 = headB;
        }
    }
        bool flag1 = true, flag2 = true;
        if(temp1->next != NULL){
            temp1 = temp1->next;
        } else
        	flag1 = false;
        if(temp2->next != NULL){
            temp2 = temp2->next;
        } else
           	flag2 = false;
        if(flag1 == true && flag2 == true)
			do{
				do{
					if(temp1->data <= temp2->data)
						insertNodeAtEnd(result, temp1->data);
					else
						break;
					temp1 = temp1->next;
					if(temp1 == NULL){
						flag1 = false;
					}
				}while(temp1 != NULL);
				if(flag1 == true)
					do{
						if(temp1->data >= temp2->data)
							insertNodeAtEnd(result, temp2->data);
						else
							break;
						temp2 = temp2->next;
						if(temp2 == NULL)
							flag2 = false;
					}while(temp2 != NULL);
			}while(temp1 != NULL && temp2 != NULL);
        if(flag1 == false && flag2 == false)
        	return result;
        else if(flag1 == false)
        	do{
        		insertNodeAtEnd(result, temp2->data);
        		temp2 = temp2->next;
        	}while(temp2 != NULL);
        else if (flag2 == false)
        	do{
        		insertNodeAtEnd(result, temp1->data);
        		temp1 = temp1->next;
        	}while(temp1 != NULL);
    return result;
}
int CompareLists(Node *headA, Node* headB)
{
    int result = 0;
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = headA; temp2 = headB;
    if(temp1->next == NULL && temp2->next == NULL)
        result = 1;
    else if(temp1->next == NULL || temp2->next == NULL)
        result = 0;
    else{
    	temp1 = temp1->next;
    	temp2 = temp2->next;
        do{
            if(temp1->data == temp2->data)
                result = 1;
            else{
                result = 0;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        } while(temp1 != NULL && temp2 != NULL);
        if(temp1 != NULL || temp2 != NULL)
        	result = 0;
    }
    return result;
    /*****When head has value
      int result = 0;
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = headA; temp2 = headB;
    if(temp1 == NULL && temp2 == NULL)
        result = 1;
    else if(temp1 == NULL || temp2 == NULL)
        result = 0;
    else{
        if(temp1->next != NULL && temp2->next != NULL){
    	   temp1 = temp1->next;
    	   temp2 = temp2->next;
           do{
                if(temp1->data == temp2->data)
                    result = 1;
                else{
                    result = 0;
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            } while(temp1 != NULL && temp2 != NULL);
            if(temp1 != NULL || temp2 != NULL)
        	   result = 0;
        } else{
            result = 0;
        }
    }
    return result;
    */
}
int HasCycle(Node* head)
{
    Node *temp = new Node;
    temp = head;
    int result = 0;
    if(temp == NULL)
        result = 0;
    else{
        /*do{
            if(temp->data == -99999){
                result = 1;
                break;
            }
            temp->data = -99999;
            temp = temp->next;
        }while(temp != NULL);*/
        int i = 1;
        do{
            if(i > 100){
                result = 1;
                break;
            }
            temp = temp->next;
            i++;
        }while(temp != NULL);
    }
    return result;
}
Node* RemoveDuplicates(Node *head)
{
    Node *temp = new Node;
    temp = head;
    int v[100];
    int i = 1, data; bool flag = false;
    if(temp == NULL || temp->next == NULL)
        return head;
    else if(temp->next != NULL){
        v[0] = temp->data;
        do{
            flag = false;
            if(temp != NULL){
                data = temp->next->data;
                for (int j = 0; j < i; j++){
                    if(v[j] == data){
                        temp->next = temp->next->next;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == false){
                if(temp->next != NULL){
                    temp = temp->next;
                    v[i] = temp->data;
                    i++;
                }
            }
        }while(temp->next != NULL );
    }
    return head;
}
int main() {

	Node *head = new Node;
	head->next = NULL;
    Node *head1 = new Node;
    head1->next = NULL;

	head = insertNodeAtEnd(head, 8);
	//head = insertNodeAtEnd(head, 5);
	//display(head);
	//head = insertNodeAtEnd(head, 8);

	head1 = insertNodeAtEnd(head1, 9);
	//head1 = insertNodeAtEnd(head1, 5);
	//head1 = insertNodeAtEnd(head1, 6);

/*	head = insertNodeAtTop(head,3);
	int n = 2;
	if(n<=count && n>0)
		head = insertAtNPos(head, n, 18);
	else
		cout << "Cannot be added at this position, try another" <<endl;
	display(head);
	reversePrint(head);
	head = reverseList(head);
	cout<<GetNode(head, 2);*/
	/*cout <<"Total = "<< count << endl;
    n = 4;
	head = deleteNodeAtNPos(head, n);
	head = deleteNodeAtHead(head);
	head = deleteNodeAtEnd(head);

	display(head);*/
	//head = deleteNodeAtNPos(head, 0);
	Node *result = new Node;
	result->next = NULL;

	//result = MergeLists(head, head1);
	//display(result);
	int sameOrNot = CompareLists(head, head1);
	cout << sameOrNot << endl ;
	return 0;
}
