#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;

class player{
private:
	bool status, win;
	int shield, attack, count;
public:
	player(){
		srand(time(NULL));
		shield = 0;
		attack = 0;
		count = 0;
		win = false;
		return;
	}
	void setstatus(bool a){
		status = a;
	}
	bool getstatus(){
		return status;
	}
	bool powerup(){
		int temp = rand()%2;
		if(temp == 1){
			if(shield != 2 || shield+attack != 2 || attack != 2){
				shield++;
				return true;
			}
		} else {
			if(shield != 2 || shield+attack != 2 || attack != 2){
				attack++;
				return true;
			}
		}
		cout<<getstatus()<<" INI PAS NAMBAH : "<<shield<<" "<<attack<<endl;
	}
	void countpower(){
		count++;
		if(count % 2 == 0){
			powerup();
			count = 0;
		}
	}
	bool useshield(){
		if(shield != 0){
			shield--;
			return true;
		} else {
			return false;
		}
	}
	bool useattack(){
		if(attack != 0){
			attack--;
			return true;
		} else {
			return false;
		}
	}
	void refresh(){
		count = 0;
	}
	int cekshield(){
		return shield;
	}
	int cekattack(){
		return attack;
	}
	void winner(){
		win = true;
	}
	bool getwinner(){
		return win;
	}
};