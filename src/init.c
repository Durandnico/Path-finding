/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Path Finding                                       :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 15/01/2023 03:31:40 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file init.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sun 15 January 2023 - 03:31:40
 *
 *  \brief bunch of init function
 *
 *
 */

//librairies
#include "../inc/PathFinding.h"


void
init(t_recup* ptr_rcp_recup)
{
    /*Create the window*/
    ptr_rcp_recup->ptr_void_mlx = mlx_init();
    ptr_rcp_recup->ptr_void_win = mlx_new_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->int_window_width, ptr_rcp_recup->int_window_height, "Pathfinding");

    
    /*create the 3 sprites*/
    init_sprites(ptr_rcp_recup);

    /*init hooks functions*/
    init_hooks(ptr_rcp_recup);

    /*init all button*/
    init_button(ptr_rcp_recup);

    /*init background*/
    init_background(ptr_rcp_recup);

    show_everything(ptr_rcp_recup);
    
    mlx_loop(ptr_rcp_recup->ptr_void_mlx);
}



void
init_sprites(t_recup*    ptr_rcp_recup)
{
    ptr_rcp_recup->int_nb_sprite = 7;
    ptr_rcp_recup->ptr_img_sprites = malloc(ptr_rcp_recup->int_nb_sprite * sizeof(t_img));
    int tint_colors[7] = {0xbfbfbf, 0x7D6D61, 0x00A9A5, 0xFFD166, 0x2E933C, 0xFF3C38, 0x0D00A4};
    
    /*image of case:
     *  0 : empty
     *  1 : wall
     *  2 : entry point
     *  3 : exit point
     *  4 : visited
     *  5 : next visite
     *  6 : correct way
     */
    for(int i = 0; i < ptr_rcp_recup->int_nb_sprite; i++){
        ptr_rcp_recup->ptr_img_sprites[i].ptr_void_img  = mlx_new_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->int_pixel_per_case , ptr_rcp_recup->int_pixel_per_case);

        ptr_rcp_recup->ptr_img_sprites[i].ptr_char_addr = mlx_get_data_addr(ptr_rcp_recup->ptr_img_sprites[i].ptr_void_img, &ptr_rcp_recup->ptr_img_sprites[i].int_bits_per_pixel, &ptr_rcp_recup->ptr_img_sprites[i].int_line_length, &ptr_rcp_recup->ptr_img_sprites[i].int_endian);

        ptr_rcp_recup->ptr_img_sprites[i].int_height    = ptr_rcp_recup->int_pixel_per_case;
        ptr_rcp_recup->ptr_img_sprites[i].int_width     = ptr_rcp_recup->int_pixel_per_case;

        for(int j = 0; j < ptr_rcp_recup->int_pixel_per_case; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->ptr_img_sprites[i], j, 0, 0x7e7e7e);
            my_mlx_pixel_put(&ptr_rcp_recup->ptr_img_sprites[i], j, ptr_rcp_recup->int_pixel_per_case - 1, 0x7e7e7e);
            my_mlx_pixel_put(&ptr_rcp_recup->ptr_img_sprites[i], ptr_rcp_recup->int_pixel_per_case - 1, j, 0x7e7e7e);
            my_mlx_pixel_put(&ptr_rcp_recup->ptr_img_sprites[i], 0, j, 0x7e7e7e);
        }
    
        fill(&ptr_rcp_recup->ptr_img_sprites[i], 1, 1, ptr_rcp_recup->int_pixel_per_case - 1, ptr_rcp_recup->int_pixel_per_case - 1, tint_colors[i]);
    }
}


void
init_button(t_recup* ptr_rcp_recup)
{
    ptr_rcp_recup->pptr_btn_board   = malloc(ptr_rcp_recup->int_btn_per_line * sizeof(t_button*));
    for(int i = 0; i < ptr_rcp_recup->int_btn_per_line; i++){
        ptr_rcp_recup->pptr_btn_board[i]    =   malloc(ptr_rcp_recup->int_btn_per_row * sizeof(t_button));

        for(int j = 0; j < ptr_rcp_recup->int_btn_per_row; j++){
            ptr_rcp_recup->pptr_btn_board[i][j]         =   create_button(ptr_rcp_recup->ptr_img_sprites[0], exit, 1 + j * (ptr_rcp_recup->int_pixel_per_case), 1 + i * (ptr_rcp_recup->int_pixel_per_case));
            ptr_rcp_recup->pptr_btn_board[i][j].data    =   create_data();
        }
    }
}


void
init_background(t_recup* ptr_rcp_recup)
{
    ptr_rcp_recup->img_background.ptr_void_img  = mlx_new_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->int_window_width, ptr_rcp_recup->int_window_height);
    ptr_rcp_recup->img_background.ptr_char_addr = mlx_get_data_addr(ptr_rcp_recup->img_background.ptr_void_img, &ptr_rcp_recup->img_background.int_bits_per_pixel, &ptr_rcp_recup->img_background.int_line_length, &ptr_rcp_recup->img_background.int_endian);

    /*draw border*/
    for(int i = 0; i < ptr_rcp_recup->int_window_width; i++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, 0, 0x7e7e7e);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, ptr_rcp_recup->int_window_height - 1, 0x7e7e7e);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->int_window_width - 1, i, 0x7e7e7e);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, 0, i, 0x7e7e7e);
    }
    
    /*draw each button*/
    for(int i = 0; i < ptr_rcp_recup->int_btn_per_line; i++)
        for(int j = 0; j < ptr_rcp_recup->int_btn_per_row; j++)
            drawn_sprite(&ptr_rcp_recup->img_background, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.pt_coord.int_x, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.pt_coord.int_y);
}

/*!
 *  \proc void init_hooks(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 25 January 2023 - 12:48:23
 *  \brief 
 *  \param 
 */
void
init_hooks(t_recup* ptr_rcp_recup)
{
    /*red cross to exit*/
    mlx_hook(ptr_rcp_recup->ptr_void_win, 17, 0L, exit_prog, ptr_rcp_recup);

    /*mouse click*/
    mlx_hook(ptr_rcp_recup->ptr_void_win, 4, 1L<<2, mouse_press, ptr_rcp_recup);

    /*mouse release*/
    mlx_hook(ptr_rcp_recup->ptr_void_win, 5, 1L<<3, mouse_release, ptr_rcp_recup);

    /*mouse move*/
    mlx_hook(ptr_rcp_recup->ptr_void_win, 6, 1L<<6, mouse_move, ptr_rcp_recup);
}