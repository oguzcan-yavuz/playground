/*
ID: oguzcan1
PROG: milk2
LANG: C
*/
#include <stdio.h>
#include <stdbool.h>

void swap(int *arr, int *end, int i, int j){
    if(i == j) return;
    int temp = arr[i];
    int temp2 = end[i];
    arr[i] = arr[j];
    end[i] = end[j];
    arr[j] = temp;
    end[j] = temp2;
}

void quick_sort(int *arr, int *end, int length){
    if(length <= 0) return;

    int pivot = arr[length - 1], wall = 0;

    for(int i = 0; i < length - 1; i++)
        if(pivot > arr[i]) {
            swap(arr, end, wall, i);
            wall += 1;
        }

    swap(arr, end, wall, length - 1);
    // Sağ taraf için aynı işlemi yap.
    quick_sort(arr + wall + 1, end + wall + 1, length - wall - 1);
    // Sol taraf için aynı işlemi yap.
    quick_sort(arr, end, wall);
}

int not_milking(int start[], int end[], int length) {
    int result = 0;
    bool control = false;
    for(int j = 0; j < length - 1; j++) {
        if (end[j] < start[j + 1] && (start[j + 1] - end[j] > result)) {
            for(int i = 0; i < length; i++) {
                if(start[i] < start[j + 1] && end[i] > end[j + 1]) {
                    control = true;
                    break;
                }
            }
            if(control) {
                control = false;
                continue;
            }
            result = start[j + 1] - end[j];
        }
    }
    return result;
}

int milking(int start[], int end[], int length) {
    int pivot = 0, longest = end[pivot] - start[pivot];
    for(int i = 0; i < length; i++) {
        if (end[i] - start[i] > longest) {
            longest = end[i] - start[i];
        }
    }
    return longest;
}

void sequential(int *start, int *end, int length) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(i != j && ((end[i] == start[j] || (start[j] > start[i] && end[j] > end[i] && start[j] < end[i])) || (start[i] > start[j] && end[i] < end[j]))) {
                end[i] = end[j];
            }
        }
    }
}

int main() {
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    int n;
    fscanf(fin, "%d ", &n);
    // array in size of farmers
    int start[n];
    int end[n];
    // scan the input file
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d %d ", &start[i], &end[i]);
    }
    // edit the arrays in case of sequential data
    int *ptstart = start;
    int *ptend = end;
    quick_sort(ptstart, ptend, n);
    sequential(ptstart, ptend, n);
    // get the results
    int milk = milking(start, end, n);
    int not_milk = not_milking(start, end, n);
    // print results to output file
    fprintf(fout, "%d %d\n", milk, not_milk);
    return 0;
}

/* USACO SOLUTION:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXMILKING 5000

typedef struct Milking	Milking;
struct Milking {
    int begin;
    int end;
};

Milking milking[MAXMILKING];
int nmilking;

int
milkcmp(const void *va, const void *vb)
{
    Milking *a, *b;

    a = (Milking*)va;
    b = (Milking*)vb;

    if(a->begin > b->begin)
	return 1;
    if(a->begin < b->begin)
	return -1;
    return 0;
}

void
main(void)
{
    FILE *fin, *fout;
    int i, j, t, tmilk, tnomilk;
    Milking cur;

    fin = fopen("milk2.in", "r");
    fout = fopen("milk2.out", "w");
    assert(fin != NULL && fout != NULL);

    /* read input, sort 
    fscanf(fin, "%d", &nmilking);
    for(i=0; i<nmilking; i++)
	fscanf(fin, "%d %d", &milking[i].begin, &milking[i].end);

    qsort(milking, nmilking, sizeof(Milking), milkcmp);

    /* walk over list, looking for long periods of time 
    /* tmilk = longest milking time 
    /* tnomilk = longest non-milking time 
    /* cur = current span of milking time being considered 

    tmilk = 0;
    tnomilk = 0;
    cur = milking[0];
    for(i=1; i<nmilking; i++) {
	if(milking[i].begin > cur.end) {	/* a down time 
	    t = milking[i].begin - cur.end;
	    if(t > tnomilk)
		tnomilk = t;

	    t = cur.end - cur.begin;
	    if(t > tmilk)
		tmilk = t;

	    cur = milking[i];
	} else {	
	    if(milking[i].end > cur.end)
		cur.end = milking[i].end;
	}
    }
    
    /* check final milking period 
    t = cur.end - cur.begin;
    if(t > tmilk)
	tmilk = t;

    fprintf(fout, "%d %d\n", tmilk, tnomilk);
    exit(0);
}
/*Another Idea (from Jesse Ruderman)

The solution given for milk2 sorts milking periods by start and then walks through them. The solution page also mentions a second possible solution involving a huge array. Here's a third solution that sorts starting and stopping times together, and walks through the "events" of farmers starting and stopping to milk.

/* sort the starting and ending times, then go through them from
 start to finish, keeping track of how many farmers are milking
 between each "event" (a single farmer starting and stopping). 

#include <fstream.h>
#include <stdlib.h>

struct event
{
 long seconds;   /* seconds since 5 am 
 signed char ss; /* start = 1, stop = -1 (delta number of farmers milking)

};

int eventcmp (const event *a, const event *b)
{
 if (a->seconds != b->seconds)
  return (a->seconds - b->seconds); /* 300 before 500 

 return (b->ss - a->ss); /* 1 (start) before -1 (stop) 
}

int main ()
{
 ifstream in;
 ofstream out;

 in.open("milk2.in");
 out.open("milk2.out");

 int num_intervals, num_events, i;
 event events[5000 * 2];

 in >> num_intervals;
 num_events = num_intervals * 2;
 for (i = 0; i < num_intervals; ++i)
 {
  in >> events[2*i  ].seconds; events[2*i  ].ss = 1;
  in >> events[2*i+1].seconds; events[2*i+1].ss = -1;
 }

 qsort(events, num_events, sizeof(event),
  (int(*)(const void*, const void*)) eventcmp);

/* for (i = 0; i < num_events; ++i)
  out << events[i].seconds
    << (events[i].ss == 1 ? " start" : " stop") << endl;

 int num_milkers = 0, was_none = 1;
 int longest_nomilk = 0, longest_milk = 0;
 int istart, ilength;

 for (i = 0; i < num_events; ++i)
 {
  num_milkers += events[i].ss;

  if (!num_milkers && !was_none)
  {
   /* there are suddenly no milkers. 
   ilength = (events[i].seconds - istart);
   if (ilength > longest_milk)
    longest_milk = ilength;
   istart = events[i].seconds;
  }
  else if (num_milkers && was_none)
  {
   /* there are suddenly milkers. 
   if (i != 0)
   {
    ilength = (events[i].seconds - istart);
    if (ilength > longest_nomilk)
     longest_nomilk = ilength;
   }
   istart = events[i].seconds;
  }

  was_none = (num_milkers == 0);
 }

 out << longest_milk << " " << longest_nomilk << endl;

 return 0;
}
*/