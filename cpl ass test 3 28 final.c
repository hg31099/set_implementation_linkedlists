//preprocessor directives
#include<stdio.h>
#include<stdlib.h>

// structure definations

typedef int item;

typedef struct set_tag{
    item data;
    struct set_tag * next;
}set;

typedef enum{FAILURE,SUCCESS} status_code;

typedef enum{FALSE,TRUE} boolean;
int set_nos;


//create set first time(intialisation)

set * createset()
{    set *lptr;
     lptr=NULL;
     return lptr;
    
}

//is element of a set returns boolean

boolean iselement(set * ptr,item ele)
{
    boolean b=FALSE;
    while(ptr!=NULL && b==FALSE)
    {
        if(ptr->data==ele) b=TRUE;
        else ptr=ptr->next;
        
    }
    
    return b;
    
}


//remove element from set

set * removele(set *lptr,item ele)
{
    set *ptr,*sptr;
    ptr=lptr;
    sptr=ptr;
    boolean b=FALSE;
    while(ptr!=NULL && b==FALSE)
    {
        if(ptr->data==ele) {
            b=TRUE;
            sptr->next=ptr->next;
            if(lptr==ptr) lptr=lptr->next;
            free(ptr);
            
        }
        sptr=ptr;
        ptr=ptr->next;
        
    }
    return lptr;
    
}

//add element in set at start of list

set * addele(set *lptr,item ele)
{
    set * ptr;
    boolean check;
    check=iselement(lptr,ele);
    if(check==FALSE)
    {
        ptr=(set *)malloc(sizeof(set));
        ptr->data=ele;
        ptr->next=lptr;
        lptr=ptr;
    }
    else printf("Element is alredy present in set \n");
    return lptr;
    
}


//is empty returns boolean ,checks if any element is present or not

boolean isempty(set *lptr)
{
    boolean b=FALSE;
    if(lptr==NULL) b=TRUE;
    return b;
}

//to get size of set i.e no. of element in set
int sizeset(set *lptr)
{
    int size=0;
    while(lptr!=NULL)
    {
        size++;
        lptr=lptr->next;
    }
    return size;
    
}

// unionset fxn takes pointers to 2 linked lists and returns a pointer to union of list(set)

set * unionset(set * sptr, set * tptr)
{
    boolean check;
    set * uptr=NULL,* ptr;
    if(sptr!=NULL && tptr!=NULL)
    {
        while(sptr!=NULL)
        {
           ptr=(set *)malloc(sizeof(set));
           ptr->data=sptr->data;
           sptr=sptr->next;
           ptr->next=uptr;
           uptr=ptr;
           
        }
        while(tptr!=NULL)
        {
            check=iselement(uptr,tptr->data);
            if(check==FALSE)
            {
                uptr=addele(uptr,tptr->data);
            }
            tptr=tptr->next;
            
        }
        
    }
    else  
    {
        if(sptr==NULL) uptr=tptr;
        else if(tptr==NULL) uptr=sptr;
        
    }
    return uptr;
    
}

// traverseset fxn traverses set and prints all elements of set

void traverseset(set *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d \t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    
}

// enumerate fxn prints all elements of set

void enumerate(set *ptr)
{
    traverseset(ptr);
}



// to create intersection of 2 sets

set * interset(set *sptr,set *tptr)
{
    boolean check;
    set *iptr=NULL;
    if(sptr==NULL || tptr==NULL) iptr==NULL;
    else
    {
        while(sptr!=NULL && tptr!=NULL)
        {
          check=iselement(sptr,tptr->data);
          if(check==TRUE)
          {
              iptr=addele(iptr,tptr->data);
          }
          tptr=tptr->next;
            
        }
        
    }
    return iptr;
    
}
// diffset fxn returns difference of set -> S-T



set * diffset(set *sptr,set *tptr)
{
     set *dptr=NULL;
     boolean check;
     if(tptr==NULL) dptr=sptr;
     else 
     {
         if(sptr==NULL) dptr==NULL;
         else
         {
             while(sptr!=NULL)
             {
                 check=iselement(tptr,sptr->data);
                 if(check==FALSE)
                 {
                     dptr=addele(dptr,sptr->data);
                 }
                 sptr=sptr->next;
             }
         }
     }
     return dptr;
    
}


