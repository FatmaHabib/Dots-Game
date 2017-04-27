#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(800, 600), "DOTS");
int N, POSITION_X = 0, POSITION_Y = 0, turn = 0, ScorePlayer1 = 0, ScorePlayer2 = 0;
string SCORE;
bool HAPPEND = false, lista = 0, textbox = false, info = false, WIN = false;
Event event;
struct point
{
	int x, y;
};
struct line
{
	bool DRAW;
	string player;
};
line row[100][100], col[100][100];
vector<RectangleShape> AllLines, square;
void first()
{
	sf::Texture t1;
	sf::Sprite s1;
	t1.loadFromFile("first.jpg");
	s1.setTexture(t1);
	s1.setPosition(0, 0);
	window.draw(s1);
	sf::Font f1;
	sf::Text tx1;
	f1.loadFromFile("BAZARONI.ttf");
	tx1.setFont(f1);
	tx1.setString("DOTS");
	tx1.setStyle(sf::Text::Bold);
	tx1.setPosition(240, 23);
	tx1.setCharacterSize(100);
	tx1.setColor(sf::Color::White);
	window.draw(tx1);
	window.display();
	while (true)
	{


		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				return;
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
}
void list()
{
	window.clear();
	sf::Sprite frame;
	sf::Texture background;
	background.loadFromFile("thelist.jpg");
	frame.setTexture(background);
	frame.setPosition(0, 0);
	window.draw(frame);
	sf::Font fonts, font1, font2;
	sf::Text texts, text1, text2;
	fonts.loadFromFile("Watermelon.ttf");//<==
	texts.setFont(fonts);
	texts.setString("START THE GAME");
	texts.setStyle(sf::Text::Bold);
	texts.setStyle(sf::Text::Underlined);
	texts.setColor(sf::Color(0, 50, 255));
	texts.setCharacterSize(50);
	texts.setPosition(100, 100);
	window.draw(texts);
	font1.loadFromFile("Watermelon.ttf");//<==
	text1.setFont(font1);
	text1.setString("HOW TO PLAY");
	text1.setStyle(sf::Text::Bold);
	text1.setStyle(sf::Text::Underlined);
	text1.setColor(sf::Color(0, 50, 255));
	text1.setCharacterSize(50);
	text1.setPosition(100, 250);
	window.draw(text1);
	font2.loadFromFile("Watermelon.ttf");//<==
	text2.setFont(font2);
	text2.setString("QUITE");
	text2.setStyle(sf::Text::Bold);
	text2.setStyle(sf::Text::Underlined);
	text2.setColor(sf::Color(0, 50, 255));
	text2.setCharacterSize(50);
	text2.setPosition(100, 400);
	window.draw(text2);
	window.display();
	
}
void INFO()
{
	window.clear(sf::Color::White);
	sf::Texture t1;
	sf::Sprite s1;
	t1.loadFromFile("info.jpg");
	s1.setTexture(t1);
	s1.setPosition(0, 0);
	window.draw(s1);
	window.display();

}
void win()
{
	WIN = true;
	if (ScorePlayer1>ScorePlayer2)
	{
		sf::Texture t1;
		sf::Sprite s1;
		t1.loadFromFile("player1.jpg");
		s1.setTexture(t1);
		s1.setPosition(0, 0);
		window.draw(s1);
		sf::Font f1;
		sf::Text tx1;
		string str1;
		if (ScorePlayer1 >= 9)
		{
			str1 += ((ScorePlayer1 / 10) + '0');
			str1 += ((ScorePlayer1 % 10) + '0');
		}
		else
		{
			str1 = (ScorePlayer1 + '0');
		}
		f1.loadFromFile("ARIBL0.ttf");
		tx1.setFont(f1);
		tx1.setString(str1);
		tx1.setPosition(485, 466);
		tx1.setColor(sf::Color::Red);
		window.draw(tx1);

	}
	else if (ScorePlayer1<ScorePlayer2)
	{
		sf::Texture t2;
		sf::Sprite s2;
		t2.loadFromFile("player2.jpg");
		s2.setTexture(t2);
		s2.setPosition(0, 0);
		window.draw(s2);
		sf::Font f2;
		sf::Text tx2;
		string str2;
		if (ScorePlayer1 >= 9)
		{
			str2 += ((ScorePlayer2 / 10) + '0');
			str2 += ((ScorePlayer2 % 10) + '0');
		}
		else
		{
			str2 = (ScorePlayer2 + '0');
		}
		f2.loadFromFile("ARIBL0.ttf");
		tx2.setFont(f2);
		tx2.setString(str2);
		tx2.setPosition(485, 431);
		tx2.setColor(sf::Color::Red);
		window.draw(tx2);
	}
	else
	{
		sf::Texture t2;
		sf::Sprite s2;
		t2.loadFromFile("draw.jpg");
		s2.setTexture(t2);
		s2.setPosition(0, 0);
		window.draw(s2);
	}
	window.display();

}
void DRAWBOARD(int N)
{
	window.clear(Color::White);
	sf::Texture t1;
	sf::Sprite s1;
	t1.loadFromFile("dots-on-blue-lights-backgrounds-wallpapers.jpg");
	s1.setTexture(t1);
	s1.setPosition(0, 0);
	window.draw(s1);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			CircleShape circle;
			circle.setPosition(j * 5 * 20.f, i * 5 * 20.f);
			circle.setRadius(10);
			circle.setFillColor(sf::Color(128, 0, 128));
			window.draw(circle);
		}
	}
	for (int i = 0; i<AllLines.size(); i++)
	{
		window.draw(AllLines[i]);
	}
	for (int j = 0; j<square.size(); j++)
	{
		window.draw(square[j]);
	}
	sf::Font font1, font2;
	sf::Text text1, text2;
	font1.loadFromFile("Watermelon.ttf");//<==
	text1.setFont(font1);
	SCORE = "Player '1' Score : ";
	SCORE += (ScorePlayer1 + '0');
	text1.setString(SCORE);
	text1.setColor(sf::Color::Yellow);
	text1.setCharacterSize(25);
	text1.setPosition(10, 511);
	window.draw(text1);
	font2.loadFromFile("Watermelon.ttf");
	text2.setFont(font2);
	SCORE = "Player '2' Score :";
	SCORE += (ScorePlayer2 + '0');
	text2.setString(SCORE);
	text2.setColor(sf::Color::Red);
	text2.setCharacterSize(25);
	text2.setPosition(10, 550);//15,511
	window.draw(text2);

	window.display();//<==
}
void DRAWLINE(point A, point B)
{
	HAPPEND = false;//<<<===
	if (A.x < N * 100 + 10 && A.y<N * 100 + 10 && B.x<N * 100 + 10 && B.y<N * 100 + 10)
	{
		RectangleShape Line;
		RectangleShape SQUARE;
		if (A.y == B.y)
		{
			if (turn % 2 == 0)
			{
				Line.setPosition(A.x+10, A.y);
				Line.setSize(Vector2f(80, 3));
				Line.setFillColor(Color::Yellow);
			}
			else
			{
				Line.setPosition(A.x+10, A.y);
				Line.setSize(Vector2f(80, 3));
				Line.setFillColor(Color::Red);
			}
			row[(A.y - 10) / 100][(A.x - 10) / 100].DRAW = 1;
			if ((A.y - 10) / 100 != 0 && col[(A.y - 10) / 100 - 1][(A.x - 10) / 100].DRAW == 1 && col[(A.y - 10) / 100 - 1][(A.x - 10) / 100 + 1].DRAW == 1 && row[(A.y - 10) / 100 - 1][(A.x - 10) / 100].DRAW == 1)
			{ //bybose le fo2
				SQUARE.setPosition(A.x + 10, A.y - 100 + 10);
				SQUARE.setSize(Vector2f(80, 80));
				if (turn % 2 == 0)
				{
					ScorePlayer1++;
					SQUARE.setFillColor(Color::Yellow);
				}
				else
				{
					ScorePlayer2++;
					SQUARE.setFillColor(Color::Red);
				}
				turn--;
				HAPPEND = true;
				square.push_back(SQUARE);
			}
			if ((A.y - 10) / 100 != N && col[(A.y - 10) / 100][(A.x - 10) / 100].DRAW == 1 && col[(A.y - 10) / 100][(A.x - 10) / 100 + 1].DRAW == 1 && row[(A.y - 10) / 100 + 1][(A.x - 10) / 100].DRAW == 1)
			{//bybose le t7t
				SQUARE.setPosition(A.x + 10, A.y + 10);
				SQUARE.setSize(Vector2f(80, 80));
				if (HAPPEND == true)
				{
					turn++;
					HAPPEND = false;
				}
				if (turn % 2 == 0)
				{
					ScorePlayer1++;
					SQUARE.setFillColor(Color::Yellow);
				}
				else
				{
					ScorePlayer2++;
					SQUARE.setFillColor(Color::Red);
				}
				turn--;
				square.push_back(SQUARE);
			}
		}
		else if (A.x == B.x)
		{
			if (turn % 2 == 0)
			{
				Line.setPosition(A.x, A.y+10);
				Line.setSize(Vector2f(80, 3));
				Line.setFillColor(Color::Yellow);
				Line.rotate(90);
			}
			else
			{
				Line.setPosition(A.x, A.y+10);
				Line.setSize(Vector2f(80, 3));
				Line.setFillColor(Color::Red);
				Line.rotate(90);
			}
			col[(A.y - 10) / 100][(A.x - 10) / 100].DRAW = 1;
			if ((A.x - 10) / 100 != 0 && col[(A.y - 10) / 100][(A.x - 10) / 100 - 1].DRAW == 1 && row[(A.y - 10) / 100][(A.x - 10) / 100 - 1].DRAW == 1 && row[(A.y - 10) / 100 + 1][(A.x - 10) / 100 - 1].DRAW == 1)
			{//bybos le el left
				SQUARE.setPosition(A.x - 100 + 10, A.y + 10);
				SQUARE.setSize(Vector2f(80, 80));
				if (turn % 2 == 0)
				{
					ScorePlayer1++;
					SQUARE.setFillColor(Color::Yellow);
				}
				else
				{
					ScorePlayer2++;
					SQUARE.setFillColor(Color::Red);
				}

				HAPPEND = TRUE;
				turn--;
				square.push_back(SQUARE);
			}
			if ((A.x - 10) / 100 != N && col[(A.y - 10) / 100][(A.x - 10) / 100 + 1].DRAW == 1 && row[(A.y - 10) / 100][(A.x - 10) / 100].DRAW == 1 && row[(A.y - 10) / 100 + 1][(A.x - 10) / 100].DRAW == 1)
			{//bybos le el right
				SQUARE.setPosition(A.x + 10, A.y + 10);
				SQUARE.setSize(Vector2f(80, 80));
				if (HAPPEND == true)
				{
					turn++;
					HAPPEND = false;
				}
				if (turn % 2 == 0)
				{
					ScorePlayer1++;
					SQUARE.setFillColor(Color::Yellow);
				}
				else
				{
					ScorePlayer2++;
					SQUARE.setFillColor(Color::Red);
				}
				turn--;
				square.push_back(SQUARE);

			}
		}
		turn++;
		//cout << ScorePlayer1 << "&" << ScorePlayer2 << "| turn = " << turn << endl;//<==
		AllLines.push_back(Line);
		if (ScorePlayer1 + ScorePlayer2 == ((N - 1)*(N - 1)))
		{
			DRAWBOARD(N);

			win();

		}
	}
}

