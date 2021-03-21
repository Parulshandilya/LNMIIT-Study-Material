/*************************************************************    
  Template Program for Programming Assignment 

   Evaluate and Analyze Sorting Programs
   =====================================
   This program uses input:
     1. read in from an input file 

        file format:  
          <n -- number of elements to sort>
          <element 1>
          <element 2>
          ... 
          <element n>

     2. creates random input lists
     3. creates increasing input lists
     4. creates decreasing input lists

   This program runs:
     1. insertion sort 
     2. mergesort
     3. quicksort 
     4. heapsort 
     5. radix sort 

   It has a menu interface.  
   The time of the sort is displayed after it is run, along with
   the number of comparisons performed (for comparison-based sorts).

   Also, the statistics are written to an output file named 
   "prog.out".

**************************************************************/


#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*************
 * CONSTANTS *
 *************/

#define TAKE_COUNT
#define NOFILE "XXXNONAMEXXX"      /* string used for no active input file */
#define OUTPUTFILE "prog.out"     /* output file name                     */
#define DEFAULT_SEED 255           /* default seed for random numbers      */

/************
 * TYPEDEFS *
 ************/

#define NUMMENUOPTIONS 10
typedef enum { INFILE, RANDOM, INCREASING, DECREASING,
               INSERTION, MERGE, QUICK1,QUICK2,QUICK3,HEAP, RADIX,
               EXIT}
MenuOptionTypes;

/*******************
 * GLOBAL VARIABLE *
 *******************/

unsigned long comparison_count;    /* Count of comparisons */

/***********************
 * FUNCTION PROTOTYPES *
 ***********************/

int Menu(void);
void GetFilename(char *);
int  IsActiveFile(char *);
long *ReadInData(char *, int *);
long *MakeRandomList(int *);
long *MakeIncreasingList(int *);
long *MakeDecreasingList(int *);
long *CreateList(int);
void CopyList(long *, long *, int);
void OutputList(long *, int);
void ShowResults(char *, clock_t,clock_t, int, char *);
void Check(long *, int);
int getMax(long* , int ); // utility function

void InsertionSort(long *, int);               /* Insertion Sort */

void MergeSort(long *, long *, int ,int);      /* Merge Sort */
void Merge(long *, long *, int, int, int);

void QuickSort(long *, int ,int,int);              /* Quick Sort */
int  FindMedian(long *, int, int, int);
int get_pivot(long*,int,int,int); /*chooses the pivot by user choice*/
void Split(long *, int, int, int *);
void Swap(long *, long *);

void HeapSort(long *, int);                    /* Heap Sort */
void Heapify(long *, int, int, int);

void RadixSort(long *, int);                   /* Radix Sort */
void countSort(long* , int , int );


/**************************************************************************

 MAIN PROCEDURE

     No input/output

**************************************************************************/

