#include "DisjointSets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjointSets::DisjointSets( int numElements ) : s( numElements, -1 )
{
}

/**
 * Union two disjoint sets.
 */
void DisjointSets::unionSets( int root1, int root2 )
{
    int root1Parent = find(root1);
    int root2Parent = find(root2);
    
    if (root1Parent != root2Parent) {
        s[root2Parent] = root1Parent;
    }
}


/**
 * Perform a find (does not change anything).
 * Return the set containing x.
 */
int DisjointSets::find( int x ) const
{
   if (s[x] == -1) {
        return x;
    } else {
        return find(s[x]);
    }

}
/**
 * Perform a find with path compression (the mutator version).
 * Return the set containing x.
 */
int DisjointSets::find( int x )
{
   if (s[x] == -1) {
        return x;  
    } else {
        s[x] = find(s[x]);  
        return s[x];
    }
}