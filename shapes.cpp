#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	

	al_init();

	al_init_primitives_addon();

	display = al_create_display(640, 480);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_init_primitives_addon();
	al_init_font_addon();

	display = al_create_display(10000, 10000);

	al_clear_to_color(al_map_rgb(0, 0, 0));



	ALLEGRO_FONT* font = al_create_builtin_font();
	al_draw_triangle(100, 150, 160, 65, 80, 90, al_map_rgb(0, 100, 6), 20);

	al_draw_triangle(400, 120, 180, 40, 70, 75, al_map_rgb(0, 5, 50), 10);

	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "happy valentine");


	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}

	sample = al_load_sample("boom.wav");

	if (!sample) {
		printf("Audio clip sample not loaded!\n");
		return -1;
	}


	if (!display) {
		fprintf(stderr, "failed to create display!\n");

		return -1;

		al_flip_display();




		al_rest(10.0);




		al_destroy_display;


	}

	/* Loop the sample until the display closes. */
	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	al_rest(10.0);


	al_destroy_display(display);
	al_destroy_sample(sample);
	return 0;
}
