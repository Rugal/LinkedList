/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Administrator
 *
 * Created on 2016年6月7日, 下午9:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linked_list.h"

int
main (int argc, char** argv)
{
  linked_list* list = NULL;
  list = create_linked_list ();
  list = add_on_head (list);
  list = input_data (list, 1, 23);
  display_list (list);
  printf ("!\n");
  list = add_on_head (list);
  list = input_data (list, 1, 4);
  display_list (list);
  printf ("!!\n");
  list = add_on_tail (list);
  list = input_data (list, 1, 7);
  display_list (list);
  printf ("!!!\n");
  list = delete_one_node (list, 3);
  display_list (list);
  printf ("!!!!\n");
  //  list = delete_one_node (list, 4);
  //  display_list (list);
  //  printf ("!!!!!\n");
  list = delete_one_node (list, 2);
  display_list (list);
  printf ("!!!!!\n");
  //  list = sort_list (list);
  //  display_list (list);
  //  printf ("!!!!\n");
  list = add_on_head (list);
  list = input_data (list, 1, 23);
  display_list (list);
  printf ("!\n");
  list = add_on_head (list);
  list = input_data (list, 1, 4);
  display_list (list);
  printf ("!!\n");
  list = add_on_tail (list);
  list = input_data (list, 1, 7);
  printf ("!!!!!\n");
  display_list (list);
  list = sort_list (list);
  display_list (list);
  printf ("!!!!!\n");
    delete_list (list);
  printf ("!!!!\n");

  return (EXIT_SUCCESS);
}
