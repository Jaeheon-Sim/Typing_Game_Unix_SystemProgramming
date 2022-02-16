#define row_start LINES/5
#define row_last 4*LINES/5
#define row_value row_start+row_last/6
#define col_start COLS/5
#define col_last 4*COLS/5
#define col_value col_start+col_last/20
#define ENDTIME 5
#define CORRECTTIME 2
#define OOPSTIME 3
#define Q_NUMBER 10

void start_screen();
void explain_rules();
void init_screen();
void game_over(int score);
void correct(int score);
void all();
void out_condition();
void go_condition();
int question(int num,int score,int type);
int type_input();
void error_screen();
void correct_time();
void oops_time();
void grid_screen();