//
//  main.cpp
//  GA_1
//
//  Created by Liuliet.Lee on 3/2/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#define maxPopulation 1500
using namespace std;
using std::vector;

string target = "to be or not to be, that is the question.";
string best = "";
string population[maxPopulation] = { "" };
vector<string> matingPool = {};
int generation = 0;
int fitness[maxPopulation] = { 0 };

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
            if (population[i][j] == target[j]) {
                fitness[i]++;
            }
        }
        if (maxFitness < fitness[i]) {
            maxFitness = fitness[i];
            best = population[i];
        }
    }
    
    for (int i = 0; i < maxPopulation; i++) {
        int fit = fitness[i] * 100 / maxFitness;
        for (int j = 0; j < fit; j++) {
            matingPool.push_back(population[i]);
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
        population[i] = child;
        fitness[i] = 0;
    }
    generation++;
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < maxPopulation; i++) {
        population[i] = createNewString();
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