int main()
{
   int choice;                 /* value of user's menu choice           */
   int done = 0;               /* Set to 1 when user wants to exit menu */
   char filename[50] = NOFILE; /* input filename initialized to NONAME  */
   long *List=NULL;            /* Original List of Values               */
   long *TestList;             /* List used for testing                 */
   long *TestListCopy;         /* used to store copy of TestList        */
   int num;                    /* number of elements in list            */
   clock_t start, end;         /* used to time each sort                */


   do                   /* Loop executes until done is equal to 1.   */
   {
      comparison_count = 0;	/* Set compare-count to zero		     */
      choice = Menu();  /* Display menu. Get value of user's choice. */
      switch(choice)    /* Examine value of user's choice.           */
      {
	 case INFILE:  /* (1) SPECIFY INPUT FILE */
		  /* Prompt user to enter filename and read it in.     */
		  /* Read in numbers from input file and place in List */
		  GetFilename(filename);
        if (List != NULL) free (List);
		  List = ReadInData(filename, &num);
		  break;
	 case RANDOM:  /* (2) Make Random Input List */
        if (List != NULL) free (List);
		  List = MakeRandomList(&num);
        strcpy(filename,"random list"); /* input 'filename' is random */
		  break;
	 case INCREASING:  /* (3) Make Increasing Input List */
        if (List != NULL) free (List);
		  List = MakeIncreasingList(&num);
        strcpy(filename,"increasing list"); /* input 'filename' is increasing */
		  break;
	 case DECREASING:  /* (4) Make Decreasing Input List */
        if (List != NULL) free (List);
		  List = MakeDecreasingList(&num);
        strcpy(filename,"decreasing list"); /* input 'filename' is decreasing */
		  break;
	 case INSERTION:  /* (5) INSERTION SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     TestList = CreateList(num);
		     CopyList(TestList, List, num);
		     start = clock();               /* get start time */
		     InsertionSort(TestList, num);  /* sort list      */
		     end = clock();                 /* get end time   */
		     ShowResults("1Insertion Sort",start,end,num,filename); 
		     Check(TestList,num);  /* Check for correct sorting */
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case MERGE:  /* (6) MERGE SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     /* Create a copy of Test List since Merge Sort needs */
		     /* two lists of data. */
		     TestList = CreateList(num);
		     CopyList(TestList, List, num);
		     TestListCopy = CreateList(num);
		     CopyList(TestListCopy, TestList, num);
		     start = clock();                    /* get start time */
		     MergeSort(TestListCopy, TestList, 0 ,num-1); /* sort */
		     end = clock();                        /* get end time */
		     ShowResults("1Merge Sort", start, end, num, filename); 
		     Check(TestList,num);  /* Check for correct sorting */
		     free(TestListCopy);
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case QUICK1:  /* (7) QUICK SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     TestList = CreateList(num);
		     CopyList(TestList, List, num);
		     start = clock();                      /* get start time*/
		     QuickSort(TestList, 0, num-1,1);        /* sort list     */
		     end = clock();                        /* get end time  */
		     ShowResults("1Quick Sort (pivot 1)", start, end, num, filename);
		     Check(TestList,num);  /* Check for correct sorting */
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case QUICK2:  /* (8) QUICK SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     TestList = CreateList(num);
		     CopyList(TestList, List, num);
		     start = clock();                      /* get start time*/
		     QuickSort(TestList, 0, num-1,2);        /* sort list     */
		     end = clock();                        /* get end time  */
		     ShowResults("2Quick Sort (random pivot)", start, end, num, filename);
		     Check(TestList,num);  /* Check for correct sorting */
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case QUICK3:  /* (9) QUICK SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     TestList = CreateList(num);
		     CopyList(TestList, List, num);
		     start = clock();                      /* get start time*/
		     QuickSort(TestList, 0, num-1,3);        /* sort list     */
		     end = clock();                        /* get end time  */
		     ShowResults("3Quick Sort (median pivot)", start, end, num, filename);
		     Check(TestList,num);  /* Check for correct sorting */
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case HEAP:  /* (10) HEAP SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     /* Values start at position 1 in array because of     */
		     /* binary tree implementation. */
		     TestList = CreateList(num+1);
		     CopyList(TestList+1, List, num);
		     start = clock();                   /* get start time */
		     HeapSort(TestList, num);           /* sort list      */
		     end = clock();                     /* get end time   */
		     ShowResults("1Heap Sort", start, end, num, filename); 
		     Check(TestList+1,num);  /* Check for correct sorting */
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case RADIX:  /* (11) RADIX SORT */
		  /* Check to make sure there is a list to sort...*/
		  if( List != NULL )
		  {
		     /* Create a Test List and copy original values into it*/
		     TestList = CreateList(num);
		     CopyList(TestList, List, num);
		     start = clock();                    /* get start time */
		     RadixSort(TestList, num);           /* sort list      */
		     end = clock();                      /* get end time   */
		     ShowResults("1Radix Sort",start,end,num,filename); 
		     Check(TestList,num);  /* Check for correct sorting */
		     free(TestList);
		  } else {
           printf ("\nThere is no input list. Specify one!.\n");
        }
		  break;
	 case EXIT:  /* (12) EXIT */
		  done = 1;      /* Set done to 1 so loop will terminate.*/
		  break;
	default:  /* INVALID MENU CHOICE */
		  printf("\nInvalid Choice. Press 1,2,3,4,5,6,7 or 8.\n");
		  break;
     } /* end switch */
   } while(!done);

   return(0);
} /* end main */


/**************************************************************************

 PROCEDURE: InsertionSort (*L, n)

	    This procedure uses the insertion-sort method to sort elements

     INPUT: L	Pointer to an array of unsorted elements
	    n	Number of elements in array

    OUTPUT: L  Pointer to array of sorted elements

**************************************************************************/

