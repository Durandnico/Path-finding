/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 15/01/2023 03:17:26 by Durandnico   #+#    #+#    #+#             */
/*   Updated: None                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */


/*! 
 *  \file PathFinding.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sun 15 January 2023 - 03:17:26
 *
 *  \brief Headers of PathFinding.c
 *
 *
 */

#ifndef __PATHFINDING_H
#define __PATHFINDING_H

// librairies
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

/*---------------------------DEFINE---------------------------------------------------*/

/*! 
 *  \def RIGHT_CLICK 
 *  \brief keycode of the the right click
 */
#define RIGHT_CLICK 3  

/*! 
 *  \def LEFT_CLICK 1
 *  \brief keycode of the the left click 
 */
#define LEFT_CLICK 1

/*! 
 *  \def SPACE 32
 *  \brief keycode of the space bar
 */
#define SPACE 32


/*! 
 *  \def ENTER 36
 *  \brief keycode of the enter key
 */
#define ENTER 65293


/*-------------------------STRUCTURES---------------------------------------------*/

// typedef struct      s_recup to use it in the data structure
typedef struct s_button t_button;

typedef struct      s_dataCase
{
    t_button*   ptr_btn_previous;
    t_button*   ptr_btn_next;

    int         has_been_visited;
    int         is_end;
    int         isWall;
    int         int_distTarget;
    int         int_distStart;
}                   t_dataCase;

/*!
 *  \struct t_point
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 20:42:30
 *  \brief coord of a point (x and y) 
 *  \param x : x value of the point
 *  \param y : y value of the point
 */
typedef struct      s_point
{
    int int_x;  
    int int_y;
}                   t_point;


/*!
 *  \struct t_img
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:11:20
 *  \brief All data mandatory for an image in mlx
 *  \param img              : pointeur to the img
 *  \param addr             : pointeur to memory adress of the image
 *  \param bits_per_pixel   : mandatory for mlx
 *  \param line_length      : mandatory for mlx
 *  \param endian           : mandatory for mlx
 *  \param coord            : position of the img
 *  \param width            : width of the image
 *  \param height           ; height of the image
 */
typedef struct      s_img
{
    void*       ptr_void_img;
    char*       ptr_char_addr;
	int		    int_bits_per_pixel;
	int		    int_line_length;
	int		    int_endian;

    t_point     pt_coord;
    int         int_width;
    int         int_height;
}                   t_img;

/*!
 *  \struct t_button
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 21:45:44
 *  \updated Sat 14 January 2023 - 12:35:24
 *  \brief structure of a button
 *  \param img_sprite       : image of the button
 *  \param ptr_intf_func    : pointer to the function to call when the button is pressed
 *  \param int_state        : state of the button (0 = not pressed, 1 = pressed)
 *  \param data             : data of the button
 */

struct      s_button
{
    t_img           img_sprite;
    int             (*ptr_intf_func)();
    int             int_state;
    
    t_dataCase      data;
};

/*!
 *  \struct s_keys
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 25 January 2023 - 13:47:18
 *  \brief data to know which keys are pressed
 *  \param int_left_click   : boolean if the left click is pressed
 *  \param int_right_click  : boolean if the right click is pressed
 */

typedef struct  s_keys {
    int     int_left_click;
    int     int_right_click;
}               t_keys;

/*!
 *  \struct t_recup
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:10:17
 *  \brief All data for the window
 *  \param mlx              : pointeur to the mlx
 *  \param win              : pointeur to the window of mlx
 *  \param background       : image of the board
 *  \param sprites          : all image we gonna use
 *  \param window_width     : width of the window
 *  \param window_height    : height of the window
 *  \param pixel_per_case   : lenght of the case
 *  \param board            : all button on the screen
 */
typedef struct      s_recup
{
    void*           ptr_void_mlx;
	void*           ptr_void_win;

    t_img           img_background;
    t_img*          ptr_img_sprites;
    int             int_nb_sprite;
    int             int_pixel_per_case;
    
    int             int_window_width;
    int             int_window_height;

    t_keys          key_pressed;
    t_button**      pptr_btn_board;
    int             int_btn_per_line;
    int             int_btn_per_row;

    t_button*       ptr_btn_start;
    t_button*       ptr_btn_end;
}                   t_recup;


/*---------------------------------------My MLX FUNCTION---------------------------------------------------------------*/
void
drawn_sprite(t_img* ptr_img_base, t_img img_to_add, int int_x, int int_y);

/*!
 *  \fn t_button create_button(t_img img_sprite, int (*ptr_intf_func)(), int int_x, int int_y)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 21:45:27
 *  \brief initialize a button
 *  \param  img_sprite      : image of the button
 *  \param  ptr_intf_func   : pointer to the function to call when the button is pressed
 *  \param  int_x           : x position of the button
 *  \param  int_y           : y position of the button
 *  \return a button with all data
 */
t_button create_button(t_img img_sprite, int (*ptr_intf_func)(), int int_x, int int_y);


