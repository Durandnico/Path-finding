/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Pathfinding                                        :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 16/01/2023 13:26:01 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file function.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 13:26:01
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/PathFinding.h"

t_dataCase create_data(void)
{
    t_dataCase dtc_new; 

    dtc_new.int_distStart       = 0;
    dtc_new.int_distTarget      = 0;
    dtc_new.isWall              = 0;
    dtc_new.ptr_btn_next        = NULL;
    dtc_new.ptr_btn_previous    = NULL;
    dtc_new.is_end              = 0;

    return (dtc_new);
}


void
show_everything(t_recup* ptr_rcp_recup)
{
    mlx_clear_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win);

    for(int i = 0; i < ptr_rcp_recup->int_btn_per_line; i++)
        for(int j = 0; j < ptr_rcp_recup->int_btn_per_row; j++)
            drawn_sprite(&ptr_rcp_recup->img_background, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.pt_coord.int_x, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.pt_coord.int_y);

    mlx_put_image_to_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win, ptr_rcp_recup->img_background.ptr_void_img, 0, 0);
}