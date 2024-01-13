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
    fileTimes["ftv55.xml"] = 120;
    fileTimes["ftv170.xml"] = 240;
    fileTimes["rbg358.xml"] = 360;

    vector<string> fileNames{"ftv55.xml", "ftv170.xml", "rbg358.xml"};

    vector<int> populations{100, 500, 1000};

    for (const auto &fileName: fileNames) {
        graph.loadXML(fileName);
        vector<BestPath> bestCosts;
        int bestFileCost = INF;
        vector<int> bestPath;
        for (auto population: populations) {

            // OX crossover
            string fileNameTimeRelativeToCostOX =
                    "GA_TimeRelativeToCost_OX_POPULATION_" + to_string(population) + "_FILE_" + fileName;
            string fileNamePathOX = "GA_Path_OX_POPULATION_" + to_string(population) + "_FILE_" + fileName;
            GeneticAlgorithm gaOX(graph, fileTimes[fileName], population, 0.8, 0.01);
            int pathCostOX = gaOX.start(true);
            graph.saveTimeRelativeToCost(fileNameTimeRelativeToCostOX, gaOX.getTimeRelativeToCost());
            graph.savePath(fileNamePathOX, pathCostOX, gaOX.getFinalPath());

            // PX crossover
            string fileNameTimeRelativeToCostPX ="GA_TimeRelativeToCost_PX_POPULATION_" + to_string(population) + "_FILE_" + fileName;
            string fileNamePathPX = "GA_Path_PX_POPULATION_" + to_string(population) + "_FILE_" + fileName;
            GeneticAlgorithm gaPX(graph, fileTimes[fileName], population, 0.8, 0.01);
            int pathCostPX = gaPX.start(true);
            graph.saveTimeRelativeToCost(fileNameTimeRelativeToCostPX, gaPX.getTimeRelativeToCost());
            graph.savePath(fileNamePathPX, pathCostPX, gaPX.getFinalPath());
        }
    }
}