/*!
 *  \proc void change_btn_sprite(t_button* ptr_btn_button, t_img img_sprite)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 26 January 2023 - 18:59:30
 *  \brief change the sprite of a button
 *  \param ptr_btn_button   : pointer to the button
 *  \param img_sprite       : new sprite of the button
 */
void change_btn_sprite(t_button* ptr_btn_button, t_img img_sprite);

/*!
 *  \fn void my_mlx_pixel_put(t_img* ptr_img_base, int int_x, int int_y, int int_color)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 23:11:32
 *  \brief put a pixel in an image
 *  \param ptr_img_base     : pointeur to an image
 *  \param int_x            : x position of the pixel
 *  \param int_y            : y position of the pixel
 *  \param int_color        : color of the pixel
 */
void my_mlx_pixel_put(t_img* ptr_img_base, int int_x, int int_y, int int_color);

/*!
 *  \proc void fill(t_img* ptr_img_base, int int_x, int int_y, int int_color)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 13:06:57
 *  \brief 
 *  \param ptr_img_base     : pointeur to an image
 *  \param int_x0           : root x
 *  \param int_xn           : target x
 *  \param int_y0           : root y
 *  \param int_yn           : target yn
 *  \param int_color        : color to use
 */
void fill(t_img* ptr_img_base, int int_x0, int int_y0, int int_xn, int int_yn, int int_color);
/*---------------------------------------   INIT   ---------------------------------------------------------------*/

/*!
 *  \proc void init(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sun 15 January 2023 - 03:32:52
 *  \brief init everything for da prog
 *  \param ptr_rcp_recup    : pointeur to all window's data
 */
void init(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_sprites(t_recup*)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sun 15 January 2023 - 03:37:59
 *  \brief init all sprites
 *  \param ptr_rcp_recup    : pointeur to all window's data
 */
void init_sprites(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_button(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 13:14:49
 *  \brief init all button
 *  \param ptr_rcp_recup    : pointeur to all window's data
 */
void init_button(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_background(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 13:38:21
 *  \brief init background image
 *  \param ptr_rcp_recup    : pointeur to all window's data
 */
void init_background(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_hooks(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 25 January 2023 - 12:48:23
 *  \brief init all hooks function
 *  \param ptr_rcp_recup    : pointeur to all window's data
 */
void init_hooks(t_recup* ptr_rcp_recup);
/*----------------------------------FUNCTION-----------------------------------------------*/

/*!
 *  \fn t_dataCase create_data(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 13:32:02
 *  \brief create a dataCase
 *  \param void
 *  \return data initialize
 */
t_dataCase create_data(void);

/*!
 *  \proc void show_everything(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 17 January 2023 - 12:02:39
 *  \brief draw on the board + show on screen
 *  \param ptr_rcp_recup    : pointeur to all window's data
 */
void show_everything(t_recup* ptr_rcp_recup);

/*----------------------------------KEY DRAWx-----------------------------------------------*/

/*!
 *  \fn int exit_prog(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 25 January 2023 - 12:53:16
 *  \brief exit the prog properly
 *  \param ptr_rcp_recup    : pointeur to all window's data
 *  \return success : 0
 */
int exit_prog(t_recup* ptr_rcp_recup);

/*!
 *  \fn int mouse_press(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 17 January 2023 - 12:24:03
 *  \brief set the key to true
 *  \param int_keycode      : code of the button press
 *  \param int_x            : x coord of the mouse
 *  \param int_y            : y coord of the mouse
 *  \param ptr_rcp_recup    : pointeur to all window's data
 *  \return change the key to true in recup
 */
int mouse_press(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup);

/*!
 *  \fn int mouse_release(int keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 25 January 2023 - 13:40:50
 *  \brief set the key to false
 *  \param keycode          : keycode of the button
 *  \param int_x            : x coord of the mouse
 *  \param int_y            : y coord of the mouse
 *  \param ptr_rcp_recup    : pointeur to all window's data
 *  \return change the key to false in recup
 */
int mouse_release(int keycode, int int_x, int int_y, t_recup* ptr_rcp_recup);

/*!
 *  \fn int mouse_move(int int_x, int int_y, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 25 January 2023 - 13:54:03
 *  \brief keep track of the mouse position and do stuff if click pressed
 *  \param keycode          : keycode of the button
 *  \param int_x            : x coord of the mouse
 *  \param int_y            : y coord of the mouse
 *  \param ptr_rcp_recup    : pointeur to all window's data
 *  \return set button to wall if mouse is pressed on a button
 */
int mouse_move(int int_x, int int_y, t_recup* ptr_rcp_recup);

/*!
 *  \fn int key_press(int int_keycode, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 26 January 2023 - 15:56:21
 *  \brief intercept key press
 *  \param int_keycode      : code of the button press
 *  \param ptr_rcp_recup    : pointeur to all window's data
 *  \return set the new starting point and the new ending point
 */
int key_press(int int_keycode, t_recup* ptr_rcp_recup);
#endif