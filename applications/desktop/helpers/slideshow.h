#pragma once

#include <gui/canvas.h>

typedef struct Slideshow Slideshow;

Slideshow* slideshow_alloc();

void slideshow_free(Slideshow* slideshow);
bool slideshow_load(Slideshow* slideshow, const char* fspath);
void slideshow_goback(Slideshow* slideshow);
bool slideshow_advance(Slideshow* slideshow);
void slideshow_draw(Slideshow* slideshow, Canvas* canvas, uint8_t x, uint8_t y);
