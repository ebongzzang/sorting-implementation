//
// Created by sangbong on 8/3/18.
//

#ifndef SORTING_IMPLEMENTATION_KRUSKALSMST_H
#define SORTING_IMPLEMENTATION_KRUSKALSMST_H


#include <functional>
#include "UndirectedGraph.h"

class KruskalsMst {

public:
    static void buildMst(UndirectedGraph *graph);


private:
    static int find(struct subset subsets[], int i);

    static void doUnion(struct subset subsets[], int x, int y);


};


#endif //SORTING_IMPLEMENTATION_KRUSKALSMST_H