void InsertionSort(long *L, int n)
{
   int x;                        /* value to be inserted */
   int k, j;                     /* index in for loops */

   for (k = 1; k < n; ++k)       /* walk down list */
   {
      x = L[k];                     /* assign x to kth element */
      j = k - 1;                    /* j is (k-1)th element */

#ifdef TAKE_COUNT
     comparison_count++;
#endif
      /* Loop searches for value from right to left, which is <= x */
      while ((j > -1) && (L[j] > x)) {
#ifdef TAKE_COUNT
	       comparison_count++;
#endif
          L[j + 1] = L[j];         /* move values in list right */
          --j;                     /* decrease j index by 1 */
      }
      L[j + 1] = x;     /* value is inserted in sorted part of list */
   }
}


/**************************************************************************

 PROCEDURE: QuickSort (*L, first, last,typ)

    This procedure uses the quick-sort method to sort elements.
    it takes typ and then chooses pivot accorindly

     INPUT: L	   Pointer to unsorted array of elements
	    first  first element of chunk to sort this time
	    last   last element of chunk to sort this time

    OUTPUT: L      Pointer to sorted array of elements

**************************************************************************/

void QuickSort(long *L, int first, int last,int typ)
{
   int SplitPoint;  /* Value to Split list around */

   if( first < last )
   {
      /* Use first element as pivot (for splitting) */
      SplitPoint =get_pivot(L,first,last,typ);                 /* assign SplitPoint by checking the typ */
      Split(L, first, last, &SplitPoint); /* Split List around SplitPoint */
      QuickSort(L, first, SplitPoint-1,typ);  /* Sort 1st section of list */
      QuickSort(L, SplitPoint+1, last,typ);   /* Sort 2nd section of list */
   }
}

void Split(long *L, int first, int last, int *SplitPoint)
/* Splits a list around SplitPoint such that all values to the left of
   SplitPoint are < than SplitPoint and all values to the right of
   SplitPoint are >= SplitPoint */
{
   int x;            /* Key */
   int unknown;      /* index of unknown value */

   x = L[*SplitPoint];   /* assign x to value at SplitPoint */
   Swap( &L[*SplitPoint], &L[first] ); 
   *SplitPoint = first; 

   /* Loop walks through unknown portion of list */
   for ( unknown = first+1; unknown <= last; ++unknown)
   {
      /* If unknown value is < SplitPoint Value, then: */
#ifdef TAKE_COUNT
         comparison_count++;
#endif
      if( L[unknown] < x ) {
         ++ (*SplitPoint);                     /* SplitPoint is incremented */
         Swap( &L[*SplitPoint], &L[unknown] ); /* values are swapped*/
      }
   }
   /* Original value which was being split upon is swapped with the current
      SplitPoint to put it in correct position */
   Swap( &L[first], &L[*SplitPoint] );
}
int get_pivot(long *L,int l,int h,int typ)
{
	if(typ==1)
		return l;
	else if(typ==2)
	{
		return l+rand()%(h-l+1);
	}
	else if(typ==3)
	{
		return FindMedian(L,l,(l+h)/2,h);
	}
}
int FindMedian(long *L, int A, int B, int C)
/* Receives array and three respective indices in the array. */
/* Returns the index of the median. */
{
   if (L[A] < L[B])
     if (L[B] < L[C]) 		/*  A < B < C  */
       return (B);
     else
       if (L[A] < L[C])         /*  A < C < B  */
	 return (C);
       else
	 return (A);            /*  C < A < B  */
   else
     if (L[A] < L[C])           /*  B < A < C  */
       return (A);
     else
       if (L[B] < L[C])		/*  B < C < A  */
	 return (C);
       else
	 return (B);            /*  C < B < A  */
}

void Swap(long *a, long *b)
/* This function uses call by reference to switch two elements.*/
{
   long temp;    /* temporary variable used to switch. */

   temp = *a;   /* temp = 1st # */
   *a = *b;     /* 1st # = 2nd # */
   *b = temp;   /* 2nd # = temp */
}


/**************************************************************************

 PROCEDURE: MergeSort (*Source, *Destination, Lower, Upper)

	    This procedure uses the merge-sort method to sort elements

     INPUT: Source
	    Destination
	    Lower
	    Upper

    OUTPUT:

**************************************************************************/

