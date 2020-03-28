#include <vector>
#include <iostream>
#include <stdio.h>

int part1(std::vector<int> vec){
    vec[1] = 12;
    vec[2] = 2;
    int ip = 0;
    while(true){
        int op = vec[ip];
        if(op==99)
            break;
        int a = vec[vec[ip+1]];
        int b = vec[vec[ip+2]];
        int dest = vec[ip+3];
        if(op == 1)
            vec[dest] = a + b;
        else if(op == 2)
            vec[dest] = a * b;
        else
            break;
        ip += 4;
    }
    return vec[0];
}

int run_program(std::vector<int> vec){
    int ip = 0;
    while(true){
        int op = vec[ip];
        if(op==99)
            break;
        int a = vec[vec[ip+1]];
        int b = vec[vec[ip+2]];
        int dest = vec[ip+3];
        if(op == 1)
            vec[dest] = a + b;
        else
            vec[dest] = a * b;
        ip += 4;
    }
    return vec[0];
}

int part2(std::vector<int> vec){
    std::vector<std::vector<int> > ans;
    std::vector<int> cop;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            std::copy(vec.begin(),vec.end(),std::back_inserter(cop));
            cop[1] = i;
            cop[2] = j;
            int r = run_program(cop);
            if(r == 19690720)
                return 100*i+j;
            cop.clear();
        }
    }
}

int main(){

    std::vector<int> vec{1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,5,19,23,2,6,23,27,1,27,5,31,2,9,31,35,1,5,35,39,2,6,39,43,2,6,43,47,1,5,47,51,2,9,51,55,1,5,55,59,1,10,59,63,1,63,6,67,1,9,67,71,1,71,6,75,1,75,13,79,2,79,13,83,2,9,83,87,1,87,5,91,1,9,91,95,2,10,95,99,1,5,99,103,1,103,9,107,1,13,107,111,2,111,10,115,1,115,5,119,2,13,119,123,1,9,123,127,1,5,127,131,2,131,6,135,1,135,5,139,1,139,6,143,1,143,6,147,1,2,147,151,1,151,5,0,99,2,14,0,0};
    int val;
    //val = part1(vec);
    val = part2(vec);
    std::cout << val << std::endl;
    return 0;
}