//to check if s is a subset of t.
boolean subset(set *sptr,set *tptr)
{
    boolean b=TRUE;
    while(sptr!=NULL && b==TRUE)
    {
        b=iselement(tptr,sptr->data);
        sptr=sptr->next;
        
        
    }
    return b;
}

//build fxn takes num. of elements and then elements and adds them to list(set);


set * build(set *ptr,int n)
{
    int ele;
    printf("enter elements \n");
    while(n!=0)
    {
        
        scanf("%d",&ele);
        ptr=addele(ptr,ele);
        n--;
    }
    return ptr;
}

//selecting of set

int selectset()
{
    int i;
    printf("select the set to perform operation \n");
    printf("give set number from 1 to %d \n",set_nos);
    scanf("%d",&i);
    i--;
    return i;
    
}

//user interface function
void user_interface()
{
		printf("enter choice  \n");
    	printf("0) to exit \n");
        printf("1) to add multiple elements (build) \n");
    	printf("2) to check element in  set \n");
        printf("3) to remove element from  set \n");
        printf("4) to add element in  set \n");
        printf("5) to check if set is empty \n");
        printf("6) to get size of set \n");
        printf("7) to get union of 2 sets \n");
        printf("8) to get all elements  of set \n");
        printf("9) to get intersection of 2 sets \n");
        printf("10) to get difference of 2 sets \n");
        printf("11) to check if first set is subset of second set  \n");
      
}


//main function,driver function
int main()
{
    int choice=1;
    set *uptr=NULL,*iptr=NULL,*dptr=NULL;
    int j;
    item ele;
    printf("Enter number of sets you want to create \n");
    scanf("%d",&set_nos);
    set *lptr[set_nos];
    int i;
    for(i=0;i<set_nos;i++)
    {
        lptr[i]=createset();
    }
    
    int size;
    boolean  b;
    while(choice!=0)
    {
    
        user_interface();
        scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:  i=selectset();  
                 printf("Enter number of elements to be added \n");
                 int n;
	             scanf("%d",&n);
		         lptr[i]=build(lptr[i],n);
		         break;
        case 2:  i=selectset();
                 scanf("%d",&ele);
                 b=iselement(lptr[i],ele);
                 if(b==TRUE) printf("TRUE \n");
    	    	 if(b==FALSE) printf("FALSE \n");
      	    	 break;
    	case 3:  i=selectset(); 
    	         scanf("%d",&ele);
                 lptr[i]=removele(lptr[i],ele); 	
    			 break;
        case 4:  i=selectset();
        		 printf("enter element \n");
                 scanf("%d",&ele);
                 lptr[i]=addele(lptr[i],ele);
                 break;
        case 5:  i=selectset(); 
                 b=isempty(lptr[i]);
                 if(b==TRUE) printf("SET is empty \n");
                 if(b==FALSE) printf("SET is not empty \n");
				 break;
        case 6:  i=selectset(); 
                 size=sizeset(lptr[i]);
                 printf("%d \n",size);
                 break;
        case 7:  i=selectset();
                 j=selectset();
                 uptr=unionset(lptr[i],lptr[j]);
                 traverseset(uptr);
                 break;
        case 8 : i=selectset();
                 enumerate(lptr[i]);
				 break;   
		case 9 : i=selectset();
                 j=selectset();
		         iptr=interset(lptr[i],lptr[j]);
		         traverseset(iptr);
	             break;
    
        case 10 :i=selectset();
                 j=selectset();
		         dptr=diffset(lptr[i],lptr[j]);
		         traverseset(dptr);
		         break;
		         
		case 11: i=selectset();
                 j=selectset();
		         b=subset(lptr[i],lptr[j]);
		         if(b==TRUE) printf("S is a subset of T \n");
    	    	 if(b==FALSE) printf("S is not a subset of T \n");
		         break;
		
    }
    }
    return 0;
}






















