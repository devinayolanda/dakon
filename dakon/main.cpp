#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include<iostream>
#include "dakon.h"
using namespace std;

sf::RenderWindow window(sf::VideoMode(1366, 768), "Dakon"/*, sf::Style::Fullscreen*/);

//Texture
sf::Texture text_background;
sf::Texture text_backbutt;
sf::Texture text_biji7; sf::Texture text_biji10; sf::Texture text_biji12;
sf::Texture text_img;
sf::Texture text_lubang5; sf::Texture text_lubang7;
sf::Texture text_startbutt;
sf::Texture text_lubk;
sf::Texture text_biji;
sf::Texture text_lubang;
sf::Texture text_menu;
sf::Texture text_shield1;
sf::Texture text_shield2;
sf::Texture text_sword1;
sf::Texture text_sword2;
sf::Texture text_ready;
sf::Texture text_pause;
sf::Texture text_ketsw;
sf::Texture text_ketsh;
sf::Texture text_win;

//Sprite
sf::Sprite spr_background;
sf::Sprite spr_backbutt;
sf::Sprite spr_biji7; sf::Sprite spr_biji10; sf::Sprite spr_biji12;
sf::Sprite spr_img;
sf::Sprite spr_lubang5; sf::Sprite spr_lubang7;
sf::Sprite spr_startbutt;
sf::Sprite spr_lubk;
sf::Sprite spr_menu;
sf::Sprite spr_ready;
sf::Sprite spr_shield1;
sf::Sprite spr_shield2;
sf::Sprite spr_sword1;
sf::Sprite spr_sword2;
sf::Sprite spr_pause;
sf::Sprite spr_ketsw;
sf::Sprite spr_ketsh;
sf::Sprite spr_win;

//Sound
sf::SoundBuffer sb_backsound;
sf::Sound backsound;

//Time
sf::Time h_time;
sf::Clock h_clock;

void drawlubang(sf::RenderWindow &window, LList<lubang> llubang, int byklubang, bool turn, player &p1, player &p2);
void nembak(int nomor, Node<lubang> *head, Node<lubang> *counter, bool turn, int byklubang);
void move(Node<lubang> *temp, LList<lubang> llubang, sf::RenderWindow &window, int biji, bool &ambil, bool &turn,int shield, bool &cek, player &p1, player &p2, int byklubang);
int getdpn(int nomor);
int shield(int shield);

void play(int bykbiji, int byklubang);

void main(){
	if(!sb_backsound.loadFromFile("musics/backgroundsound.ogg")){
		std::cout<<"Error"<<std::endl;
	}
	/*backsound.setBuffer(sb_backsound);
	backsound.setVolume(200);
	backsound.play();*/
home:
	text_background.loadFromFile("images/mainmenu2.png");
	spr_background.setTexture(text_background);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
				if((mouse_x>=420 && mouse_x<=655) && (mouse_y>=506 && mouse_y<=570)){
					goto start;
				} else if ((mouse_x>=708 && mouse_x<=949) && (mouse_y>=506 && mouse_y<=567)){
					backsound.stop();
					window.close();
				}
			}
		}
		window.clear();
		window.draw(spr_background);
		window.display();
	}

