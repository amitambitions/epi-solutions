/*
    Problem:
        Given 3 pegs and 'n' no. of rings each of increasing diameter. All the
        rings are initially on any one of the 'source' pegs and the remaining pegs are empty. Shift the pegs 
        from initial peg to 'destination' peg in minimum number of steps. We cannot place a bigger peg on top of smaller one.

    Input:
        n = no. of rings
        src = source/initial peg
        dest = destination peg 

    Output:
        Print each move made 
*/

#include<iostream>
#include<array>
#include<stack>
using namespace std;

const int num_pegs = 3;

// Driver function for the Hanoi steps function
void towerHanoiDriver(int num_rings, int src, int dest, int aux){
    // for storing peg states
    array< stack<int>, num_pegs> pegs;
    
    // initialize the initial peg with rings
    for(int i = num_rings; i >= 0; i--){
        pegs[src].push(i);
    }
    
    // do the required moves
    towerOfHanoiMove(pegs, num_rings, src, dest, aux);
} 

// performs and prints one move of moving the ring 
/* 
// for moving the rings to the dest peg, we first use the auxiallary peg
// to move the n-1 rings. We then move the largest ring to the dest peg and 
// then using the initial peg as auxiallary peg, we move the n-1 rings from
// the current auxillary peg to the dest peg 
*/
void towerOfHanoiMove(array< stack<int>, num_pegs>& peg, int num_rings, 
                                            int src, int dest, int aux){
    // base condition
    if(num_rings > 0){
        // first move the n-1 rings to the auxillary peg
        towerOfHanoiMove(num_rings-1, src, aux, dest);

        // move the last ring to the destination peg

    }
}

int main(){
    
    return 0;
}