void MergeSort(long *Source, long *Destination, int Lower, int Upper)
{
   int Mid;  /* middle index of list */

   if (Lower != Upper)
   {
      Mid = (int) ((Lower + Upper)/2);         /* find middle of list */
      MergeSort(Destination, Source, Lower, Mid);    /* sort 1st half */
      MergeSort(Destination, Source, Mid+1, Upper);  /* sort 2nd half */
      Merge(Source, Destination, Lower, Mid, Upper); /* combine lists */
   }
}

void Merge(long *Source, long *Destination, int Lower, int Mid, int Upper)
/* Combines two sorted lists for the Merge Sort. Receives Source List,
   Destination List, and Lower, Mid, and Upper indices of list.  */
{
   int S1, S2, D;    /* indices for source1, source2, and destination */

   /* Initialize Pointers */
   S1 = Lower;      /* Set S1 to lower index of list */
   S2 = Mid + 1;    /* Set S2 to middle index + 1 of list */
   D = Lower;       /* Set D to lower index of list */

   /* Repeat the comparison of current item from each list */
   do {
      /* If source value in list 1 is less than value in Source2: */
#ifdef TAKE_COUNT
      comparison_count++;
#endif
      if( Source[S1] < Source[S2] ) {
         Destination[D] = Source[S1];   /* Put Source1 in List */
         ++ S1;                         /* look at next Source1 value */
      } else {                          /* Otherwise: */
         Destination[D] = Source[S2];   /* Put Source2 in List */
         ++ S2;                         /* look at next Source2 value */
      }
      ++ D;                             /* increment List index */
   } while (( S1 <= Mid ) && ( S2 <= Upper));

   /* Move what is left of remaining list */
   if ( S1 > Mid ) {    /* If Source1 has more than 1/2 values: */
     do {               /* Put the rest of Source1 in List */
        Destination[D] = Source[S2];
        ++ S2;
        ++ D;
     } while ( S2 <= Upper );
   } else {                /* Otherwise: */
     do {               /* Put the rest of Source2 in List */
        Destination[D] = Source[S1];
        ++ S1;
        ++ D;
     } while ( S1 <= Mid );
   }
}


/**************************************************************************

 PROCEDURE: HeapSort (*L, n)

	    This procedure uses the heap-sort method to sort elements

     INPUT: L	Pointer to unsorted array of elements
	    n  	Number of elements in list

    OUTPUT: L   Pointer to sorted array of elements

**************************************************************************/

void HeapSort(long *L, int n)
{
   int i, heapsize;    /* indices */
   int max;            /* max value in heap */

   for ( i = (int)(n/2); i >= 1; --i )   /* Build Heap from list */
      Heapify(L, i, L[i], n);

   /* Repeatedly remove key at root of heap and rearrange the heap */
   for ( heapsize = n; heapsize >= 2; --heapsize ) {
      max = L[1];                     /* max is the root value of heap */
      Heapify(L, 1, L[heapsize], heapsize-1 );  /* fix the heap */
      L[heapsize] = max;              /* put value in the list  */
   }
}

void Heapify(long *L, int root, int key, int bound)
/* Reconstructs a heap from list. Used for Heap Sort. Receives the list,
   the root index, key value, and the bound of the heap. */
{
   int vacant, LargerChild;    /* indices */

   vacant = root;      /* set vacant to root element of heap */

   while( (2*vacant) <= bound ) {  /* loop executes while bound not exceeded */
      LargerChild = 2*vacant;    /* Set Large Child to left child of vacant */
      if( ( 2*vacant < bound ) && ( L[2*vacant+1] > L[2*vacant] ) ) {
          /* If right child is bigger, */
#ifdef TAKE_COUNT
          comparison_count++;
#endif
          LargerChild = 2*vacant+1; /* make it LargerChild. */
      }
      if ( key < L[LargerChild] ) { /* if key value is less than LargerChild:*/
#ifdef TAKE_COUNT
          comparison_count++;
#endif
          L[vacant] = L[LargerChild];  /* make vacant value the larger child*/
          vacant = LargerChild;        /* make vacant index the LargerChild*/
      }
      else break;                     /* Otherwise: end the loop */
   }
   L[vacant] = key;    /* set vacant value equal to key value */
}

