//
//  main.cpp
//  Matches
//
//  Created by Liuliet.Lee on 1/7/2016.
//  Copyright © 2016 Liuliet.Lee. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int dic[19] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 8, 4, 7, 7, 6, 7, 8, 5, 9};
    int n;
    cin >> n;
    int num = n - 4;
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            int sum = i + j;
            int sumSticks = dic[i] + dic[j];
            
            if (sum >= 19) {
                int ten = sum * 0.1;
                int one = sum - ten * 10;
                sumSticks += dic[ten] + dic[one];
            } else {
                sumSticks += dic[sum];
            }
            
            if (sumSticks == num) {
                cout << i << " + " << j << " = " << sum << endl;
            }
        }
    }
    
    return 0;
}
