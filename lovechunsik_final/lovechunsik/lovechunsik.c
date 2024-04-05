// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// #include <Windows.h>
#include <unistd.h>
#include <time.h>

typedef struct
{
	int affect;
	double scale;
	int xpos, ypos;
	int turn;
}Chunsik;
void printmap(int map[][25]);				//맵 출력
void printstat(Chunsik chunsik);			//춘식이 정보 출력
void move(int map[][25],Chunsik* chunsik);  //춘식이 이동
void size(Chunsik chunsik, int map[][25]);  //춘식이 커짐
int sick(Chunsik* chunsik);				    //춘식이 아픔...
void feed(Chunsik* chunsik);			    //춘식이 밥먹자!

int main(void)
{
	// system("mode con cols=100");
	srand(time(NULL));  //난수 시드값 초기화
	int map[25][25] = { //춘식이 방
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	}; 
	int quit = 0;//종료코드
	Chunsik chunsik = { 0,10,12,12,0 };//춘식이 정보 설정
	
	while (chunsik.scale < 100) //100이 되면(넘어가면) 종료
	{
		int event = rand() % 100;
		chunsik.affect += 5, chunsik.turn++;

		map[chunsik.xpos][chunsik.ypos] = 2; //춘식이 위치
		size(chunsik, map); //20,40,60,80 초과할때마다 커짐.

		printmap(map); //맵 출력
		move(map,&chunsik); //춘식이 돌아다님
		printstat(chunsik); //춘식이 상태 정보 출력

		if (event < 10)
		{
			printf("춘식이가 병에 걸렸습니다...\n");
			quit = sick(&chunsik);
		}
		else
		{
			printf("춘식이가 밥을 먹습니다!♡ \n");
			feed(&chunsik);
		}

		// Sleep(500);
		// system("cls");
		sleep(1); 
		system("clear");
		if (quit == 1)
		{
			char imgarr[500];
			FILE* fp = fopen("lovefail.txt", "rt");
			// system("cls");
			system("clear");
			// system("mode con cols=130");

			if (fp == NULL) printf("파일 불러오기에 실패했습니다. \n");
			memset(imgarr, 0, sizeof(imgarr)); //왜 깨지는거야아ㅏ
			// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("%c[1;33m",27);
			while (fgets(imgarr, sizeof(imgarr), fp) != NULL)
			{
				printf("%s", imgarr);
			}
			fclose(fp);
			printf("%c[0m\n",27);
			// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("춘식이가 병을 이겨내지 못하였습니다. <게임 오버> \n");
			return 0; //게임 오버(아파서 죽음...)
		}
	}
	char imgarr[500];
	FILE* fp = fopen("love_chunsik.txt", "rt");
	// system("cls");
	system("clear");

	if (fp == NULL) printf("파일 불러오기에 실패했습니다. \n");
	memset(imgarr, 0, sizeof(imgarr)); //왜 깨지는거야아ㅏ
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c[1;33m",27);
	while (fgets(imgarr, sizeof(imgarr), fp) != NULL)
	{
		printf("%s", imgarr);
	}
	fclose(fp);
	printf("%c[0m",27);
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("축하드립니다! %d회동안 춘식이를 키우셨습니다. \n", chunsik.turn);
	printf("춘식이 최종 몸무게: %gkg, 애정도: %d♥ \n\n\n",chunsik.scale,chunsik.affect);
	return 0;
}
void printmap(int map[][25])
{
	for (int i = 0;i < 25;i++)
	{
		for (int j = 0;j < 25;j++)
		{
			switch (map[i][j])
			{
			case 0: printf("   "); break; //방 안
			case 1:
				// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("%c[1;33m",27);
				// printf("■"); break; //벽
				printf("■  "); break;
			case 2: 
				// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("%c[1;31m",27);
				// printf("♥"); break; //춘식이
				printf("♥  "); break; //춘식이
			default:
				break;
			}
		}
		printf("\n");
	}
	printf("%c[0m",27);
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void printstat(Chunsik chunsik)
{
	printf("---------------------------------------------------\n");
	printf("춘식이 몸무게: %gkg		애정도: %d♥ \n", chunsik.scale, chunsik.affect);
	printf("---------------------------------------------------\n");
}
void move(int map[][25],Chunsik* chunsik) //몸무게에 따른 크기변화 적용
{
	int rnd = rand() % 4;
	int size = (int)chunsik->scale / 10; //2,4,6,8일때마다 변동
	switch (rnd)
	{
	case 0: //오른쪽 이동
		move_right(size,chunsik,map);
		break;
	case 1: //위로 이동
		move_up(size,chunsik,map);
		break;
	case 2: //왼쪽으로 이동
		move_left(size,chunsik,map);
		break;
	default: //3일때 아래로 이동
		move_down(size,chunsik,map);
		break;
	}
}
void size(Chunsik chunsik,int map[][25])
{
	switch ((int)chunsik.scale/10)
	{
	case 9:
	case 8: 
		map[chunsik.xpos - 1][chunsik.ypos - 1] = 2;
		map[chunsik.xpos - 1][chunsik.ypos] = 2;
		map[chunsik.xpos - 1][chunsik.ypos + 1] = 2;
	case 7:
	case 6:
		map[chunsik.xpos][chunsik.ypos - 1] = 2;
		map[chunsik.xpos + 1][chunsik.ypos - 1] = 2;
	case 5:
	case 4:
		map[chunsik.xpos + 1][chunsik.ypos] = 2;
		map[chunsik.xpos + 1][chunsik.ypos + 1] = 2;
	case 3:
	case 2:
		map[chunsik.xpos][chunsik.ypos + 1] = 2;
	default:
		break;
	}
}
int sick(Chunsik* chunsik) //춘식이 아픔...
{
	int event = rand() % 100;
	char imgarr[500];
	FILE* fp = fopen("chunsik_sick.txt", "rt");

	chunsik->scale -= 3; // 너무 아파대...아프지마 
	if (event >= 99||chunsik->scale<0) return 1;	  //1퍼 확률로 게임 오버 10->1 죽는 확률 조정... + 몸무게 0아래로 내려갔을때...
	else if (event < chunsik->affect * 0.1) return 0; //애정도에 따라 회복
	else
	{
		// system("cls");
		system("clear");
		if (fp == NULL) printf("파일 불러오기에 실패했습니다. \n");
		memset(imgarr, 0, sizeof(imgarr)); //왜 깨지는거야아ㅏ
		// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("%c[1;33m",27);
		while (fgets(imgarr, sizeof(imgarr), fp) != NULL)
		{
			printf("%s", imgarr);
		}
		fclose(fp);
		// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("%c[0m",27);
		printf("춘식이가 병을 이겨내는 중입니다! 응원해주세요. \n");
		// Sleep(300);
		sleep(1);
		chunsik->turn++; chunsik->affect += 5; sick(chunsik);
	}
}
void feed(Chunsik* chunsik)
{
	int event = rand() % 2;
	chunsik->scale += 3; //몸무게 증량 0.3->3
	if (event == 0)
	{
		printf("춘식이가 똥을 쌉니다. ※ \n");
		chunsik->scale -= 0.2; 
	} 
}
void move_right(int size,Chunsik* chunsik,int map[][25])
{
	switch (size)
		{
		case 9:
		case 8:
			if (map[chunsik->xpos][chunsik->ypos + 2] == 1) move(map, chunsik); //사이즈 변화가 있을 수 있어 모두 0만들어야함...
			map[chunsik->xpos - 1][chunsik->ypos - 1] = 0;
			map[chunsik->xpos - 1][chunsik->ypos ] = 0;
			map[chunsik->xpos - 1][chunsik->ypos + 1] = 0;
		case 7:
		case 6:
			if (map[chunsik->xpos][chunsik->ypos + 2] == 1) move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos - 1] = 0;
			map[chunsik->xpos + 1][chunsik->ypos - 1] = 0;
		case 5:
		case 4:
			if (map[chunsik->xpos][chunsik->ypos + 2] == 1) move(map, chunsik);
			map[chunsik->xpos+1][chunsik->ypos] = 0;
			map[chunsik->xpos+1][chunsik->ypos+1] = 0;
		case 3:
		case 2:
			if (map[chunsik->xpos][chunsik->ypos + 2] == 1) move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos+1] = 0;
		default:
			if (map[chunsik->xpos][chunsik->ypos + 1] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos] = 0;
			chunsik->ypos++;
			break;
		}
}
void move_up(int size,Chunsik* chunsik,int map[][25])
{
	switch (size)
		{
		case 9:
		case 8:
			if (map[chunsik->xpos - 2][chunsik->ypos] == 1) move(map, chunsik);
			map[chunsik->xpos - 1][chunsik->ypos - 1] = 0;
			map[chunsik->xpos - 1][chunsik->ypos ] = 0;
			map[chunsik->xpos - 1][chunsik->ypos + 1] = 0;
		case 7:
		case 6:
			if (map[chunsik->xpos - 1][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos - 1] = 0;
			map[chunsik->xpos + 1][chunsik->ypos - 1] = 0;
		case 5:
		case 4:
			if (map[chunsik->xpos - 1][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos+1][chunsik->ypos] = 0;
			map[chunsik->xpos+1][chunsik->ypos+1] = 0;
		case 3:
		case 2:
			if (map[chunsik->xpos - 1][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos+1] = 0;
		default:
			if (map[chunsik->xpos - 1][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos] = 0;
			chunsik->xpos--;
			break;
		}
}
void move_left(int size,Chunsik* chunsik,int map[][25])
{
	switch (size)
		{
		case 9:
		case 8:
			if (map[chunsik->xpos][chunsik->ypos - 2] == 1) move(map, chunsik);
			map[chunsik->xpos - 1][chunsik->ypos - 1] = 0;
			map[chunsik->xpos - 1][chunsik->ypos ] = 0;
			map[chunsik->xpos - 1][chunsik->ypos + 1] = 0;
		case 7:
		case 6:
			if (map[chunsik->xpos][chunsik->ypos - 2] == 1) move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos - 1] = 0;
			map[chunsik->xpos + 1][chunsik->ypos - 1] = 0;
		case 5:
		case 4:
			if (map[chunsik->xpos][chunsik->ypos - 1] == 1)move(map, chunsik);
			map[chunsik->xpos+1][chunsik->ypos] = 0;
			map[chunsik->xpos+1][chunsik->ypos+1] = 0;
		case 3:
		case 2:
			if (map[chunsik->xpos][chunsik->ypos - 1] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos+1] = 0;
		default:
			if (map[chunsik->xpos][chunsik->ypos - 1] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos] = 0;
			chunsik->ypos--;
			break;
		}
}
void move_down(int size,Chunsik* chunsik,int map[][25])
{
	switch (size)
		{
		case 9:
		case 8:
			if (map[chunsik->xpos + 2][chunsik->ypos] == 1) move(map, chunsik);
			map[chunsik->xpos - 1][chunsik->ypos - 1] = 0;
			map[chunsik->xpos - 1][chunsik->ypos] = 0;
			map[chunsik->xpos - 1][chunsik->ypos + 1] = 0;
		case 7:
		case 6:
			if (map[chunsik->xpos+2][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos - 1] = 0;
			map[chunsik->xpos + 1][chunsik->ypos - 1] = 0;
		case 5:
		case 4:
			if (map[chunsik->xpos+2][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos+1][chunsik->ypos] = 0;
			map[chunsik->xpos+1][chunsik->ypos+1] = 0;
		case 3:
		case 2:
			if (map[chunsik->xpos +1][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos + 1] = 0;
		default:
			if (map[chunsik->xpos +1][chunsik->ypos] == 1)move(map, chunsik);
			map[chunsik->xpos][chunsik->ypos] = 0;
			chunsik->xpos++;
			break;
		}
}