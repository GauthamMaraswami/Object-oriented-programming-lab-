#include<stdio.h>
#include<stdlib.h>
struct edge{
int src,dest;
int w;
}E[100],temp,rE[100];
int nnode;

struct sset{
int par,nch;
int ach[100];
int lev;
}sets[100];



void edgesort(int ctr){
	int i=0,j=0;
 for(i=0;i<ctr;++i)
{
	 for(j=0;i<ctr;++i)
	{
	if(E[i].w>E[j].w)
	{
 	  temp=E[i];
  	 E[i]=E[j];
  	 E[j]=temp;
	}	
}

}


}

void makeset(){
int i=0;
for(i=0;i<nnode;++i)
{
sets[i].parent=i;
sets[i].nch=0;
sets[i].lev=0;
}

}

int find(int u)
{
return sets[u].parent;
}


void union1(int u,int v){
int i;
if(sets[u].nch>sets[v].nch){
	for(i=0;i<nnode;++i)
	{
	if(sets[i].parent==v)
	  sets[i].parent=u;
	}
}
else{
for(i=0;i<nnode;++i)
	{
	if(sets[i].parent==u)
	  sets[i].parent=v;
	}

}
}
void kruskal(int ctr)
{
edgesort(ctr); 
makeset();
int nfn=1;
//int c1=0;
int u,v;
for(i=0;i<ctr;++i){
if(nfn<nnode)
 { u=E[i].src;
   v=E[i].dest;
if(find(u)!=find(v))
 {
   union1(u,v);
   ++nfn;
 }
}
}
}




void main()
{
int ctr=0;
printf("enter the no of edges\n");
scanf("%d",&nnode);

printf("enter the edges\n");
int ch=1;
while(ch){
printf("enter source, dest,weight\n");
scanf("%d %d%d",&E[ctr].src,&E[ctr].dest,&E[ctr].w);
++ctr;
printf("enter your choice\n");
scanf("%d",&ch);
}
kruskal(ctr);
}
