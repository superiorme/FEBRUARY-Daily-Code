#include<iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


int main(){
        
	ALLEGRO_DISPLAY *display = NULL;
		
		al_init();

		al_init_primitives_addon();

		display = al_create_display(640, 480);

		al_clear_to_color(al_map_rgb(0, 0, 0));
		





		al_draw_triangle(50, 150, 60, 65, 85, 90, al_map_rgb(0, 100, 6), 2);

		al_draw_triangle(60, 10, 80, 40, 50, 75, al_map_rgb(0, 5, 200), 10);

		al_draw_triangle(90, 60, 25, 20, 30, 50, al_map_rgb(0, 50, 60), 10);
		
		




		al_flip_display();




		al_rest(10.0);




		al_destroy_display;

		



		return 0;


	}