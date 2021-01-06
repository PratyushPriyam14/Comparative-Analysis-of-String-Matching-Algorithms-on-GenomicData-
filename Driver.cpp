#include<stdio.h>
#include<string.h>
#include<time.h>
#include"a.h"
#include"b.h"
#include"c.h"


// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void RabinKarp(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                printf("Pattern found at index by rabin karp %d\n", i);
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }
    }
}


/* Driver Code */
int main()
{
    char txt[700000] ;
   // printf("enter the text");
    FILE *fptr;
    if ((fptr = fopen("txt.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.

    }

    // reads text until newline is encountered
    fscanf(fptr, "%[^\n]", txt);
    printf("Data from the text file:\n%s", txt);
  // printf("\nLen = %i", strlen(txt));
    fclose(fptr);

   // gets(txt);
    char pat[10000] ;

    //printf("enter the pattern");
   // gets(pat);
   FILE *fptr2;
    if ((fptr2 = fopen("pat.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.

    }

    // reads text until newline is encountered
    fscanf(fptr2, "%[^\n]", pat);
    printf("\n Data from the pattern file:\n%s", pat);
   //printf("\nLen = %i", strlen(pat));
    fclose(fptr2);
    printf("\n");

      // A prime number
    int q = 101;
    // function call
       clock_t t1,t2,t4,t5,t7,t8,t10,t11;
       double t3,t6,t9,t12;

      // function call
      t1= clock();
      RabinKarp(pat, txt, q);
      t2= clock();
	  t3 = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", t3 );


	  t4= clock();
  	  Boyer(txt, pat);
      t5= clock();
	  t6 = ((double)(t5 -t4)) / CLOCKS_PER_SEC;
      printf("\nTotal time taken by CPU: %f\n\n", t6 );



		t7= clock();
    	KMPSearch(pat, txt);
    	t8= clock();
		t9 = ((double)(t8-t7)) / CLOCKS_PER_SEC;
    	printf("Total time taken by CPU: %f\n", t9 );


	t10= clock();
    Finite(pat, txt);
    t11= clock();
	t12 = ((double)(t11 - t10)) / CLOCKS_PER_SEC;
    printf("\nTotal time taken by CPU: %f\n", t12 );
    return 0;
}