start:
	int bykbiji=0, byklubang=0, check1=0, check2=0;
	bool checkstart=false;

	text_background.loadFromFile("images/BG2.png");
	spr_background.setTexture(text_background);

	text_backbutt.loadFromFile("images/back.png");
	spr_backbutt.setTexture(text_backbutt);
	spr_backbutt.setPosition(50, 50);

	text_biji7.loadFromFile("images/DAKON7.png");
	spr_biji7.setTexture(text_biji7);
	spr_biji7.setScale(0.3,0.3);
	spr_biji7.setPosition(150,280);

	text_biji10.loadFromFile("images/DAKON10.png");
	spr_biji10.setTexture(text_biji10);
	spr_biji10.setScale(0.3,0.3);
	spr_biji10.setPosition(270,280);

	text_biji12.loadFromFile("images/DAKON12.png");
	spr_biji12.setTexture(text_biji12);
	spr_biji12.setScale(0.3,0.3);
	spr_biji12.setPosition(390,280);

	text_lubang5.loadFromFile("images/LUBANG5.png");
	spr_lubang5.setTexture(text_lubang5);
	spr_lubang5.setScale(0.3,0.3);
	spr_lubang5.setPosition(150, 480);

	text_lubang7.loadFromFile("images/LUBANG7.png");
	spr_lubang7.setTexture(text_lubang7);
	spr_lubang7.setScale(0.3,0.3);
	spr_lubang7.setPosition(270, 480);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
				if((mouse_x>=51 && mouse_x<=210) && (mouse_y>=51 && mouse_y<=92)){
					check1=0; check2=0; bykbiji=0; byklubang=0;
					goto home;
				} else if ((mouse_x>=161 && mouse_x<=236) && (mouse_y>=278 && mouse_y<=363)){
					bykbiji=7; check1=1;
				} else if ((mouse_x>=276 && mouse_x<=362) && (mouse_y>=278 && mouse_y<=363)){
					bykbiji=10; check1=1;
				} else if ((mouse_x>=397 && mouse_x<=481) && (mouse_y>=278 && mouse_y<=363)){
					bykbiji=12; check1=1;
				} else if ((mouse_x>=161 && mouse_x<=236) && (mouse_y>=474 && mouse_y<=568)){
					byklubang=5; check2=1;
				} else if ((mouse_x>=276 && mouse_x<=362) && (mouse_y>=474 && mouse_y<=568)){
					byklubang=7; check2=1;
				}
			}
			if(check1==1 && check2==1){
				checkstart=true;
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
				if((mouse_x>=1149 && mouse_x<=1309) && (mouse_y>=683 && mouse_y<=720) && checkstart==true){
					//play(bykbiji, byklubang);
					goto play;
				}
			}
		}
		window.clear();
		window.draw(spr_background);
		window.draw(spr_backbutt);
		window.draw(spr_biji7);
		window.draw(spr_biji10);
		window.draw(spr_biji12);
		window.draw(spr_lubang5);
		window.draw(spr_lubang7);

		if(bykbiji==7){
			text_img.loadFromFile("images/mellow.png");
			spr_img.setTexture(text_img);
			spr_img.setPosition(800,230);
			spr_img.setScale(0.3,0.3);

			text_biji7.loadFromFile("images/DAKON7C.png");
			spr_biji7.setTexture(text_biji7);
			spr_biji7.setPosition(150, 280);

			text_biji10.loadFromFile("images/DAKON10.png");
			spr_biji10.setTexture(text_biji10);
			spr_biji10.setPosition(270, 280);

			text_biji12.loadFromFile("images/DAKON12.png");
			spr_biji12.setTexture(text_biji12);
			spr_biji12.setPosition(390, 280);
			
			window.draw(spr_img);
			window.draw(spr_biji7);
			window.draw(spr_biji10);
			window.draw(spr_biji12);
		} else if(bykbiji==10){
			text_img.loadFromFile("images/mellow2.png");
			spr_img.setTexture(text_img);
			spr_img.setPosition(800,230);
			spr_img.setScale(0.3,0.3);

			text_biji7.loadFromFile("images/DAKON7.png");
			spr_biji7.setTexture(text_biji7);
			spr_biji7.setPosition(150, 280);

			text_biji10.loadFromFile("images/DAKON10C.png");
			spr_biji10.setTexture(text_biji10);
			spr_biji10.setPosition(270, 280);

			text_biji12.loadFromFile("images/DAKON12.png");
			spr_biji12.setTexture(text_biji12);
			spr_biji12.setPosition(390, 280);

			window.draw(spr_img);
			window.draw(spr_biji7);
			window.draw(spr_biji10);
			window.draw(spr_biji12);
		} else if(bykbiji==12){
			text_img.loadFromFile("images/mellow3.png");
			spr_img.setTexture(text_img);
			spr_img.setPosition(800,230);
			spr_img.setScale(0.3,0.3);

			text_biji7.loadFromFile("images/DAKON7.png");
			spr_biji7.setTexture(text_biji7);
			spr_biji7.setPosition(150, 280);

			text_biji10.loadFromFile("images/DAKON10.png");
			spr_biji10.setTexture(text_biji10);
			spr_biji10.setPosition(270, 280);

			text_biji12.loadFromFile("images/DAKON12C.png");
			spr_biji12.setTexture(text_biji12);
			spr_biji12.setPosition(390, 280);

			window.draw(spr_img);
			window.draw(spr_biji7);
			window.draw(spr_biji10);
			window.draw(spr_biji12);
		} else {}

		if(byklubang==5){
			text_lubang5.loadFromFile("images/LUBANG5C.png");
			spr_lubang5.setTexture(text_lubang5);
			spr_lubang5.setPosition(150, 480);

			text_lubang7.loadFromFile("images/LUBANG7.png");
			spr_lubang7.setTexture(text_lubang7);
			spr_lubang7.setPosition(270, 480);

			window.draw(spr_lubang5);
			window.draw(spr_lubang7);
		} else if(byklubang==7){
			text_lubang5.loadFromFile("images/LUBANG5.png");
			spr_lubang5.setTexture(text_lubang5);
			spr_lubang5.setPosition(150, 480);

			text_lubang7.loadFromFile("images/LUBANG7C.png");
			spr_lubang7.setTexture(text_lubang7);
			spr_lubang7.setPosition(270, 480);
			
			window.draw(spr_lubang5);
			window.draw(spr_lubang7);
		} else {}

		if(check1==1 && check2==1){
			text_startbutt.loadFromFile("images/start.png");
			spr_startbutt.setTexture(text_startbutt);
			spr_startbutt.setPosition(1150, 680);
			window.draw(spr_startbutt);
			checkstart=true;
		} else {}

		window.display();
	}

