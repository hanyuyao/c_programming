#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define GAME_TERMINATE -1

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_DISPLAY_MODE   disp_data;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *image2 = NULL;
ALLEGRO_BITMAP *image3 = NULL;
ALLEGRO_BITMAP *game_name = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *startwin = NULL;
ALLEGRO_BITMAP *about = NULL;
ALLEGRO_KEYBOARD_STATE keyState ;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *timer2 = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE *song2=NULL;
ALLEGRO_SAMPLE *cheer=NULL;
ALLEGRO_SAMPLE_ID myID;
ALLEGRO_FONT *font = NULL;
ALLEGRO_FONT *font2 = NULL;
ALLEGRO_FONT *font3 = NULL;


int aboutpage = 0;
int p1=0;
int p1jump=0;
int p1right=0;
int p1left=0;
int p1attack=0;
int p1attack1=0;

int p2=0;
int p2jump=0;
int p2right=0;
int p2left=0;
int p2attack=0;
int p2attack1=0;


ALLEGRO_BITMAP *photo1 = NULL;
ALLEGRO_BITMAP *win1 = NULL;
ALLEGRO_BITMAP *p11 = NULL;
ALLEGRO_BITMAP *p12 = NULL;
ALLEGRO_BITMAP *p13 = NULL;
ALLEGRO_BITMAP *p14 = NULL;
ALLEGRO_BITMAP *p15 = NULL;
ALLEGRO_BITMAP *p16 = NULL;
ALLEGRO_BITMAP *p17 = NULL;
ALLEGRO_BITMAP *p18 = NULL;
ALLEGRO_BITMAP *p19 = NULL;
ALLEGRO_BITMAP *p110 = NULL;

ALLEGRO_BITMAP *p11j = NULL;
ALLEGRO_BITMAP *p12j = NULL;
ALLEGRO_BITMAP *p13j = NULL;
ALLEGRO_BITMAP *p14j = NULL;
ALLEGRO_BITMAP *p15j = NULL;
ALLEGRO_BITMAP *p16j = NULL;
ALLEGRO_BITMAP *p17j = NULL;
ALLEGRO_BITMAP *p18j = NULL;
ALLEGRO_BITMAP *p19j = NULL;
ALLEGRO_BITMAP *p110j = NULL;

ALLEGRO_BITMAP *p11l = NULL;
ALLEGRO_BITMAP *p12l = NULL;
ALLEGRO_BITMAP *p13l = NULL;
ALLEGRO_BITMAP *p14l = NULL;
ALLEGRO_BITMAP *p15l = NULL;
ALLEGRO_BITMAP *p16l = NULL;
ALLEGRO_BITMAP *p17l = NULL;
ALLEGRO_BITMAP *p18l = NULL;
ALLEGRO_BITMAP *p19l = NULL;
ALLEGRO_BITMAP *p110l = NULL;

ALLEGRO_BITMAP *p11a = NULL;
ALLEGRO_BITMAP *p12a = NULL;
ALLEGRO_BITMAP *p13a = NULL;
ALLEGRO_BITMAP *p14a = NULL;
ALLEGRO_BITMAP *p15a = NULL;
ALLEGRO_BITMAP *p16a = NULL;
ALLEGRO_BITMAP *p17a = NULL;
ALLEGRO_BITMAP *p18a = NULL;
ALLEGRO_BITMAP *p19a = NULL;
ALLEGRO_BITMAP *p110a = NULL;


ALLEGRO_BITMAP *photo2 = NULL;
ALLEGRO_BITMAP *win2 = NULL;
ALLEGRO_BITMAP *p21 = NULL;
ALLEGRO_BITMAP *p22 = NULL;
ALLEGRO_BITMAP *p23 = NULL;
ALLEGRO_BITMAP *p24 = NULL;
ALLEGRO_BITMAP *p25 = NULL;
ALLEGRO_BITMAP *p26 = NULL;
ALLEGRO_BITMAP *p27 = NULL;
ALLEGRO_BITMAP *p28 = NULL;
ALLEGRO_BITMAP *p29 = NULL;
ALLEGRO_BITMAP *p210 = NULL;

ALLEGRO_BITMAP *p21j = NULL;
ALLEGRO_BITMAP *p22j = NULL;
ALLEGRO_BITMAP *p23j = NULL;
ALLEGRO_BITMAP *p24j = NULL;
ALLEGRO_BITMAP *p25j = NULL;
ALLEGRO_BITMAP *p26j = NULL;
ALLEGRO_BITMAP *p27j = NULL;
ALLEGRO_BITMAP *p28j = NULL;
ALLEGRO_BITMAP *p29j = NULL;
ALLEGRO_BITMAP *p210j = NULL;

