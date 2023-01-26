/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   PathFinding                                        :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 17/01/2023 12:23:40 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*        int_pox_y                                                                      */
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
    mlx_clear_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win);
   
    /*free sprites*/
    for(int i = 0; i < ptr_rcp_recup->int_nb_sprite; i++)
        mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_img_sprites[i].ptr_void_img);
    free(ptr_rcp_recup->ptr_img_sprites);

    //*free all the button*/
    for(int i = 0; i < ptr_rcp_recup->int_btn_per_row; i++)
        free(ptr_rcp_recup->pptr_btn_board[i]);        
    free(ptr_rcp_recup->pptr_btn_board);


    mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->img_background.ptr_void_img);
    
    mlx_destroy_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win);
    mlx_destroy_display(ptr_rcp_recup->ptr_void_mlx);
    
    exit(0); 
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


int mouse_release(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
{
    switch (int_keycode)
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
    int int_pox_x;
    int int_pox_y;
    
    int_pox_x = int_x / ptr_rcp_recup->int_pixel_per_case;
    int_pox_y = int_y / ptr_rcp_recup->int_pixel_per_case;

    if(int_x >= ptr_rcp_recup->int_btn_per_line || int_y >= ptr_rcp_recup->int_btn_per_row)
        return 1;

    /* set all btn to wall*/
    if(ptr_rcp_recup->key_pressed.int_left_click){
        ptr_rcp_recup->pptr_btn_board[int_pox_y][int_pox_x].data.isWall = 1;
    }

    /**/
    else if(ptr_rcp_recup->key_pressed.int_right_click){
        ptr_rcp_recup->pptr_btn_board[int_pox_y][int_pox_x].data.isWall = 0;
    }
    return (1);
}


int key_press(int int_keycode, t_recup* ptr_rcp_recup)
{
    switch (int_keycode)
    {
    case SPACE:
        if(ptr_rcp_recup->ptr_btn_start != NULL)
            ptr_rcp_recup->ptr_btn_start->img_sprite = ptr_rcp_recup->ptr_img_sprites[0];
        
        ptr_rcp_recup->ptr_btn_start = &ptr_rcp_recup->pptr_btn_board[0][0];
        ptr_rcp_recup->ptr_btn_start->img_sprite = ptr_rcp_recup->ptr_img_sprites[2];
        break;
    
    case ENTER:
        ptr_rcp_recup->ptr_btn_end->data.is_end = 0;
        ptr_rcp_recup->ptr_btn_end->img_sprite = ptr_rcp_recup->ptr_img_sprites[0];
        ptr_rcp_recup->ptr_btn_end = &ptr_rcp_recup->pptr_btn_board[0][0];
        ptr_rcp_recup->ptr_btn_end->img_sprite = ptr_rcp_recup->ptr_img_sprites[3];
        
        break;
    default:
        break;
    }

    return (1);
}