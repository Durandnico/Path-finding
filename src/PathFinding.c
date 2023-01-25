/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   PathFinding                                        :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 16/01/2023 12:22:16 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file PathFinding.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 12:22:16
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/PathFinding.h"


/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 16 January 2023 - 12:22:18
 *  \brief Main program
 *  \param argc : number of parameters
 *  \param argv : Values of the parameters 
 *  \return 0 if no error, -1 otherwise
 */
int main (int argc, char** argv) {
    
    t_recup rcp_recup;

    rcp_recup.int_window_width      = 800;
    rcp_recup.int_window_height     = 800;
    rcp_recup.int_pixel_per_case    = 20;
    rcp_recup.int_btn_per_line      = 40;
    rcp_recup.int_btn_per_row       = 40;

    init(&rcp_recup);    

    return 0;
}