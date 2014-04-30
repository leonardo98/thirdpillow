/*
 * screen.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: jwpilly
 */

#include "screen.h"

screen::screen(int render_width, int render_height) {
	this->render_width = render_width;
	this->render_height = render_height;
	this->buffer = new float[render_width * render_height * 3];
}

void screen::cls() {
	for (int i = 0; i < (render_width * render_height * 3); i++) {
		this->buffer[i] = (float) 0;
	}
}

int screen::get_width() {
	return this->render_width;
}

int screen::get_height() {
	return this->render_height;
}

void screen::set_buffer(float* buffer) {
	this->buffer = buffer;
}

float* screen::get_buffer() {
	return this->buffer;
}

float screen::get_at(int i) {
	return this->buffer[i];
}

void screen::set_at(int i, float f) {
	this->buffer[i] = f;
}

color* screen::get_pixel(int x, int y) {
	int index = putils::get_index_3d(x, y, 0, this->render_width, 3);
	color* c = new color(this->buffer[index], this->buffer[index + 1],
			this->buffer[index + 2], 1);
	return c;
}

void screen::set_pixel(int x, int y, color* c) {
	int index = putils::get_index_3d(x, y, 0, this->render_width, 3);
	this->buffer[index] = c->get_r();
	this->buffer[index + 1] = c->get_g();
	this->buffer[index + 2] = c->get_b();
}

screen::~screen() {
	delete this->buffer;
}
