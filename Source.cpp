#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	ALLEGRO_DISPLAY *gamescreen = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *images = NULL;
	
	int a, b, c;

	a = rand() % 500;
	b = rand() % 200;
	c = rand() % 700;


	al_init();

	al_init_image_addon();

	al_create_timer(5);
	
	gamescreen = al_create_display(500,500);
	
	al_set_target_backbuffer(gamescreen);

	event_queue = al_create_event_queue();

	al_clear_to_color(al_map_rgb(a, b, c));

	al_flip_display();

	al_register_event_source(event_queue, al_get_display_event_source(gamescreen));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);


	al_destroy_timer(timer);
	al_destroy_display(gamescreen);
	al_destroy_event_queue(event_queue);

	return 0;
}