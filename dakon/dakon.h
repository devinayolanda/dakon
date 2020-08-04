#include "linkedlist.h"
#include "player.h"
#include <time.h>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class biji {
private:
	int bykbiji;
	sf::Sprite sprite;
	sf::Vector2f position;
	bool status;
public:
	biji() {
		bykbiji=0;
		status = false;
	}
	void settexture(sf::Texture &text_biji){
		sprite.setTexture(text_biji);
		sprite.setScale(0.4,0.4);
	}
	int getbykbiji(){
		return bykbiji;
	}
	sf::Sprite getSprite() {
		return sprite;
	}
	bool getStatus() {
		return status;
	}
	void setPosition(double x, double y) {
		sprite.setPosition(x, y);
		status = true;
	}
	void Rotate(double degree) {
		sprite.rotate(degree);
	}
	void setOrigin(double x, double y) {
		sprite.setOrigin(x, y);
	}
	void setScale(double x, double y) {
		sprite.setScale(x, y);
	}
	void draw(sf::RenderWindow &window) {
		window.draw(sprite);
	}
};

class lubang {
private:
	biji biji[100];
	bool besar, status, pos;
	int jumlah, nomor;
	char temp[100];
	sf::Font font;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Text jmlbiji;
	sf::Texture text_biji;
public:
	lubang(int jmlh=7){
		srand(time(NULL));
		status = true;
		besar = false;
		jumlah = jmlh;
		font.loadFromFile("fonts/ARLRDBD.ttf");
		jmlbiji.setCharacterSize(25);
		jmlbiji.setFont(font);
	}
	void minbiji(int x){
		jumlah-=x;
		if(jumlah<0){
			jumlah=0;
		}
	}
	void setNomor(int x) {
		nomor = x;
	}
	int getNomor() {
		return nomor;
	}
	void setPos(bool a){
		pos = a;
	}
	void setScale(double x, double y) {
		sprite.setScale(x, y);
	}
	void setPosition(double posx, double posy) {
		position.x = posx;
		position.y = posy;
		sprite.setPosition(position);
	}
	void setLubangBesar(int x){
		jumlah = 0;
		if(x == 7){
			text_biji.loadFromFile("images/mellows.png");
		} else if(x == 10){
			text_biji.loadFromFile("images/mellow2s.png");
		} else {
			text_biji.loadFromFile("images/mellow3s.png");
		}
		besar = true;
	}
	void addBiji(){
		jumlah++;
	}
	void addBiji(int x) {
		jumlah += x;
	}
	bool getPos(){
		return pos;
	}
	int getBiji(){
		int temp = jumlah;
		jumlah = 0;
		return temp;
	}
	int cekBiji(){
		return jumlah;
	}
	void disable() {
		status = false;
	}
	void setJumlah(int x) {
		jumlah = x;
		if(jumlah == 7){
			text_biji.loadFromFile("images/mellows.png");
		} else if(jumlah == 10){
			text_biji.loadFromFile("images/mellow2s.png");
		} else {
			text_biji.loadFromFile("images/mellow3s.png");
		}
	}
	sf::Vector2f getPosition() {
		sf::Vector2f posi;
		posi.x = position.x;
		posi.y = position.y;
		return posi;
	}
	void setTexture(sf::Texture &texture){
		sprite.setTexture(texture);
	}
	void draw(sf::RenderWindow &window, int postx, int posty) {
		if (!pos){
			if(Besar()){
				jmlbiji.setPosition((position.x+150) - sprite.getGlobalBounds().width/2, (position.y+40) - sprite.getGlobalBounds().height/2);
			} else {
				jmlbiji.setPosition((position.x+55) - sprite.getGlobalBounds().width/2, (position.y+30) - sprite.getGlobalBounds().height/2);
			}
		} else {
			if(Besar()){
				jmlbiji.setPosition((position.x+150) - sprite.getGlobalBounds().width/2, (position.y+40) - sprite.getGlobalBounds().height/2);
			} else {
				jmlbiji.setPosition((position.x+45) - sprite.getGlobalBounds().width/2, (position.y+50) - sprite.getGlobalBounds().height/2);
			}
		}
		sprintf(temp, "%d", jumlah);
		jmlbiji.setString(temp);
		setPosition(postx, posty);
		window.draw(sprite);
		for (int i=0; i<jumlah; i++) {
			if (!biji[i].getStatus()) {
				int degree = rand () % 361;
				int xbiji = rand () % 20 + (position.x + 42);
				int ybiji = rand () % 20 + (position.y + 40);
				biji[i].settexture(text_biji);
				biji[i].Rotate((double)degree);
				biji[i].setPosition(xbiji, ybiji);
				postx+=120;
			}
			biji[i].draw(window);
		}
		window.draw(jmlbiji);
	}
	bool getStat() {
		return status;
	}
	bool Besar() {
		return besar; 
	}
	bool isClicked(float x, float y){
		if(sprite.getGlobalBounds().contains(x, y)){
			return true;
		}
		return false;
	}
};