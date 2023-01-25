/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   BlackJack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 27/12/2022 23:25:29 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 30/11/2022 04:48:36 by Durandnico   ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file my_mlx_func.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:25:29
 *
 *  \brief some of my functions for mlx
 *
 *
 */

//librairies
#include "../inc/PathFinding.h"

void
drawn_sprite(t_img* ptr_img_base, t_img img_to_add, int int_x, int int_y)
{
     
    int     i; //loop variable
    int     j; //loop variable
    char*   p_img; //pointeur to a pixel of the img
    char*   p_bg; //pointeur to a pixel of the background
    
    /*loop through all pixel*/
    for(i = 0; i < img_to_add.int_height; i++){
        for(j = 0; j < img_to_add.int_width; j++){
            p_img = img_to_add.ptr_char_addr + (i * img_to_add.int_line_length + j * (img_to_add.int_bits_per_pixel / 8));
            
            /*if is not transparent : write pixel on base_image*/
            if(*(int*)p_img != -16777216){
                p_bg = ptr_img_base->ptr_char_addr + ((i + int_y) * ptr_img_base->int_line_length + (j + int_x) * (ptr_img_base->int_bits_per_pixel / 8));
                
                *(unsigned int*) p_bg = *(unsigned int*) p_img;
            }
        }
    }
}


t_button
create_button(t_img img_sprite, int (*ptr_intf_func)(), int int_x, int int_y)
{
    t_button    btn_new; //button to create

    /*affect value*/
    btn_new.img_sprite = img_sprite;
    btn_new.ptr_intf_func = ptr_intf_func;
    btn_new.img_sprite.pt_coord.int_x = int_x;
    btn_new.img_sprite.pt_coord.int_y = int_y;
    
    return (btn_new);
}

void
my_mlx_pixel_put(t_img* ptr_img_base, int int_x, int int_y, int int_color)
{
	char	*ptr_char_dst;

    /*find correct memory point corresponding to (x,y) and change pixel value*/
	ptr_char_dst = ptr_img_base->ptr_char_addr + (int_y * ptr_img_base->int_line_length + int_x * (ptr_img_base->int_bits_per_pixel / 8));
	*(unsigned int*)ptr_char_dst = int_color;
}


void fill(t_img* ptr_img_base, int int_x0, int int_y0, int int_xn, int int_yn, int int_color)
{
    for(int i = int_x0; i < int_xn; i++)
        for(int j = int_y0; j < int_yn; j++)
            my_mlx_pixel_put(ptr_img_base, i, j, int_color);     
}