void movement()
{
	while (true)
	{


		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					return;
				}
			}
	
		}

	}
}

void TextBox()
{
	window.clear();
	string m;
	bool number = false;
	while (true)
	{
		
		sf::Sprite frame;
		sf::Texture background;
		background.loadFromFile("number1.jpg");
		frame.setTexture(background);
		frame.setPosition(0, 0);
		window.draw(frame);
		if (number == true)
		{
			sf::Font fonts;
			sf::Text texts;
			fonts.loadFromFile("BAZARONI.TTF");//<==
			texts.setFont(fonts);
			texts.setString(m);
			texts.setStyle(sf::Text::Bold);
			texts.setColor(sf::Color::White);
			texts.setCharacterSize(60);
			texts.setPosition(647, 490);
			window.draw(texts);
		}
		window.display();
		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Return))
				return;
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == 58)
					continue;
				number = true;
				char k = event.key.code;
				N = k - 26;
				m = N + '0';
				sf::Font fonts;
				sf::Text texts;
				fonts.loadFromFile("BAZARONI.ttf");//<==
				texts.setFont(fonts);
				texts.setString(m);
				texts.setStyle(sf::Text::Bold);
				texts.setColor(sf::Color(0, 100, 255));
				texts.setCharacterSize(25);
				texts.setPosition(733, 546);
				window.draw(texts);
			}

		}
	}
}

