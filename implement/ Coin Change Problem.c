/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin Change Problem.c
 * Author: HYH
 *
 * Created on 2016年7月5日, 上午5:36
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
 * 
 */
void coin_change (int cost, int max_coin, int mid_coin, int min_coin);
bool check_greatest_common_divisor (int samll_number, int big_number);
int get_least_common_multiple (int a, int b);
void plan1 (int cost, int max_coin, int mid_coin, int min_coin);
void plan2 (int cost, int max_coin, int mid_coin, int min_coin);
void plan3 (int cost, int max_coin, int mid_coin, int min_coin);
void plan4 (int cost, int max_coin, int mid_coin, int min_coin);

void
coin_change (int cost, int max_coin, int mid_coin, int min_coin)
{
  assert (cost > min_coin);
  bool a = check_greatest_common_divisor (max_coin, mid_coin);
  bool b = check_greatest_common_divisor (mid_coin, min_coin);
  if (a == true && b == true)
    plan1;
  //  if (!a == 1 && !b == 1)
  //    plan2;
  //  if (a == 1 && !b == 1)
  //    plan3;
  //  if (a == 1 && !b == 1)
  //    plan4;
}

bool
check_greatest_common_divisor (int big_number, int small_number)
{
  int temp = big_number;
  while (temp > 0)
    {
      temp = temp - small_number;
      if (temp == 0)
        return true;
    }
  return false;
}

int
get_least_common_multiple (int a, int b)
{
  return a * b;
}

void
plan1 (int cost, int max_coin, int mid_coin, int min_coin)
{
  int max_coin_used = 0;
  int mid_coin_used = 0;
  int min_coin_used = 0;
  int total = 0;
  int temp = 0;
  int multiple = max_coin / mid_coin;
  while (total > cost)
    {
      temp += min_coin;
      min_coin_used++;
      if (temp == mid_coin_used)
        {
          min_coin_used == 0;
          mid_coin_used++;
          if (mid_coin == multiple)
            {
              mid_coin_used = 0;
              max_coin_used++;
            }
        }
    }
  printf ("%d %d %d", max_coin_used, mid_coin_used, min_coin_used);
}