ALLEGRO_BITMAP *p21l = NULL;
ALLEGRO_BITMAP *p22l = NULL;
ALLEGRO_BITMAP *p23l = NULL;
ALLEGRO_BITMAP *p24l = NULL;
ALLEGRO_BITMAP *p25l = NULL;
ALLEGRO_BITMAP *p26l = NULL;
ALLEGRO_BITMAP *p27l = NULL;
ALLEGRO_BITMAP *p28l = NULL;
ALLEGRO_BITMAP *p29l = NULL;
ALLEGRO_BITMAP *p210l = NULL;

ALLEGRO_BITMAP *p21a = NULL;
ALLEGRO_BITMAP *p22a = NULL;
ALLEGRO_BITMAP *p23a = NULL;
ALLEGRO_BITMAP *p24a = NULL;
ALLEGRO_BITMAP *p25a = NULL;
ALLEGRO_BITMAP *p26a = NULL;
ALLEGRO_BITMAP *p27a = NULL;
ALLEGRO_BITMAP *p28a = NULL;
ALLEGRO_BITMAP *p29a = NULL;
ALLEGRO_BITMAP *p210a = NULL;

//Custom Definition
const char *title = "Final Project 106060011";
const float FPS = 60;
const int WIDTH = 1600;
const int HEIGHT = 898;

typedef struct character
{
    float x;
    float y;
    char name;
    int hp=10;
    int state=0;
    ALLEGRO_BITMAP *image_path;

}Character;

Character character1;
Character character2;
Character character3;

int imageWidth = 0;
int imageHeight = 0;
int draw = 0;
int done = 0;
int window = 1;
bool judge_next_window = false;
bool ture_1 , ture_2;

void show_err_msg(int msg);
void game_load();
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();
void reset();

int main(int argc, char *argv[]) {
    int msg = 0;

    game_init();
    game_begin();

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("End Game\n");
    }

    game_destroy();
    return 0;
}

void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d\n", msg);
    game_destroy();
    exit(9);
}

