#include <iostream>
#include<vector>
#include<stack>
#include<cstdlib>
#include<ctime>

using namespace std;


struct node{
	int x,y;
	vector<node*> child;
	node *prev;
};


node* getNode(int x,int y){
	node *newNode = new node();
	newNode->x=x;
	newNode->y=y;
	return newNode;
}


node *traverse_tree(struct node* root,int randx, int randy) 
{ 
	int mindistance = INT_MAX;
	node *temp;
	
    // Stack to store the nodes 
    stack<node*> nodes; 
  
    // push the current node onto the stack 
    nodes.push(root); 
  
    // loop while the stack is not empty 
    while (!nodes.empty()) { 
  
        // store the current node and pop it from the stack 
        node* curr = nodes.top(); 
        nodes.pop(); 
  
        // current node has been travarsed 
        if( (abs(randx-curr->x ) + abs(randy-curr->y) )<=mindistance ){
        mindistance = (abs(randx-curr->x ) + abs(randy-curr->y)) ;               //mindistance = (abs(tc[0]-rval[i]) + abs(tc[1]-cval[i]));
  			temp = curr;
			  }
  
        // store all the childrens of current node from 
        // right to left. 
        vector<node*>::iterator it = curr->child.end(); 
  
        while (it != curr->child.begin()) { 
            it--; 
            nodes.push(*it); 
        } 
    }
    return temp;
} 







bool check_tree(struct node* root,int x,int y) 
{ 
    // Stack to store the nodes 
    stack<node*> nodes; 
  
    // push the current node onto the stack 
    nodes.push(root); 
  
    // loop while the stack is not empty 
    while (!nodes.empty()) { 
  
        // store the current node and pop it from the stack 
        node* curr = nodes.top(); 
        nodes.pop(); 
  
        // current node has been travarsed 
        if(curr->x==x&&curr->y==y)
			return true; 
  
        // store all the childrent of current node from 
        // right to left. 
        vector<node*>::iterator it = curr->child.end(); 
  
        while (it != curr->child.begin()) { 
            it--; 
            nodes.push(*it); 
        } 
    }
	
	return false; 
} 















int main() {
	int n=10;	//limit coordinate to nxn on positive side
	
	vector<int> obx;	//obstacles x coordinates 
	vector<int> oby;	//obstacles y
	
	int gx,gy;
	srand(time(0));
	
	
//creating start node(root node)
	node *startptr = getNode(0,0);
	cout<<"enter coordinates(x,y) of start node and goal node"<<endl;
	scanf("%d %d",&startptr->x,&startptr->y);
	startptr->prev=NULL;

// storing goal coordinates in variables
	scanf("%d %d",&gx,&gy);

// choosing obstacles
int a,b,zx;
cout<<"enter number of obstables"<<endl;
cin>>zx;
cout<<"enter coordinates(x,y) of obstacles"<<endl;
for(int i=0;i<zx;i++){
	cin>>a>>b;
	obx.push_back(a);
	oby.push_back(b);
}

//testing

//startptr->child.push_back(getNode(3,1));
//startptr->child.push_back(getNode(5,1));
//startptr->child[1]->child.push_back(getNode(5,2));
//traverse_tree(startptr);

cout<<endl<<endl;
//main loop
int randx,randy;
int tempx=0,tempy=0;
node *temp,*temp2;

while(1){
//choose a random point
	randx=(rand()%n)+1;
	randy=(rand()%n)+1;
	
//select closest node
	temp = 	traverse_tree(startptr,randx,randy);

//generate a new node(coordinates) towards random point from closest node
	if(temp->x<randx)
		tempx=(temp->x)+1;
	else if(temp->x>randx)
		tempx = (temp->x)-1;
	else
		tempx = temp->x;
		
		
	if(temp->y<randy)
		tempy=(temp->y)+1;
	else if(temp->y>randy)
		tempy = (temp->y)-1;
	else
		tempy = temp->y;
		
//check if the generated node is in obstacle position
int flag =0;
	for(unsigned int i =0;i<obx.size();i++){
		if( (tempx==obx[i] && tempy==oby[i]) ){
			flag=1;
			break;
		}
	}
	if(flag==1)
		continue;
// also check if the generated node is already gen
if( check_tree(startptr,tempx,tempy)==true){
	continue;
}


// generate a new node(temp2) and add it to temp
	temp2=getNode(tempx,tempy);
	temp->child.push_back(temp2);
	temp2->prev=temp;
	
if(temp2->x==gx && temp2->y==gy)
	break;	

}


// print the coordinates path from goal to start
while(temp2!=NULL){
	cout<<temp2->x<<" "<<temp2->y<<endl;
	temp2 = temp2->prev;
}
	
	
	return 0;
}






