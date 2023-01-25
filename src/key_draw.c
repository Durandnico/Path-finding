/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   PathFinding                                        :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 17/01/2023 12:23:40 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file key_draw.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 17 January 2023 - 12:23:40
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/PathFinding.h"

/*a tester !*/
int
exit_prog(t_recup* ptr_rcp_recup)
{
    //free all the sprites
    for(int i = 0; i < ptr_rcp_recup->int_nb_sprite; i++)
        mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_img_sprites[i].ptr_void_img);

    free(ptr_rcp_recup->ptr_img_sprites);
    
    //free all the button
    for(int i = 0; i < ptr_rcp_recup->int_btn_per_line; i++){
        for(int j = 0; j < ptr_rcp_recup->int_btn_per_row; j++)
            mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.ptr_void_img);
        free(ptr_rcp_recup->pptr_btn_board[i]);        
    }
    free(ptr_rcp_recup->pptr_btn_board);


    mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->img_background.ptr_void_img);
    mlx_destroy_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win);
    mlx_destroy_display(ptr_rcp_recup->ptr_void_mlx);
    return (0);
}


int
mouse_press(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
{
    switch (int_keycode)
    {
    case LEFT_CLICK:
        ptr_rcp_recup->key_pressed.int_left_click = 1;
        break;
    
    case RIGHT_CLICK:
        ptr_rcp_recup->key_pressed.int_right_click = 1;
        break;

    default:
        break;
    }

    return (1);
}


int mouse_release(int keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
{
    switch (keycode)
    {
    case LEFT_CLICK:
        ptr_rcp_recup->key_pressed.int_left_click = 0;
        break;

    case RIGHT_CLICK:
        ptr_rcp_recup->key_pressed.int_right_click = 0;
        break;  
    default:
        break;
    }   

    return (1);
}


int mouse_move(int int_x, int int_y, t_recup* ptr_rcp_recup)
{
    if(ptr_rcp_recup->key_pressed.int_left_click){

    }
    return (1);
}
