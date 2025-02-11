#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int max_health = health;
    int heal_time = bandage[0];
    int heal = bandage[1];
    int bonus = bandage[2];
    int now_time = 1;
    int nonstop = 0;
    for(auto attack : attacks){
        int attack_time = attack[0];
        int attack_damage = attack[1];
        for(int i=now_time;i<attack_time;i++){
            now_time++;
            nonstop++;
            health+=heal;
            if(nonstop==heal_time){
                health += bonus;
                nonstop = 0;
            }            
            health = min(max_health, health);
            cout << health << " ";
        }
        now_time++;
        nonstop=0;
        health -= attack_damage;
        if(health <=0){
            answer = -1;
            return answer;
        }
        cout << health << " ";
        
    }
    answer = health;
    return answer;
}