play:
	bool turn = true, cek=false, ambil=false;

	text_background.loadFromFile("images/dakon_board.png");
	spr_background.setTexture(text_background);

	text_menu.loadFromFile("images/PAUSE.png");
	spr_menu.setTexture(text_menu);
	spr_menu.setPosition(30,30);

	text_pause.loadFromFile("images/PAUSE_CARD.png");
	spr_pause.setTexture(text_pause);

	text_ready.loadFromFile("images/PLAYER_READY.png");
	spr_ready.setTexture(text_ready);

	text_ketsw.loadFromFile("images/SWORD_CARD.png");
	spr_ketsw.setTexture(text_ketsw);

	text_ketsh.loadFromFile("images/SHIELD_CARD.png");
	spr_ketsh.setTexture(text_ketsh);

	LList<lubang> llubang;
	lubang lubangs, lubangBesar1, lubangBesar2;
	player p1, p2;
	p1.setstatus(true);
	p2.setstatus(false);
	
	text_lubk.loadFromFile("images/lubang_kecil.png");
	spr_lubk.setTexture(text_lubk);
	lubangs.setJumlah(bykbiji);
	int nomor = 1;
	lubangBesar1.setLubangBesar(bykbiji);
	lubangBesar2.setLubangBesar(bykbiji);

	lubangBesar1.setPos(false);
	lubangBesar1.setTexture(text_lubk);
	lubangBesar1.setNomor(nomor);
	nomor++;
	llubang.add(lubangBesar1);
	for (int i = 0; i < byklubang; i++){
		lubangs.setPos(true);
		lubangs.setTexture(text_lubk);
		lubangs.setNomor(nomor);
		llubang.add(lubangs);
		nomor++;
	}
	lubangBesar2.setPos(true);
	lubangBesar2.setTexture(text_lubk);
	lubangBesar2.setNomor(nomor);
	nomor++;
	llubang.add(lubangBesar2);
	for (int i = 0; i < byklubang; i++){
		lubangs.setPos(false);
		lubangs.setTexture(text_lubk);
		lubangs.setNomor(nomor);
		llubang.add(lubangs);
		nomor++;
	}
	bool cekpause=false, cekp=false, cekwin1=false, cekwin2=false;
	int checkexit=2;
	//untuk jalan
	Node<lubang> *temp;
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
				if((mouse_x>=20 && mouse_x<=90) && (mouse_y>=20 && mouse_y<=90)){
					cekp=true;
					cekpause=false;
				} else {
					if(cekp==true){
						cekpause=true;
						checkexit=2;
						if((mouse_x>=555 && mouse_x<=811) && (mouse_y>=380 && mouse_y<=424)){
							//restart
							goto play;
						} else if ((mouse_x>=871 && mouse_x<=924) && (mouse_y>=51 && mouse_y<=104)){
							//cancel
							checkexit=3;
							cekp=false;
						} else if ((mouse_x>=555 && mouse_x<=811) && (mouse_y>=457 && mouse_y<=504)){
							//balik ke home
							goto home;
						}
					} else {
						cekp=false;
						temp = llubang.gethead();
						cek = false;
						int cp1 = 0, cp2 = 0;
						do{
							if((temp->getdata()->cekBiji() > 0 || temp->getdata()->getNomor() < byklubang + 2) && !temp->getdata()->Besar()){
								cp1++;
							} else if((temp->getdata()->cekBiji() > 0 || temp->getdata()->getNomor() > byklubang + 2) && !temp->getdata()->Besar()){
								cp2++;
							}
							temp = temp->getNext();
						} while(temp != llubang.gethead());
						if(cp1 == byklubang){
							cek = true;
							if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
								float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
								if((mouse_x>=557 && mouse_x<=807) && (mouse_y>=559 && mouse_y<=607)){
									goto home;
								}
							}
						} else if(cp2 == byklubang){
							cek = true;
							if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
								float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
								if((mouse_x>=557 && mouse_x<=807) && (mouse_y>=559 && mouse_y<=607)){
									goto home;
								}
							}
						}
						//cek apakah biji di papan habis
						if(cek == false){
							if(ambil == false){
								if(event.type == sf::Event::MouseButtonPressed){
									if(event.mouseButton.button == sf::Mouse::Left){
										temp = llubang.gethead();
										do{
											if(temp->getdata()->isClicked(event.mouseButton.x, event.mouseButton.y) && !temp->getdata()->Besar() && turn == temp->getdata()->getPos() && temp->getdata()->cekBiji() != 0){
												ambil = true;
												break;
											}
											temp = temp->getNext();
										} while (temp != llubang.gethead());
									}
								}
							}
						} else {
							temp = llubang.gethead();
							int b1;
							int b2 = temp->getdata()->cekBiji();
							do{
								if(temp->getdata()->getPos() == true && temp->getdata()->Besar()){
									b1 = temp->getdata()->cekBiji();
									break;
								}
								temp = temp->getNext();
							} while (temp != llubang.gethead());

							if(b1 < b2){
								p2.winner();
							} else if(b1>b2){
								p1.winner();
							} else {
								if(cp1 == byklubang){
									p1.winner();
								} else {
									p2.winner();
								}
							}
							  
							//kalo sudah ada salah satu menang :D					
							if(p1.getwinner()){
								cekwin1=true; cekwin2=false;
								if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
									float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
									if((mouse_x>=30 && mouse_x<=90) && (mouse_y>=30 && mouse_y<=90)){
										goto home;
									}
								}
							} else if(p2.getwinner()){
								cekwin2=true; cekwin1=false;
								if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
									float mouse_x = event.mouseButton.x, mouse_y = event.mouseButton.y;
									if((mouse_x>=30 && mouse_x<=90) && (mouse_y>=30 && mouse_y<=90)){
										goto home;
									}
								}
							}
						}
						int shield=0;
						if(ambil){
							int abiji = temp->getdata()->getBiji();
							move(temp, llubang, window, abiji, ambil, turn, shield, cek, p1, p2, byklubang);
						}
					}
				}
			}
		}
		window.clear();
		window.draw(spr_background);
		window.draw(spr_menu);
		
		drawlubang(window, llubang,byklubang, turn, p1, p2);
		if(cekpause==true){
			window.draw(spr_pause);
		}
		if(checkexit==3){
			drawlubang(window, llubang,byklubang, turn, p1, p2);
			cekp=false;
			cekpause=false;
		}
		if(cekwin1==true){
			text_win.loadFromFile("images/WIN1.png");
			spr_win.setTexture(text_win);
			window.draw(spr_win);
		} else if(cekwin2==true){
			text_win.loadFromFile("images/WIN2.png");
			spr_win.setTexture(text_win);
			window.draw(spr_win);
		}
		window.display();
	}
}

