#include<stdio.h>
	void  bubble(float x[],int n);
	void  minimum(float t[22][22],int n,int m,int *ir,int *ic);
	void vam(float c[22][22],float a[22],float b[22],int n,int m);
	void main()
	{
	float c[22][22],a[22],b[22];
	int n,m,i,j;
	char ch;
	do
	{
	clrscr();
	printf("\nEnter number or origins(1-20)=");
	scanf("%d",&n);
	printf("Enter number of destinations(1-20)=");
	scanf("%d",&m);
	/* To initialize cost matrix, capacity, requirement */
	for(i=1;i<22;i++)
	{
	a[i]=0;
	b[i]=0;
		for(j=1;j<22;j++)
		{
		c[i][j]=0;
		}
	}
	printf("Enter elements of cost matrix one by one--->\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
		printf("c[%d][%d]=",i,j);
		scanf("%f",&c[i][j]);
		}
	printf("Enter Capacities one by one--->\n");
		for(i=1;i<=n;i++)
		{
		printf("capacity[%d]=",i);
		scanf("%f",&a[i]);
		}
	printf("Enter Requirements one by one--->\n");
		for(i=1;i<=m;i++)
		{
		printf("requirement[%d]=",i);
		scanf("%f",&b[i]);
		}
	vam(c,a,b,n,m);
	printf("\nDo you want to continue(Y/N?) :");
	ch=getch();
	}while(ch=='y' || ch=='Y');
	}

	/* Bubble sort function */

	void  bubble(float x[],int n)
	{
	float t;
	int i,flag;
	flag=0;
	while(flag == 0)
	{
	flag=1;
	n=n-1;
		for(i=1;i<=n;i++)
		if(x[i] > x[i+1])
		{
		t=x[i];
		x[i]=x[i+1];
		x[i+1]=t;
		flag=0;
		}
	}
	}

	/* To get the minimum value from  a matrix. */

	void  minimum(float t[22][22],int n,int m,int *ir,int *ic)
	{
	float small;
	int i,j;
	small=-999;
	if(*ir == -1)
	{
		for(i=1;i<=n;i++)
		if(t[i][*ic] != -999)
		{
		small=t[i][*ic];
		*ir=i;
		break;
		}

		for(j=1;j<=n;j++)
		if((t[j][*ic] != -999) && (t[j][*ic] <  small))
		{
		small=t[j][*ic];
		*ir=j;
		}
	}
	else
	{

		for(i=1;i<=m;i++)
		if(t[*ir][i] != -999)
		{
		small=t[*ir][i];
		*ic=i;
		break;
		}
		for(j=1;j<=m;j++)
		if((t[*ir][j] != -999) && (t[*ir][j] < small))
		{
		small=t[*ir][j];
		*ic=j;
		}
	}
	}
	void vam(float c[22][22],float a[22],float b[22],int n,int m)
	{
	float allot[22][22],cost;
	float t[22][22],nr[22],nc[22],s1,s2;
	float rop[22],cop[22], pmax,r1[22],c1[22],rmax,cmax;
	int i,j,k,l,l1,k1,flag,ir,ic;
	int d;
	char ch1;
	int itr,nallot,nn;
	int i1,j1;

	/* To initialize signature matrix */
		for(i=1;i<22;i++)
		{
			for(j=1;j<22;j++)
			{
			t[i][j]=0;
			}
		}

	/* To create initial signature matrix */
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			t[i][j]=c[i][j];
	/* To initialize allotment matrix. */
		for(i=1;i<22;i++)
			for(j=1;j<22;j++)
			allot[i][j]=0;

	s1=0;
	for(i=1;i<=n;i++)
	{
	s1=s1+a[i];
	}

	s2=0;
	for(i=1;i<=m;i++)
	{
	s2=s2+b[i];
	}

	/* Testing of balanced/unbalanced matrix */

	if(s1 < s2)
	{
	n=n+1;
	a[n]=s2-s1;
	}

	if(s2 < s1)
	{
	m=m+1;
	b[m]=s1-s2;
	}
	if(s1!=s2)
	{
	 printf("\nThe matrix was unbalanced.\nPress any key to make it balanced.\n");
	 getch();
	 }

	/*  Printing of input data   */
	printf("\nElements of Cost Matrix--->\n");
	for(i=1;i<=n;i++)
	{
	printf("     ");
		for(j=1;j<=m;j++)
		printf("%-4.0f",c[i][j]);
	printf(" a-%d : %4.0f\n",i,a[i]);
	}
	printf("   b:");
	for(i=1;i<=m;i++)
	printf("%4.0f",b[i]);
	printf("\nPress any key to continue--->");
	getch();
	clrscr();
	/*Formation of allotment matrix */
	flag=0;
	itr=0;
	while(flag == 0)
	{
		/*  calculation of row penalties  */

		for(i=1;i<22;i++)
		{
		rop[i]=0;
		cop[i]=0;
		r1[i]=0;
		c1[i]=0;
		nr[i]=0;
		nc[i]=0;
		}
		k1=1;
		for(i=1;i<=n;i++)
		{
		k=0;
			for(j=1;j<=m;j++)
				if(t[i][j] != -999)
				{
				k=k+1;
				r1[k]=t[i][j];
				}
			if( k >1)
			bubble(r1,k);

			if(k >1)
			rop[k1]=r1[2]-r1[1];
			else if(k==1)
			rop[k1]=r1[1];
			if(k>=1)
			{
			nr[k1]=i;
			k1=k1+1;
			}
		}

	     /* Calculation of column penalties  */

	l1=1;
		for(i=1;i<=m;i++)
		{
		l=0;
			for(j=1;j<=n; j++)
			if(t[j][i] != -999)
			{
			l=l+1;
			c1[l]=t[j][i];
			}
			if(l > 1)
			bubble(c1,l);
				if(l > 1)
				cop[l1]=c1[2]-c1[1];
				else if(l==1)
				cop[l1]=c1[1];
				if(l>=1)
				{
				nc[l1]=i;
				l1=l1+1;
				}
		}
	/*Calculation of maximum penalty value from row and column
	   penalties. */

	rmax=rop[1];
	ir=nr[1];
	for(i=2;i<k1;i++)
		if(rop[i] > rmax)
		{
		rmax=rop[i];
		ir=nr[i];
		}
	cmax=cop[1];
	ic=nc[1];
	for(i=2;i<l1;i++)
		if(cop[i] >  cmax)
		{
		cmax=cop[i];
		ic=nc[i];
		}
	 /* Calculation of  largest penalty value */

		if(rmax > cmax)
		{
		ic=-1;
		pmax=rmax;
		}
		else
		{
		ir=-1;
		pmax=cmax;
		}

	/*   To get the lowest cost value from cost matrix  */
	minimum(t,n,m,&ir,&ic);
		if((b[ic]/*+bp[ic]*/) < (a[ir] /*+ap[ir] */))
		{
		allot[ir][ic]=b[ic];
		a[ir]=a[ir]-b[ic];
		b[ic]=0;
			for(i=1;i<=n;i++)
			t[i][ic]=-999;
		}
		else
		{
		allot[ir][ic]=a[ir];
		b[ic]=b[ic]-a[ir];
		a[ir]=0;
			for(i=1;i<=m;i++)
			t[ir][i]=-999;
		}
		/* To calculate number of allotments done */
	      itr=0;
		for(i1=1;i1<=n;i1++)
			for(j1=1;j1<=m;j1++)
				if((allot[i1][j1] )!=0)
				itr++;


		/* Printing of intermediate cost matrix with row and column
		penalties. */
		printf("\nIteration number-->%d\n",itr);
		printf("Elements of Cost Matrix--->\n");
		for(i=1;i<=n;i++)
		{
		printf("     ");
			for(j=1;j<=m;j++)
			printf("%5.0f",c[i][j]);
			printf(" a-%d : %4.0f\n",i,a[i]);
		}
		printf("   b:");
		for(i=1;i<=m;i++)
		printf("%4.0f",b[i]);
		printf("\nIntermediate signature matrix--->\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				if(t[i][j] != -999)
				printf("%5.0f",t[i][j]);
				else
				printf("    *");
		printf("\n");
		}
	       /*Printing of row penalty and column penalty*/
		printf("\nRow penalties :");
		for(i=1;i<k1;i++)
			if(i!=(k1-1))
			printf("%-3.0f,",rop[i]);
			else
			printf("%-3.0f\n",rop[i]);
		printf("Column penalties :");
		for(i=1;i<l1;i++)
			if(i!=(l1-1))
			printf("%-3.0f,",cop[i]);
			else
			printf("%-3.0f\n",cop[i]);
		printf("Maximum penalty=%-5.0f\n",pmax);
		printf("Elements in Allotment matrix--->\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{

				if((allot[i][j] )!=0)
				{
					 if(allot[i][j]!=0)
					 {
					 printf("%5.0f",allot[i][j]);
					 }
					 else
					 printf("     ");

				}
				else
				printf("    X");
			}
			printf(" a-%d=%-4.0f",i,a[i]);
			printf("\n");
		}
		printf("b: ");
			for(k=1;k<=m;k++)
				{
				printf("%4.0f",b[k]);
				}
		printf("\n");
	printf("\nPress any key to continue--->");
	getch();
	clrscr();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			if(t[i][j] != -999)
			{
			flag=1;
			break;
			}
			if(flag == 1)
			break;
		}
		if(flag == 1)
		flag=0;
		else
		flag=1;
	}

	/* To display allotment matrix */

	printf("\nElements in Final Allotment matrix--->\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{

				if((allot[i][j] )!=0)
				{
					 if(allot[i][j]!=0)
					 {
					 printf("%5.0f",allot[i][j]);
					 }
					 else
					 printf("     ");
				}
				else
				printf("    X");
			}
			printf(" a-%d=%-4.0f",i,a[i]);
				/*
				if(ap[i]!=0)
				printf("%dd",ap[i]);
				*/
				printf("\n");

		}
		printf("b: ");
			for(i=1;i<=m;i++)
				{
				printf("%4.0f",b[i]);
				}
		printf("\n");
	printf("\nPress any key to continue--->");
	getch();

	printf("\nElements in Cost matrix--->\n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		printf("%5.0f",c[i][j]);
	printf("\n");
	}

	 /* Calculation of cost by taking the product of allotment matrix
	 and the cost matrix. */
	nallot=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(allot[i][j] !=0)
		nallot=nallot+1;
	printf("Total Transportation cost using VAM method =\n");
	nn=cost=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(allot[i][j] !=0)
			{
			nn=nn+1;
				if(nn<itr)
				printf("%4.0f*%-4.0f+",allot[i][j],c[i][j]);
				else
				printf("%4.0f*%-4.0f\n",allot[i][j],c[i][j]);
			cost=cost+allot[i][j]*c[i][j];
			}
		}
	printf("=%-8.0f\n",cost);
	printf("\nTotal number of allotments=%d\n",itr);
		if(itr<(m+n-1))
		printf("\n***It is a degenerate system. \nYou have to use perturbation method to obtain optimal solution.***\n");

	}