int main()
{
	sf::Music music,music1;
music.openFromFile("Haggstrom_-_C418_mp3cut.ogg");
music.setLoop(true);
music.play();
	first();
	list();
	AllLines.clear();//<==
	while (window.isOpen())
	{
		point A, B;
		if (lista == true && textbox == true && WIN == false)
			DRAWBOARD(N);
		while (window.pollEvent(event))
		{ 
			if (lista == true && textbox == false)
			{
				window.clear();
				TextBox();
				DRAWBOARD(N);
				textbox = true;
			}
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					POSITION_X = event.mouseButton.x;
					POSITION_Y = event.mouseButton.y;
					cout << POSITION_X << " " << POSITION_Y << endl;
					if (lista == 0)
					{
						if (POSITION_X >= 98 && POSITION_X <= 530 && POSITION_Y >= 114 && POSITION_Y <= 143 && info == false)
						{
							lista = 1;
							/*window.clear(Color::White);
							window.display();*/
							continue;
						}
						else if (POSITION_X >= 98 && POSITION_X <= 425 && POSITION_Y >= 255 && POSITION_Y <= 304 && info == false)
						{
							info = true;
							INFO();
						}
						else if (POSITION_X >= 52 && POSITION_X <= 247 && POSITION_Y >= 565 && POSITION_Y <= 587 && info == true)
						{
							info = false;
							list();
						}
						else if (POSITION_X >= 98 && POSITION_X <= 227 && POSITION_Y >= 406 && POSITION_Y <= 455 && info == false)
						{
							window.close();
						}
					}
					if (WIN == false)
					{
						/*if (ScorePlayer1 > ScorePlayer2)
						{

						}*/
						if ((POSITION_X % 100 >= 0 && POSITION_X % 100 <= 20) && (POSITION_Y % 100<0 || POSITION_Y % 100>20) && POSITION_X<N * 100 + 10)
						{
							A.x = B.x = (POSITION_X / 100) * 100 + 10;
							A.y = (POSITION_Y / 100) * 100 + 10;
							B.y = ((POSITION_Y / 100) + 1) * 100 + 10;
							if (col[(A.y - 10) / 100][(A.x - 10) / 100].DRAW == 1)//<==
								continue;
							DRAWLINE(A, B);
						}
						else if ((POSITION_Y % 100 >= 0 && POSITION_Y % 100 <= 20) && (POSITION_X % 100<0 || POSITION_X % 100>20) && POSITION_Y<N * 100 + 10)
						{
							A.y = B.y = (POSITION_Y / 100) * 100 + 10;
							A.x = (POSITION_X / 100) * 100 + 10;
							B.x = ((POSITION_X / 100) + 1) * 100 + 10;
							if (row[(A.y - 10) / 100][(A.x - 10) / 100].DRAW == 1)//<==
								continue;
							DRAWLINE(A, B);
						}
					}
					if (WIN == true)
					{
						music.stop();
						music1.openFromFile("Kids_Saying_Yay_Sound_Effect_mp3cut.ogg");
                        music1.play();
						movement();
	            
						if (ScorePlayer2 > ScorePlayer1)
						{
							music1.stop();
							 if (POSITION_X >=678  && POSITION_X <= 797 && POSITION_Y >= 39 && POSITION_Y <= 90)
							{
							music1.stop();
							window.close();
								//return 0;
							}
							else if (POSITION_X >= 26 && POSITION_X <= 279 && POSITION_Y >= 49 && POSITION_Y <= 87)
							{
                               
								WIN = false;
								AllLines.clear();
								square.clear();
								music.openFromFile("Haggstrom_-_C418_mp3cut.ogg");
                                 music.setLoop(true);
                                music.play();
								for (int i = 0; i < N; i++)
								{
									for (int j = 0; j < N; j++)
									{
										row[i][j].DRAW = 0;
										col[i][j].DRAW = 0;
									}
								}
								turn = 1;
								textbox = 0;
								ScorePlayer1 = ScorePlayer2 = 0;
								continue;
								
							}
						}
						else if (ScorePlayer1>ScorePlayer2)
						{
							music1.stop();
						 if (POSITION_X >=696  && POSITION_X <= 790 && POSITION_Y >= 33 && POSITION_Y <= 86)
						{
							music1.stop();
							window.close();
							//return 0;
						}
						else if (POSITION_X >= 41 && POSITION_X <= 297 && POSITION_Y >= 40 && POSITION_Y <= 83)
						{
                           
							WIN = false;
							AllLines.clear();
							square.clear();
							music.openFromFile("Haggstrom_-_C418_mp3cut.ogg");
                           music.setLoop(true);
                            music.play();
							for (int i = 0; i < N; i++)
							{
								for (int j = 0; j < N; j++)
								{
									row[i][j].DRAW = 0;
									col[i][j].DRAW = 0;
								}
							}
							turn = 0;
							textbox = 0;
							ScorePlayer1 = ScorePlayer2 = 0;
							continue;
						}
						}
						else if (ScorePlayer1==ScorePlayer2)
						{
						music1.stop();
						 if (POSITION_X >=13  && POSITION_X <= 161 && POSITION_Y >= 532 && POSITION_Y <= 557)
						{
							music1.stop();
							window.close();
							//return 0;
						}
						else if (POSITION_X >=13  && POSITION_X <= 299 && POSITION_Y >= 491 && POSITION_Y <= 524)
						{
							WIN = false;
							AllLines.clear();
							square.clear();
							music.openFromFile("Haggstrom_-_C418_mp3cut.ogg");
                             music.setLoop(true);
                              music.play();
							for (int i = 0; i < N; i++)
							{
								for (int j = 0; j < N; j++)
								{
									row[i][j].DRAW = 0;
									col[i][j].DRAW = 0;
								}
							}
							turn = 0;
							textbox = 0;
							ScorePlayer1 = ScorePlayer2 = 0;
							continue;
						}
						}
						
					}
				}
			}
		}
	}

	return 0;
}
