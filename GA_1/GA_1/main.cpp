//
//  main.cpp
//  GA_1
//
//  Created by Liuliet.Lee on 3/2/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#define maxPopulation 1500
using namespace std;
using std::vector;

struct DNA {
    string text;
    int fitness;
};

string target = "to be or not to be, that is the question.";
string best = "";
DNA population[maxPopulation] = { "" };
vector<string> matingPool = {};
int generation = 0;

string createNewString() {
    string letters = "abcdefghijklmnopqrstuvwxyz,. ";
    string newString = "";
    for (int i = 0; i < target.length(); i++) {
        int n = rand() % (letters.length());
        string c = string(1, letters[n]);
        newString += c;
    }
    return newString;
}

void select() {
    int maxFitness = 0;
    for (int i = 0; i < maxPopulation; i++) {
        for (int j = 0; j < target.length(); j++) {
            if (population[i].text[j] == target[j]) {
                population[i].fitness++;
            }
        }
        population[i].fitness = pow(population[i].fitness, 2);
        if (maxFitness < population[i].fitness) {
            maxFitness = population[i].fitness;
            best = population[i].text;
        }
    }
    
    for (int i = 0; i < maxPopulation; i++) {
        int fit = population[i].fitness * 100 / maxFitness;
        for (int j = 0; j < fit; j++) {
            matingPool.push_back(population[i].text);
        }
    }
}

string mutate(string origin) {
    int n = rand() % 100;
    if (n < 20) {
        return createNewString();
    } else {
        return origin;
    }
}

void generate() {
    for (int i = 0; i < maxPopulation; i++) {
        string s1 = matingPool[rand() % matingPool.size()];
        string s2 = matingPool[rand() % matingPool.size()];
        int point = rand() % s1.length();
        string child = "";
        for (int j = 0; j < s1.length(); j++) {
            if (j < point) {
                child += string(1, s1[j]);
            } else {
                child += string(1, s2[j]);
            }
        }
        child = mutate(child);
        population[i].text = child;
        population[i].fitness = 0;
    }
    generation++;
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < maxPopulation; i++) {
        population[i].text = createNewString();
        population[i].fitness = 0;
    }
    
    select();
    while (best != target) {
        generate();
        matingPool.clear();
        select();
        cout << "Generation: " << generation << " " << best << endl;
    }
    
    return 0;
}
