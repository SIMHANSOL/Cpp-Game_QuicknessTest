#include < iostream >
#include < Windows.h >
#include < conio.h >
#include < time.h >

int random_range(int _x1, int _x2)
{
  int range = (_x2 - _x1) + 1;
  return (rand() % range) + _x1;
}

void goto_xy(int _x, int _y)
{
  COORD pos = {_x, _y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
  int x_max = 60;
  int y_max = 20;
  int start = 0;
  int number = 0;
  int score = 0;
  float timer = 0;
  float max_timer = 1000;
  int key = 0;
  int ran_sleep_min = 600;
  int ran_sleep_max = 3000;
  clock_t start_clk = clock();
  clock_t end_clk = clock();
  srand(time(NULL));
main_loop:
  goto_xy(26, 10);
  printf("준비하세요. 곧 시작합니다.");
  Sleep(ran_sleep_max);
  system("cls");
  while (1)
  {
    if (start == 0)
    {
      number = random_range(0, 9);
      goto_xy(random_range(0, x_max), random_range(0, y_max));
      printf("[%d]", number);
      goto_xy(0, 0);
      start_clk = clock();
      start = 1;
    }
    else if (start == 1)
    {
      if (_kbhit() == 1)
      {
        key = _getch();
        key -= 48;
        if (key == number)
        {
          end_clk = clock();
          timer = (float)(end_clk - start_clk);
          if (timer < max_timer)
          {
            score++;
            system("cls");
            goto_xy(26, 8);
            if ((int)(timer / 100) > 8)
            {
              printf("아슬했어요. ");
            }
            else if ((int)(timer / 100) > 6)
            {
              printf("나쁘지 않아요. ");
            }
            else if ((int)(timer / 100) > 4)
            {
              printf("훌륭해요! ");
            }
            else if ((int)(timer / 100) > 2)
            {
              printf("굉장한데요! ");
            }
            else if ((int)(timer / 100) > 1)
            {
              printf("당신 혹시 기계? ");
            }
            else if ((int)(timer / 100) > 0)
            {
              printf("시험도 찍으시나보죠. ");
            }
            goto_xy(26, 10);
            printf("시간 경과: %.2f초", timer / 1000);
            Sleep(ran_sleep_max / 2);
            system("cls");
            Sleep(random_range(ran_sleep_min, ran_sleep_max));
            start = 0;
          }
          else
          {
            system("cls");
            goto_xy(26, 10);
            printf("시간 경과: %.2f초", timer / 1000);
            Sleep(ran_sleep_max);
            system("cls");
            break;
          }
        }
        else
        {
          system("cls");
          goto_xy(26, 10);
          printf("키가 틀림 [숫자: %d]  [누른 숫자 : %d]", number, key);
          Sleep(ran_sleep_max);
          system("cls");
          break;
        }
      }
    }
  }
  goto_xy(26, 10);
  printf("게임 오버. 다시 도전하시겠습니까? [엔터 후 + 1번: 재도전]");
  goto_xy(26, 12);
  printf("점수: %d\n", score);
  while (getchar() != '\n')
    ;

  int _key = _getch();
  switch (_key)
  {
  case 49:
    start = 0;
    system("cls");
    goto main_loop;
    break;
  }
  return 0;
}