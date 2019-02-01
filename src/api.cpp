#define _CRT_SECURE_NO_WARNINGS

typedef enum {
	eScene_Load,
	eScene_Menu,
	eScene_Start,
	eScene_Exit,
	eScene_Standby,
} eScene;

extern bool DeviceStatus;
extern int Scene;
extern int steakX[3];
extern int steakY[3];

static int x, y;
static bool Cheat = false;
static double CC;
extern int SSX[3][2];


//メモリの改ざん検証用関数
bool AntiMem() {
	CC = 0.0;

	CC = SSX[0][0] - steakX[0];

	for (x = 0; x < 3; x++) {
		if (Cheat == true) {
			break;
		}
		for (y = 0; y < 2; y++) {
			if (y == 0) {
				CC = SSX[x][y] - steakX[x];
				SSX[x][y] = steakX[x];
			}
			else {
				CC = SSX[x][y] - steakY[x];
				SSX[x][y] = steakY[x];
			}
			if (CC > 2.0 || CC < -2.0) {
				Cheat = true;
				break;
			}
		}
	}

	if (Cheat == true) {

		return true;
	}
	return false;
}