void drawlubang(sf::RenderWindow &window, LList<lubang> llubang, int byklubang, bool turn, player &p1, player &p2){
	window.draw(spr_background);
	window.draw(spr_menu);

	// ability untuk player 1
	if(p1.cekshield() == 1){
		text_shield1.loadFromFile("images/player1_shield_1.png");
		spr_shield1.setTexture(text_shield1);
		spr_shield1.setPosition(480,-35);
		window.draw(spr_shield1);
	}
	else if(p1.cekshield() == 2){
		text_shield1.loadFromFile("images/player1_shield_2.png");
		spr_shield1.setTexture(text_shield1);
		spr_shield1.setPosition(480,-35);
		window.draw(spr_shield1);
	}
	else {
		text_shield1.loadFromFile("images/player1_shield_none.png");
		spr_shield1.setTexture(text_shield1);
		spr_shield1.setPosition(480,-35);
		window.draw(spr_shield1);
	}

	if(p1.cekattack() == 1){
		text_sword1.loadFromFile("images/player1_sword_1.png");
		spr_sword1.setTexture(text_sword1);
		spr_sword1.setPosition(680,-35);
		window.draw(spr_sword1);
	}
	else if(p1.cekattack() == 2){
		text_sword1.loadFromFile("images/player1_sword_2.png");
		spr_sword1.setTexture(text_sword1);
		spr_sword1.setPosition(680,-35);
		window.draw(spr_sword1);
	}
	else {
		text_sword1.loadFromFile("images/player1_sword_none.png");
		spr_sword1.setTexture(text_sword1);
		spr_sword1.setPosition(680,-35);
		window.draw(spr_sword1);
	}

	// ability untuk player 2
	if(p2.cekshield() == 1){
		text_shield2.loadFromFile("images/player2_shield_1.png");
		spr_shield2.setTexture(text_shield2);
		spr_shield2.setPosition(680,583);
		window.draw(spr_shield2);
	}
	else if(p2.cekshield() == 2){
		text_shield2.loadFromFile("images/player2_shield_2.png");
		spr_shield2.setTexture(text_shield2);
		spr_shield2.setPosition(680,583);
		window.draw(spr_shield2);
	}
	else {
		text_shield2.loadFromFile("images/player2_shield_none.png");
		spr_shield2.setTexture(text_shield2);
		spr_shield2.setPosition(680,583);
		window.draw(spr_shield2);
	}

	if(p2.cekattack() == 1){
		text_sword2.loadFromFile("images/player2_sword_1.png");
		spr_sword2.setTexture(text_sword2);
		spr_sword2.setPosition(480,583);
		window.draw(spr_sword2);
	}
	else if(p2.cekattack() == 2){
		text_sword2.loadFromFile("images/player2_sword_2.png");
		spr_sword2.setTexture(text_sword2);
		spr_sword2.setPosition(480,583);
		window.draw(spr_sword2);
	}
	else {
		text_sword2.loadFromFile("images/player2_sword_none.png");
		spr_sword2.setTexture(text_sword2);
		spr_sword2.setPosition(480,583);
		window.draw(spr_sword2);
	}

	if(turn==true){
		spr_ready.setPosition(1000,15);
		window.draw(spr_ready);
	} else {
		spr_ready.setPosition(1000,700);
		window.draw(spr_ready);
	}

	Node<lubang> *temp;
	temp = llubang.gethead();
	if(byklubang == 5){
		int posx=273;
		temp->getdata()->setScale(1.5,1.5);
		temp->getdata()->draw(window, 100, 300);
		temp = temp->getNext();
		for(int i=0; i<5; i++){
			temp->getdata()->draw(window, posx, 236);
			temp = temp->getNext();
			posx+=180;
		}
		posx=993;
		temp->getdata()->setScale(1.5,1.5);
		temp->getdata()->draw(window, 1100, 300);
		temp = temp->getNext();
		for(int i=0; i<5; i++){
			temp->getdata()->draw(window, posx, 406);
			temp = temp->getNext();
			posx-=180;
		}
	}else if(byklubang == 7){
		int posx=268;
		temp->getdata()->setScale(1.5,1.5);
		temp->getdata()->draw(window, 100, 300);
		temp = temp->getNext();
		for(int i=0; i<7; i++){
			temp->getdata()->draw(window, posx, 236);
			temp = temp->getNext();
			posx+=120;
		}
		posx=988;
		temp->getdata()->setScale(1.5,1.5);
		temp->getdata()->draw(window, 1100, 300);
		temp = temp->getNext();
		for(int i=0; i<7; i++){
			temp->getdata()->draw(window, posx, 406);
			temp = temp->getNext();
			posx-=120;
		}
	}
}