void game_load()
{
    song2 = al_load_sample( "700 .wav" );
    cheer = al_load_sample( "cheer.wav" );
    //load image
    photo1 = al_load_bitmap("photo1.png");
    win1 = al_load_bitmap("win1.png");
    p11 = al_load_bitmap("1-11.png");
    p12 = al_load_bitmap("1-2.png");
    p13 = al_load_bitmap("1-3.png");
    p14 = al_load_bitmap("1-4.png");
    p15 = al_load_bitmap("1-5.png");
    p16 = al_load_bitmap("1-6.png");
    p17 = al_load_bitmap("1-7.png");
    p18 = al_load_bitmap("1-8.png");
    p19 = al_load_bitmap("1-9.png");
    p110 = al_load_bitmap("1-10.png");

    p11j = al_load_bitmap("j1-1.png");
    p12j = al_load_bitmap("j1-2.png");
    p13j = al_load_bitmap("j1-3.png");
    p14j = al_load_bitmap("j1-4.png");
    p15j = al_load_bitmap("j1-5.png");
    p16j = al_load_bitmap("j1-6.png");
    p17j = al_load_bitmap("j1-7.png");
    p18j = al_load_bitmap("j1-8.png");
    p19j = al_load_bitmap("j1-9.png");
    p110j = al_load_bitmap("j1-10.png");

    p11l = al_load_bitmap("l1-1.png");
    p12l = al_load_bitmap("l1-2.png");
    p13l = al_load_bitmap("l1-3.png");
    p14l = al_load_bitmap("l1-4.png");
    p15l = al_load_bitmap("l1-5.png");
    p16l = al_load_bitmap("l1-6.png");
    p17l = al_load_bitmap("l1-7.png");
    p18l = al_load_bitmap("l1-8.png");
    p19l = al_load_bitmap("l1-9.png");
    p110l = al_load_bitmap("l1-10.png");

    p11a = al_load_bitmap("a1-1.png");
    p12a = al_load_bitmap("a1-2.png");
    p13a = al_load_bitmap("a1-3.png");
    p14a = al_load_bitmap("a1-4.png");
    p15a = al_load_bitmap("a1-5.png");
    p16a = al_load_bitmap("a1-6.png");
    p17a = al_load_bitmap("a1-7.png");
    p18a = al_load_bitmap("a1-8.png");
    p19a = al_load_bitmap("a1-9.png");
    p110a = al_load_bitmap("a1-10.png");

    photo2 = al_load_bitmap("photo2.png");
    win2 = al_load_bitmap("win2.png");
    p21 = al_load_bitmap("2-1.png");
    p22 = al_load_bitmap("2-2.png");
    p23 = al_load_bitmap("2-3.png");
    p24 = al_load_bitmap("2-4.png");
    p25 = al_load_bitmap("2-5.png");
    p26 = al_load_bitmap("2-6.png");
    p27 = al_load_bitmap("2-7.png");
    p28 = al_load_bitmap("2-8.png");
    p29 = al_load_bitmap("2-9.png");
    p210 = al_load_bitmap("2-10.png");

    p21j = al_load_bitmap("j2-1.png");
    p22j = al_load_bitmap("j2-2.png");
    p23j = al_load_bitmap("j2-3.png");
    p24j = al_load_bitmap("j2-4.png");
    p25j = al_load_bitmap("j2-5.png");
    p26j = al_load_bitmap("j2-6.png");
    p27j = al_load_bitmap("j2-7.png");
    p28j = al_load_bitmap("j2-8.png");
    p29j = al_load_bitmap("j2-9.png");
    p210j = al_load_bitmap("j2-10.png");

    p21l = al_load_bitmap("l2-1.png");
    p22l = al_load_bitmap("l2-2.png");
    p23l = al_load_bitmap("l2-3.png");
    p24l = al_load_bitmap("l2-4.png");
    p25l = al_load_bitmap("l2-5.png");
    p26l = al_load_bitmap("l2-6.png");
    p27l = al_load_bitmap("l2-7.png");
    p28l = al_load_bitmap("l2-8.png");
    p29l = al_load_bitmap("l2-9.png");
    p210l = al_load_bitmap("l2-10.png");

    p21a = al_load_bitmap("a2-1.png");
    p22a = al_load_bitmap("a2-2.png");
    p23a = al_load_bitmap("a2-3.png");
    p24a = al_load_bitmap("a2-4.png");
    p25a = al_load_bitmap("a2-5.png");
    p26a = al_load_bitmap("a2-6.png");
    p27a = al_load_bitmap("a2-7.png");
    p28a = al_load_bitmap("a2-8.png");
    p29a = al_load_bitmap("a2-9.png");
    p210a = al_load_bitmap("a2-10.png");
}

void game_init() {
    if (!al_init()) {
        show_err_msg(-1);
    }
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        show_err_msg(-1);
    }
    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        show_err_msg(-1);
    }
    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        show_err_msg(-1);
    }
    // Create display
//    display = al_create_display(WIDTH, HEIGHT);

    al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    display = al_create_display(disp_data.width, disp_data.height);
    /*create a full screen display*/


    event_queue = al_create_event_queue();
    if (display == NULL || event_queue == NULL) {
        show_err_msg(-1);
    }
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
////    al_register_event_source(event_queue, al_get_mouse_event_source());
}

void game_begin() {
    game_load();
    // Load sound
    song = al_load_sample( "31 minutes.wav" );
    if (!song){
        printf( "Audio clip sample not loaded!\n" );
        show_err_msg(-1);
    }
    // Loop the song until the display closes
    al_play_sample(song, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&myID);
////    al_clear_to_color(al_map_rgb(100,100,0));
    startwin = al_load_bitmap("startwin2.jpg");
    game_name = al_load_bitmap("jungle.png");
    //load about
    about = al_load_bitmap("about.png");
    // Load and draw text
    font = al_load_ttf_font("LucidaSansDemiBold.ttf  ",70,0);
    font2 = al_load_ttf_font("LucidaBrightDemiItalic.ttf",120,0);
    font3 = al_load_ttf_font("LucidaBrightDemiItalic.ttf",60,0);
}

