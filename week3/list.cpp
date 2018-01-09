#include<iostream>
#include<stdlib.h>
using namespace std;


class list{
private:
        struct node
{
	int value;
	struct node* next;
	
};
        node *l1;
        int len;
        
        node* rec(node * r)
        {
         if(r==NULL  || r->next==NULL)
                {
                
                return r;
                
                }
           else{
                 node * it= rec(r->next);
                r->next->next=r;
                 return it;
                }
        
        }
public:
    list(){
          l1=NULL; 
          len=0;  
    }
    void create(int );
    void reverse();
    void deletenode(int );
    void insertion(int ,int);
    void search(int);
    void swap(int ,int );
    void display();
};


void list:: swap(int pos1,int pos2)
{
     if(pos1>len && pos2>len)
        {
            cout<<"wrong pos";
        
        }
      else{
            
       node *n1=new node; 
               n1=l1;
        node *n2=new node; 
               n2=l1;
       int te;        
        for(int i=0;i<pos1;++i)      
               n1=n1->next;
        for(int j=0;j<pos2;++j)
                n2=n2->next;
                
                 te=n1->value;
                
                 n1->value=n2->value;
                 n2->value=te;
                 
      }


}
void list:: create(int n)
{
        l1->value=n;
        l1->next=NULL;   

}
void list:: deletenode(int pos)
{
        
        node *prev=new node;
        if (pos>len)
        {
                cout<<"wrong pos"<<endl;
        
        }
        else if(pos==0)
          {
          l1=l1->next;  
          --len;
          
          }
         
        else if(pos==len-1)
          {
          
                node *n=new node; 
                
                     n=l1;
              for(int i=0;i<pos-1;++i)   
                {
                     
                     n=n->next;  
                     
                
                }
                
                n->next=NULL;
                --len;
          }
          else if(pos<len-1)
          {
           node *n=new node; 
                
                     n=l1;
          node *n1=new node;
          for(int i=0;i<pos-1;++i)   
                {
                     
                     n=n->next;  
                     
                
                }
                n=n->next;
                n->next=n1;
                   --len;
          
          }
        cout<<"delete succcessful"<<endl;
        
        
}
void list::reverse()
{
 if(l1==NULL)
   cout<<"empty"<<endl;
 else
  { node * n1=rec(l1);
   l1->next=NULL;
   l1=n1;
}
}
void list::insertion(int pos,int val)
{
        // cout<<"aaaaaaaaa"<<endl;
        node *n=new node;
	n->value=val;
	n->next=NULL;
	 //cout<<"aaaaaaaaa";
	if(l1==NULL)
                {
              //  cout<<"aaaaaaaaa";
                l1=n;
                ++len;
                }
        else if (pos==0)
              {
              n->next=l1;
              l1=n;
              ++len;           
              }	
        else if (pos>len)
                {
                cout<<"wrong position";
                                
                }
        else if(pos<len)
                {
                    node *np=new node;
                    np=l1;
                   int i=0;
                   for(i=0;i<pos-1;++i)
                   {
                   np=np->next;
                   }
                   n->next=np->next;
                   np->next=n; 
                   ++len;                        
                }
         else if(pos==len)
         {
                node *np=new node;
                    np=l1;
                    while(np->next!=NULL)
                    {
                    np=np->next;
                                       
                    }
                    np->next=n;
                    ++len;
         
         }
         cout<<"successful";
         


}
void list::display()
{
		node *n=new node;
		n=l1;
 		if(n==NULL)
		{
			cout<<"empty\n";	
		}
		else
		{
			while(n!=NULL)
			{
				cout<<n->value<<"<--";
				n=n->next;
			}
		}
		cout<<endl<<"length  "<<len;
}
void list:: search(int val)
{
        
node *n=new node;
		n=l1;
		if(n==NULL)
		  cout<<"empty";
		else {
		    int pos=-1;
		    int ctr=0;
		        while(n!=NULL)
		        {
		             if(n->value==val)
		                {
		                   pos=ctr;
		                   break;
		                }
		            n=n->next;
		            ++ctr;        
		        }
		if(pos==-1)
		     cout<<"not found"<<endl;
		else 
		     cout<<"found at"<<pos;
		
		}



}
int main()
{
        int pos,val,pos1,pos2,ch;
      
        
        cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
          cin>>ch;
  list l;
  while(ch<10)
  {
  switch (ch)
  {case 1:
    cout<<"enter position and value\n"; 
   cin>>pos>>val;
  l.insertion(pos,val);
  cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
  cin>>ch;
  break;
  case 2:
  
   l.display();
   cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
   cin>>ch;
   break;
  case 3:
  cout<<"enter position\n"; 
    cin>>pos;
   l.deletenode(pos);
   cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
   cin>>ch;
   break;
   case 4:
   cout<<"enter value\n"; 
    cin>>val;
   l.search(val);
   cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
   cin>>ch;
   case 5:
   cout<<"enter position1 and position2\n"; 
    cin>>pos1>>pos2;
   l.swap(pos1,pos2);
   cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
   cin>>ch;
   break;
    case 6:
 
   l.reverse();
    cout<<"1- insert 2 display 3 delete 4 search 5 swap 6 reverse 7 exit enter choice \n";
   cin>>ch;
   break;
   default :
    exit(0);
   }
    }

}





