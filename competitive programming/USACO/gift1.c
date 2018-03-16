/*
ID: oguzcan1
PROG: gift1
LANG: C
*/
#include <stdio.h>
#include <string.h>

void make_calculations(char names[][15], int moneys[], int np, FILE *fin) {
    // who is gonna give money?
    char giver[15];
    fscanf(fin, "%s", giver);
    int index = 0;
    // find the index of the giver in names two-dimensional array
    for(; index < np; index++) {
        if(strcmp(names[index], giver) == 0) {
            break;
        }
    }
    // how many he/she will give and how many times he/she will give
    int money;
    int share;
    fscanf(fin, "%d %d", &money, &share);
    // if the giver is stingy, return. because we don't want a floating point exception
    if(money == 0) {
        return;
    }
    // calculate how much people will get money
    int pay = money / share;
    // decrase the money of the giver
    moneys[index] -= money - money % share;
    // scan for shares
    for(int i = 0; i < share; i++) {
        char lucky[15];
        fscanf(fin, "%s", lucky);
        int j = 0;
        for(; j < np; j++) {
            if(strcmp(names[j], lucky) == 0) {
                break;
            }
        }
        moneys[j] += pay;
    }
}

int main() {
    // main variables
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");
    int np;
    fscanf(fin, "%d", &np);
    
    // create names and moneys array's at np sizes
    char names[np][15];
    int moneys[np];
    
    // initialize everyone's money to 0
    for(int i = 0; i < np; i++) {
        moneys[i] = 0;
    }
    
    // get everyone's names
    for(int i = 0; i < np; i++) {
        fscanf(fin, "%s", names[i]);
    }
    
    // make calculations for everyone
    for(int i = 0; i < np; i++) {
        make_calculations(names, moneys, np, fin);    
    }
    // print the results to an output file
    for(int i = 0; i < np; i++) {
        fprintf(fout, "%s %d\n", names[i], moneys[i]);
    }
    return 0;
}

/* USACO Solution:
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXPEOPLE 10
#define NAMELEN	32

typedef struct Person Person;
struct Person {
    char name[NAMELEN];
    int total;
};

Person people[MAXPEOPLE];
int npeople;

void
addperson(char *name)
{
    assert(npeople < MAXPEOPLE);
	strcpy(people[npeople].name, name);
    npeople++;
}

Person*
lookup(char *name)
{
    int i;

    /* look for name in people table
    for(i=0; i<npeople; i++)
	if(strcmp(name, people[i].name) == 0)
	    return &people[i];

    assert(0);	/* should have found name 
}

int
main(void)
{
    char name[NAMELEN];
    FILE *fin, *fout;
    int i, j, np, amt, ng;
    Person *giver, *receiver;

    fin = fopen("gift1.in", "r");
    fout = fopen("gift1.out", "w");

    fscanf(fin, "%d", &np);
    assert(np <= MAXPEOPLE);

    for(i=0; i<np; i++) {
	fscanf(fin, "%s", name);
	addperson(name);
    }

    /* process gift lines 
    for(i=0; i<np; i++) {
	fscanf(fin, "%s %d %d", name, &amt, &ng);
	giver = lookup(name);

	for(j=0; j<ng; j++) {
	    fscanf(fin, "%s", name);
	    receiver = lookup(name);
	    giver->total -= amt/ng;
	    receiver->total += amt/ng;
	}
    }

    /* print gift totals 
    for(i=0; i<np; i++)
	fprintf(fout, "%s %d\n", people[i].name, people[i].total);
    exit (0);
}
*/

