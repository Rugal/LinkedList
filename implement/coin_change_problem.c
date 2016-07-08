/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   coin_change_problem.c
 * Author: HYH
 * reference :Rugal,(2016.1.13). Rugal/algorithm. Retrieved from https://github.com/Rugal/algorithm/blob/master/dp/src/main/java/ga/rugal/dp/Main.java#L181
 * Created on 2016年7月5日, 上午5:36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIG_NUMBER 1<<30 //1<<31 is negative

int
coin_change_problem (int cost, int coin[], int coin_array_size)
{
  int coin_used[cost + 1];
  for (int k = 0; k < cost + 1; k++)//can i use memset? memset(coin_used,BIG_NUMBER,cost+1)
    coin_used[k] = BIG_NUMBER;
  coin_used[0] = 0;
  for (int i = 0; i <= cost; i++)
    {
      for (int j = 0; j < coin_array_size; j++)
        {
          if (i > coin[j])
            {
              int current_coin_used = coin_used[i - coin[j]];
              if (current_coin_used != BIG_NUMBER && current_coin_used + 1 < coin_used[i])//why +1?
                coin_used[i] = current_coin_used + 1;
            }
          else
            coin_used[i] = 0;
        }
    }
  return coin_used[cost];
}
