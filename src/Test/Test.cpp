//
// Created by Kamil Wojcieszak on 03/01/2024.
//

#include "Test.h"
#include <map>
#include "Graph/Graph.h"
#include "GeneticAlgorithm/GeneticAlgorithm.h"

void Test::test() {
    Graph graph;
    std::map<std::string, int> fileTimes;
    fileTimes["ftv55.xml"] = 5;
    fileTimes["ftv170.xml"] = 5;
    fileTimes["rbg358.xml"] = 5;

    vector<string> fileNames{"ftv55.xml", "ftv170.xml", "rbg358.xml"};

    vector<int> populations{100, 500, 1000};

    for (const auto &fileName: fileNames) {
        graph.loadXML(fileName);
        vector<BestPath> bestCosts;
        int bestFileCost = INF;
        vector<int> bestPath;
        for (auto population: populations) {
            for (int i = 0; i < 10; ++i) {
                string fileNameTimeRelativeToCost = "GA_TimeRelativeToCost_OX" + fileName;
                string fileNamePath = "GA_Path_OX" + fileName;
                GeneticAlgorithm ga(graph, fileTimes[fileName], population, 0.8, 0.01);
                int pathCost = ga.start(true);
                graph.saveTimeRelativeToCost(fileNameTimeRelativeToCost, ga.getTimeRelativeToCost());
                graph.savePath(fileNamePath, pathCost,ga.getFinalPath());
            }
        }
    }
}