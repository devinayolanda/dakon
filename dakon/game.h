#include "dakon.h"
#include "player.h"
#include "powerup.h"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game {
protected:
	LList<lubang> llubang;
	lubang lubangs, lubangBesar1, lubangBesar2;
	player player1, player2;
	Powerup powerup[2];
	papan papan;
public:
	Game(int jmlhlubang, int jmlhbiji){
		lubangs.setJumlah(jmlhbiji);
		lubangBesar1.setLubangBesar();
		lubangBesar2.setLubangBesar();
		llubang.add(lubangBesar1);
		for (int i = 0; i < jmlhlubang; i++){
			llubang.add(lubangs);
		}
		llubang.add(lubangBesar2);
		for (int i = 0; i < jmlhlubang; i++){
			llubang.add(lubangs);
		}
	}

	void setNamaPlayer1(string _nama){
		player1.setnama(_nama);
	}

	void setNamaPlayer2(string _nama){
		player2.setnama(_nama);
	}
};