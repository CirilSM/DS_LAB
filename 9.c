//sorting
#include<stdio.h>
int ch;
void main()
{
	printf("\n\n\t1.Bubble Sort\n\t2.Insertion Sort\n\t3.Selection Sort\n\t4.Recursive Quick Sort\n\t5.Recursive Merge Sort\n-----Press any other ket to EXIT-----\n");
	scanf("%d",&ch);
	if(ch==1)
		bubble();
	else if(ch==2)
		insertion();
	else if(ch==3)
		selection();
	else if(ch==4)
		requick();
	else if(ch==5)
		remerge();
	else
		exit(0);
	
}

