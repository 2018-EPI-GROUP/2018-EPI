/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct s1
{
	char cal[20];
	int top;
}S1;
typedef struct s2
{
	char num[20];
	int top;
}S2;
int compare(char a, char b)
{
    int i,j;
    switch(a)			//栈外级别 
	{					
        case '+': i=1; break;
        case '-': i=1; break;
        case '*': i=2; break;
        case '/': i=2; break;
        case '^': i=4; break;
        case '#': i=-2;break;
    }
    switch(b)
	{					//栈内级别 
        case '+': j=1; break;
        case '-': j=1; break;
        case '*': j=2; break;
        case '/': j=2; break;
        case '^': i=3; break;
        case '#': i=-2;break;
    }
    if(i>j) return 1;
	else return 0; 
}
main()
{
	int count,i,a=0,j,c,k,x,y,z;
	char ch1,ch;
	S2 *s2;
	S1 *s1;
	s2=(S2 *)malloc(sizeof(S2));
	s1=(S1 *)malloc(sizeof(S1));
	s1->top=-1;
	s2->top=-1;
	char A[20],B[20];
	gets(A);
	count=strlen(A);
   	for(i=0;i<=count;i++)
	{
		ch=A[i];
		if(isdigit(ch))
		{
			s2->top++;
			s2->num[s2->top]=ch;
		}
		else
		{
			if(s1->top==-1||ch=='('||compare(ch,s1->cal[s1->top])==1)
			{
				s1->top++;
				s1->cal[s1->top]=ch;
			}
			else if(compare(ch,s1->cal[s1->top])==0)
			{
				ch1=s1->cal[s1->top];
				s1->top--;
				s2->top++;
				s2->num[s2->top]=ch1; 
				s1->top++;
				s1->cal[s1->top]=ch;
			}
			else if(ch==')')
			{	
				while(s1->cal[s1->top]!='(')
				{
					ch1=s1->cal[s1->top];
					s1->top--;
					s2->top++;
					s2->num[s2->top]=ch1; 	
				}
				s1->top--;
			}
		}
	}
	while(s1->top>-1)
	{
		ch1=s1->cal[s1->top];
		s1->top--;
		s2->top++;
		s2->num[s2->top]=ch1; 
	}
	i=0;
	j=0;
	while(i<=s2->top)
	{
		if(s2->num[i]=='\0'||s2->num[i]=='('||s2->num[i]==')')
		{
			i++;
			continue;
	    }
	    printf("%c",s2->num[i]);
		B[j++]=s2->num[i];
		i++;
	}
	/*for(k=0;k<=j-1;k++) printf("%c",B[k]);
	putchar('\n');
	printf("%d\n\n",j-1);*/
/*	for(k=0;k<=j-1||j-1==0;k++)
	{
		ch=B[k];
		if(isdigit(ch))
		{
			continue;
		}
		else
		{
			x=(int)B[k-1]-48;
			y=(int)B[k-2]-48;
			k=k-2;
			switch(ch)
			{
				case '+':z=x+y;	break;
				case '-':z=x-y;	break;
				case '*':z=x*y;	break;
				case '/':z=0.1*x/y;break;
				case '%':z=x%y;	break;
			}		
			B[k]=(z+48);
			for(c=k+1;c<j-2;c++) B[c]=B[c+2];
			j-=2;
		}
	}
	printf("\n%d\n",B[0]-48);
	
		
}*/