void move(Node<lubang> *temp, LList<lubang> llubang, sf::RenderWindow &window, int biji, bool &ambil, bool &turn,int shield, bool &cek, player &p1, player &p2, int byklubang){
	if(ambil == 0){
		ambil = false;
		return;
	}
	while(biji>0){
		sf::Event event;
		while(window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		h_time = sf::seconds(0.5);
		if (h_clock.getElapsedTime() >= h_time){
			temp = temp->getNext();
			//cek lubang besar punya turn
			if(temp->getdata()->Besar()){
				if(temp->getdata()->getPos() == turn){
					temp->getdata()->addBiji();
				} else continue;
			} else { //kalo bukan lubang besar
				temp->getdata()->addBiji();
			}
			biji--;
			window.clear();
			drawlubang(window, llubang, byklubang, turn, p1, p2);
			window.display();
			h_clock.restart();
		}
	}
	Node<lubang> *temps;
	//cek apa bisa nembak
	if(temp->getdata()->cekBiji() == 1){
		if(!temp->getdata()->Besar()){
			//jika bisa nembak
			if(turn == temp->getdata()->getPos()){
				ambil = false;
				//cek apa turn milik player
				if(turn != p1.getstatus()){
					//cek jika player punya shield
					temps = llubang.gethead();
					do{
						if(temps->getdata()->getPos() == turn && temps->getdata()->Besar()){
							break;
						}
						temps = temps->getNext();
					} while (temps != llubang.gethead());
					if(!p1.useshield()){
						nembak(temp->getdata()->getNomor(), temps, temp, turn, byklubang);
					}
				} else if(turn != p2.getstatus()){
					temps = llubang.gethead();
					do{
						if(temps->getdata()->getPos() == turn && temps->getdata()->Besar()){
							break;
						}
						temps = temps->getNext();
					} while (temps != llubang.gethead());
					if(!p2.useshield()){
						nembak(temp->getdata()->getNomor(), temps, temp, turn, byklubang);
					}
				}
			}
			//ganti turn
			if(turn == false){
				turn = true;
			} else {
				turn = false;
			}
		} else {
			ambil = false;
		}
	} else {
		if(turn == p1.getstatus()){
			//cek apa bisa pake attack;
			if(p1.useattack()){
				//melakukan attack
				temp = llubang.gethead();
				do{
					if(temp->getdata()->getPos() == p1.getstatus() && temp->getdata()->Besar()){
						temp->getdata()->addBiji(5);
						break;
					}
					temp = temp->getNext();
				} while (temp != llubang.gethead());

				temp = llubang.gethead();
				do{
					if(temp->getdata()->getPos() == p2.getstatus() && temp->getdata()->Besar()){
						temp->getdata()->minbiji(5);
						break;
					}
					temp = temp->getNext();
				} while (temp != llubang.gethead());
			}
		} else if(turn == p2.getstatus()){
			//cek apa bisa pake attack
			if(p2.useattack()){
				//melakukan attack
				temp = llubang.gethead();
				do{
					if(temp->getdata()->getPos() == p1.getstatus() && temp->getdata()->Besar()){
						temp->getdata()->minbiji(5);
						break;
					}
					temp = temp->getNext();
				} while (temp != llubang.gethead());

				temp = llubang.gethead();
				do{
					if(temp->getdata()->getPos() == p2.getstatus() && temp->getdata()->Besar()){
						temp->getdata()->addBiji(5);
						break;
					}
					temp = temp->getNext();
				} while (temp != llubang.gethead());
			}
		}
		if(!temp->getdata()->Besar()){
			if(turn == false){
				turn = true;
			} else {
				turn = false;
			}
			if(turn==true){
				spr_ready.setPosition(600,10);
				window.draw(spr_ready);
			} else {
				spr_ready.setPosition(600,600);
				window.draw(spr_ready);
			}
			//kalo ndak dibesar p1 dan p2 count power di refresh
			p1.refresh();
			p2.refresh();
		} else {
			//kalo dibesar, turn tidak ganti, bisa ambil lagi, dan count power ditambah
			if(turn == p1.getstatus()){
				p1.countpower();
			} else if(turn == p2.getstatus()){
				p2.countpower();
			}
		}
		ambil = false;
	}
}

int getdpn(int nomor, int lubang){
	if(lubang == 5){
		if(nomor == 2){
			return 12;
		} else if(nomor == 3){
			return 11;
		} else if(nomor == 4){
			return 10;
		} else if(nomor == 5){
			return 9;
		} else if(nomor == 6){
			return 8;
		} else if(nomor == 8){
			return 6;
		} else if(nomor == 9){
			return 5;
		} else if(nomor == 10){
			return 4;
		} else if(nomor == 11){
			return 3;
		} else if(nomor == 12){
			return 2;
		}
	} else if(lubang == 7) {
		if(nomor == 2){
			return 16;
		} else if(nomor == 3){
			return 15;
		} else if(nomor == 4){
			return 14;
		} else if(nomor == 5){
			return 13;
		} else if(nomor == 6){
			return 12;
		} else if(nomor == 7){
			return 11;
		} else if(nomor == 8){
			return 10;
		} else if(nomor == 10){
			return 8;
		} else if(nomor == 11){
			return 7;
		} else if(nomor == 12){
			return 6;
		} else if(nomor == 13){
			return 5;
		} else if(nomor == 14){
			return 4;
		} else if(nomor == 15){
			return 3;
		} else if(nomor == 16){
			return 2;
		} 
	}
}
void nembak(int nomor, Node<lubang> *head, Node<lubang> *counter, bool turn, int byklubang){
	Node<lubang> *temp = head;
	//cari sebrang ku
	while(temp->getdata()->getNomor() != getdpn(nomor, byklubang)){
		temp = temp->getNext();
	}
	//cari lubang besarku
	//dimasukin ke lubang besarku
	if(temp->getdata()->cekBiji()>0){
		head->getdata()->addBiji(counter->getdata()->getBiji());
		head->getdata()->addBiji(temp->getdata()->getBiji());
	}
}
