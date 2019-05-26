#pragma once
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
void timer_binding(int i);

class cScena {
public:
	cScena();
	~cScena();
	void resize(int width, int height);
	void timer();
	void display();
	void mouse(int button, int state, int x, int y);
	int motion(int x, int y);
	void init(int argc, char *argv[], const char* window_name);
	void set_callbacks();
	void key(unsigned char key, int x, int y);

};