int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    // Our setting for controlling animation
    if(event.timer.source == timer){
        ture_1 = !ture_1 ;
    }
    if(event.timer.source == timer2){
        ture_2 = !ture_2 ;
    }

    //restart
    if(window==3 || window==4){
        if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            if(event.keyboard.keycode == ALLEGRO_KEY_Y){
                judge_next_window=false;
                al_stop_sample(&myID);
                window=1;
                game_begin();
                game_run();
            }
    }

    // Keyboard
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch(event.keyboard.keycode)
        {
            // P2 control

            case ALLEGRO_KEY_A:
                if(character1.state!=4 && character1.state!=5)
                    character1.state=0;
                break;
            case ALLEGRO_KEY_D:
                if(character1.state!=4 && character1.state!=5)
                    character1.state=0;
                break;

            // P1 control
            case ALLEGRO_KEY_RIGHT:
                if(character2.state!=4 && character2.state!=5)
                character2.state=0;
                break;
            case ALLEGRO_KEY_LEFT:
                if(character2.state!=4 && character2.state!=5)
                character2.state=0;
                break;


            // For Start Menu
            case ALLEGRO_KEY_SPACE:
                judge_next_window = true;
                break;

            //For about
            case ALLEGRO_KEY_1:
                aboutpage = 1;
                break;

            case ALLEGRO_KEY_2:
                aboutpage = 0;
                break;

            case ALLEGRO_KEY_ESCAPE:
                return GAME_TERMINATE;
                break;
        }
    }

    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(event.keyboard.keycode)
        {
            // P2 control
            case ALLEGRO_KEY_W:
                if(character1.state!=4 && character1.state!=5)
                    character1.state=1;
                break;
            case ALLEGRO_KEY_A:
                if(character1.state!=4 && character1.state!=5)
                if(character1.x > 20 && character1.state!=1){
                    character1.state=2;
                }
                break;
            case ALLEGRO_KEY_D:
                if(character1.state!=4 && character1.state!=5)
                if(character1.x < 1600 && character1.state!=1)
                character1.state=3;
                break;

            case ALLEGRO_KEY_F:
                if(character1.state==2 || character1.state==0){
                    character1.state=4;
                    if((character1.x-character2.x>0 && character1.x-character2.x<350) || (character2.x-character1.x>0 && character2.x-character1.x<350))
                    if((character1.y-character2.y>0 && character1.y-character2.y<100) || (character2.y-character1.y>0 && character2.y-character1.y<100)){
                        character2.hp -= 1;
                    }
                }
                else if(character1.state==3 || character1.state==0){
                    character1.state=5;
                    if((character1.x-character2.x>0 && character1.x-character2.x<350) || (character2.x-character1.x>0 && character2.x-character1.x<350))
                        if((character1.y-character2.y>0 && character1.y-character2.y<100) || (character2.y-character1.y>0 && character2.y-character1.y<100)){
                        character2.hp -= 1;
                    }
                }
                break;

            // P1 control
            case ALLEGRO_KEY_UP:
                if(character2.state!=4 && character2.state!=5)
                character2.state = 1;
                break;
            case ALLEGRO_KEY_RIGHT:
                if(character2.state!=4 && character2.state!=5)
                if(character2.x < 1600 && character2.state!=1)
                character2.state=3;
                break;
            case ALLEGRO_KEY_LEFT:
                if(character2.state!=4 && character2.state!=5)
                if(character2.x > 20 && character2.state!=1)
                character2.state=2;
                break;
            case ALLEGRO_KEY_0:
                if(character2.state==2 || character2.state==0){
                    character2.state=4;
                    if((character1.x-character2.x>0 && character1.x-character2.x<350) || (character2.x-character1.x>0 && character2.x-character1.x<350))
                    if((character1.y-character2.y>0 && character1.y-character2.y<100) || (character2.y-character1.y>0 && character2.y-character1.y<100)){
                        character1.hp -= 1;
                    }
                }
                else if(character2.state==3 || character2.state==0){
                    character2.state=5;
                    if((character1.x-character2.x>0 && character1.x-character2.x<350) || (character2.x-character1.x>0 && character2.x-character1.x<350))
                        if((character1.y-character2.y>0 && character1.y-character2.y<100) || (character2.y-character1.y>0 && character2.y-character1.y<100)){
                        character1.hp -= 1;
                    }
                }
                break;
        }

    }
    return 0;
}