/**************************************************************************

 PROCEDURE: RadixSort (*L, n)

	    This procedure uses the bucket-sort method to sort elements

     INPUT: L	Pointer to an array of unsorted elements
	    n	Number of elements in array

    OUTPUT: L  Pointer to array of sorted elements

**************************************************************************/
void RadixSort(long* L, int n)
{
    // Find the maximum number to know number of digits
    int exp,m = getMax(L, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(L, n, exp);
}
// A utility function to get maximum value in arr[]
int getMax(long* arr, int n)
{
    long i, mx = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(long* arr, int n, int exp)
{
    long output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

/**************************************************************************

  FUNCTION: ReadInData (*filename, *num)

	    This function reads in data from a file. It receives the
	    filename and an int address to store the number of elements
	    in the file.  The input file format is:

		n <number of elements>
		element 1
		element 2
		.
		.
		element n

     INPUT: filename	Pointer to unsorted array of elements
	    num		Pointer where to store n <number of elements>

    OUTPUT: num		Value of <number of elements> is stored at this
			location
	    ReadInData  Returns a pointer to the unsorted array of elements

**************************************************************************/

long *ReadInData(char *filename, int *num)
{
   FILE *file;  /* pointer to input file */
   long *L;     /* pointer to List */
   int i;       /* index of for loop */

   file = fopen(filename, "r");   /* open input file for reading. */
   if (file == NULL) {            /* see if file exists. */
      printf("\nFile %s could not be found\n", filename);
      strcpy(filename, NOFILE);
      return(NULL);               /* Return no List */
   } else {           /* file exists */
      /* Allocate memory for # of elements. If memory cannot be allocated,
	      display message and terminate program. Read in the elements. */

      printf("\nFile %s is now the input file.\n", filename);
      fscanf(file, "%d", num);
      L = CreateList(*num);
      if (L == NULL) {
        printf("\nCannot allocate enough memory for number list.\n");
        exit(0);
      }
      for (i = 0; i < (*num); ++i) {
        fscanf(file, "%ld", &L[i]);
      }
      fclose(file);     /* Close the input file */
      return(L);        /* Return the List */
   }
}

long *MakeRandomList(int *num)
{
   long *L;               /* pointer to List */
   unsigned int seed;     /* seed for random number generator */
   int i;                 /* index of for loop */
   FILE *o=fopen("outrandom.txt","w");
   printf("\nNumber of elements to sort=>");
   scanf("%d",num);

   printf("\nSeed for random number generator (integer)=>");
   scanf("%d",&seed);
   srand(seed);

   /* Allocate memory for # of elements. If memory cannot be allocated,
      display message and terminate program. Read in the elements. */
   L = CreateList(*num);
   if (L == NULL) {
      printf("\nCannot allocate enough memory for number list.\n");
      exit(0);
   }
   for (i = 0; i < *num; ++i)
   {
      L[i] = rand();
      fprintf(o,"%ld\n",L[i]);
   }
   fclose(o);

   return(L);           /* Return the List */
}

long *MakeIncreasingList(int *num)
{
   long *L;               /* pointer to List */
   int i;                 /* index of for loop */
   FILE *o=fopen("outinc.txt","w");
   printf("\nNumber of elements to sort=>");
   scanf("%d",num);

   /* Allocate memory for # of elements. If memory cannot be allocated,
      display message and terminate program. Read in the elements. */
   L = CreateList(*num);
   if (L == NULL) {
      printf("\nCannot allocate enough memory for number list.\n");
      exit(0);
   }
   for (i = 0; i < *num; ++i)
   {
      L[i] = i;
       fprintf(o,"%d\n",i);
    }
     fclose(o);

   return(L);           /* Return the List */
}

long *MakeDecreasingList(int *num)
{
   long *L;               /* pointer to List */
   int i;                 /* index of for loop */
   FILE *o=fopen("outdec.txt","w");
   printf("\nNumber of elements to sort=>");
   scanf("%d",num);

   /* Allocate memory for # of elements. If memory cannot be allocated,
      display message and terminate program. Read in the elements. */
   L = CreateList(*num);
   if (L == NULL) {
      printf("\nCannot allocate enough memory for number list.\n");
      exit(0);
   }
   for (i = 0; i < *num; ++i)
   {
      L[i] = *num - i - 1;
      fprintf(o,"%ld\n",L[i]);
    }
    fclose(o);
   return(L);           /* Return the List */
}



long *CreateList(int n)
/* Allocates memory for an array of n longs */
{
   long *L;

   L = (long *) malloc( n * sizeof(long) );
   if( L == NULL) { /* Exit program if memory cannot be allocated */
      printf("\nCannot allocate enough memory for list.\n");
      exit(0);
   }

   return (L);
}

void CopyList(long *copy, long *L, int n)
/* Copies an array L of n longs into an array copy */
{
   int i;       /* index of for loop */

   for( i=0; i < n; ++i) 
      copy[i] = L[i];      /* copy value into copy array */
}

void OutputList(long *L, int n)
/* Outputs an array of n longs to the screen */
{
   int i;

   for (i = 0; i < n; ++i)
      printf("%ld\n", L[i]);
   printf ("\n");
}


void GetFilename(char *s)
/* This function prompts the user to enter a filename string.  The user then
   enters the string and presses enter when done. */
{
   printf("\nEnter filename: ");     /* user prompted.          */
   scanf("%s", s);                   /* string entered by user. */
}

int IsActiveFile(char *fname)
/* Function returns 1 if there is an active input file in use. Otherwise,
   0 is returned */
{
   if( strcmp(fname, NOFILE) == 0 ) {
      printf ("\nThere is no active input file. You must specify an input file.\n");
      return (0);   /* There is no active input file */
   } else {
      return (1);   /* There is an active input file */
   }
}

void ShowResults(char *string, clock_t t1, clock_t t2, int n, char *filename)
{
  long micro = t2 - t1;               /* no. of cpu clock ticks*/
  float sec = (float) micro / CLOCKS_PER_SEC;  /* time in seconds */
  FILE *file;

  printf("\n\nResults:\n---------------------------------\n");
  printf("Sort: %s\n",&string[1]);
  printf("cpu clock ticks: %ld mS, Time: %.3f S\n",micro,sec);
  printf("Elements: %d\n",n);
  if (comparison_count!=0) {
    /*printf("T/C: %.3f\n",(float)(micro/comparison_count));*/
    printf("Comparisons: %lu\n\n",comparison_count);
  } else {
    printf ("Comparisons: N/A\n\n");
  }

  file = fopen(OUTPUTFILE, "a");   /* open output file for append. */
  if (file == NULL) {             /* see if problem exists. */
     printf("\nERROR Writing to %s\n", OUTPUTFILE);
  } else {           /* no error */
     fprintf (file,"%c%c %10d %15lu %15ld %.3f ",
               string[1],string[0],n,comparison_count,micro,sec);
     fprintf (file,"%s\n",filename);
     fclose (file);
  }  
}

void Check(long *L, int n)
/* Determines of a List is sorted in increasing order */
{
   int i;           /* index of for loop */
   int valid = 1;   /* initialize validity to TRUE */

   for (i = 1; i < n; ++i) {    /* walk down list */
      if( L[i-1] > L[i] ) {     /* If a greater value precedes a number: */
         valid = 0;            /* valid is FALSE. */
      }
   }

   if (valid) {  /* List is correctly sorted. Display message. */
      printf("List was sorted correctly\n");
   } else {        /* List is sorted incorrectly. Display message. */
      printf("List was sorted incorrectly\n");
   }
}

int Menu(void)
/* Displays user menu choices and returns value of user's choice */
{
   int  choice;      /* number associated with user's choice. */

   printf("\n");
   printf("============================\n");
   printf("        SORTING MENU        \n");
   printf("============================\n");
   printf("<Press the # of your choice>\n");
   printf("<   and then press Enter   >\n");
   printf("============================\n");
   printf("INPUT TYPE                  \n");
   printf("(0) Specify Input File      \n");
   printf("(1) Make Random Input List  \n");
   printf("(2) Make Increasing Input List  \n");
   printf("(3) Make Decreasing Input List  \n");
   printf("SORTING ALGORITHMS          \n");
   printf("(4) Insertion Sort          \n");
   printf("(5) Merge Sort              \n");
   printf("(6) Quick Sort (pivot 1)    \n");
   printf("(7) Quick Sort (random pivot)    \n");
   printf("(8) Quick Sort (median pivot)    \n");
   printf("(9) Heap Sort               \n");
   printf("(10) Radix Sort              \n");
   printf("(11) Exit                    \n");

   printf("\n\nchoice==>");
   scanf("%d", &choice);     /* user enters choice # */
	if ( !(choice >= INFILE && choice <= EXIT) )
      choice = -1;

   return (choice);          /* return value of user's choice */
}
