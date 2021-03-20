#include<bangtal.h>

SceneID scene, scene1;
ObjectID start;
ObjectID p[9];
ObjectID l[9];
ObjectID g[9];

int ly[9] = { -100, 50, 200, 350, 500, -50, 100, 250, 400 };
int lx[9] = { -200, -200, -200, -200, -200, 600, 600, 600, 600 };
int gx[9] = { 100,200,300,100,200,300,100,200,300 };
int gy[9] = { 300,300,300,200,200,200,100,100,100 };
bool open[9] = { true, true, true, true,true, true, true, true, true };
bool closed = true;
bool fish[9] = { true, true, true, true,true, true, true, true, true };

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	
	for (int i = 0; i < 9; i++) {
		if (object == start) {
			enterScene(scene1);
			locateObject(start, scene1, 20, 20);
			locateObject(p[i], scene1, lx[i], ly[i]);
			showObject(p[i]);
			showObject(g[i]);
			locateObject(l[i], scene1, lx[i], ly[i]);
			locateObject(g[i], scene1, gx[i], gy[i]);
		}
		else if (object == p[i] && closed == true) {
			showObject(l[i]);
			hideObject(p[i]);
			closed = false;
			open[i] = false;
		}
		else if (object == l[i] && closed == false) {
			showObject(p[i]);
			hideObject(l[i]);
			closed = true;
			open[i] = true;
		}
		else if (object == g[i] && open[i] == false) {
			hideObject(l[i]);
			hideObject(g[i]);
			locateObject(p[i], scene1, gx[i], gy[i]);
			showObject(p[i]);
			closed = true;
			fish[i] = false;

		}
		else if (fish[0] == false && fish[1] == false && fish[2] == false && fish[3] == false && fish[4] == false && fish[5] == false && fish[6] == false && fish[7] == false && fish[8] == false) {
			enterScene(scene);
			showMessage("축하합니다");
			endGame();

		}
		
		
	}
	
	 
	
	
		
	
}




int main() {
	setMouseCallback(mouseCallback);
	
	scene = createScene("퍼즐맞추기", "00.png");
	start = createObject("start.png");
	locateObject(start, scene, 200, 20);
	showObject(start);

	scene1 = createScene("퍼즐맞추기", "000.png");

	
	p[0] = createObject("01.png");
	p[1] = createObject("02.png");
	p[2] = createObject("03.png");
	p[3] = createObject("04.png");
	p[4] = createObject("05.png");
	p[5] = createObject("06.png");
	p[6] = createObject("07.png");
	p[7] = createObject("08.png");
	p[8] = createObject("09.png");
	
	l[0] = createObject("011.png");
	l[1] = createObject("022.png");
	l[2] = createObject("033.png");
	l[3] = createObject("044.png");
	l[4] = createObject("055.png");
	l[5] = createObject("066.png");
	l[6] = createObject("077.png");
	l[7] = createObject("088.png");
	l[8] = createObject("099.png");

	g[0] = createObject("001.png");
	g[1] = createObject("002.png");
	g[2] = createObject("003.png");
	g[3] = createObject("004.png");
	g[4] = createObject("005.png");
	g[5] = createObject("006.png");
	g[6] = createObject("007.png");
	g[7] = createObject("008.png");
	g[8] = createObject("009.png");


	

	


	startGame(scene);

}