int game_run() {
    int error = 0;
    // First window(Menu)
    if(window == 1){
        reset();
        al_draw_bitmap(startwin, 0, 0, 0);
        al_draw_bitmap(game_name, 600, 100, 0);
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+300 , ALLEGRO_ALIGN_CENTRE, "Start - Press Space");
        al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2+780, HEIGHT/2+100 , ALLEGRO_ALIGN_CENTRE, "Exit - Press ESC");
        al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2-480, HEIGHT/2+100 , ALLEGRO_ALIGN_CENTRE, "About - Press 1");
        if(aboutpage) al_draw_bitmap(about, 450, 200, 0);
        al_flip_display();

        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();

            if(judge_next_window) {
                window = 2;
                // Setting Character
                character1.x = 200;
                character1.y = 600;
                character2.x = 1400;
                character2.y = 600;
                character1.image_path = al_load_bitmap("2-1.png");
                character2.image_path= al_load_bitmap("1-1.png");
                character3.image_path = al_load_bitmap("jungle.png");
                background = al_load_bitmap("playwin.png");

                //Initialize Timer
                timer  = al_create_timer(1.0/60.0);
                timer2  = al_create_timer(1.0/60.0);
                al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                al_start_timer(timer);
                al_start_timer(timer2);

                //song setting
                al_stop_sample(&myID);
                al_play_sample(song2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&myID);
            }
        }
    }
    // Second window(Main Game)
    else if(window == 2){

        // Change Image for animation
        al_draw_bitmap(background, 0,0,0);
        al_draw_bitmap(photo2, 20,20,0);
        al_draw_bitmap(photo1, 1700,20,0);
        al_draw_text(font3, al_map_rgb(255,255,255), 200, 200 , ALLEGRO_ALIGN_CENTRE, "P2: Taokaka");
        al_draw_text(font3, al_map_rgb(255,255,255), 1650, 200 , ALLEGRO_ALIGN_CENTRE, "P1: Arakune");
        if(character1.hp > 0){
            al_draw_filled_rectangle(200, 50, 200+60*character1.hp, 150, al_map_rgb(255,0,0));
        }
        if(character2.hp > 0){
            al_draw_filled_rectangle(1650-60*character2.hp, 50, 1650, 150, al_map_rgb(255,0,0));
        }

        if(character2.state == 0)
        {
            p1++;
            if(p1<40) character2.image_path = p11;
            if(p1>=40 && p1<80) character2.image_path = p12;
            if(p1>=80 && p1<120) character2.image_path = p13;
            if(p1>=120 && p1<160) character2.image_path = p14;
            if(p1>=160 && p1<200) character2.image_path = p15;
            if(p1>=200 && p1<240) character2.image_path = p16;
            if(p1>=240 && p1<280) character2.image_path = p17;
            if(p1>=280 && p1<320) character2.image_path = p18;
            if(p1>=320 && p1<360) character2.image_path = p19;
            if(p1>=360 && p1<400) character2.image_path = p110;
            if(p1==400) p1=0;
            if(ture_1) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
            else al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        }
        else if(character2.state == 1)
        {
            p1jump++;
            if(p1jump<30){
                character2.image_path = p11j;
                character2.y -= 2;
            }
            if(p1jump>=30 && p1jump<60){
                character2.image_path = p12j;
                character2.y -= 2;
            }
            if(p1jump>=60 && p1jump<90){
                character2.image_path = p13j;
                character2.y -= 2;
            }
            if(p1jump>=90 && p1jump<120){
                character2.image_path = p14j;
                character2.y -= 2;
            }
            if(p1jump>=120 && p1jump<150){
                character2.image_path = p15j;
                character2.y -= 2;
            }
            if(p1jump>=150 && p1jump<180){
                character2.image_path = p16j;
                character2.y += 2;
            }
            if(p1jump>=180 && p1jump<210){
                character2.image_path = p17j;
                character2.y += 2;
            }
            if(p1jump>=210 && p1jump<240){
                character2.image_path = p18j;
                character2.y += 2;
            }
            if(p1jump>=240 && p1jump<270){
                character2.image_path = p19j;
                character2.y += 2;
            }
            if(p1jump>=270 && p1jump<300){
                character2.image_path = p110j;
                character2.y += 2;
            }
            if(p1jump==300){
                p1jump=0;
                character2.state = 0;
            }
            if(ture_1) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
            else al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        }
        else if(character2.state == 2 && character2.x > 20)
        {
            p1left++;
            if(p1left<50){
                character2.image_path = p11l;
                character2.x -= 1;
            }
            if(p1left>=50 && p1left<100){
                character2.image_path = p12l;
                character2.x -= 1;
            }
            if(p1left>=100 && p1left<150){
                character2.image_path = p13l;
                character2.x -= 1;
            }
            if(p1left>=150 && p1left<200){
                character2.image_path = p14l;
                character2.x -= 1;
            }
            if(p1left>=200 && p1left<250){
                character2.image_path = p15l;
                character2.x -= 1;
            }
            if(p1left>=250 && p1left<300){
                character2.image_path = p16l;
                character2.x -= 1;
            }
            if(p1left>=300 && p1left<350){
                character2.image_path = p17l;
                character2.x -= 1;
            }
            if(p1left>=350 && p1left<400){
                character2.image_path = p18l;
                character2.x -= 1;
            }
            if(p1left>=400 && p1left<450){
                character2.image_path = p19l;
                character2.x -= 1;
            }
            if(p1left>=450 && p1left<500){
                character2.image_path = p110l;
                character2.x -= 1;
            }
            if(p1left==500){
                p1left=0;
            }
            if(ture_1) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
            else al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        }
        else if(character2.state == 3 && character2.x < 1600)
        {
            p1right++;
            if(p1right<50){
                character2.image_path = p11l;
                character2.x += 1;
            }
            if(p1right>=50 && p1right<100){
                character2.image_path = p12l;
                character2.x += 1;
            }
            if(p1right>=100 && p1right<150){
                character2.image_path = p13l;
                character2.x += 1;
            }
            if(p1right>=150 && p1right<200){
                character2.image_path = p14l;
                character2.x += 1;
            }
            if(p1right>=200 && p1right<250){
                character2.image_path = p15l;
                character2.x += 1;
            }
            if(p1right>=250 && p1right<300){
                character2.image_path = p16l;
                character2.x += 1;
            }
            if(p1right>=300 && p1right<350){
                character2.image_path = p17l;
                character2.x += 1;
            }
            if(p1right>=350 && p1right<400){
                character2.image_path = p18l;
                character2.x += 1;
            }
            if(p1right>=400 && p1right<450){
                character2.image_path = p19l;
                character2.x += 1;
            }
            if(p1right>=450 && p1right<500){
                character2.image_path = p110l;
                character2.x += 1;
            }
            if(p1right==500){
                p1right=0;
            }
            if(ture_1) al_draw_bitmap(character2.image_path, character2.x, character2.y, ALLEGRO_FLIP_HORIZONTAL);
            else al_draw_bitmap(character2.image_path, character2.x, character2.y, ALLEGRO_FLIP_HORIZONTAL);
        }
        else if(character2.state == 4)
        {
            p1attack++;
            if(p1attack<40){
                character2.image_path = p11a;
            }
            if(p1attack>=40 && p1attack<80){
                character2.image_path = p12a;
            }
            if(p1attack>=80 && p1attack<120){
                character2.image_path = p13a;
            }
            if(p1attack>=120 && p1attack<160){
                character2.image_path = p14a;
            }
            if(p1attack>=160 && p1attack<200){
                character2.image_path = p15a;
            }
            if(p1attack>=200 && p1attack<240){
                character2.image_path = p16a;
            }
            if(p1attack>=240 && p1attack<280){
                character2.image_path = p17a;
            }
            if(p1attack>=280 && p1attack<320){
                character2.image_path = p18a;
            }
            if(p1attack>=320 && p1attack<360){
                character2.image_path = p19a;
            }
            if(p1attack>=360 && p1attack<400){
                character2.image_path = p110a;
            }
            if(p1attack==400){
                p1attack=0;
                character2.state=0;
            }
            if(ture_1) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
            else al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        }
        else if(character2.state == 5)
        {
            p1attack1++;
            if(p1attack1<40){
                character2.image_path = p11a;
            }
            if(p1attack1>=40 && p1attack1<80){
                character2.image_path = p12a;
            }
            if(p1attack1>=80 && p1attack1<120){
                character2.image_path = p13a;
            }
            if(p1attack1>=120 && p1attack1<160){
                character2.image_path = p14a;
            }
            if(p1attack1>=160 && p1attack1<200){
                character2.image_path = p15a;
            }
            if(p1attack1>=200 && p1attack1<240){
                character2.image_path = p16a;
            }
            if(p1attack1>=240 && p1attack1<280){
                character2.image_path = p17a;
            }
            if(p1attack1>=280 && p1attack1<320){
                character2.image_path = p18a;
            }
            if(p1attack1>=320 && p1attack1<360){
                character2.image_path = p19a;
            }
            if(p1attack1>=360 && p1attack1<400){
                character2.image_path = p110a;
            }
            if(p1attack1==400){
                p1attack1=0;
                character2.state=0;
            }
            if(ture_1) al_draw_bitmap(character2.image_path, character2.x, character2.y, ALLEGRO_FLIP_HORIZONTAL);
            else al_draw_bitmap(character2.image_path, character2.x, character2.y, ALLEGRO_FLIP_HORIZONTAL);
        }


        if(character1.state == 0)
        {
            p2++;
            if(p2<70) character1.image_path = p21;
            if(p2>=70 && p2<140) character1.image_path = p22;
            if(p2>=140 && p2<210) character1.image_path = p23;
            if(p2>=210 && p2<280) character1.image_path = p24;
            if(p2>=280 && p2<350) character1.image_path = p25;
            if(p2>=350 && p2<420) character1.image_path = p26;
            if(p2>=420 && p2<490) character1.image_path = p27;
            if(p2>=490 && p2<560) character1.image_path = p28;
            if(p2>=560 && p2<630) character1.image_path = p29;
            if(p2>=630 && p2<700) character1.image_path = p210;
            if(p2==700) p2=0;
            if(ture_1) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
            else al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        }
        else if(character1.state == 1)
        {
            p2jump++;
            if(p2jump<30){
                character1.image_path = p21j;
                character1.y -= 2;
            }
            if(p2jump>=30 && p2jump<60){
                character1.image_path = p22j;
                character1.y -= 2;
            }
            if(p2jump>=60 && p2jump<90){
                character1.image_path = p23j;
                character1.y -= 2;
            }
            if(p2jump>=90 && p2jump<120){
                character1.image_path = p24j;
                character1.y -= 2;
            }
            if(p2jump>=120 && p2jump<150){
                character1.image_path = p25j;
                character1.y -= 2;
            }
            if(p2jump>=150 && p2jump<180){
                character1.image_path = p26j;
                character1.y += 2;
            }
            if(p2jump>=180 && p2jump<210){
                character1.image_path = p27j;
                character1.y += 2;
            }
            if(p2jump>=210 && p2jump<240){
                character1.image_path = p28j;
                character1.y += 2;
            }
            if(p2jump>=240 && p2jump<270){
                character1.image_path = p29j;
                character1.y += 2;
            }
            if(p2jump>=270 && p2jump<300){
                character1.image_path = p210j;
                character1.y += 2;
            }
            if(p2jump==300){
                p2jump=0;
                character1.state = 0;
            }
            if(ture_1) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
            else al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        }
        else if(character1.state == 2 && character1.x > 20)
        {
            p2left++;
            if(p2left<50){
                character1.image_path = p21l;
                character1.x -= 1;
            }
            if(p2left>=50 && p2left<100){
                character1.image_path = p22l;
                character1.x -= 1;
            }
            if(p2left>=100 && p2left<150){
                character1.image_path = p23l;
                character1.x -= 1;
            }
            if(p2left>=150 && p2left<200){
                character1.image_path = p24l;
                character1.x -= 1;
            }
            if(p2left>=200 && p2left<250){
                character1.image_path = p25l;
                character1.x -= 1;
            }
            if(p2left>=250 && p2left<300){
                character1.image_path = p26l;
                character1.x -= 1;
            }
            if(p2left>=300 && p2left<350){
                character1.image_path = p27l;
                character1.x -= 1;
            }
            if(p2left>=350 && p2left<400){
                character1.image_path = p28l;
                character1.x -= 1;
            }
            if(p2left>=400 && p2left<450){
                character1.image_path = p29l;
                character1.x -= 1;
            }
            if(p2left>=450 && p2left<500){
                character1.image_path = p210l;
                character1.x -= 1;
            }
            if(p2left==500){
                p2left=0;
            }
            if(ture_1) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
            else al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        }
        else if(character1.state == 3 && character1.x <1600)
        {
            p2right++;
            if(p2right<50){
                character1.image_path = p21l;
                character1.x += 1;
            }
            if(p2right>=50 && p2right<100){
                character1.image_path = p22l;
                character1.x += 1;
            }
            if(p2right>=100 && p2right<150){
                character1.image_path = p23l;
                character1.x += 1;
            }
            if(p2right>=150 && p2right<200){
                character1.image_path = p24l;
                character1.x += 1;
            }
            if(p2right>=200 && p2right<250){
                character1.image_path = p25l;
                character1.x += 1;
            }
            if(p2right>=250 && p2right<300){
                character1.image_path = p26l;
                character1.x += 1;
            }
            if(p2right>=300 && p2right<350){
                character1.image_path = p27l;
                character1.x += 1;
            }
            if(p2right>=350 && p2right<400){
                character1.image_path = p28l;
                character1.x += 1;
            }
            if(p2right>=400 && p2right<450){
                character1.image_path = p29l;
                character1.x += 1;
            }
            if(p2right>=450 && p2right<500){
                character1.image_path = p210l;
                character1.x += 1;
            }
            if(p2right==500){
                p2right=0;
            }
            if(ture_1) al_draw_bitmap(character1.image_path, character1.x, character1.y, ALLEGRO_FLIP_HORIZONTAL);
            else al_draw_bitmap(character1.image_path, character1.x, character1.y, ALLEGRO_FLIP_HORIZONTAL);
        }
        else if(character1.state == 4)
        {
            p2attack++;
            if(p2attack<40){
                character1.image_path = p21a;
            }
            if(p2attack>=40 && p2attack<80){
                character1.image_path = p22a;
            }
            if(p2attack>=80 && p2attack<120){
                character1.image_path = p23a;
            }
            if(p2attack>=120 && p2attack<160){
                character1.image_path = p24a;
            }
            if(p2attack>=160 && p2attack<200){
                character1.image_path = p25a;
            }
            if(p2attack>=200 && p2attack<240){
                character1.image_path = p26a;
            }
            if(p2attack>=240 && p2attack<280){
                character1.image_path = p27a;
            }
            if(p2attack>=280 && p2attack<320){
                character1.image_path = p28a;
            }
            if(p2attack>=320 && p2attack<360){
                character1.image_path = p29a;
            }
            if(p2attack>=360 && p2attack<400){
                character1.image_path = p210a;
            }
            if(p2attack==400){
                p2attack=0;
                character1.state=0;
            }
            if(ture_1) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
            else al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        }
        else if(character1.state == 5)
        {
            p2attack1++;
            if(p2attack1<40){
                character1.image_path = p21a;
            }
            if(p2attack1>=40 && p2attack1<80){
                character1.image_path = p22a;
            }
            if(p2attack1>=80 && p2attack1<120){
                character1.image_path = p23a;
            }
            if(p2attack1>=120 && p2attack1<160){
                character1.image_path = p24a;
            }
            if(p2attack1>=160 && p2attack1<200){
                character1.image_path = p25a;
            }
            if(p2attack1>=200 && p2attack1<240){
                character1.image_path = p26a;
            }
            if(p2attack1>=240 && p2attack1<280){
                character1.image_path = p27a;
            }
            if(p2attack1>=280 && p2attack1<320){
                character1.image_path = p28a;
            }
            if(p2attack1>=320 && p2attack1<360){
                character1.image_path = p29a;
            }
            if(p2attack1>=360 && p2attack1<400){
                character1.image_path = p210a;
            }
            if(p2attack1==400){
                p2attack1=0;
                character1.state=0;
            }
            if(ture_1) al_draw_bitmap(character1.image_path, character1.x, character1.y, ALLEGRO_FLIP_HORIZONTAL);
            else al_draw_bitmap(character1.image_path, character1.x, character1.y, ALLEGRO_FLIP_HORIZONTAL);
        }

        if(character1.hp <= 0){
            window=3;
            al_stop_sample(&myID);
            al_play_sample(cheer, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&myID);
        }
        if(character2.hp <= 0){
            window=4;
            al_stop_sample(&myID);
            al_play_sample(cheer, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&myID);
        }
        al_flip_display();
        //al_clear_to_color(al_map_rgb(0,0,0));

        // Listening for new event
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
    }
    else if(window==3){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(win1, WIDTH/2-150, HEIGHT/2-400, 0);
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+50 , ALLEGRO_ALIGN_CENTRE, "P1 win!!!");
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+200 , ALLEGRO_ALIGN_CENTRE, "Exit - Press ESC");
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+350 , ALLEGRO_ALIGN_CENTRE, "Restart - Press y");

        al_flip_display();
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
    }
    else if(window==4){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(win2, WIDTH/2-50, HEIGHT/2-300, 0);
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+50 , ALLEGRO_ALIGN_CENTRE, "P2 win!!!");
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+200 , ALLEGRO_ALIGN_CENTRE, "Exit - Press ESC");
        al_draw_text(font2, al_map_rgb(255,255,255), WIDTH/2+100, HEIGHT/2+350 , ALLEGRO_ALIGN_CENTRE, "Restart - Press y");

        al_flip_display();
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
        }
    }
    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_timer(timer2);
    al_destroy_bitmap(image);
    al_destroy_sample(song);
}

void reset(){
    p1=0;
    p1jump=0;
    p1right=0;
    p1left=0;
    p1attack=0;
    p1attack1=0;

    p2=0;
    p2jump=0;
    p2right=0;
    p2left=0;
    p2attack=0;
    p2attack1=0;

    character1.hp=10;
    character2.hp=10;
    character1.state=0;
    character2.state=0;
}
