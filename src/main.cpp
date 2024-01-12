#include "Graph/Graph.h"
#include "Menu/Menu.h"
#include "GeneticAlgorithm/GeneticAlgorithm.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Graph graph;
    int time = 5;
    int population = 1000;
    float mutations = 0.01;
    float crosses = 0.8;
    graph.loadXML("burma14.xml");

	graph.printMatrix();
    GeneticAlgorithm ga(graph, time, population, crosses, mutations);
    ga.start(false);
    cout << ga.toString();
//    Menu menu;
//    menu.enable();
}
