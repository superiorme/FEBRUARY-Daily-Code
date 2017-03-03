#include <allegro5/allegro.h>
//include libraries for fonts
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//include libraries for sound
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>//allows .wav, .flac, .ogg, .it, .mod, .s3m, .xm
#include <stdio.h>
#include <cmath>
#include<iostream>
using namespace std;

const float FPS = 100;
const int SCREEN_W = 1000;
const int SCREEN_H = 1000;

const int BOUNCER_SIZE = 2;


int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;
	double t = 1;

	al_init();


	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);


	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//change the numbers to change the background color, 000 is black
	al_clear_to_color(al_map_rgb(250, 250, 250));
	al_flip_display();

	al_start_timer(timer);

	//font stuff

	al_init_font_addon(); // initialize the font addon

	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

						//audio stuff

	ALLEGRO_SAMPLE *sample = NULL; //variable to hold the audio file

								   //these two functions initalize the two included audio libraries
	al_install_audio();

	al_init_acodec_addon();

	al_reserve_samples(1);//decides how many samples we're using, creates a default mixer

						  //returns a memory address to the music file. make sure it's in your project folder!
	sample = al_load_sample("bomb 2.wav");
	if (sample == NULL) cout << "oops";
	//end audio stuff

	

	//hooks up the chosen font. make sure it's in your project folder!
	ALLEGRO_FONT *font = al_load_ttf_font("KLCupid.ttf", 72, 0);

	al_clear_to_color(al_map_rgb(50, 10, 70));



	al_flip_display();

	//here's where the sound is actually played!
	//parameters:  1) the sound file, 2) volume, 3) pan (left or right), 4) speed, 5) loop, 6) return value
	//looping options include: loop - ALLEGRO_PLAYMODE_ONCE, ALLEGRO_PLAYMODE_LOOP, or ALLEGRO_PLAYMODE_BIDIR
	al_play_sample(sample, 1.0, 0.0,2, ALLEGRO_PLAYMODE_LOOP, NULL);


	while (1)
	{

		t++;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
				bouncer_dy = -bouncer_dy;
			}

			//////////////////////////////////////////////////////////////////////////////////////////////
			//here's the parametric equations that determine the shape!!
			bouncer_x = 550 + 100* (1.6*cos(t) - (.6*cos((1.6*t) / .6)));
			bouncer_y = 250 + 120 * (1.6*sin(t) - (.6*sin((1.6*t) / .6)));



			/////////////////////////////////////////////////////////////////////////////////////////////////////
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//a well-placed if statement here might make it blink

			//uncommenting this line makes it moving dots instead of picture
			//also, change the number values to change the background color 
			// al_clear_to_color(al_map_rgb(0,0,0)); 	

			al_set_target_bitmap(bouncer);

			//mess with this last line here to change colors
			al_clear_to_color(al_map_rgb(100, 255, 250));
			al_set_target_bitmap(al_get_backbuffer(display));
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			//draws text to screen
			al_draw_text(font, al_map_rgb(200, 0, 0), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "do you see the octopi");

			al_flip_display();

			


		
	}

}
	
	al_destroy_sample(sample);
   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
   }